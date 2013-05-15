## How Do I Count the Number of Lines in a File?

You can do this reading the file line by line, and counting the number of lines. 
std::getline(std::iostream&, std::string&) tries to read a single line from an 
iostream. Returns true on success, false on error.

```c++
int countLinesInFile(const char* fileName) {
    std::ifstream file(fileName);
    std::string line;
    int lineCount = 0;
    while (getline(file, line)) {
        ++lineCount;
    }
    return lineCount;
}

