#include <fstream>
#include <iostream>

#include "../header/error_handling.h"
#include "../header/header.h"
#include "../header/interpreter.h"
#include "../header/preprocessor.h"


using std::cout;

int main(const int argc, const char **argv) {
    char raw[MAX_FILESIZE] = {};
    char src[MAX_FILESIZE] = {};
    int jump_table[MEMORY_SIZE] = {};

    bool should_interpret = false;
    bool should_compile = false;

    bool show_debug = false;
    bool show_jump_table = false;

    if (argc == 1) {
        cout << "\n";
        cout << "Usage: " << "brnfk <file> [OPTIONS]\n";
        cout << "brnfk -h for help\n";
        exit(0);
    }

    for (int i = 1; i < argc; i++) {

        if (argv[i][0] == '-') {

            switch (argv[i][1]) {

                case 'h':
                    cout << "\n";
                    cout << "Usage: " << "brnfk <file> [OPTIONS]\n\n";
                    cout << "\t-h\tShow this message\n";
                    cout << "\n";
                    cout << "\t-i\tInterpret brainfuck sourcefile (Default behaviour)\n";
                    cout << "\t-c\tCompile brainfuck sourcefile to C\n";
                    cout << "\n";
                    cout << "\t-d\tShow debug information\n";
                    cout << "\t-j\tShow jump table\n";
                    break;

                case 'i':
                    should_interpret = true;
                    break;

                case 'c':
                    should_compile = true;
                    break;

                case 'd':
                    show_debug = true;
                    break;

                case 'j':
                    show_jump_table = true;
                    break;

                default:
                    cout << "Unknown option: " << argv[i] << "\n";

            }

        } else {

            std::ifstream file(argv[i]);

            if (!file.is_open()) {
                cout << "\n";
                cout << "Unable to open file: " << argv[i] << "\n";
                exit(1);
            }

            file.read(raw, MAX_FILESIZE);
            raw[file.gcount()] = '\0';

        }

    }


    Machine machine;

    process(raw, src, jump_table);

    if (should_compile) {
        cout << "Compiling...\n"; // TODO
        cout << "Done\n";
    }

    if (should_interpret or !should_compile) {

        interpret(src, &machine, jump_table);

        if (show_debug) {
            dump_status(&machine);
        }

        if (show_jump_table) {

            cout << "\n\n";
            cout << "Jump table:\n";

            for (int i: jump_table) {
                cout << i << " ";
            }

        }

    }

    return 0;
}
