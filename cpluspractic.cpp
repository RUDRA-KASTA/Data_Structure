#include <iostream>

//////  :: called as scope resolution operator.

using namespace std;

namespace first{
    int x=1;
}
namespace Second{
    int x=2;
}

class teacher{
private: 
    string salary;

public:
    string name;
    string dep;
    string subject;
    int *cgpaptr;

    /// @brief non parametrise constructor.
    teacher(){
        std::cout << "non parametrise Constructor" << endl;
    }
    /// @brief parametrise constructor
    teacher(string name,string dep,string subject,int cgpa){
        this->name = name;
        this->dep = dep;
        this->subject = subject;
        cgpaptr = new int;                                      /// alocating memory for the variable where the cgpaptr is pointing
        *cgpaptr = cgpa;
    }
    /// @brief copy constructor
    teacher(teacher &t)
    {
        this->name = t.name;
        this->dep = t.dep;
        this->subject = t.subject;
        cgpaptr = new int;
        *cgpaptr = *t.cgpaptr;

    }
    /// @brief function to set private data
    void setsal(int sal)
    {
        this->salary = sal;
    }
    /// @brief function to show private data
    string getsal(int sal)
    {
        return this->salary;
    }
    /// @brief destructor 
    ~teacher()
    {
        cout << "Hello, memory is deallocated.";
        delete cgpaptr;
    }
    /// @brief to get the information about the class
    void getInfo()
    {
        cout<<"///////////////////////////////////////////////////////////////"<<endl;
        cout<<this->name<<endl;
        cout<<this->dep<<'\n';
        cout<<this->subject<<endl;
        cout<<*cgpaptr<<'\n';
    }

};

class student{
public:
    string name;
    string roll_no;

    student(string name,string roll_no){
        this->name = name;
        this->roll_no = roll_no;
    }
};

class EC_Student : public student{
public:    
    string subject;

    EC_Student (string name, string roll_no, string subject): student(name,roll_no){
        this->subject = subject;
    }

    void getInfo()
    {
        cout<< "name : " << name << endl;
        cout<< "roll_no : " << roll_no << endl;
        cout<< "subject : " << subject << endl;
    }

};

int main()
{

    // /////////////   Basic IO    //////////////////

    // std::cout <<"Rudra Kasta.  ";                                     // to print the data in the output console without new line
    // std::cout <<"Rudra Kasta." << '\n';                             // to print the data in the output console with new line.
    // std::cout <<"Rudra Kasta." << std::endl;                        // another way.

    // /////////////   Data Types    ///////////////////

    // std::string name = "Kasta";
    // std::cout << name << '\n';
    // std::cout << "hello " << name  << " I am 21 years old " << name << std::endl;

    // /////////////   const keyword   ////////////////

    // const double PI = 3.14;
    // const int LIGHT_SPEED = 300000000;

    // //////////////  namespace   ///////////////////

    // using namespace first;
    // std::cout << x ;

    // teacher t1;
    // t1.name = "rudra";
    // t1.dep = "EC";
    // t1.subject = "DSA";
    // *(t1.cgpaptr) = 9.0;
    // t1.getInfo();

    // teacher t2("kevin","EC","RTOS",8);
    // t2.getInfo();

    // teacher t3(t1);
    // *(t3.cgpaptr) = 8.0;
    // t3.getInfo();
    // t1.getInfo();
    string name;
    getline(std::cin,name);

    EC_Student s("rudra","21bec107","math");
    s.getInfo();
 

    return 0;
}