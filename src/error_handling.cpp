#include "../header/error_handling.h"

#include <iostream>


void dump_status(Machine* machine) {
    std::cout << "\n\n\n";
    std::cout << "DEBUG INFORMATION:\n\n";
    std::cout << "Instruction pointer: " << machine->instr_ptr << "\n";
    std::cout << "Data pointer: " << machine->data_ptr << "\n";
    std::cout << "\n";

    std::cout << "Memory view:\n";

    for (const int i : machine->memory) {
        std::cout << i << " ";
    }
}


void throw_interpreter(const int exit_code, const char src[], Machine *machine) {

    std::cout << "ERROR: Runtime exception:\n";

    switch (exit_code) {

    case EXECUTION_SUCCESS:
        std::cout << "Execution success\n";
        break;

    case MEMORY_OUT_OF_BOUNDS:
        std::cout << "Attempted shift operation out of bounds at memory location " << machine->data_ptr << "\n";
        break;

    case UNKNOWN_INSTRUCTION:
        std::cout << "Unknown instruction " << src[machine->instr_ptr] << "\n";
        break;

    default:
        std::cout << "Unknown exit code " << exit_code << "\n";

    }
}


void throw_preprocessor(const int exit_code, const char src[], int ptr) {

    std::cout << "ERROR: Preprocessor exception:\n";

    switch (exit_code) {

    case EXECUTION_SUCCESS:
        std::cout << "Execution success\n";
        break;

    case UNMATCHED_BRACKET:
        std::cout << "Unmatched bracket at location " << ptr << "\n";
        break;

    default:
        std::cout << "Unknown exit code " << exit_code << "\n";

    }
}
