#include <iostream>
#include "graphics.h"

using namespace std;
class Shape
{
protected:
    int color;
public:
    Shape()
    {
        color=0;
    }
    Shape(int _color)
    {
        color=_color;
    }
    Shape(const Shape& old)
    {
        color=old.color;
    }
    int& colorVal()
    {
        return this->color;
    }
    virtual void Draw()=0;
};
class Point
{
private:
    int x;
    int y;
public:
    Point()
    {
        x=0;
        y=0;
    }
    Point(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
    Point (const Point& old)
    {
        x=old.x;
        y=old.y;
    }

    int& xPoint()
    {
        return this->x;
    }
    int& yPoint()
    {
        return this->y;
    }
    Point operator=(const Point& right)
    {
        x=right.x;
        y=right.y;
        return *this;
    }
    ~Point()
    {
    }
};
class Line:public Shape
{
private:
    Point pu, pd;
public:
    Line() {}
    Line(int x1,int y1,int x2,int y2,int _color):
        pu(x1,y1),pd(x2,y2),Shape(_color) {}
    Line(const Line& old)
    {
        pu=old.pu;
        pd=old.pd;
        color=old.color;
    }
    Point& puPoint()
    {
        return this->pu;
    }
    Point& pdPoint()
    {
        return this->pd;
    }
    void Draw() override
    {
        setcolor(color);
        line(pu.xPoint(),pu.yPoint(),pd.xPoint(),pd.yPoint());
    }
};
class Rect:public Shape
{
private:
    Point ul, dr;
public:
    Rect() {}
    Rect(int x1, int y1, int x2, int y2, int c):
        ul(x1,y1),dr(x2,y2), Shape(c) {}
    Rect(Point _ul,Point _dr, int c):
        ul(_ul),dr(_dr),Shape(c) {}
    Rect(const Rect& old)
    {
        ul=old.ul;
        dr=old.dr;
        color=old.color;
    }
    Point& ulPoint()
    {
        return this->ul;
    }
    Point& drPoint()
    {
        return this->dr;
    }
    void Draw() override
    {
        setcolor(color);
        rectangle(ul.xPoint(),ul.yPoint(),dr.xPoint(),dr.yPoint());
    }
};
class Circle:public Shape
{
private:
    Point center;
    int radius;
public:
    Circle()
    {
        radius=0;
    }
    Circle(int _x,int _y, int r, int c):
        center(_x,_y),Shape(c)
    {
        radius=r;
    }
    Circle(Point _center, int r, int c):
        center(_center),Shape(c)
    {
        radius=r;
    }
    Circle(const Circle& old)
    {
        center=old.center;
        radius=old.radius;
        color=old.color;
    }
    Point& cenPoint()
    {
        return this->center;
    }
    int& radPoint()
    {
        return this->radius;
    }
    void Draw() override
    {
        setcolor(color);
        circle(center.xPoint(),center.yPoint(),radius);
    }
};
class Triangle:public Shape
{
private:
    Point ul, dl, dr;
public:
    Point& ulPoint()
    {
        return this->ul;
    }
    Point& dlPoint()
    {
        return this->dl;
    }
    Point& drPoint()
    {
        return this->dr;
    }
    Triangle() {}
    Triangle(int x1,int y1, int x2, int y2, int _color):
        ul(x1,y1),dl(x1,y2), dr(x2,y2),Shape(_color) {}
    Triangle(const Triangle& old)
    {
        ul=old.ul;
        dl=old.dl;
        dr=old.dr;
        color=old.color;
    }
    void Draw() override
    {
        Line l1(ul.xPoint(),ul.yPoint(),dl.xPoint(),dl.yPoint(),color);
        Line l2(ul.xPoint(),ul.yPoint(),dr.xPoint(),dr.yPoint(),color);
        Line l3(dr.xPoint(),dr.yPoint(),dl.xPoint(),dl.yPoint(),color);
        l1.Draw();
        l2.Draw();
        l3.Draw();
    }
};
class Picture
{
    Shape **arr;
    int Size;
public:
    Picture()
    {
        arr=NULL;
        Size=0;
    }
    Picture(Shape **_arr,int _size)
    {
        arr=_arr;
        Size=_size;
    }
    void Paint()
    {
        for(int i=0; i<Size; i++)
        {
            arr[i]->Draw();
        }
    }
};

int main()
{
    initgraph();
    Circle* circles=new Circle[2];
    circles[0]=Circle(540,90,100,10);
    circles[1]=Circle(540,300,200,30);
    Rect* r=new Rect(340,430,740,510,10);
    Triangle* t= new Triangle(700,440,640,500,5);
    Line* lines= new Line[4];
    lines[0]=Line(490,90,440,300,20);
    lines[1]=Line(590,90,640,300,20);
    lines[2]=Line(580,390,580,430,20);
    lines[3]=Line(500,390,500,430 ,20);
    Shape *shape[8]={circles,&circles[1],r,t,lines,&lines[1],&lines[2],&lines[3]};
    Picture pic(shape,8);
    pic.Paint();
    int x;
    cin>>x;
    return 0;
}
