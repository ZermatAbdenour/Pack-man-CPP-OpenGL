#include "Util.h"

std::string ReadShaderFromFile(std::string Path) {
     std::string fileContent;

     std::ifstream file;
     file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
     try
     {
         // open files
         file.open(Path);
         std::stringstream stream;
         // read file's buffer contents into streams
         stream << file.rdbuf();
         // close file handlers
         file.close();
         // convert stream into string
         fileContent = stream.str();
     }
     catch (std::ifstream::failure e)
     {
         std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
     }
     return fileContent;
}

std::string GetImagePath(std::string name) {
    return (fs::current_path() / fs::path("Resources/" + name)).string();
}

std::string GetShaderPath(std::string shaderName) {
    return (fs::current_path() / fs::path("src/Renderer/Shaders/" + shaderName)).string();
}