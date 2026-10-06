#include "../header/preprocessor.h"

#define INSTRUCTION_SET_SIZE 8

const char characters[INSTRUCTION_SET_SIZE] = {'+', '-', '<', '>', '.', ',', '[', ']'};

bool is_instruction(const char character) {

    bool flag = false;

    for (const char instruction : characters) {
        if (character == instruction) {
            flag = true;
            break;
        }
    }

    return flag;
}


void process(const char raw[], char src[]) {
    int ptr_raw = 0;
    int ptr_src = 0;

    while (raw[ptr_raw] != '\0') {

        if (is_instruction(raw[ptr_raw])) {
            src[ptr_src] = raw[ptr_raw];
            ptr_src++;
        }

        ptr_raw++;

    }

    src[ptr_src] = '\0';
}
