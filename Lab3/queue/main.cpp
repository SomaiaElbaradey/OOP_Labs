#include <iostream>

using namespace std;
class Queue
{
private:
    int* arr;
    int first, last, top;
    int capacity;
public:
    Queue()
    {
        capacity = 10;
        first = top = 0;
        last = capacity-1;
        arr = new int[(capacity*sizeof(int))];
    }
    Queue(int _capacity)
    {
        capacity = _capacity;
        first = top = 0;
        last = capacity - 1;
        arr = new int[(capacity*sizeof(int))];
    }
    int isFull()
    {
        return (top==capacity);
    }
    int isEmpty()
    {
        return (top==0);
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            cout<<"the Queue is full.."<<endl;
        }
        else
        {
            last = (last + 1)% capacity;
            arr[last] =item;
            top = top + 1;
        }
    }
    int dequeue()
    {
        int retVal=-1;
        if (isEmpty())
        {
            cout<<"Empty Queue.. "<<endl;
        }
        else
        {
            retVal = arr[first];
            first=(first+1)%capacity;
            top=top-1;
        }

        return retVal;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<< "the first input: "<<q.dequeue()<<endl;
    return 0;
}
