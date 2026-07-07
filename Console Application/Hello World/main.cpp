#include <iostream>
#include <fstream>
#include <string>   // for std::string

using namespace std;

// Global file streams, as requested.
ifstream  fin ("input.in");
ofstream  fout("output.out");

int main(int argc, char** argv)
{
    // 0) A classic console hello.
    cout << "Hello world!" << endl; // endl = '\n' + flush

    // 1) Show command-line arguments (argc = count, argv = values).
    cout << "argc = " << argc << '\n';
    for (int i = 0; i < argc; ++i)
        cout << "argv[" << i << "] = " << argv[i] << '\n';

    // 2) Check that files opened correctly.
    if (!fin.is_open())
        cerr << "[Warn] Could not open input.in (reading will fall back to keyboard)." << '\n';
    if (!fout.is_open())
        cerr << "[Warn] Could not open output.out (file writing will be skipped)." << '\n';

    // 3) Read one line: prefer file; else, read from keyboard.
    string line;
    bool got = false;
    if (fin.is_open() && std::getline(fin, line)) {
        cout << "[Info] Read from input.in" << '\n';
        got = true;
    } else {
        cout << "Type a line, then press Enter:" << '\n';
        if (std::getline(cin, line)) {
            cout << "[Info] Read from keyboard" << '\n';
            got = true;
        }
    }

    // 4) Echo to console and file (if available).
    if (got) {
        cout << "You wrote: " << line << '\n';
        if (fout.is_open()) {
            fout << "Hello file!" << '\n';
            fout << "You wrote: " << line << '\n';
            fout.flush(); // ensure data reaches disk now
        }
    } else {
        cout << "[Info] No input was read." << '\n';
    }

    return 0; // exit status for the OS (0 = success)
}
