#include <iostream>

using namespace std;
const int SIZE = 100;

#include <iostream>
#include <ctime>

int sumOfProgression(int start, int end) {
    return (end * (end + 1) / 2) - ((start - 1) * start / 2);
}

int main()
{
    srand(time(0));
    int Max,  Min, Numbers[SIZE];
    cout << "Input Min : ";
    cin >> Min;
    cout << "Input Max : ";
    cin >> Max;
    int Sum = sumOfProgression(Min, Max);
    int Missed = Min + rand() % Max;
    for (int i = Min; i <= Max; i++)
    {
        if (i == Missed)
        {
            Numbers[i] = 0;
        }
        else Numbers[i] = i;
    }

    for (int i = Min; i <= Max; i++)
    {
        if (i == Missed)
        {
            cout << " ";
        }
        else cout << Numbers[i] << " ";
    }

    for (int i = Min; i <= Max; i++)
    {
        Sum -= Numbers[i];
    }

    cout << "\nMissed Number : " << Sum;

    return 0;
}


