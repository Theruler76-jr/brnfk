#pragma once

#include "header.h"


void dump_status(Machine* machine);

void throw_interpreter(int exit_code, const char src[], Machine *machine);
void throw_preprocessor(int exit_code, const char src[], int ptr);
