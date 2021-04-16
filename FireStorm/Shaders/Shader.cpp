#include "Shader.hpp"

Shader::Shader() {
    id = 0;
}

std::stringstream file2string(const std::string& filepath) {
    std::ifstream stream(filepath);
    std::string line;
    std::stringstream s;

    while (getline(stream, line)) {
        s << line << '\n';
    }
    return s;
}

unsigned int CompileShader(unsigned int type, std::string source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "fragment ") << "shader!\n";
    }

    return id;
}

void Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader) {
    std::stringstream s1 = file2string(vertexShader);
    std::stringstream s2 = file2string(fragmentShader);

    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, s1.str());
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, s2.str());

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    //return program;

    id = program;

}

void getCursorPos(GLFWwindow* window, double x, double y)
{
    glfwGetCursorPos(window, &x, &y);
}

void Shader::uniform2f_mouse_pos(GLFWwindow* window, const char* field)
{
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    glUniform2f(glGetUniformLocation(id, field), (float)(x / 320.0f - 1.0f), (float)(1.0f - y / 240.0f));
}

void Shader::uniform1i(const char* field, int value)
{
    glUniform1i(glGetUniformLocation(id, field), value);
}

void Shader::bind() const {
	glUseProgram(id);
}

void Shader::unbind() const {
	glDeleteProgram(id);
}
