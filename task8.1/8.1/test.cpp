#include <iostream>
#include <string>

class Exception {
public:
    Exception(std::string message, std::string file, int line) : message(message), file(file), line(line) {}
    std::string what() const {
        return message + " in file " + file + " at line " + std::to_string(line);
    }
private:
    std::string message;
    std::string file;
    int line;
};

int main() {
    int x = -1;
    try {
        if (x < 0) {
            throw Exception("x must be non-negative", __FILE__, __LINE__);
        }
    } catch (Exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}