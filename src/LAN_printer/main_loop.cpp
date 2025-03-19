//
// Created by Canjia Huang <canjia7@gmail.com> on 25-3-19.
//

#include "LAN_printer/Macro.h"
#include "LAN_printer/printer.h"
#include <iostream>

namespace LANPrinter {
    int Printer::initialize(
        ) {
        if (search_path_.empty()) {
            WARN("No search path provided");
            return 1;
        }

        if (get_current_files(last_files_)) {
            WARN("Get init file error");
            return 2;
        }

        return 0;
    }

    void Printer::main_loop(
        ) {
        if (initialize()) {
            return;
        }

        while (true) {
            std::unordered_map<std::string, std::string> new_files;
            get_new_files(new_files);

            for (const auto& v : new_files) {
                // TODO print!
            }

            sleep(static_cast<int>(sleep_time_ * 1000));
        }
    }
}