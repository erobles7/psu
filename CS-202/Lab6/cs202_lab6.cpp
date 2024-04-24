#include "shape.h"

//Step 5 - Implement the Point class operators

Point Point::operator + (const Point& p) const
{
    Point temp;
    temp.x = x+p.x;
    temp.y = y+p.y;

    return temp;
}

Point& Point::operator += (const Point& p)
{
    x += p.x;
    y += p.y;

    return *this;
}

bool Point::operator == (const Point& p) const
{
    if(x == p.x && y == p.y)
        return true;
    else
        return false;    
}

ostream& operator << (ostream& out, const Point& p)
{
    out<<"("<<p.x<<","<<p.y<<")";

    return out;
}


//Step 6 - Impelment the Shape class operators

Shape& Shape::operator = (const Shape& s)
{
    if(this == &s)
        return *this;

    center = s.center;
    if(color)
        delete [] color;
    color = new char[strlen(s.color)+1];
    strcpy(color,s.color);
    return *this;
}

Shape& Shape::operator += (const Point& p)
{
    center += p;

    return *this;    
}

Shape operator + (const Point& p, const Shape& s)
{
     Shape temp(s);
     temp.center =  temp.center + p;
     return temp;
}

Shape operator + (const Shape& s, const Point& p)
{
     Shape temp(s);
     temp.center =  temp.center + p;
     return temp;
}

//Step 7 Implement the Circle class operators
Circle operator + (const Point& p, const Circle& c)
{
    Circle temp(c);
    //temp.center = temp.center + p;
    return temp;
}

Circle operator + (const Circle& c, const Point& p)
{
    Circle temp(c);
    temp+=p;
    return temp;
}

Circle& Circle::operator = (const Circle& c)
{
  if(this == &c)
      return *this;

  Shape::operator=(c);
  radius = c.radius;

  return *this;
}

ostream& operator << (ostream& out, const Shape& s)
{

    out<<" Center :"<<s.center<<" Color: "<<s.color<<s.display()<<endl;
    return out;
}

