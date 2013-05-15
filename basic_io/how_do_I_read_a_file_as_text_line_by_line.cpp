#include <fstream>
#include <iostream>

void readFileLineByLine(const char* fileName) {
    std::ifstream file(fileName);
    std::string line;
    int lineCount = 0;
    while (getline(file, line)) {
        std::cout << "Line " << lineCount << ": " << line << std::endl;
        ++lineCount;
    }
}

int main() {
    readFileLineByLine(__FILE__);
}

