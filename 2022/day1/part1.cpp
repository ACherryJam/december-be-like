#include <string>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream input_file("input.txt");

    int max_calories = 0;

    int calories = 0;
    std::string line;
    while ( std::getline(input_file, line) ) {
        if ( line.empty() ) {
            if ( calories > max_calories )
                max_calories = calories;
            calories = 0;
        } else {
            calories += std::stoi(line);
        }
    }

    if ( calories > max_calories )
        max_calories = calories;
    std::cout << max_calories;

    return 0;
}