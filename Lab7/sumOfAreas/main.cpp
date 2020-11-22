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
double sumOfAreas(Rect *r, int rSize, Circle *c, int cSize, Triangle *t, int tSize)
{
    double sum=0;
    for(int i=0; i<rSize; i++)
    {
        sum+=r[i].cArea();
    }
    for(int i=0; i<cSize; i++)
    {
        sum+=c[i].cArea();
    }
    for(int i=0; i<tSize; i++)
    {
        sum+=t[i].cArea();
    }
    return sum;
}
int main()
{
    Circle C[2]={Circle(2),Circle(5)};
    Triangle T[1]={Triangle(5,10)};
    Rect R[1]={Rect(4,10)};
    double sum=sumOfAreas(R,1,C,2,T,1);
    cout<<"the sum of your shapes: "<<sum;
    return 0;
}
