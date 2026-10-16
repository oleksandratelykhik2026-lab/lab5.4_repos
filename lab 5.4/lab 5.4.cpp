
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Обчислення одного множника
double F(const int i)
{
    return (i + 1.0 / (i * i)) /
        sqrt(1.0 + exp(1.0 / i));
}

// 1. Рекурсивний спуск, спадання параметра
double P1(const int N, const int i, const double p)
{
    double t = p * F(i);

    if (i <= N)
        return t;

    return P1(N, i - 1, t);
}

// 2. Рекурсивний спуск, зрозтання параметра
double P2(const int N, const int i, const double p)
{
    double t = p * F(i);

    if (i >= 10)
        return t;

    return P2(N, i + 1, t);
}

// 3. Рекурсивний підйом, спадання параметра
double P3(const int N, const int i)
{
    if (i < N)
        return 1.0;

    return F(i) * P3(N, i - 1);
}

// 4. Рекурсивний підйом, зростання параметра
double P4(const int N, const int i)
{
    if (i > 10)
        return 1.0;

    return F(i) * P4(N, i + 1);
}

// 5. Ітераційний спосіб
double P0(const int N)
{
    double p = 1.0;

    for (int i = N; i <= 10; i++)
        p *= F(i);

    return p;
}

int main()
{
    int N;

    cout << "Enter N (1..10): ";
    cin >> N;

    if (N < 1 || N > 10)
    {
        cout << "Invalid N!" << endl;
        return 1;
    }

    cout << fixed << setprecision(10);

    cout << "P0 (iterative) = "
        << P0(N) << endl;

    cout << "P1 (rec down, i--) = "
        << P1(N, 10, 1.0) << endl;

    cout << "P2 (rec down, i++) = "
        << P2(N, N, 1.0) << endl;

    cout << "P3 (rec up, i--) = "
        << P3(N, 10) << endl;

    cout << "P4 (rec up, i++) = "
        << P4(N, N) << endl;

    return 0;
}