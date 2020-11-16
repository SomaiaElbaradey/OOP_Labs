#include <iostream>

using namespace std;
template <class T>
class Stack
{
private:
    int Size;
    T *arr;
    int tos;
    static int counter;
public:
    Stack();
    Stack(int _Size);
    ~Stack();
    void push(T num);
    int isFull();
    int isEmpty();
    T pop();
    static int getCounter();
};
template <class T>
int Stack<T>::counter=0;

int main()
{
    Stack<int> s1;
    cout<<"number of objects: "<<Stack<int>::getCounter()<<endl;
    return 0;
}
//constructors
template <class T>
Stack<T>::Stack(int _Size)
{
    tos=0;
    Size=_Size;
    arr=new T[Size];
    counter++;
}
template <class T>
Stack<T>::Stack()
{
    tos=0;
    Size=6;
    arr=new T[Size];
    counter++;
}
//counter
template <class T>
int Stack<T>::getCounter()
{
    return Stack::counter;
}
//push, pop
template <class T>
int Stack<T>::isFull()
{
    return (tos==Size);
}
template <class T>
int Stack<T>::isEmpty()
{
    return (tos==0);
}
template <class T>
void Stack<T>::push(T num)
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
template <class T>
T Stack<T>::pop()
{
    T retVal=-1;
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
template <class T>
Stack<T>::~Stack()
{
    cout<<"destructor. ";
    counter--;
        for (int i=0; i<Size; i++)
    {
        arr[i]=-1;
    }
    delete []arr;
}
