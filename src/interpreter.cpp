#include "../header/interpreter.h"

#include <iostream>
#include <conio.h>

#include "../header/header.h"
#include "../header/error_handling.h"


void interpret(const char code[], Machine *machine, const int jump_table[]) {

    while (code[machine->ptr_instr] != '\0') {

        switch (code[machine->ptr_instr]) {

        case '+':
            machine->memory[machine->ptr_data]++;
            break;
        case '-':
            machine->memory[machine->ptr_data]--;
            break;

        case '<':
            if (machine->ptr_data == 0) throw_interpreter(MEMORY_OUT_OF_BOUNDS, code, machine);
            machine->ptr_data--;
            break;
        case '>':
            if (machine->ptr_data == MEMORY_SIZE) throw_interpreter(MEMORY_OUT_OF_BOUNDS, code, machine);
            machine->ptr_data++;
            break;

        case '.':
            std::cout << machine->memory[machine->ptr_data];
            break;
        case ',':
            machine->memory[machine->ptr_data] = getch();
            break;

        case '[':
            if (machine->memory[machine->ptr_data] == 0) {
                machine->ptr_instr = jump_table[machine->ptr_instr];
            }
            break;
        case ']':
            machine->ptr_instr = jump_table[machine->ptr_instr];
            break;

        default:
            throw_interpreter(UNKNOWN_INSTRUCTION, code, machine);;

        }

        machine->ptr_instr++;

    }
}
