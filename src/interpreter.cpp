#include "../header/interpreter.h"

#include <iostream>
#include <conio.h>

#include "../header/header.h"
#include "../header/error_handling.h"


void interpret(const char code[], Machine *machine, const int jump_table[]) {

    while (code[machine->instr_ptr] != '\0') {

        switch (code[machine->instr_ptr]) {

        case '+':
            machine->memory[machine->data_ptr]++;
            break;
        case '-':
            machine->memory[machine->data_ptr]--;
            break;

        case '<':
            if (machine->data_ptr == 0) {
                throw_interpreter(MEMORY_OUT_OF_BOUNDS, code, machine);
                return;
            }
            machine->data_ptr--;
            break;
        case '>':
            if (machine->data_ptr >= MEMORY_SIZE - 1) {
                throw_interpreter(MEMORY_OUT_OF_BOUNDS, code, machine);
                return;
            }
            machine->data_ptr++;
            break;

        case '.':
            std::cout << machine->memory[machine->data_ptr];
            break;
        case ',':
            machine->memory[machine->data_ptr] = getch();
            break;

        case '[':
            if (machine->memory[machine->data_ptr] == 0) {
                machine->instr_ptr = jump_table[machine->instr_ptr];
            }
            break;
        case ']':
            if (machine->memory[machine->data_ptr] != 0) {
                machine->instr_ptr = jump_table[machine->instr_ptr];
            }
            break;

        default:
            throw_interpreter(UNKNOWN_INSTRUCTION, code, machine);
            return;

        }

        machine->instr_ptr++;
    }
}
