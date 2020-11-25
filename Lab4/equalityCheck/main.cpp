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
    Stack(const Stack &old);
    ~Stack();
    void push(int num);
    int isFull();
    int isEmpty();
    int pop();
    static int getCounter();
    Stack& operator=(const Stack& right);
    Stack operator+(const Stack& right);
    void printStack();
    //check equality
    int operator==(Stack right)
    {
        int check=1;
        if(right.tos!=tos)
        {
            check=0;
        }
        Stack temp1= right;
        Stack temp2 = *this;
        int temp;
        for (int i=0; i<temp1.tos; i++)
        {
            for(int j=i+1; j<temp1.tos; j++)
            {
                if (temp1.arr[i]>temp1.arr[j])
                {
                    temp = temp1.arr[j];
                    temp1.arr[j] = temp1.arr[i];
                    temp1.arr[i] = temp;
                }
            }
        }
        int tmp;
        for (int i=0; i<temp2.tos; i++)
        {
            for(int j=i+1; j<temp2.tos; j++)
            {
                if (temp2.arr[i]>temp2.arr[j])
                {
                    tmp = temp2.arr[j];
                    temp2.arr[j] = temp2.arr[i];
                    temp2.arr[i] = tmp;
                }
            }
        }
        for(int i=0; i<temp2.tos; i++)
        {
            if (temp1.arr[i]!=temp2.arr[i])
            {
                check=0;
            }
        }
        delete [] temp1;
        delete [] temp2;
        return check;
    }
};
int Stack::counter=0;

int main()
{
    Stack s1(3),s2(2),s3(6),s4;
    s2.push(10);
    s2.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s4.push(30);
    s4.push(40);
    s4.push(50);
    s4.push(50);

    if(s1==s4)
    {
        cout<<"match"<<endl;
    } else
    {
        cout<<"no match"<<endl;
    }
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
Stack::Stack(const Stack &old)
{
    Size=old.Size;
    tos=old.tos;
    arr= new int[Size];
    for(int i=0; i<tos; i++)
    {
        arr[i]=old.arr[i];
    }
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
//print
void Stack::printStack()
{
    cout<<"The Stack:"<<endl;
    for(int i=0; i<tos; i++)
    {
        cout<<arr[i]<<endl;
    }
}
//operators overloading
//s1=s2
Stack& Stack::operator=(const Stack& right)
{
    delete[] arr;
    tos=right.tos;
    Size= right.Size;
    arr= new int[Size];
    for(int i=0; i<tos; i++)
    {
        arr[i]=right.arr[i];
    }
    return *this;
}
//s1+s2
Stack Stack::operator+(const Stack& right)
{
    Stack temp;
    temp.Size= Size+right.Size;
    temp.tos=tos+right.tos;
    temp.arr=new int [temp.Size];
    for(int i=0; i<tos; i++)
    {
        temp.arr[i]=arr[i];
    }
    for(int j=tos; j<temp.tos; j++)
    {
        temp.arr[j]=right.arr[j-tos];
    }
    return temp;
}
//destructor
Stack::~Stack()
{
    //cout<<"destructor. ";
    counter--;
    for (int i=0; i<Size; i++)
    {
        arr[i]=-1;
    }
    delete []arr;
}
