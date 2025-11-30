#include "word.h"
#include "tree.h"
#include <sstream>
#include <fstream>

using namespace std;

string normalize(string&);
int main(int argc, char* argv[])
{
    BST<Word> myTree;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);
    string rawWord;

    while (file >> rawWord) {
        string word = normalize(rawWord);
    }




    return 0;
}

string normalize(string &raw) {
    string cleaned;
    for (char characters : raw) {
        // convert uppercase to lowercase
        if (characters >= 'A' && characters <= 'Z') {
            characters = characters - 'A' + 'a';
        }
        //keep only letters and digits
        if ((characters >= 'a' && characters <= 'z') || (characters >= '0' && characters <= '9')) {
            cleaned += characters;
        }
    }
    return cleaned;
}