#include <iostream>

#include "../header/header.h"
#include "../header/interpreter.h"
#include "../header/preprocessor.h"


int main() {

    //const char raw[MAX_FILESIZE] = ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.";
    const char raw[MAX_FILESIZE] = "+++++++++++++++++++++++++++++++++++++++++++++++++..,+.";
    char src[MAX_FILESIZE];

    unsigned char memory[256] = {};
    int ptr_data = 0;
    int ptr_instr = 0;

    process(raw, src);

    const int exit_code = interpret(src, memory, &ptr_data, &ptr_instr);
    std::cout << std::endl << std::endl;

    switch (exit_code) {

        case EXECUTION_SUCCESS:
            std::cout << "Success" << std::endl;
            break;

        case MEMORY_OUT_OF_BOUNDS:
            std::cout << "Attempted shift operation out of bounds at memory location " << ptr_data << std::endl;
            break;

        case UNMATCHED_PARENTHESIS:
            std::cout << "Unmatched parenthesis at instruction " << ptr_instr << std::endl;
            break;

        case UNKNOWN_INSTRUCTION:
            std::cout << "Unknown instruction " << src[ptr_instr] << std::endl;
            break;

        default:
            std::cout << "Unknown exit code " << exit_code << std::endl;

    }

    for (const int i : memory) {
        std::cout << i << ", ";
    }

    getchar();

    return 0;

}
