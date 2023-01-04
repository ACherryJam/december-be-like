#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


int main()
{
    std::ifstream input_file("input.txt");

    int priorities = 0;

    std::string first, second, third;
    while (std::getline(input_file, first)  &&
           std::getline(input_file, second) &&
           std::getline(input_file, third)) 
    {
        std::map<char, int> first_frequency {};
        for (char c : first)
            first_frequency[c]++;
        
        std::map<char, int> second_frequency {};
        for (char c : second)
            second_frequency[c]++;

        char common;
        for (char c : third)
            if (first_frequency[c] && second_frequency[c]) {
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