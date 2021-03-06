#include "GLFWRenderer.h"

#include "CSDisplayableObject.h"
#include "Camera.h"
#include "Scene.h"
#include <cs/core/CSBufferObject.h>

#include <GL/glew.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

namespace {

struct vertex
{
  float x, y;
};

static const char* vertex_shader_text =
  "#version 330 core\n"
  "uniform mat4 MVP;\n"
  // "in vec3 vCol;\n"
  "in vec2 vPos;\n"
  "out vec3 color;\n"
  "void main()\n"
  "{\n"
  "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
  "    color = vec3(1.0, 0.0, 0.0);\n"
  "}\n";

static const char* fragment_shader_text = "#version 330 core\n"
                                          "in vec3 color;\n"
                                          "out vec4 fragColor;\n"
                                          "void main()\n"
                                          "{\n"
                                          "    fragColor = vec4(color, 1.0);\n"
                                          "}\n";

static void
error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void
key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
}

using namespace cs::render;
using namespace cs::core;

using BASE_CLASS = Renderer;

struct GLFWRenderer::Impl
{
  GLFWwindow* _window;
  GLuint _program;
  GLint _mvp_location;

  GLint _vpos_location;
  // GLint _vcol_location;

  GLsizei gen(Node& node)
  {
    auto* p = dynamic_cast<cs::render::CSDisplayableObject*>(&node);
    if (!p) {
      return 0;
    }
    auto buffer = p->GetBuffer();
    auto vertices = buffer->_points;

    std::vector<vertex> v;
    for (size_t i = 0; i < vertices.size(); i += 2) {
      vertex v1 = { (float)vertices[i], (float)vertices[i + 1] };
      v.push_back(v1);
    }

    GLuint vertex_shader, fragment_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, nullptr);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, nullptr);
    glCompileShader(fragment_shader);

    GLuint program = glCreateProgram();
    _program = program;
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    _mvp_location = glGetUniformLocation(program, "MVP");
    _vpos_location = glGetAttribLocation(program, "vPos");

    // for 4.1 use VAO instead of VBO
    GLuint vao;
    GLuint vertex_buffer;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    {
      glGenBuffers(1, &vertex_buffer);
      glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
      glBufferData(
        GL_ARRAY_BUFFER, sizeof(vertex) * v.size(), v.data(), GL_STATIC_DRAW);

      glEnableVertexAttribArray(_vpos_location);
      glVertexAttribPointer(
        _vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(v[0]), (void*)nullptr);

      // glEnableVertexAttribArray(vcol_location);
      // glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
      //                       sizeof(vertices[0]), (void *)(sizeof(float) *
      //                       2));
    }

    return v.size();
  }
};

GLFWRenderer::GLFWRenderer()
  : _impl(std::make_unique<Impl>())
{}

GLFWRenderer::~GLFWRenderer() = default;

void
GLFWRenderer::Init()
{
  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  _impl->_window =
    glfwCreateWindow(640, 480, "Simple example", nullptr, nullptr);
  if (!_impl->_window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(_impl->_window);
  glewInit();
  // gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);
}

void
GLFWRenderer::Terminate()
{
  glfwDestroyWindow(_impl->_window);
  glfwTerminate();
}

void
GLFWRenderer::Resize(int width, int height)
{
  BASE_CLASS::Resize(width, height);
}

bool
GLFWRenderer::WindowShouldClose()
{
  return glfwWindowShouldClose(_impl->_window);
}

void
GLFWRenderer::Render(const Scene& scene, const Camera& camera)
{
  _impl->_window = glfwGetCurrentContext();

  int width = 0, height = 0;
  glfwGetFramebufferSize(_impl->_window, &width, &height);
  float ratio = width / (float)height;

  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);

  auto rot_angle = 0.0F; //(float)glfwGetTime();
  auto m = glm::rotate(glm::mat4x4(1.0), rot_angle, { 0, 0, 1.0 });
  auto p = glm::ortho(-ratio, ratio, -1.F, 1.F, 1.F, -1.F);
  auto mvp = (p * m);

  std::vector<GLsizei> npoints;
  auto rootObj = scene.RootObject();
  for (auto& c : rootObj->Children()) {
    GLsizei n = _impl->gen(*c);
    npoints.push_back(n);

    glUseProgram(_impl->_program);
    glUniformMatrix4fv(
      _impl->_mvp_location, 1, GL_FALSE, (const GLfloat*)glm::value_ptr(mvp));
    // glDrawArrays(GL_LINES, 0, npos);
    glDrawArrays(GL_LINE_STRIP, 0, n);
  }

  auto err = glGetError();
  if (err != GL_NO_ERROR) {
    assert(false);
  }

  glfwSwapBuffers(_impl->_window);
  glfwPollEvents();
}
