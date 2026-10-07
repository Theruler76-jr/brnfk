#pragma once

#include "header.h"


void throw_interpreter(int exit_code, const char src[], Machine *machine);
void throw_preprocessor(int exit_code, const char src[], int ptr);
