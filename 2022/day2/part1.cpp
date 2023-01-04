#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


int main()
{
    int outcomes[3][3] = {{3, 0, 6},
                          {6, 3, 0},
                          {0, 6, 3}};

    std::string your_moves = "XYZ";
    std::string opponent_moves = "ABC";

    std::ifstream input_file("input.txt");

    int points = 0;
    char opponent, you;
    
    std::string line;
    while ( std::getline(input_file, line) && !line.empty() ) {
        std::stringstream line_stream { line };
        line_stream >> opponent >> you;

        int your_move = your_moves.find(you);
        int opponent_move = opponent_moves.find(opponent);

        points += outcomes[your_move][opponent_move] + your_move + 1;
    }
    
    std::cout << points;

    return 0;
}