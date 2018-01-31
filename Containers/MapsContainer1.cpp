/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>

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
            
            int getStudentStandard()
            {
                return this->standard;    
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
    map<int, Student*> mapStudent;
    // we need a default constructor in our class to use operator[] on map.
    mapStudent.insert(std::pair<int, Student*>(101, new Student(23, "Manjinder", 10)));
    mapStudent.insert(std::make_pair<int, Student*>(102, new Student(23, "Harry", 12)));
    
    // cout<<mapStudent[101].second.getStudentAge();        // will not work, untill we introduce a default constructor
    
    /*
     *  Retreiving key.value from map using bi-directional iterator
     *  auto = map<int, Student>::const_iterator
     */
    for(auto student = mapStudent.cbegin(); student != mapStudent.cend(); ++student)
    {
        // cout<< student->second->getStudentAge();
        // erro: error: passing 'const Student' as 'this' argument discards qualifiers [-fpermissive]
        // will generate error if const isn't a modifier appended with your member functons: https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers
        
        // so append const to the member functions
        cout<< "Student Info before modification.\n";
        cout<< "Name: "<<student->second->getStudentName()<<" Age: "<< student->second->getStudentAge() << endl;
    }
    
    /*
     *  Writing key.value from map using bi-directional iterator
     *  auto = map<int, Student>::const_iterator
     */
    for(auto student = mapStudent.begin(); student != mapStudent.end(); ++student)
    {
        student->second->setStudentAge(16);
        cout<< "Student Info after modification.\n";
        cout<< "Name: "<<student->second->getStudentName()<<" Age: "<< student->second->getStudentAge() << endl;
    }
    
    /*
     * Say, for instance now I want to sort the entries in Map by some custom condition and now by keys.
     * A map is sorted by its keys and doesn't preserve the order of data filled into it.
     * So, I'll try a custom way. I'll populate a vector with values that are there in map, and will call std::sort() -- <algorithm>
     * on vector and will overload operator< in my class to sort the values based on my criteria.
     */
    
    vector<std::pair<int, Student*> > vectorStudent(mapStudent.begin(), mapStudent.end());
    cout<<"Vector container has been filled with the stuff that was there in map"<<endl;
    
    // std::sort is defined in <algorithm>
    // std::sort(vectorStudent.begin(), vectorStudent.end(), greater< std::pair<int,Student*> >());
    
    std::sort(vectorStudent.begin(), vectorStudent.end(), [&](const std::pair<int, Student*>& student1, const std::pair<int, Student*>& student2){
        if(student1.second->getStudentStandard() > student2.second->getStudentStandard())
        {
            return true;
        }
        else
            return false;
        
    });
    
    cout<<"-----------Vector after Sort Contains--------------"<<endl;
    for(const auto& student : vectorStudent)
    {
        cout<< "Name: "<<student.second->getStudentName()<<" Age: "<< student.second->getStudentAge() << endl;
    }
    cout<<"-----------------------------------"<<endl;
    
    /*
     * The code has been commented, as while inserting the elements from vector, the map will default sort by
     * the keys and will not preserve the insertion order of data and we'll loose the sorting result.
     
        mapStudent.clear();
    
        mapStudent.insert(vectorStudent.begin(), vectorStudent.end());
    
        for(auto student = mapStudent.begin(); student != mapStudent.end(); ++student)
        {
            cout<< "Student info after performing std::sort";
            cout<< "Name: "<<student->second->getStudentName()<<" Age: "<< student->second->getStudentAge() << endl;
        }
    */
    
    return 0;
}