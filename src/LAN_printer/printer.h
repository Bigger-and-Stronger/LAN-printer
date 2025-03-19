//
// Created by Canjia Huang <canjia7@gmail.com> on 25-3-19.
//

#ifndef GET_PRINT_FILE_H
#define GET_PRINT_FILE_H

#include <unordered_set>
#include <string>

namespace LANPrinter{
    class Printer {
    public:
        Printer()= default;

        void set_search_path(const std::string& path) {search_path_ = path;}
        void set_sleep_time(const double time) {sleep_time_ = time;}

        int get_current_files(std::unordered_map<std::string, std::string>& current_files) const;
        int get_new_files(std::unordered_map<std::string, std::string>& new_files);

        int initialize();
        void main_loop();
    private:
        std::string search_path_;
        double sleep_time_ = 5; // sec
        std::unordered_map<std::string, std::string> last_files_;
    };
}

#endif //GET_PRINT_FILE_H
