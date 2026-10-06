#include <iostream>

#include "../header/header.h"
#include "../header/interpreter.h"
#include "../header/preprocessor.h"


int main() {
    //const char raw[MAX_FILESIZE] = ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.";
    //const char raw[MAX_FILESIZE] = "+++++++++++++++++++++++++++++++++++++++++++++++++..,+.";
    //const char raw[MAX_FILESIZE] = "++>+++>-.>.--.<<+";
    //const char raw[MAX_FILESIZE] = "+[+]";
    const char raw[MAX_FILESIZE] = ",+.,+.";
    char src[MAX_FILESIZE] = {};

    Machine machine;

    process(raw, src);

    const int exit_code = interpret(src, &machine);

    std::cout << "\n\n";

    switch (exit_code) {

        case EXECUTION_SUCCESS:
            std::cout << "Execution success\n";
            break;

        case MEMORY_OUT_OF_BOUNDS:
            std::cout << "Attempted shift operation out of bounds at memory location " << machine.ptr_data << "\n";
            break;

        case UNMATCHED_BRACKET:
            std::cout << "Unmatched bracket at instruction " << machine.ptr_instr << "\n";
            break;

        case UNKNOWN_INSTRUCTION:
            std::cout << "Unknown instruction " << src[machine.ptr_instr] << "\n";
            break;

        default:
            std::cout << "Unknown exit code " << exit_code << "\n";

    }

    std::cout << "\n";
    std::cout << "Instruction pointer: " << machine.ptr_instr << "\n";
    std::cout << "Data pointer: " << machine.ptr_data << "\n";
    std::cout << "\n";

    std::cout << "Memory view:\n";

    for (const int i : machine.memory) {
        std::cout << i << " ";
    }

    getchar();

    return 0;
}
