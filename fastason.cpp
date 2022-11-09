#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

// struct
struct fasta {
    int id;
    std::string header;
    std::string seq;
} f1;


// main
int main(int argc, char *argv[]) {
    
    // if no command line aguments, print the help text
    if (argc == 1) {
        print_help();
        return 0;
    } 
    
    // parse command line argument
    std::string input_file = argv[1];
    std::string output_file = input_file + ".json";

    // if the command line argument is -h or --help, print the help text
    if (input_file == "-h" || input_file == "--help") {
        print_help();
        return 0;
    } else if (input_file[0] == '-') {
        std::cout << "Unknown flag, try fastason -h\n";
        return 0;
    }

    // json indentations
    std::string indent4 = "\n    ";
    std::string indent8 = "\n        ";

    // open the input and output files
    std::ifstream inf(input_file);
    std::ofstream outf(output_file);

    outf << "[";
    
    int id = 1;
    std::string line;
    while (getline(inf, line)) {
        if (contains('>', line)) {
            // if f1.header and f1.seq are not empty
            if (f1.header != "" && f1.seq != "") {
                std::string str_id = std::to_string(f1.id);
                outf << indent4 + "{" + indent8 + "\"id\": " + str_id + "," + indent8 + "\"header\": \"" + f1.header + "\"," + indent8 + "\"seq\": \"" + f1.seq + "\"" + indent4 + "},";
                f1.header = "";
                f1.seq = "";
            }
            f1.id = id;
            f1.header = line;
            id++;
        } else {
            f1.seq += line;
        }
    }

    // process the last header and sequence
    std::string str_id = std::to_string(f1.id);
    outf << indent4 + "{" + indent8 + "\"id\": " + str_id + "," + indent8 + "\"header\": \"" + f1.header + "\"," + indent8 + "\"seq\": \"" + f1.seq + "\"" + indent4 + "}\n]";

    inf.close();
    outf.close();

    return 0;
}

