#include <iostream>

using namespace std;
class GeoShape
{
protected:
    double dim1;
    double dim2;
public:
    GeoShape()
    {
        dim1=dim2=0;
    }
    GeoShape(double _dim1, double _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    double& dim1Val()
    {
        return dim1;
    }
    double& dim2Val()
    {
        return dim2;
    }
    virtual double cArea()
    {
        return 0;
    }
};
class Rect:public GeoShape
{
public:
    Rect();
    Rect(double _dim1, double _dim2):GeoShape(_dim1,_dim2) {}
    double cArea()
    {
        return dim1*dim2;
    }
};
class Triangle: public GeoShape
{
public:
    Triangle() {}
    Triangle(double _dim1, double _dim2):GeoShape(_dim1,_dim2) {}
    double cArea()
    {
        return 0.5*dim1*dim2;
    }
};
class Circle:public GeoShape
{
public:
    Circle() {}
    Circle(double _dim):GeoShape(_dim,_dim) {}
    void setDim1(double _dim1)
    {
        dim1=dim2=_dim1;
    }
    void setDim2(double _dim2)
    {
        dim1=dim2=_dim2;
    }
    double getDim1()
    {
        return dim1;
    }
    double getDim2()
    {
        return dim2;
    }
    double cArea()
    {
        return 3.14*dim1*dim2;
    }
};
double sumOfAreas(GeoShape **arr,int siz)
{
    double sum=0;
    for(int i=0; i<siz; i++)
    {
        sum+=arr[i]->cArea();
    }
    return sum;
}
int main()
{
    Circle C[2]= {Circle(2),Circle(5)};
    Triangle T[1]= {Triangle(5,10)};
    Rect R[1]= {Rect(4,10)};
    GeoShape *arr[4] = {C,&C[1],T,R};
    double sum=sumOfAreas(arr,4);
    cout<<"the sum of your shapes: "<<sum;
    return 0;
}
