#include <iostream>
#include "graphics.h"

using namespace std;
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
    void setX(int _x)
    {
        x=_x;
    }
    void setY(int _y)
    {
        y=_y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
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
class Line
{
private:
    Point pu, pd;
    int color;
public:
    Line()
    {
        pd.setX(0);
        pd.setY(0);
        pu.setY(0);
        pu.setX(0);
        color=0;
    }
    Line(int x1,int y1,int x2,int y2,int _color):
        pu(x1,y1),pd(x2,y2)
    {
        color=_color;
    }
    Line(const Line& old)
    {
        pu=old.pu;
        pd=old.pd;
        color=old.color;
    }
    void setPu(Point _pu)
    {
        pu=_pu;
    }
    void setPd(Point _pd)
    {
        pd=_pd;
    }
    void setColor(int _color)
    {
        color=_color;
    }
    int getColor()
    {
        return color;
    }
    Point getPu()
    {
        return pu;
    }
    Point getPd()
    {
        return pd;
    }
    void draw()
    {
        setcolor(color);
        line(pu.getX(),pu.getY(),pd.getX(),pd.getY());
    }
};
class Rect
{
private:
    Point ul, dr;
    int color;
public:
    Rect()
    {
        ul.setX(0);
        ul.setY(0);
        dr.setX(0);
        dr.setY(0);
        color=0;
    }
    Rect(int x1, int y1, int x2, int y2, int c):
        ul(x1,y1),dr(x2,y2)
    {
        /*
        ul.setX(x1);
        ul.setY(y1);
        dr.setX(x2);
        dr.setY(y2);
        */
        color=c;
    }
    Rect(Point _ul,Point _dr, int c):
        ul(_ul),dr(_dr)
    {
        //ul=_ul;
        //dr=_dr;
        color=c;
    }
    Rect(const Rect& old)
    {
        ul=old.ul;
        dr=old.dr;
        color=old.color;
    }
    void setUl(Point _ul)
    {
        ul=_ul;
    }
    void setDr(Point _dr)
    {
        dr=_dr;
    }
    void setColor(int c)
    {
        color=c;
    }
    Point getUl()
    {
        return ul;
    }
    Point getDr()
    {
        return dr;
    }
    int getColor()
    {
        return color;
    }
    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),dr.getX(),dr.getY());
    }
};
class Circle
{
private:
    Point center;
    int radius;
    int color;
public:
    Circle()
    {
        radius=0;
        color=0;
        center.setX(0);
        center.setY(0);
    }
    Circle(int _x,int _y, int r, int c):
        center(_x,_y)
    {
        radius=r;
        color=c;
    }
    Circle(Point _center, int r, int c):
        center(_center)
    {
        radius=r;
        color=c;
    }
    Circle(const Circle& old)
    {
        center=old.center;
        radius=old.radius;
        color=old.color;
    }
    void setRadius(int _radious)
    {
        radius=_radious;
    }
    void setColor(int _color)
    {
        color=_color;
    }
    void setCenter(Point _center)
    {
center:
        _center;
    }
    void draw()
    {
        setcolor(color);
        circle(center.getX(),center.getY(),radius);
    }
};
class Triangle
{
private:
    Point ul, dl, dr;
    int color;
public:
    void setColor(int _color)
    {
        color=_color;
    }
    void setUl(Point _ul)
    {
        ul=_ul;
    }
    void setDl(Point _dl)
    {

        dl=_dl;
    }
    void setDr(Point _dr)
    {
        dr=_dr;
    }
    int getColor()
    {
        return color;
    }
    Point getUl()
    {
        return ul;
    }
    Point getDl()
    {
        return dl;
    }
    Point getDr()
    {
        return dr;
    }
    Triangle()
    {
        ul.setX(0);
        ul.setY(0);
        dl.setX(0);
        dr.setX(0);
        dl.setY(0);
        dr.setY(0);
        color=0;
    }
    Triangle(int x1,int y1, int x2, int y2, int _color):
        ul(x1,y1),dl(x1,y2), dr(x2,y2)
    {
        color=_color;
    }
    Triangle(const Triangle& old)
    {
        ul=old.ul;
        dl=old.dl;
        dr=old.dr;
    }
    void draw()
    {
        Line l1(ul.getX(),ul.getY(),dl.getX(),dl.getY(),color);
        Line l2(ul.getX(),ul.getY(),dr.getX(),dr.getY(),color);
        Line l3(dr.getX(),dr.getY(),dl.getX(),dl.getY(),color);
        l1.draw();
        l2.draw();
        l3.draw();
    }

};
int main()
{
    initgraph();
    /*Point p1(100,100);
    Point p2(500,500);
    Rect r1(p1,p2,19);
    r1.draw();
    Circle c1(200,200,100,0);
    c1.draw();
    Line l1(100,100,500,500,50);
    l1.draw();
    Triangle t1(100,200,300,500,5);
    t1.draw();*/
    Circle c1(540,90,100,10);
    c1.draw();
    Line l1(490,90,440,300,20);
    l1.draw();
     Line l2(590,90,640,300,20);
    l2.draw();
    //r=200
    Circle c2(540,300,200,30);
    c2.draw();
    Line l3(580,390,580,430,20);
    l3.draw();
    Line l4(500,390,500,430 ,20);
    l4.draw();
    Rect r1(340,430,740,510,10);
    r1.draw();
    Triangle t1(700,440,640,500,5);
    t1.draw();
    int x;
    cin>>x;
    return 0;
}
