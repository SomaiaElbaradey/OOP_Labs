#include <iostream>
#include <string.h>
using namespace std;
class Person
{
public:
    char fullName[20];
    float netSalary;
};
class Employee
{
public:
    char fname[10];
    char lname[10];
    float salary;
    float commision;
    float deduction;
    operator Person()
    {
        Person P;
        strcat(P.fullName,this->fname);
        strcat(P.fullName,this->lname);
        P.netSalary=commision+deduction;
        return P;
    }
};

int main()
{
    Employee emp;
    strcpy(emp.fname,"Somaya ");
    strcpy(emp.lname,"Mostafa");
    emp.commision=19;
    emp.deduction=74;
    Person p1 =emp;
    cout<<"employee data:"<<endl<<"first name: "<<emp.fname<<endl;
    cout<<"last name: "<<emp.lname<<endl;
    cout<<"full name: "<<p1.fullName<<endl;
    cout<<"commision: "<<emp.commision<<endl;
    cout<<"deduction: "<<emp.deduction<<endl;
    cout<<"net salary: "<<p1.netSalary;
    return 0;
}
