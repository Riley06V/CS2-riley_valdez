#include <iostream>
#include <fstream>
using namespace std;

//io stream notes
int main(int argc, const char * argv[]) {
    ifstream fin;
    // int number;
    string inLine;
    fin.open("input.txt");
    //fail safe in case of nothing opening
    //Probably also make a do()while{} loop to make sure that a file gets opened.
    if (!fin.is_open()) {
        cerr << "Invalid filename" << endl;
        return 1;
    }
//    else {do fin.open here or something else.
//    }
    while (fin>>inLine) {
        cout <<inLine << endl;
    }
    cout << "Press Enter to quit";
    //clear buffer using cin.get() again; or cin.ignore(1000, '\n\)
    cin.get();

    fin.close();
    return 0;
}