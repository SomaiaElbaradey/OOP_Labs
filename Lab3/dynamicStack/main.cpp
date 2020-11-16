#include <iostream>

using namespace std;
class Stack
{
private:
    int Size;
    int *arr;
    int tos;
    static int counter;
public:
    Stack();
    Stack(int _Size);
    ~Stack();
    void push(int num);
    int isFull();
    int isEmpty();
    int pop();
    static int getCounter();
};
int Stack::counter=0;

int main()
{
    Stack s1,s2(2),s3(6);
    cout<<"number of objects: "<<Stack::getCounter()<<endl;
    return 0;
}
//constructors
Stack::Stack(int _Size)
{
    tos=0;
    Size=_Size;
    arr=new int[Size];
    counter++;
}
Stack::Stack()
{
    tos=0;
    Size=6;
    arr=new int[Size];
    counter++;
}
//counter
int Stack::getCounter()
{
    return Stack::counter;
}
//push, pop
int Stack::isFull()
{
    return (tos==Size);
}
int Stack::isEmpty()
{
    return (tos==0);
}
void Stack::push(int num)
{
    if(!isFull())
    {
        arr[tos++]=num;
    }
    else
    {
        cout<<"the stack is FULL ";
    }
}
int Stack::pop()
{
    int retVal=-1;
    if(!isEmpty())
    {
        retVal=arr[--tos];
    }
    else
    {
        cout<<"Empty Stack.. ";
    }
    return retVal;
}
//destructor
Stack::~Stack()
{
    cout<<"destructor. ";
    counter--;
        for (int i=0; i<Size; i++)
    {
        arr[i]=-1;
    }
    delete []arr;
}
