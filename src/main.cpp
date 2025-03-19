#include "LAN_printer/Macro.h"
#include "LAN_printer/printer.h"

#include <cstdio>
#include "CLI11/CLI11.hpp"

int main(int argc, char** argv) {
    using namespace LANPrinter;

    CLI::App app{"LAN-Printer"};
    argv = app.ensure_utf8(argv);

    std::string search_path;
    app.add_option("search_path", search_path)->check(CLI::ExistingFile)->required();

    double sleep_time;
    app.add_flag("-t", sleep_time, "Search interval time");

    CLI11_PARSE(app, argc, argv);

    /** main loop **/

    Printer P;
    P.set_search_path(search_path);
    P.set_sleep_time(sleep_time);

    P.main_loop();
}
