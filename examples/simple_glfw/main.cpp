#include <iostream>

#include <cs/base.h>
#include <cs/core.h>
#include <cs/render.h>
#include <cs/modeler.h>
#include <cs/app.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <fmt/format.h>


//     fmt::print("Hello, world!\n");
//     std::string s = fmt::format("The answer is {}.", 42);

//     auto& app = *pmyapp;

//     auto& doc = app.OpenNewDocument();
//     doc.SaveAs("save.txt");

//     auto& doc2 = app.OpenNewDocument();
//     doc2.SetName(u8"2nd document");
//     doc2.SaveAs("doc2.txt");

//     std::cout << "document saved" << std::endl;

//     size_t i = app.Documents().Size();
//     std::cout << i << std::endl;

//     cs::base::CSString str;
//     str += u8"hoge";
//     str += u8"fuga";
//     std::cout << str << std::endl;

//     cs::base::CSVec3d v3d;
//     cs::base::CSVec3d v3d2(1, 2, 3);
//     cs::base::CSVec3d v3d3(1, 2, 3);
//     v3d += v3d2;
//     v3d += v3d3;
//     std::cout << v3d.x << std::endl;
//     std::cout << v3d.y << std::endl;
//     std::cout << v3d.z << std::endl;

//     auto& modeler = doc.Modeler();
//     auto& box = modeler.CreateBox({ 0,0,0 }, { 1,1,1 });
//     auto mat = CS_NEW cs::render::BasicMaterial({ 1.0, 0.0, 0.0 });

//     bool stop = false;
//     while (stop)
//     {
//         renderer->Render(*scene, *camera);
//         stop = true;
//     }

//     std::cout << str.c_str() << std::endl;
// }


static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
{
    {-0.6f, -0.4f, 1.f, 0.f, 0.f},
    {0.6f, -0.4f, 0.f, 1.f, 0.f},
    {0.f, 0.6f, 0.f, 0.f, 1.f} };

static const char* vertex_shader_text =
"#version 110\n"
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

static const char* fragment_shader_text =
"#version 110\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
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

int main(int argc, char** argv)
{
    std::locale::global(std::locale(
#if _WIN32 && !__MINGW32__ && !__CYGWIN__
        ".UTF-8"
#else
        ""
#endif
    ));

    auto csapp = std::make_unique<cs::app::CSApp>(argc, argv);
    auto& doc = dynamic_cast<cs::app::CSDocument2d&>(csapp->Documents().OpenNewDocument(typeid(cs::app::CSDocument2d).name()));

    auto scene = CS_NEW cs::render::Scene();
    auto camera = CS_NEW cs::render::PerspectiveCamera();
    auto renderer = CS_NEW cs::render::GLRenderer();

    // doc.Modeler2d

    // auto cube = CS_NEW cs::render::Mesh(box, *mat);
    // scene->Add(*cube);



    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glewInit();
    // gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    // NOTE: OpenGL error checks have been omitted for brevity

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    mvp_location = glGetUniformLocation(program, "MVP");
    vpos_location = glGetAttribLocation(program, "vPos");
    vcol_location = glGetAttribLocation(program, "vCol");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
        sizeof(vertices[0]), (void*)0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
        sizeof(vertices[0]), (void*)(sizeof(float) * 2));





    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        auto rot_angle = (float)glfwGetTime();
        auto m = glm::rotate(glm::mat4x4(1.0), rot_angle, { 0, 0, 1.0 });
        auto p = glm::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        auto mvp = (p * m);

        glUseProgram(program);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)glm::value_ptr(mvp));
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}
