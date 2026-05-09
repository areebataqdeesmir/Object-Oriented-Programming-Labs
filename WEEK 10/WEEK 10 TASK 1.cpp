#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ofstream writeFile("notes.txt");

    writeFile << "This is the first line." << endl;
    writeFile << "Welcome to file handling in C++." << endl;
    writeFile << "Files help store data permanently." << endl;

    writeFile.close();
    ifstream readFile("notes.txt");
    string line;
    cout << "File Contents:\n";
    while(getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();
    ofstream appendFile("notes.txt", ios::app);

    appendFile << "Name: Areeba Taqdees" << endl;
    appendFile << "Roll No: 12345" << endl;
    appendFile.close();
    cout << "\nName and Roll Number appended successfully.";
    return 0;
}
