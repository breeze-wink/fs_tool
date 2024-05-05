#include "fs_tool.h"
#include <chrono>
#include <iostream>
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
        auto relative_entry = fs::relative(entry, source);

        fs::path dest = backup_dir / relative_entry;

        fs::create_directories(dest.parent_path()); //用来确保目标父目录存在

        fs::copy(entry, dest, fs::copy_options::update_existing);

    }
}

void FsTool::clean_old_files(const fs::path& dir, const int day_before, std::unordered_set<std::string> extentions)
{
    auto now = fs::file_time_type::clock::now();
    for(const auto& entry : fs::directory_iterator(dir))
    {
        
        if (fs::is_regular_file(entry.status()))
        {
            auto ftime = fs::last_write_time(entry);
            if (now - ftime > std::chrono::hours(24 * day_before))
            {
                if (extentions.empty() || extentions.count(entry.path().extension().string()))
                {
                    fs::remove(entry);
                    std::cout << "Removing : " << entry.path() << std::endl;
                }
            }
        }
    }
}

void FsTool::clean_old_files(const fs::path& dir, const int day_before)
{
    clean_old_files(dir, day_before, std::unordered_set<std::string>());
}