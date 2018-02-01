/* Single Inheritence
 * flags used to compile(on wandbox):  g++ prog.cc -Wall -Wextra -std=c++14
 */
#include <iostream>
#include <string>
using namespace std;

class LivingBeing
{
    public:
        virtual void isAlive()
        {
            cout<<"I'm a mortal being and still alive"<<endl;
        }
};


class Mammal : public LivingBeing
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
    void isAlive()
        {
            cout<<"I'm a Mammal and still alive"<<endl;
        }
};

class Pet : public LivingBeing
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
    void isAlive()
        {
            cout<<"I'm a Pet and still alive"<<endl;
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
       void isAlive()
        {
            cout<<"I'm a dog and still alive"<<endl;
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
        void isAlive()
        {
            cout<<"I'm a Bear and still alive"<<endl;
        }
};


int main()
{
    Dog dog("Tommy");
    dog.displayFunc();
    
    Mammal *mammal = new Bear("Stuart");
    mammal->printMammalTraits();
    
    LivingBeing *livingBeing = mammal;
    livingBeing->isAlive();
    return 0;
}