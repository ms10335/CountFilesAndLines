#include <filesystem>
#include <iomanip>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

void countLinesinFile(const std::string& pathFiles) {
    int numLines = 0;
    int emptyLines = 0;
    std::string line{};
    std::ifstream file(pathFiles);
    if(file.is_open()) {
        while (file.peek() != EOF) {
            getline(file, line);
            if (line.empty()) {
                ++emptyLines;
            }
            ++numLines;
        }
    }
    std::cout << "Line numbers is : "<<numLines << ' ' <<" and empty lines is: "<< emptyLines << '\n';
    file.close();
}

void fileSystem(const fs::path& pathToScan, int level = 0) {
    for (const auto& entry : fs::directory_iterator(pathToScan)) {
        const auto filenameStr = entry.path().filename().string();
        if (entry.is_directory()) {
            std::cout << std::setw(level * 3) << ' ' << filenameStr << '\n';
            fileSystem(entry, level + 1);
        }else if (entry.is_regular_file()) {
            std::cout << std::setw(level * 3) << ' ' << filenameStr <<
            ", size " << entry.file_size() << " bytes" << " and Lines number is : ";
            countLinesinFile(entry.path().string());
            std::cout << '\n';
        }else {
            std::cout << std::setw(level * 3) << "" << " [?]" << filenameStr << '\n';
        }
    }
}


int main() {
    // const fs::path pathToShow{fs::current_path() };
    const fs::path p1("/home/marcins/Programowanie/C_Programing/CheckPESEL");
    fileSystem(p1);

    
    
    return 0;
}