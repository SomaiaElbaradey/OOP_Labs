#include <iostream>

using namespace std;
class Complex
{
    int real;
    int img;
public:
    Complex()
    {
        real=0;
        img=0;
    }
    Complex(int _real,int _img)
    {
        real=_real;
        img=_img;
    }
    Complex(const Complex& old)
    {
        real=old.real;
        img=old.img;
    }
    ~Complex()
    {
    }
    int getReal()
    {
        return real;
    }
    void setReal(int _real)
    {
        real=_real;
    }
    int getImg()
    {
        return img;
    }
    void setImg(int _img)
    {
        img=_img;
    }
    //Casting int
    operator int(){
        return real;
    }

};
int main()
{
    Complex c1(3,2);
    int x=1;
    x=c1;
    cout<<x;
    return 0;
}
