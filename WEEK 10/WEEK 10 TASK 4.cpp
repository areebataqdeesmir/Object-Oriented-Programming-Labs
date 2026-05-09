#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ofstream writeFile("students.txt");
    writeFile << "Ali - 101" << endl;
    writeFile << "Sana - 102" << endl;
    writeFile << "Ahmed - 103" << endl;
    writeFile.close();
    ifstream readFile("students.txt");
    string line;
    cout << "Student Details:\n";
    while(getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();
    return 0;
}
