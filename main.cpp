#include <iostream>

using namespace std;

class Point {
    int x;
    int y;
public:
    Point(int x, int y);

    int getX() const;
    int getY() const ;
    void setX(int x);
    void setY(int y);

    int operator[](int index);
    int operator[](char index);
    friend istream& operator>>(istream&, Point&);
    //friend Point operator+(const Point&, int);
    //friend Point operator+(int, const Point&);

};
int Point::getX() const{return x;}
int Point::getY() const{return y;}
void Point::setX(int x){this->x = x;}
void Point::setY(int y){this->y = y;}

Point operator+(const Point& left, int right) {
    Point p(0,0);
    p.setX(left.getX() + right);
    p.setY(left.getY() + right);
    return p;
}
Point operator+(int left, const Point & right){
    return right+left;
}

ostream& operator<<(ostream& out, const Point & right) {
    out << "Point[ " << right.getX() << " , " << right.getY() << " ]";
    return out;
}

istream& operator>>(istream& in, Point& right) {
    in >> right.x;
    in >> right.y;
    return in;
}



Point::Point(int x, int y) : x(x), y(y) {}

int Point::operator[](int index) {
    if(index == 0) return x;
    if(index == 1) return y;
    throw exception();
}

int Point::operator[](char index) {
    if(index == 'x') return x;
    if(index == 'y') return y;
    throw exception();
}



class Pow{
    int p;
public:
    Pow(int pow) : p(pow) {}

    double operator()(int a){
       return pow(a,p);
    }
};



int main() {

    Point p = Point(2,5);

    cout<<p[1]<<endl;
    cout<<p[0]<<endl;

    cout<<p['x']<<endl;


    Pow sqr(2);
    cout<<sqr(5);

    getchar();
    return 0;
}

