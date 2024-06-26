#pragma once
#include <cstdint>
#include <filesystem>
#include <unordered_set>
namespace fs = std::filesystem;

namespace breeze::fs_tool
{
    class FsTool
    {
    public:
        static void backup_files(const fs::path& source, const fs::path& backup_dir); // 备份目录下的普通文件

        static void recursive_backup_files(const fs::path& source, const fs::path& backup_dir); // 递归备份完整目录

        static void clean_old_files(const fs::path& dir, const int day_before, std::unordered_set<std::string> extentions); //删除旧文件
        static void clean_old_files(const fs::path& dir, const int day_before);

        static std::uintmax_t calculate_directory_size(const fs::path& dir, bool include_subdirs = true);
    };  
    

}

