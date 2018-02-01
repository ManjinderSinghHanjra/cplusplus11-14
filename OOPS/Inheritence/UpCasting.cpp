/* Single Inheritence
 * flags used to compile(on wandbox):  g++ prog.cc -Wall -Wextra -std=c++14
 */
#include <iostream>
#include <string>
using namespace std;
class Mammal
{
    protected: 
        string trait;
    public:
    Mammal(string trait):trait(trait)
    {
    }
    ~Mammal(){}
    void printMammalTraits()
    {
        std::cout<<"Animal Trait: "<<trait<<endl;
    }
};

class Pet
{
    protected:
        bool isFriendly;
    public:
    Pet(bool isFriendly): isFriendly(isFriendly)
    {}
    void isPetFriendly()
    {
        if(isFriendly)
        {
            cout<<"Has frienldy nature"<<endl;
        }
        else
        {
            cout<<"Pet isn't frienldy with strangers"<<endl;
        }
    }
};

class Dog : public Mammal, public Pet
{
    private:
        string name;
    public:
        Dog(string name) : Mammal("Barks"), Pet(true), name(name)
        {}
        ~Dog() {}
        void displayFunc()
        {
            cout<<"Dog's name is "<<name<<endl;
            isPetFriendly();
            printMammalTraits();
        }
};

class Bear : public Mammal
{
    private:
        string name;
    public:
        Bear(string name) : Mammal("Growls"), name(name)
        {}
        ~Bear() {}
        void displayFunc()
        {
            cout<<"Bear's name is "<<name<<endl;
            printMammalTraits();
        }
};


int main()
{
    Dog dog("Tommy");
    dog.displayFunc();
    
    Mammal *mammal = new Bear("Stuart");
    mammal->printMammalTraits();
    return 0;
}