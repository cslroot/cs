#include "GLFWRenderer.h"

#include "camera.h"
#include "scene.h"
#include "CSDisplayableObject.h"
#include <cs/core/CSBufferObject.h>

#include <GL/glew.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

namespace
{

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

    static const char* fragment_shader_text =
        "#version 330 core\n"
        "in vec3 color;\n"
        "out vec4 fragColor;\n"
        "void main()\n"
        "{\n"
        "    fragColor = vec4(color, 1.0);\n"
        "}\n";

    static void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
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

    void gen(const Scene& scene)
    {
        auto rootObj = scene.RootObject();
        auto p = dynamic_cast<cs::render::CSDisplayableObject2d*>(rootObj);
        auto buffer = p->GetBuffer();
        auto vertices = buffer->_points;

        std::vector<vertex> v;
        vertex v1 = { (float)vertices[0], (float)vertices[1] };
        vertex v2 = { (float)vertices[2], (float)vertices[3] };
        v.push_back(v1);
        v.push_back(v2);

        GLuint vertex_shader, fragment_shader;
        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
        glCompileShader(vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
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
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * v.size(), v.data(), GL_STATIC_DRAW);

            glEnableVertexAttribArray(_vpos_location);
            glVertexAttribPointer(_vpos_location, 2, GL_FLOAT, GL_FALSE,
                sizeof(v[0]), (void*)0);

            // glEnableVertexAttribArray(vcol_location);
            // glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
            //                       sizeof(vertices[0]), (void *)(sizeof(float) * 2));
        }
    }
};


GLFWRenderer::GLFWRenderer()
    : _impl(std::make_unique<Impl>())
{}

GLFWRenderer::~GLFWRenderer()
{}


void GLFWRenderer::Init()
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _impl->_window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!_impl->_window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(_impl->_window);
    glewInit();
    // gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);
}

void GLFWRenderer::Terminate()
{
    glfwDestroyWindow(_impl->_window);
    glfwTerminate();
}

void GLFWRenderer::Resize(int width, int height)
{
    BASE_CLASS::Resize(width, height);
}

bool GLFWRenderer::WindowShouldClose()
{
    return glfwWindowShouldClose(_impl->_window);
}

void GLFWRenderer::Render(const Scene& scene, const Camera& camera)
{
    _impl->_window = glfwGetCurrentContext();

    _impl->gen(scene);

    float ratio;
    int width, height;

    glfwGetFramebufferSize(_impl->_window, &width, &height);
    ratio = width / (float)height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    auto rot_angle = 0.0f; //(float)glfwGetTime();
    auto m = glm::rotate(glm::mat4x4(1.0), rot_angle, { 0, 0, 1.0 });
    auto p = glm::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    auto mvp = (p * m);


    glUseProgram(_impl->_program);
    glUniformMatrix4fv(_impl->_mvp_location, 1, GL_FALSE, (const GLfloat*)glm::value_ptr(mvp));
    glDrawArrays(GL_LINES, 0, 2);
    auto err = glGetError();
    if (err != GL_NO_ERROR)
    {
        assert(false);
    }

    glfwSwapBuffers(_impl->_window);
    glfwPollEvents();
}

