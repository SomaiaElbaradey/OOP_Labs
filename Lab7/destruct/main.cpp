#include <iostream>

using namespace std;
class Base
{
public:
    virtual ~Base()
    {
        cout<<"Base destruct"<<endl;
    };

};
class Derived: public Base
{
public:
    ~Derived()
    {
        cout<<"Derived destruct"<<endl;
    };
};
int main()
{

    Base *ptr = new Derived();
    delete ptr;
    int x;
    cin>>x;
    return 0;
}
