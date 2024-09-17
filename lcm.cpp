#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    int c;
    while (a % b != 0)
    {
        c = b;
        b = a % b;
        a = c;
    }
    if (b > 0)
    {
        return b;
    }
    else
    {
        return -b;
    }
}

int LCM(int a, int b) // lcm(a,b) = (a * b)/gcm(a,b)
{
    return (a * b) / GCD(a, b);
}

int main()
{
    int a, b;
    cout << "Input A : ";
    cin >> a;
    cout << "\nInput B : ";
    cin >> b;
    int divisor = GCD(a, b);
    cout << "\nThe GSD(Greatest Common Divisor) : " << divisor;
    int multiple = LCM(a, b);
    cout << "\nThe LCM(Least Common Multiple) : " << multiple;
    return 0;
}