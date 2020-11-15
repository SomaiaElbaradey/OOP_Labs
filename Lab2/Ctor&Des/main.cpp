#include <iostream>
// constructor are called 6 times and destructors  are called 11 times
using namespace std;
class Complex
{
private:
    int real;
    int img;
public:
    Complex();
    Complex(int _real,int _img);
    Complex(int _num);
    void setReal(int _real);
    void setImg(int _img);
    int getReal();
    int getImg();
    void printComplex();
    Complex AddComplex(Complex x);
    ~Complex();
};
Complex subComplex(Complex x, Complex y);
int main()
{
    Complex c1(1,2), c2(3,4),c3,c4;
    c3=c1.AddComplex(c2);
    c4=subComplex(c1,c2);
    c1.printComplex();
    c2.printComplex();
    c3.printComplex();
    c4.printComplex();
    return 0;

}

Complex::Complex(){
    real=0;
    img=0;
}
Complex::Complex(int _real,int _img){
    real=_real;
    img=_img;
}
Complex::Complex(int _num){
    real = img = _num;
}
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
Complex Complex::AddComplex(Complex x)
{
    Complex obj;
    obj.real = real+x.real;
    obj.img =img+x.img;
    return obj;
}
Complex subComplex(Complex x, Complex y)
{
    Complex temp;
    temp.setReal(x.getReal()-y.getReal());
    temp.setImg(x.getImg()-y.getImg());
    return temp;
}
Complex::~Complex(){
    cout<<"this is a destructor";
}
