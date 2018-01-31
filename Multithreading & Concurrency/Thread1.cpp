// Threads Programming. Calculating Incentives & Appraisals simultaneously
// compiled with flags : $ g++ prog.cc -Wall -Wextra -I/opt/wandbox/boost-1.66.0/gcc-7.1.0/include -std=gnu++17 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>

void calculateIncentives(float sale)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout<< "Incentives: "<< sale*10.0 <<std::endl;
}

void calculateAppraisal(float salary, int experience)
{
     std::this_thread::sleep_for(std::chrono::milliseconds(10));
   std::cout<< "Salary: "<< (salary/static_cast<float>(experience)) * 1000<<std::endl;
}

int main()
{
    float salary = 10000;
    int experience = 10;
    std::vector<std::thread> threadContainer;
   // std::cout.precision(2);
    std::cout<< "Salary before creating the thread: "<< salary<<std::endl;
    threadContainer.push_back(std::move(std::thread(calculateIncentives, salary)));
    threadContainer.push_back(std::move(std::thread(calculateAppraisal, salary, experience)));
    std::cout<< "Salary after creating the thread: "<< salary<<std::endl;
    std::cout<<threadContainer.size();
    for(auto& individual_thread : threadContainer)
    {
        individual_thread.join();
    }
    std::cout<< "Salary after joining the threads: "<< salary<<std::endl;
    return 0;
}