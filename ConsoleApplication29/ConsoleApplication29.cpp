#include <iostream>
#include <fstream>
#include <string>
class FileManager {
public:
    std::string readFile(std::string path) {
        std::ifstream file(path);
        std::string data, line;
        while (getline(file, line)) {
            data += line + "\\\\n";
        }
        return data;
    }

    void writeFile(std::string path, std::string data) {
        std::ofstream file(path);
        file << data;
    }

    void deleteFile(std::string path) {
        remove(path.c_str());
    }
};

class DataProcessor {
public:
    std::string processData(std::string data) {
        // Код обработки данных
        return data;
    }
};

int main() {
    FileManager fm;
    DataProcessor dp;
    std::string data = "Hello, world!";
    fm.writeFile("test.txt", data);
    std::string fileData = fm.readFile("test.txt");
    std::string processedData = dp.processData(fileData);
    fm.writeFile("test.txt", processedData);
    std::cout << fm.readFile("test.txt") << std::endl;
    fm.deleteFile("test.txt");
    return 0;
}
