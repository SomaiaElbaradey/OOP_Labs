#include <iostream>

using namespace std;
struct Complex
{
private:
    int real;
    int img;
public:
    void setReal(int _real)
    {
        real=_real;
    }
    void setImg(int _img)
    {
        img=_img;
    }
    int getReal()
    {
        return real;
    }
    int getImg()
    {
        return img;
    }
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    int subComplex(Complex x)
    {
        real-=x.real;
        img-=x.img;
    }
};
Complex AddComplex(Complex x, Complex y)
{
    Complex temp;
    temp.setReal(x.getReal()+y.getReal());
    temp.setImg(x.getImg()+y.getImg());
    return temp;
}
int main()
{
    Complex number1;
    Complex number2;
    number1.setReal(10);
    number2.setReal(20);
    number1.setImg(5);
    number2.setImg(4);
    number1.printComplex();
    number2.printComplex();
    AddComplex(number1,number2).printComplex();
    number1.subComplex(number2);
    number1.printComplex();
    return 0;
}
