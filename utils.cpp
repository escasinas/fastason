#include "utils.h"
#include <iostream>
#include <string>

// function definitions
bool contains(char c, std::string str) {
    for (char i : str) {
        if (i == c) {
            return 1;
        }
    }
    return 0;
}

void print_help() {
    std::cout << "Convert a fasta file to json.\n\n";
    std::cout << "Usage: fastason file.fasta\n\n";
    std::cout << "Positional arguments:\n\tinput_file\t\tFasta file.\n\n";
    std::cout << "Optional arguments:\n\t-h, --help\t\tShow this help message and exit.\n";
}

