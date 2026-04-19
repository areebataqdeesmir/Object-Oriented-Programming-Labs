#include <iostream>
using namespace std;

class File {
public:
    File() {
        cout << "File opened\n";
    }

    ~File() {
        cout << "File closed\n";
    }
};

class TextFile : public File {
public:
    TextFile() {
        cout << "Text File opened\n";
    }

    ~TextFile() {
        cout << "Text File closed\n";
    }
};

int main() {
    TextFile t1;
}
