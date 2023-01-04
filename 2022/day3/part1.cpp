#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


int main()
{
    std::ifstream input_file("input.txt");

    int priorities = 0;

    std::string line;
    while ( std::getline(input_file, line) ) {
        std::string first  = line.substr(0, line.length()/2);
        std::string second = line.substr(line.length()/2);

        std::map<char, int> frequency {};
        for (char c : first)
            frequency[c]++;
        
        char common;
        for (char c : second)
            if (frequency[c]) {
                common = c;
                break;
            }

        // Uppercase range: 65-90, lowercase range: 97-122
        if (islower(common))
            priorities += common - 96;
        else
            priorities += common - 64 + 26;
    }

    std::cout << priorities;

    return 0;
}