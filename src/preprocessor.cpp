#include "../header/preprocessor.h"

#include "../header/header.h"
#include "../header/error_handling.h"

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
    int raw_ptr = 0;
    int src_ptr = 0;

    int stack[MEMORY_SIZE] = {};
    int nesting = -1;

    while (raw[raw_ptr] != '\0') {

        if (raw[raw_ptr] == '[') {

            nesting++;
            stack[nesting] = src_ptr;

        } else if (raw[raw_ptr] == ']') {
            if (nesting == -1) {
                throw_preprocessor(UNMATCHED_BRACKET, src, raw_ptr);
            }

            jump_table[src_ptr] = stack[nesting] - 1;
            jump_table[stack[nesting]] = src_ptr;
            nesting--;

        }

        if (is_instruction(raw[raw_ptr])) {
            src[src_ptr] = raw[raw_ptr];
            src_ptr++;
        }

        raw_ptr++;

    }

    if (nesting > -1) {
        throw_preprocessor(UNMATCHED_BRACKET, src, raw_ptr);
    }

    src[src_ptr] = '\0';
}
