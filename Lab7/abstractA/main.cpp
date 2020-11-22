#include <iostream>

using namespace std;
class TypeA
{
protected:
    int x;
public:
    int& xValue()
    {
        return x;
    }
    TypeA()
    {
        x=0;
    }
    TypeA(int _x)
    {
        x=_x;
    }
    virtual void fun1()=0;
    virtual void fun2()=0;
    virtual void Show()
    {
        cout<<"class A"<<endl;
    }
};
class TypeB:public TypeA
{
protected:
    int y;
public:
    int& yValue()
    {
        return y;
    }
    TypeB()
    {
        y=0;
    }
    TypeB(int _x,int _y):TypeA(_x)
    {
        y=_y;
    }
    void fun1()
    {
        cout<<"this is Function 1"<<endl;
    }
};
class TypeC:public TypeB
{
protected:
    int z;
public:
    int& zValue()
    {
        return z;
    }
    TypeC()
    {
        z=0;
    }
    TypeC(int _x, int _y, int _z):TypeB(_x,_y)
    {
        z=0;
    }
    void fun1()
    {
        cout<<"this is function 1, class C"<<endl;
    }
    void fun2()
    {
        cout<<"this is function 2, class C"<<endl;
    }

};
int main()
{
   //TypeA A;
  //TypeB B;
    TypeC C;
    C.fun1();
    C.fun2();
    return 0;
}
