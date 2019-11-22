#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>

std::ofstream fout;
#define MAX 2001
#define WORK_LIMIT 5

#include "minHeap.hpp"
#include "RBTree.hpp"
#include "minHeap.cpp"
#include "RBTree.cpp"
#include "city.hpp"
#include "city.cpp"

/*!
* Driver program
*/
int main(int argc, char *argv[]) {
    City city;
    std::ifstream file;
    if (argc < 2) {
        std::cerr << "Invalid argument count" << '\n';
        std::cout << "Usage: ./risingCity filename.txt" << '\n';
//        exit(1);
        file.open("input.txt");
    } else {
        file.open(argv[1]);
    }
    fout.open("output_file.txt");
    std::string line;
    while (getline(file, line, '\n')) {
        // Tokenize the given string
        std::vector<std::string> tokens = parse_line(line);
        city.updateGlobalTimer(stoi(tokens[0]));
        if (tokens[1] == "Insert") city.insert(stoi(tokens[2]), 0,  stoi(tokens[3]));
        else if (tokens[1] == "PrintBuilding") {
            if (tokens.size() == 3) {
                city.printBuilding(stoi(tokens[2]));
            } else {
                city.printBuilding(stoi(tokens[2]), stoi(tokens[3]));
            }
        }
    }

    // File has been parsed, process all the building in the heap and print their completion time
    while (city.hasBuildingToWorkOn()) {
        city.updateGlobalTimer(city.getGlobalTime() + 100);
    }
    fout.close();
    file.close();
    return 0;
}
