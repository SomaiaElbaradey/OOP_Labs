#include<iostream>
using namespace std;

void Swap(int &x, int &y)
{
    int temp;
    temp= x;
    x=y;
    y=temp;
}
int main()
{
    int num1=10;
    int num2=20;
    Swap(num1, num2);
    cout<<"number 1 is: "<<num1<<" and number 2 is: "<<num2;
    return 0;
}
