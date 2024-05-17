#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

std::string ReadShaderFromFile(std::string Path);
std::string GetImagePath(std::string name);
std::string GetShaderPath(std::string shaderName);