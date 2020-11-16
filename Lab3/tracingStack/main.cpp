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
    Stack reverseStack();
    template<class B>
    friend void printStack(Stack<B> s);
};
template <class T>
int Stack<T>::counter=0;
//print stack
template <class B>
void printStack(Stack<B> s)
{
    cout<<"The Stack:"<<endl;
    for(int i=0; i<s.tos; i++)
    {
        cout<<s.arr[i]<<endl;
    }
}
int main()
{
    Stack<int> s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    printStack(s1);
    printStack(s1);
    s1.reverseStack();
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
//reverse stack
template <class T>
Stack<T> Stack<T>::reverseStack()
{
    Stack<T> revStack(this->Size);
    for(int i=tos-1; i>=0; i--)
    {
        revStack.push(this->arr[i]);
    }
    return revStack;
}
//destructor
template <class T>
Stack<T>::~Stack()
{
    cout<<"destructor. "<<endl;
    counter--;
    for (int i=0; i<Size; i++)
    {
        arr[i]=-1;
    }
    delete []arr;
}
