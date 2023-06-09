#pragma once

ref class SolveArctan
{
private:
    double x;

public:
    SolveArctan(double inputX)
    {
        x = inputX;
    }

    double Calculate()
    {
        return atan(x);
    }
};
