#include "../header/preprocessor.h"

#include <iostream>

#include "../header/header.h"

#define INSTRUCTION_SET_SIZE 8

constexpr char instruction_set[INSTRUCTION_SET_SIZE] = {'+', '-', '<', '>', '.', ',', '[', ']'};

bool is_instruction(const char character) {

    bool flag = false;

    for (const char instruction : instruction_set) {
        if (character == instruction) {
            flag = true;
            break;
        }
    }

    return flag;
}


void process(const char raw[], char src[], int jump_table[]) {
    int ptr_raw = 0;
    int ptr_src = 0;

    int stack[MEMORY_SIZE] = {};
    int nesting = -1;

    while (raw[ptr_raw] != '\0') {

        if (raw[ptr_raw] == '[') {

            nesting++;
            stack[nesting] = ptr_src;

        } else if (raw[ptr_raw] == ']') {
            if (nesting == -1) {
                std::cout << "Unmatched bracket at location " << ptr_raw << "\n";
                getchar();
                exit(UNMATCHED_BRACKET);
            }

            jump_table[ptr_src] = stack[nesting] - 1;
            jump_table[stack[nesting]] = ptr_src;
            nesting--;

        }

        if (is_instruction(raw[ptr_raw])) {
            src[ptr_src] = raw[ptr_raw];
            ptr_src++;
        }

        ptr_raw++;

    }

    if (nesting > -1) {
        std::cout << "Unmatched bracket at end of file" << "\n";
        getchar();
        exit(UNMATCHED_BRACKET);
    }

    src[ptr_src] = '\0';
}
