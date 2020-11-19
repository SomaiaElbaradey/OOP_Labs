#include <iostream>

using namespace std;
int retVal(int x)
{
    x++;
    return x;
}
int& retRef(int &x){
    x++;
    return x;
}
int* retAdd(int *x){
    ++(*x);
    return x;
}
int main()
{
    //value
    int x=50;
    int res= retVal(x);
    //reference
    res = retRef(x);
    retRef(x)=19;
    //address
    *retAdd(&x)=74;
    res = *retAdd(&x);
    return 0;
}
