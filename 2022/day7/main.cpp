#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>


std::vector<std::string> split(std::string string, std::string delim) {
    std::vector<std::string> segments {};

    int start = 0;
    int end = string.find(delim);

    while ( end != std::string::npos ) {
        segments.push_back(string.substr(start, end-start));

        start = end + delim.length();
        end = string.find(delim, start);
    }
    segments.push_back(string.substr(start));
    
    return segments;
}


struct Directory {
    static Directory *top;

    size_t size = 0;
    std::string name;
    Directory *parent = NULL;

    std::map<std::string, Directory*> subdirectories {};

    Directory(std::string _name)
        : name(_name) {}
    Directory(std::string _name, Directory *_parent)
        : name(_name), parent(_parent) {}

    void add_file(std::string filename, size_t filesize) {
        size += filesize;
        if (this != Directory::top)
            parent->add_file(filename, filesize);
    }
};

Directory *Directory::top = nullptr;


int get_total_size(Directory *directory) {
    size_t size = 0;

    for (auto subdirectory : directory->subdirectories)
        size += get_total_size(subdirectory.second);

    if (directory->size <= 100000)
        size += directory->size;

    return size;
}

Directory *find_optimal_directory(Directory *directory, size_t target_size) {
    if (directory->size < target_size)
        return NULL;

    Directory *optimal_dir = directory;

    for (auto subdirectory : directory->subdirectories) {
        Directory *optimal_subdir = find_optimal_directory(subdirectory.second, target_size);

        if (optimal_subdir != NULL)
            if (optimal_subdir->size < optimal_dir->size)
                optimal_dir = optimal_subdir;
    }
    return optimal_dir;
}


int main()
{
    std::ifstream input_file("input.txt");

    Directory *directory = new Directory("/");
    Directory::top = directory;

    std::string line;
    while ( std::getline(input_file, line) ) {
        auto command = split(line, " ");
        
        if (command[0] == "$") {
            if (command[1] == "cd") {
                if (command[2] == "/")
                    directory = Directory::top;
                else if (command[2] == "..")
                    directory = directory->parent;
                else
                    directory = directory->subdirectories[command[2]];
            }
        }
        else if (command[0] == "dir") {
            std::string directory_name = command[1];
            directory->subdirectories[directory_name] = new Directory(directory_name, directory);
        } else {
            size_t filesize = std::stoi(command[0]);
            std::string filename = command[1];

            directory->add_file(filename, filesize);
        }
    }

    std::cout << "Part 1 answer: " << get_total_size(Directory::top) << '\n';

    size_t free_space = 70000000 - Directory::top->size;
    std::cout << "Part 2 answer: " << find_optimal_directory(Directory::top, 30000000 - free_space)->size;

    return 0;
}