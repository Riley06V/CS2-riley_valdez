#include <iostream>
using namespace std;

template <class T1>

struct Rectangle{
    T1 s1,s2;
    T1 area;
    T1 perim;
};
//Headers go in .H files
template <class T1>
void promptSides(Rectangle<T1>&);

template <class T1>
void calcVals(Rectangle<T1>&);

template <class T1>
void printVals(Rectangle<T1>&);
//Templated functions
//template <class T1, class T2, class T3>
//T1 addNums(T2,T3);

int main(int argc, char* argv[]) {
    Rectangle<double> (rect1);
    calcVals(rect1);
    printVals(rect1);
    return 0;
}
//Definitions go into .cpp files for the main file of the program. //In make file add new .cpp to CPPFILES
template <class T1>
void promptSides(Rectangle<T1>& r1) {
    cout << "Enter the two sides of a rectangle: ";
    cin >> r1.s1 >> r1.s2;
}

template <class T1>
void calcVals(Rectangle<T1>& r1) {
    r1.area = r1.s1 * r1.s2;
    r1.perim = 2*r1.s1 + 2*r1.s2;

}

template <class T1>
void printVals(Rectangle<T1>& r1) {
    cout << "The rectangle with sides " << r1.s1 << " and " << r1.s2; << " has an area of"
         << r1.area << " and a perimeter of " << r1.perim << endl;
}