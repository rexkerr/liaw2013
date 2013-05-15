#include <fstream>
#include <iostream>

int main() {
    std::ifstream file(__FILE__);
    std::string str;
    int lineCount = 0;
    while (getline(file, str)) {
        ++lineCount;
    }
    std::cout << lineCount << "\n";
}

