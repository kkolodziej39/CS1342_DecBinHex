//
// Created by Kyle on 6/14/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Runner.h"
using namespace std;
int main(int argc, char * argv[]) {
    if(argc != 2)
    {
        cout << "Error! Incorrect number of parameters given" << endl;
        return 0;
    }

    ifstream inputFile;
    inputFile.open(argv[1]);
    vector<string> lines;
    string line;
    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }
    inputFile.close();
    Runner run(lines);


    return 0;
}
