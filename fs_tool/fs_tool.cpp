#include "fs_tool.h"
#include <filesystem>

using namespace breeze::fs_tool;

void FsTool::backup_files(const fs::path& source, const fs::path& backup_dir)
{
    fs::create_directories(backup_dir); //如果没有就创建
     
    for (const auto& entry : fs::directory_iterator(source))
        {
            fs::path dest = backup_dir / entry.path().filename();
            if (fs::is_regular_file(entry.status()))
            {
                fs::copy(entry, dest, fs::copy_options::update_existing);
            }
        }
}

void FsTool::recursive_backup_files(const fs::path& source, const fs::path& backup_dir)
{
    fs::create_directory(backup_dir);
    
    for (const auto& entry : fs::recursive_directory_iterator(source))
    {
        //构建相对路径
        auto relative_path = fs::relative(entry, source);

        fs::path dest = backup_dir / relative_path;

        fs::create_directories(dest.parent_path()); //用来确保目标父目录存在

        fs::copy(entry, dest, fs::copy_options::update_existing);

    }
}