#include "fs_tool.h"
#include <iostream>

using namespace breeze::fs_tool;

int main()
{
    fs::path dir_path = ".";
    
    auto dir_size = FsTool::calculate_directory_size(dir_path, true);

    std::cout << dir_size << std::endl;

    return 0;
}