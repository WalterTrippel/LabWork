#include <iostream>
#include <cmath>

using namespace std;

//=========================

class Shape
{
public:
    Shape();
    virtual ~Shape();
    virtual void count_p_s()  =0;
    double get_perimeter() const;
    double get_square() const;
    virtual Shape &operator=(const Shape &right);
protected:
    double perimeter;
    double square;
};

Shape::Shape():
    perimeter(0.0), square(0.0)
{
}

Shape::~Shape()
{
    perimeter=0.0;
    square=0.0;
}

Shape &Shape::operator=(const Shape &right)
{
    perimeter=right.perimeter;
    square=right.square;
    return *this;
}

double Shape::get_perimeter() const
{
    return perimeter;
}

double Shape::get_square() const
{
    return square;
}

//=========================

class Circle: public Shape
{
public:
    Circle() {};
    ~Circle() {};
    void count_p_s();
};

void Circle::count_p_s()
{
    cout<<"Круг:\n";
    double r;
    cout<<"Веедите радуис:\n";
    cin>>r;
    perimeter = 2*3.14*r;
    square = 3.14*r*r;
}

//=========================

class Triangle: public Shape
{
public:
    Triangle() {};
    ~Triangle() {};
    void count_p_s();
};


void Triangle::count_p_s()
{
    cout<<"Правильный триугольник:\n";
    double a,b,c;
    cout<<"Введите 1 катет:\n";
    cin>>a;
    cout<<"Введите 2 катет:\n";
    cin>>b;
    c=sqrt(a*a+b*b);
    if(a==0 || b==0)
        c=0;
    perimeter = a+b+c;
    square = 0.5*(a*b);
}

//=========================

class Rectangle: public Shape
{
public:
    Rectangle() {};
    ~Rectangle() {};
    void count_p_s();
};

void Rectangle::count_p_s()
{
    cout<<"Прямоугольник:\n";
    double a,b;
    cout<<"Введите 1 сторону:\n";
    cin>>a;
    cout<<"Введите 2 сторону:\n";
    cin>>b;
    perimeter = 2*(a+b);
    if(a==0 || b==0)
        perimeter = a+b;
    square = a*b;
}

//=========================

double get_ratio(Shape &x)
{
    return x.get_square()!=0?(x.get_perimeter()/x.get_square()):0.0;
}

//=========================

int main()
{
    Shape *array[3];

    Circle a;
    Triangle b;
    Rectangle c;

    array[0]=&a;
    array[1]=&b;
    array[2]=&c;

    for(int i=0; i<3; ++i)
    {
        array[i]->count_p_s();
        cout<<"Периметр: "<<array[i]->get_perimeter()<<endl;
        cout<<"Площадь: "<<array[i]->get_square()<<endl;
        cout<<"Отношение Периметр/Площадь: "<<get_ratio(*array[i])<<endl<<endl;
    }

    return 0;
}
