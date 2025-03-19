//
// Created by Canjia Huang <canjia7@gmail.com> on 25-3-19.
//

#include "LAN_printer/Macro.h"
#include "LAN_printer/printer.h"
#include <filesystem>

namespace LANPrinter{
    int Printer::get_current_files(
        std::unordered_map<std::string, std::string>& current_files
    ) const {
        INFO("get all files in " + search_path_);

        using std::filesystem::directory_iterator;
        using std::filesystem::recursive_directory_iterator;

        for (const auto& v : directory_iterator(search_path_)) {
            if (std::filesystem::is_regular_file(v.path())) {
                std::string filename = v.path().filename().string();
                std::string extension_name = v.path().extension().string();
                current_files[filename] = extension_name;
            }
            else {
                // may be a folder, do nothing
            }
        }

        return 0;
    }

    int Printer::get_new_files(
        std::unordered_map<std::string, std::string>& new_files
        ) {
        std::unordered_map<std::string, std::string> current_files;
        if (get_current_files(current_files)) {
            return 1;
        }

        int new_files_cnt = 0;
        for (const auto& v : current_files) {
            if (last_files_.find(v.first) == last_files_.end()) { // this file is new
                new_files[v.first] = v.second;
                ++new_files_cnt;
            }
        }

        if (!new_files.empty()) {
            INFO("get " + std::to_string(new_files_cnt) + " new files");
        }

        /** update last file list **/
        last_files_ = current_files;

        return 0;
    }
}