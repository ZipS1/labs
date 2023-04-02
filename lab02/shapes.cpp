#include "shapes.h"

double Circle::getArea()
{
    return M_PI * pow(radius, 2);
}

double Circle::getPerimeter()
{
    return 2 * M_PI * radius;
}

double Parallelogram::getArea()
{
    return base * height;
}

double Parallelogram::getPerimeter()
{
    return 2 * base + 2 * height / sin(angle);
}

Trapezoid::Trapezoid(double upper, double bottom, double rightside, double leftside) :
    upperBase(upper), bottomBase(bottom), rightSide(rightside), leftSide(leftside)
{
    calculateHeight();
    if (height == 0)
        throw new std::logic_error("Trapezoid with specified params does not exist");
}

double Trapezoid::getArea()
{
    return (bottomBase + upperBase) / 2 * height;
}

double Trapezoid::getPerimeter()
{
    return upperBase + bottomBase + leftSide + rightSide;
}

void Trapezoid::calculateHeight()
{
    if (height != 0)
        return;

    double lb;
    double sb;

    if (bottomBase > upperBase)
    {
        lb = bottomBase;
        sb = upperBase;
    }
    else
    {
        lb = upperBase;
        sb = bottomBase;
    }

    height = sqrt((lb + leftSide - sb + rightSide) * (-lb + leftSide + sb + rightSide)
                * (lb - leftSide - sb + rightSide) * (lb + leftSide - sb - rightSide) 
                    / (4 * pow(lb - sb, 2)));
}


