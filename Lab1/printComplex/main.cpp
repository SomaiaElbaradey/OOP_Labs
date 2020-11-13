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
        switch (img)
        {
        case 1:
            if(real==0)
            {
                cout<<"i"<<endl;
            }
            else
            {
                cout<<real<<"+i"<<endl;
            }
            break;
        case -1:
            if(real==0)
            {
                cout<<"-i"<<endl;
            }
            else
            {
                cout<<real<<"-i"<<endl;
            }
            break;

        case 0:
            if(real==0)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<real<<endl;
            }
            break;
        default:
            if(img<0&&real!=0)
            {
                cout<<real<<img<<"i"<<endl;
            }
            else if(real==0)
            {
                cout<<img<<"i"<<endl;

            }
            else
            {
                cout<<real<<"+"<<img<<"i"<<endl;

            }
            break;
        }
    }
    Complex subComplex(Complex x)
    {
        Complex obj;
        obj.real = real-x.real;
        obj.img =img-x.img;
        return obj;
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
    number1.setReal(0);
    number1.setImg(-1);
    number2.setReal(5);
    number2.setImg(4);
    number1.printComplex();
    //number2.printComplex();
    AddComplex(number1,number2).printComplex();
    Complex x=number1.subComplex(number2);
    x.printComplex();
    return 0;
}
