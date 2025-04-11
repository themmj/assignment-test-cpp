#pragma once

#include "gtest/gtest.h"

// convenience TODO perhaps replace this with std::ignore
#define UNUSED(x) (void) x

int assignment_main(int argc, const char *argv[]);
/// Calls assignment_main. args are passed as argv and number of elements is passed as argc.
#define CALL_ASSIGNMENT_MAIN(args) \
    assignment_main(sizeof(args) / sizeof(*args), args)
