#include <iostream>

using namespace std;
class Stack
{
private:
    int arr[6];
    int tos;
public:
    Stack()
    {
        tos=0;
        cout<<"constructor. ";
    }
    ~Stack()
    {
        cout<<"destructor. ";
        for (int i=0; i<Size; i++)
        {
            arr[i]=-1;
        }
        delete []arr;
    }
    void push(int num)
    {
        if(tos!=6)
        {
            arr[tos++]=num;
        }
        else
        {
            cout<<"the stack is FULL ";
        }
    }
    int pop()
    {
        int retVal=-1;
        if(tos!=0)
        {
            retVal=arr[--tos];
        }
        else
        {
            cout<<"Empty Stack.. ";
        }
        return retVal;
    }
};
int main()
{
    Stack s1;
    s1.push(10);
    s1.pop();
    s1.pop();
    return 0;
}
