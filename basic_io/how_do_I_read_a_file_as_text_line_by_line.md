## How Do I Read a File as Text Line by Line?

Open it using ifstream and read it line by line in a while loop with getline.

The following example program opens it's source file, and prints it with prefixed line numbers.



```c++
#include <fstream>
#include <iostream>

void readFileLineByLine(const char* fileName) {
    std::ifstream file(fileName);
    std::string line;
    int lineCount = 0;
    while (getline(file, line)) {
        // Do something with a single line here
        std::cout << "Line " << lineCount << ": " << line << std::endl;
        ++lineCount;
    }
}

int main() {
    readFileLineByLine(__FILE__);
}
