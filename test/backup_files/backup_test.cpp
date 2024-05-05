#include "fs_tool.h"
#include <iostream>

using namespace breeze::fs_tool;
namespace fs = std::filesystem;

const fs::path base_dir = "/home/breeze/exercise/fs_tool";

int main()
{
    fs::path source_path = base_dir / "test/backup_files";
    fs::path dest_path1 = base_dir / "test_backup";
    fs::path dest_path2 = base_dir / "test_recursive_backup";

    FsTool::backup_files(source_path, dest_path1);
    FsTool::recursive_backup_files(source_path, dest_path2);

    return 0;
}