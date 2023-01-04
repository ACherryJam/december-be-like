#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

int main()
{
    std::ifstream input_file("input.txt");

    std::vector<int> calories { 0 };
    
    int i = 0;
    std::string line;
    while ( std::getline(input_file, line) ) {
        if ( line.empty() ) {
            i++;
            calories.push_back(0);
        }
        else
            calories[i] += std::stoi(line);
    }

    std::sort(calories.begin(), calories.end());
    
    std::cout << calories[i] + calories[i-1] + calories[i-2];

    return 0;
}