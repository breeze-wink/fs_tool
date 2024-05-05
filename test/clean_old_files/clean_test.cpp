#include "fs_tool.h"

using namespace breeze::fs_tool;

int main()
{
    FsTool::clean_old_files("/home/breeze/networkProject/epoll", 0, ".log");

    return 0;
}