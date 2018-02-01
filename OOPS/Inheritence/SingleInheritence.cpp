/* Single Inheritence
 * flags used to compile(on wandbox):  g++ prog.cc -Wall -Wextra -std=c++14
 */
#include <iostream>
#include <string>
using namespace std;
class Shape
{
    protected: 
        string type;
    public:
    Shape(string type):type(type)
    {
    }
    ~Shape(){}
    void printTypeOfShape()
    {
        std::cout<<type<<endl;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle() : Shape("Rectangle")
    {  }
    void setTypeOfShape(string& type)
    {
        this->type = type;
    }
};

class Square : public Shape
{
    public:
        Square() : Shape("Square")
        {   }
        void setTypeOfShape(string& type)
        {
            this->type = type;
        }
};

int main()
{
    Rectangle rectangle;
    rectangle.printTypeOfShape();
    Square square;
    square.printTypeOfShape();
}