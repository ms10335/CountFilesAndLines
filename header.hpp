#pragma once

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>

namespace fs = std::filesystem;

class DirStatistic {
public:
    void fileSystem(const fs::path& pathToScan_);
    void countLinesinFile(const std::string&);
    unsigned int countWords(const std::string&);
    unsigned int getAllChars(const std::string&);
    void countChars(const std::string&);
    void printStatistic();

private:
    int num_of_directories = 1;
    int num_of_files = 0;
    int num_of_not_empty_lines = 0;
    int num_of_empty_lines = 0;
    int num_of_words = 0;
    int num_of_chars = 0;
    int num_of_spaces = 0;
    int num_of_all_chars = 0;
};
