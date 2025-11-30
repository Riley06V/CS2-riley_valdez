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
        //normalization of words
        string word = normalize(rawWord);
        if (word.empty()) continue; //skips
        Word tempWord(word, 1);
        //If word is in multiple times, count and return number of times updated
        if (myTree.search(tempWord)) {
            //remove old node
            myTree.remove(tempWord);
            tempWord++;
            int oldCount = tempWord.getCount();
            Word updated(word, oldCount +1);
            myTree.insert(updated);
        } else {
            myTree.insert(tempWord);
        }
    }

    myTree.inOrder();
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