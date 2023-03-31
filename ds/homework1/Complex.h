#include <iostream>
using namespace std;
class Complex
{
private:
    double real;
    double image;
    double mo;
public:
    Complex() {
        real = rand() * 1.0 / 100;
        image = rand() * 1.0 / 100;
        mo = real * real + real * real;
    }
    double real1() { return real; }
    double image1() { return image; }
    double mo1() { return mo; }
    void real2(double i) { real = i; }
    void image2(double i) { image = i; }
    void mo2(double i) { mo = i; }
    void show() {
        cout << real << "+" << image << "i" << " ";
    }
    void display() {
        cout << "(" << real << "," << image << "i) ";
    }
    bool operator>(Complex& c)const
    {
        if (real > c.real)
            return true;
        else if (real == c.real)
        {
            if (image > c.image)
            {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    bool operator<(Complex& c)const
    {
        if (real < c.real)
        {
            return true;
        }
        else if (real == c.real)
        {
            if (image < c.image)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool operator>=(Complex& c)const
    {
        if (*this < c)
            return false;
        else
            return true;
    }
    bool operator<=(Complex& c)const
    {
        if (*this > c)
            return false;
        else
            return true;
    }
    bool operator==(Complex& c)const
    {
        if ((*this > c) || (*this < c))
            return false;
        else
            return true;
    }
    bool operator!=(Complex& c)
    {
        if (*this == c)
            return false;
        else
            return true;
    }
    Complex operator++(int)//后置加加
    {
        Complex temp = *this;
        real++;
        return temp;

    }
    Complex& operator++()//前置加加
    {
        real++;
        return *this;
    }
    Complex& operator+=(double x)
    {
        real += x;
        return (Complex&)*this;
    }
};
