## How Do I Count the Number of Lines in a File?

You can do this reading the file line by line, and counting the number of lines. 
std::getline(std::iostream&, std::string&) tries to read a single line from an iostream. Returns true on success, false on error.


```c++
// Open file "input.txt" as input stream
std::ifstream file("input.txt");
std::string str;
int lineCount = 0;
while (getline(file, str)) {
    ++lineCount;
}
std::cout << lineCount << "\n";

