#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

// Function to write to a file
void writeToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Hello from C++ multithreading!\n";
        file << "This text is written by a thread.\n";
        file.close();
        cout << "File writing done." << endl;
    } else {
        cerr << "Error opening file for writing!" << endl;
    }
}

// Function to read from a file
void readFromFile(const string& filename) {
    this_thread::sleep_for(chrono::milliseconds(100)); // Ensure file is written before reading
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Reading file contents:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error opening file for reading!" << endl;
    }
}

int main() {
    string filename = "example.txt";

    thread writerThread(writeToFile, filename);
    writerThread.join(); // Ensures writing happens before reading

    thread readerThread(readFromFile, filename);
    readerThread.join();

    return 0;
}
