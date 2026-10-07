#pragma once

#define MAX_FILESIZE 2048
#define MEMORY_SIZE 1024 //4096 //16384


enum exit_codes {
    EXECUTION_SUCCESS,
    MEMORY_OUT_OF_BOUNDS,
    UNKNOWN_INSTRUCTION,
    UNMATCHED_BRACKET,
};


struct Machine {
    unsigned char memory[MEMORY_SIZE] = {};
    int ptr_data = 0;
    int ptr_instr = 0;
};
