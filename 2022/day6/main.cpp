#include <set>
#include <string>
#include <fstream>
#include <iostream>


int find_marker(std::string &data, size_t marker_size) {
    for (int i = 0; i < data.length() - marker_size; i++) {
        std::string marker = data.substr(i, marker_size);

        if (std::set<char>(marker.begin(), marker.end()).size() == marker_size) {
            return i + marker_size;
        }
    }
    return -1;
}


int main()
{
    std::ifstream input_file("input.txt");

    std::string data;
    std::getline(input_file, data);

    input_file.close();

    std::cout << "First position of marker of size 4: " << find_marker(data, 4) << '\n';
    std::cout << "First position of marker of size 14: " << find_marker(data, 14);

    return 0;
}