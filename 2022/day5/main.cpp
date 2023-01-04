#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


typedef char Crate;
typedef std::deque<Crate> Stack;
typedef std::vector<Stack> Ship;

struct Move {
    int from;
    int to;
    int amount;
};


struct CrateMover9000 {
    void move(Ship& ship, Move& move) {
        Stack *sTo   = &ship[move.to-1],
              *sFrom = &ship[move.from-1]; 

        for (int i = 0; i < move.amount; i++) {
            Crate crate = sFrom->front();
            sFrom->pop_front();
            sTo->push_front(crate);
        }
    }
};

struct CrateMover9001 {
    void move(Ship& ship, Move& move) {
        Stack *sTo   = &ship[move.to-1],
              *sFrom = &ship[move.from-1]; 

        sTo->insert(sTo->begin(), sFrom->begin(), std::next(sFrom->begin(), move.amount));
        sFrom->erase(sFrom->begin(), std::next(sFrom->begin(), move.amount));
    }
};


int main()
{
    std::ifstream input_file("input.txt");

    // Get stacks amount from the first line
    std::string line;
    std::getline(input_file, line);

    int n = line.length() / 4 + 1;
    Ship ship(n);

    // Add crates to stacks
    do {
        for (int i = 0; i < n; i++) {
            char crate = line[4*i+1];

            if (isalpha(crate)) {
                ship[i].push_back(crate);
            }
        }
    } while ( std::getline(input_file, line) && line.find('[') != std::string::npos );
    std::getline(input_file, line);


    std::vector<Move> moves {};

    std::string sep;
    int amount, from, to;
    while ( std::getline(input_file, line) ) {
        std::stringstream line_stream(line);
        line_stream >> sep >> amount >> sep >> from >> sep >> to;
        
        Move move { from, to, amount };
        moves.push_back(move);
    }

    Ship ship_2(ship);  // Clone the ship because we can
    CrateMover9000 crate_mover_9000 {};  // Woah, you bought CrateMover 9000.
    CrateMover9001 crate_mover_9001 {};  // Wait, why would you need two crate movers?!

    for (Move move : moves) {
        crate_mover_9000.move(ship, move);
        crate_mover_9001.move(ship_2, move);
    }

    // Output 'em crates
    std::cout << "Crates after CrateMover 9000: ";
    for (Stack s : ship)
        std::cout << s.front();
    
    std::cout << "\nCrates after CrateMover 9001: ";
    for (Stack s : ship_2)
        std::cout << s.front();


    return 0;
}