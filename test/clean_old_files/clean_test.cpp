#include "fs_tool.h"

using namespace breeze::fs_tool;

int main()
{
    std::unordered_set<std::string> extentions{".log", ".txt", ".c", ".cache"};

    FsTool::clean_old_files(".", 10, extentions);
    
    return 0;
}