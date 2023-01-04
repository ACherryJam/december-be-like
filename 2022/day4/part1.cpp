#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


int main()
{
    std::ifstream input_file("input.txt");

    int answer = 0;

    std::string line;
    while ( std::getline(input_file, line) ) {
        std::stringstream stream(line);

        char c;
        int a, b, x, y;
        stream >> a >> c >> b >> c >> x >> c >> y;

        if ( (a <= x && b >= y) || (x <= a && y >= b) )
            answer++;
    }

    std::cout << answer;

    return 0;
}