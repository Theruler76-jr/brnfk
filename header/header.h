#pragma once

#define MAX_FILESIZE 2048

enum exit_codes {
    EXECUTION_SUCCESS,
    MEMORY_OUT_OF_BOUNDS,
    UNKNOWN_INSTRUCTION,
    UNMATCHED_BRACKET,
};


struct Machine {
    unsigned char memory[256] = {};
    int ptr_data = 0;
    int ptr_instr = 0;
};
