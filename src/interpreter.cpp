#include "../header/interpreter.h"

#include <iostream>
#include <conio.h>

#include "../header/header.h"

int interpret(const char code[], unsigned char memory[], int *ptr_data, int *ptr_instr) {

    int stack[256] = {};
    int ptr_stack = -1;

    while (code[*ptr_instr] != '\0') {

        switch (code[*ptr_instr]) {

        case '+':
            memory[*ptr_data]++;
            break;
        case '-':
            memory[*ptr_data]--;
            break;

        case '<':
            if (*ptr_data == 0) return MEMORY_OUT_OF_BOUNDS;
            (*ptr_data)--;
            break;
        case '>':
            if (*ptr_data == 255) return MEMORY_OUT_OF_BOUNDS;
            (*ptr_data)++;
            break;

        case '.':
            std::cout << memory[*ptr_data];
            break;
        case ',':
            memory[*ptr_data] = getch();
            break;

        case '[':
            ptr_stack++;
            stack[ptr_stack] = *ptr_instr;
            break;
        case ']':
            if (ptr_stack == -1) return UNMATCHED_PARENTHESIS;

            if (memory[*ptr_data] == 0) {
                ptr_stack--;
            } else {
                *ptr_instr = stack[ptr_stack];
            }

            break;

        default:
            return UNKNOWN_INSTRUCTION;

        }

        (*ptr_instr)++;

    }

    return EXECUTION_SUCCESS;

}