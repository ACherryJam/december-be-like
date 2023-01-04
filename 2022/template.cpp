#include <string>
#include <fstream>
#include <iostream>


int main()
{
    std::ifstream input_file("input.txt");

    std::string line;
    while ( std::getline(input_file, line) ) {
        /* vine boom */
    }

    return 0;
}