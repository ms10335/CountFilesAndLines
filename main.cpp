#include "header.hpp"

struct Timer {
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Time took: " << ms << "ms" << '\n';
    }
};

int main() {
    // const fs::path pathToShow{fs::current_path() };

    namespace fs = std::filesystem;
    Timer timer;
    DirStatistic dst;
    const fs::path p1("/home/marcins/Programowanie/CodersSchool/ZadaniaRekrutacja/Test");
    dst.fileSystem(p1);
    dst.printStatistic();
    return 0;
}