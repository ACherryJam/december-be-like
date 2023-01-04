#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


int main()
{
    //           Lose Draw Win
    // Rock    | Sci  Rock Paper
    // Paper   | Rck  Papr Sci
    // Scicors | Ppr  Sci  Rock
    int outcomes[3][3] = {{3, 4, 8},
                          {1, 5, 9},
                          {2, 6, 7}};

    std::string results = "XYZ";
    std::string opponent_moves = "ABC";

    std::ifstream input_file("input.txt");

    int points = 0;
    char opponent, result;
    
    std::string line;
    while ( std::getline(input_file, line) && !line.empty() ) {
        std::stringstream line_stream { line };
        line_stream >> opponent >> result;

        int result_index = results.find(result);
        int opponent_move = opponent_moves.find(opponent);

        points += outcomes[opponent_move][result_index];
    }
    
    std::cout << points;

    return 0;
}