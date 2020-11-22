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
        return this->dim1;
    }
    double& dim2Val()
    {
        return dim2;
    }
};
class Rect:public GeoShape
{
public:
    Rect() {}
    Rect(double _dim1,double _dim2):GeoShape(_dim1,_dim2) {}
    double rArea()
    {
        return dim1*dim2;
    }
};
class Square: protected GeoShape
{
public:
    Square() {}
    Square(double _dim1):GeoShape(_dim1,_dim1) {}
    double sArea()
    {
        return dim1*dim2;
    }
    void setDim(double _dim)
    {
        dim1=dim2=_dim;
    }
    double getDim()
    {
        return dim2;
    }
};
class Triangle: public GeoShape
{
public:
    Triangle() {}
    Triangle(double _dim1, double _dim2):GeoShape(_dim1,_dim2) {}
    double tArea()
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
    };
    void setDim2(double _dim2)
    {
        dim1=dim2=_dim2;
    };
    double getDim1()
    {
        return dim1;
    };
    double getDim2()
    {
        return dim2;
    };
    double cArea()
    {
        return 3.14 *dim1 *dim2;
    }
};
int main()
{
    return 0;
}
