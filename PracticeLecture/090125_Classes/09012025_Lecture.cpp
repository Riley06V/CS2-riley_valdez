////Think about classes as small components, especially in video games.
//
///* Take a marker for example? How does it work. Well it draws, so youd need a function to make sure it can
//when pressed down on paper.
//It also has an ink level, so use a float to make sure of that
//*
// *  */
//
//#include <iostream>
//using namespace std;
//
//class MyClass{
//  public:               //Adding public, will make it not complain
//      int num1;        //Called "attribute" of an instance of a class
//  private:
//      int num2;         //public vs private is basically, what would want to be updated.
//                        //Attributes shouldn't be public that way they're trackable
//};
//
//class MyClass2{
//  private:
//    int num1A;
//    int num2A;
//  public:
//    //setters
//    void setNum1(int n1) {
//      num1A = n1;
//    }
//    void setNum2(int n2) {
//      num2A = n2;
//    }
//
//    //getters
//    int getNum1() {
//      return num1A;
//    }
//    int getNum2() {
//      return num2A;
//    }
//
//
//};
//
//int main(int argc, const char * argv[]) {
//  MyClass cl1;
//  MyClass2 cl2;
//  //complains because is inaccessible: Private
//  //Dot as accessor similar to struct
//  cl1.num1 = 10;
//
//
//  cl2.setNum1(88);//Able to modify what is stored within setNum1, which is num1A.
//  cl2.setNum2(44);
//  cout << "num1 = " << cl2.getNum1() << ", num2 = " << cl2.getNum2() << endl;
//  return 0;
//}


#include <iostream>
#include <string>
using namespace std;

class Dog {
  private:
    string _name;
    string _breed;
    int _age;
    int _numLegs;
  public:
    // Setters
    void setBreed(string breed) {
      _breed = breed;
    } // Setter that takes in breed as a string, which is different than the other breed variable
    void setAge(int age) {
      _age = age;
    }
    void setNumLegs(int numLegs) {
      _numLegs = numLegs;
    }
    void setName(string name) {
      _name = name;
    }
    //Getters
    string getBreed() {
      return _breed;
    }
    int getAge() {
      return _age;
    }
    int getNumLegs() {
      return _numLegs;
    }
    string getName() {
      return _name;
    }
};

int main(int argc, const char * argv[]) { //Since there is three, we can create an array;
  Dog* dogs[10] = {0};

  for (int i = 0; i < 10; i++) {
    cout << "Enter a dog: ";
  }
//  Dog* Dog1 = new Dog();
//  Dog* Dog2 = new Dog();
//  Dog* Dog3 = new Dog();
//
//  Dog1->setName("Novo");
//  Dog1->setBreed("Husky");
//  Dog1->setAge(10);
//  Dog1->setNumLegs(4);
//
//  Dog2->setName("Obi");
//  Dog2->setBreed("Golden Doodle");
//  Dog2->setAge(5);
//  Dog2->setNumLegs(4);
//
//  Dog3->setName("Biscuit");
//  Dog3->setBreed("Labrador");
//  Dog3->setAge(10);
//  Dog3->setNumLegs(4);
//
//  cout << Dog1->getName() << " is a " << Dog1->getBreed() << endl;
//  cout << "He is " << Dog1->getAge() << " years old and has "
//       << Dog1->getNumLegs() << endl;
//

  return 0;
}