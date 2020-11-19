#include <iostream>
//overload [] operator  setter and getter
using namespace std;
class IntArray
{
private:
    int _size;
    int *arr;
public:
    IntArray()
    {
        _size=10;
        arr = new int[_size];
    }
    IntArray(IntArray& old)
    {
        _size=old._size;
        arr = new int[_size];
        for(int i=0; i<_size; i++)
        {
            arr[i]=old.arr[i];
        }
    }
    IntArray operator=(const IntArray& right)
    {
        delete[] arr;
        _size=right._size;
        arr= new int[_size];
        for(int i=0; i<_size; i++)
        {
            arr[i]=right.arr[i];
        }
    }
    ~IntArray()
    {
        delete []arr;
    }
    void setVal(int index,int value)
    {
        if(index>=0&&index<_size)
        {
            arr[index]=value;
        }
    }
    int getVal(int index)
    {
        int retVal=-123;
        if(index>=0&&index<_size)
        {
            retVal=arr[index];
        }
        return retVal;
    }
    int& operator[](int index)
    {
        if(index>=0&&index<_size)
        {
            return arr[index];
        }
    }
};
int main()
{
    IntArray arr;
    //arr.setVal(1,11);
    //int x= arr.getVal(1);
    arr[2]=33;
    cout<<arr[2];
    return 0;
}
