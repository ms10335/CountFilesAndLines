#include "header.hpp"

void DirStatistic::fileSystem(const fs::path& pathToScan_) {
    for (const auto& entry : fs::directory_iterator(pathToScan_)) {
        if (entry.is_directory()) {
            ++num_of_directories;
            fileSystem(entry);
        } else if (entry.is_regular_file()) {
            ++num_of_files;
            countLinesinFile(entry.path().string());
        } else {
            continue;
        }
    }
}

void DirStatistic::countLinesinFile(const std::string& pathFiles) {
    std::string line{};
    std::ifstream file(pathFiles);
    if (file.is_open()) {
        while (file.peek() != EOF) {
            getline(file, line);
            if (line.empty()) {
                ++num_of_empty_lines;
            } else {
                ++num_of_not_empty_lines;
                num_of_words += countWords(line);
                countChars(line);
            }
        }
    }
    file.close();
}

unsigned int DirStatistic::countWords(const std::string& strLine) {
    std::stringstream stream(strLine);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}
unsigned int DirStatistic::getAllChars(const std::string& strLine) {
    return strLine.size();
}
void DirStatistic::countChars(const std::string& strLine) {
    std::string tmp = strLine;
    for (auto& a : tmp) {
        if (a != ' ') {
            ++num_of_chars;
        } else {
            ++num_of_spaces;
        }
    }
    num_of_all_chars = num_of_chars + num_of_spaces;
}
void DirStatistic::printStatistic() {
    std::cout
        << std::left
        << std::setw(20)
        << "Nun of directories"
        << std::left
        << std::setw(15)
        << "Num of files"
        << std::left
        << std::setw(25)
        << "Num of Non Empty Lines"
        << std::left
        << std::setw(25)
        << "Num of Empty Lines"
        << std::left
        << std::setw(25)
        << "Num of Characters"
        << std::left
        << std::setw(15)
        << "Num of Spaces\n";

    std::cout << std::left
              << std::setw(20)
              << num_of_directories
              << std::left
              << std::setw(15)
              << num_of_files
              << std::left
              << std::setw(25)
              << num_of_not_empty_lines
              << std::setw(25)
              << num_of_empty_lines
              << std::left
              << std::setw(25)
              << num_of_chars
              << std::left
              << std::setw(15)
              << num_of_spaces
              << '\n';
}