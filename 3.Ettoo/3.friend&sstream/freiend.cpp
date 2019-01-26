#include <iostream>

using namespace std;

class Point3D
{
private:
    int x,y,z;
public:
    Point3D(int x, int y, int z)
    :x{x}, y{y}, z{z} 
    { 

    }
    ~Point3D() { }
    friend ostream& operator<<(ostream& os, const Point3D& p);//esta clase tiene como amiga a esta funcion
    friend class Point3DModifier;
};

class Point3DModifier
{
public:
    Point3DModifier() { }
    ~Point3DModifier() { }
    void modify(Point3D& p, int x, int y, int z)
    {
        p.x = x;
        p.y = y;
        p.z = z;
    }
};

ostream& operator<<(ostream& os, const Point3D& p)
{
    os << p.x <<" " << p.y << " " << p.z;
    return os;
}

int main()
{
    Point3D p{6,7,8};
    cout << p << "\n";

    Point3DModifier m;
    m.modify(p, 9,10,11);
    cout << p <<"\n";
}