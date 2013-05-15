#include <fstream>
#include <iostream>

// Count number of lines in file. Unfortunately std::ifstream takes const char* as
// filename-argument, so we're gonna do the same.
int countLinesInFile(const char* fileName) {
    std::ifstream file(fileName);
    std::string line;
    int lineCount = 0;
    while (getline(file, line)) {
        ++lineCount;
    }
    return lineCount;
}

int main() {
    std::cout << countLinesInFile(__FILE__) << std::endl;
}

