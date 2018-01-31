/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Student
{
    private:
             int age;
             string name;
             int standard;
    public:
            Student(int age, string name, int standard): age(age), name(name), standard(standard)
            { }
            
            Student(const Student& student)     //copy constructor
            {
                this->age = student.age;
                this->name = student.name;
                this->standard = student.standard;
            }
            
            Student& operator=(Student& student)
            {
                this->age = student.age;
                this->name = student.name;
                this->standard = student.standard;
                return *this;
            }
            
            /* overloaded comparison operator, to check if a student is senior or not.
             * This is required for set/map containers to compare two custom objects */
             
            bool operator<(const Student& student)
            {
                // we're comparing the same object :/ . There must be a way to handle this problem.
                // but what's the type of "this" ? https://stackoverflow.com/questions/6067244/type-of-this-pointer
                if(this == &student) return false;      
                else if(this->standard < student.standard) return true;
            }
            
            // observers
            string getStudentName() const
            {
                return this->name;
            }
            
            int getStudentAge() const
            {
                return this->age;
            }
            
            // modifiers
            void setStudentName(string name)
            {
                this->name = name;
            }
            
            void setStudentAge(int age)
            {
                this->age = age;
            }
};

int main()
{
    map<int, Student> mapStudent;
    // we need a default constructor in our class to use operator[] on map.
    mapStudent.insert(std::pair<int, Student>(101, Student(23, "Manjinder", 12)));
    mapStudent.insert(std::make_pair(102, Student(23, "Harry", 12)));
    // cout<<mapStudent[101].second.getStudentAge();        // will not work, untill we introduce a default constructor
    
    /*
     *  using bi-directional iterator
     *  map<int, Student>::const_iterator
     */
    for(auto student = mapStudent.cbegin(); student != mapStudent.cend(); ++student)
    {
        // cout<< student->second->getStudentAge();
        // erro: error: passing 'const Student' as 'this' argument discards qualifiers [-fpermissive]
        // will generate error if const isn't a modifier appended with your member functons: https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers
        
        // so append const to the member functions
        cout<< student->second.getStudentAge() << endl;
    }
    return 0;
}


