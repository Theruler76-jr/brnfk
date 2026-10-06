#include "../header/interpreter.h"

#include <iostream>
#include <conio.h>

#include "../header/header.h"


int interpret(const char code[], Machine *machine) {

    int stack[256] = {};
    int ptr_stack = -1;

    while (code[machine->ptr_instr] != '\0') {

        switch (code[machine->ptr_instr]) {

        case '+':
            machine->memory[machine->ptr_data]++;
            break;
        case '-':
            machine->memory[machine->ptr_data]--;
            break;

        case '<':
            if (machine->ptr_data == 0) return MEMORY_OUT_OF_BOUNDS;
            machine->ptr_data--;
            break;
        case '>':
            if (machine->ptr_data == 255) return MEMORY_OUT_OF_BOUNDS;
            machine->ptr_data++;
            break;

        case '.':
            std::cout << machine->memory[machine->ptr_data];
            break;
        case ',':
            machine->memory[machine->ptr_data] = getch();
            break;

        case '[':
            ptr_stack++;
            stack[ptr_stack] = machine->ptr_instr;
            break;
        case ']':
            if (ptr_stack == -1) return UNMATCHED_BRACKET;

            if (machine->memory[machine->ptr_data] == 0) {
                ptr_stack--;
            } else {
                machine->ptr_instr = stack[ptr_stack];
            }

            break;

        default:
            return UNKNOWN_INSTRUCTION;

        }

        machine->ptr_instr++;

    }

    return EXECUTION_SUCCESS;
}
