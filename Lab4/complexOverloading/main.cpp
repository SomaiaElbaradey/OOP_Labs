#include <iostream>
#include <cmath>
// constructor are called 6 times and destructors  are called 11 times
using namespace std;
class Complex
{
private:
    int real;
    int img;
public:
    Complex();
    Complex(const Complex& old);
    Complex(int _real,int _img);
    Complex(int _num);
    void setReal(int _real);
    void setImg(int _img);
    int getReal();
    int getImg();
    void printComplex();
    Complex& operator=(const Complex right);
    Complex operator+(const Complex right);
    Complex& operator++();
    Complex operator++(int);
    int operator>(const Complex right);
    int operator<(const Complex right);
    int operator>=(const Complex right);
    int operator<=(const Complex right);
    ~Complex();
};
Complex subComplex(Complex x, Complex y);

int main()
{
    Complex c1(1,2), c2(3,4),c3,c4;
    //c3=c1+c2;
    //c3=c1;
    //c3=++c1;
    //c3 = c1++;
    //c1>c3; c1<c2; c3>=c1; c3<=c4;
    cout<<"your values are:"<<endl<<"c1:";
    c1.printComplex();
    cout<<"c2:";
    c2.printComplex();
    cout<<"c3:";
    c3.printComplex();
    cout<<"c4:";
    c4.printComplex();
    return 0;
}

//constructors
Complex::Complex()
{
    real=0;
    img=0;
}
Complex::Complex(int _real,int _img)
{
    real=_real;
    img=_img;
}
Complex::Complex(int _num)
{
    real = img = _num;
}
//copy constructor
Complex::Complex(const Complex& old)
{
    real = old.real;
    img = old.img;
}
//setters and getters
void Complex::setReal(int _real)
{
    this->real=_real;
}
void Complex::setImg(int _img)
{
    this->img=_img;
}
int Complex::getReal()
{
    return this->real;
}
int Complex::getImg()
{
    return this->img;
}
//operators overloading
//c1=c3
Complex& Complex::operator=(const Complex right)
{
    this->real = right.real;
    this->img = right.img;
    return *this;
}
//c3=c1+c2
Complex Complex::operator+(const Complex right)
{
    Complex temp;
    temp.real= real+ right.real;
    temp.img=img+right.img;
    return temp;
}
//c3=++c1
Complex& Complex::operator++()
{
    this->real++;
    return *this;
}
//c3=c1++
Complex Complex::operator++(int)
{
    Complex temp(*this);
    real++;
    return temp;
}
//complex distance
float complexDis(Complex c)
{
    int result = (c.getReal()*c.getReal())+(c.getImg()*c.getImg());
    float distance = sqrt(result);
    return distance;
}
//c1>c3
int Complex::operator>(const Complex right)
{
    return complexDis(*this)>complexDis(right);
}
//c1<c2
int Complex::operator<(const Complex right)
{
    return complexDis(*this)<complexDis(right);
}
//c1<=c2
int Complex::operator<=(const Complex right)
{
    return complexDis(*this)<=complexDis(right);
}
//c1>=
int Complex::operator>=(const Complex right)
{
    return complexDis(*this)>=complexDis(right);
}
//print
void Complex::printComplex()
{
    switch (this->img)
    {
    case 1:
        if(this->real==0)
        {
            cout<<"i"<<endl;
        }
        else
        {
            cout<<real<<"+i"<<endl;
        }
        break;
    case -1:
        if(this->real==0)
        {
            cout<<"-i"<<endl;
        }
        else
        {
            cout<<this->real<<"-i"<<endl;
        }
        break;

    case 0:
        if(this->real==0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<this->real<<endl;
        }
        break;
    default:
        if(img<0&&this->real!=0)
        {
            cout<<this->real<<this->img<<"i"<<endl;
        }
        else if(real==0)
        {
            cout<<this->img<<"i"<<endl;

        }
        else
        {
            cout<<this->real<<"+"<<this->img<<"i"<<endl;

        }
        break;
    }
}
//destructor
Complex::~Complex()
{
    //cout<<"this is a destructor";
}
