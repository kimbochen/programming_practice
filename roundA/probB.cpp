#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Fraction
{
public:
    Fraction(long nom_, long den_): nom(nom_), den(den_)
    {
        reduce();
    }

    Fraction operator+(const Fraction &obj)
    {
        long fac = gcd(den, obj.den);

        long nom_ = nom * (obj.den / fac) + obj.nom * (den / fac);

        long den_ = (den / fac) * obj.den;

        return Fraction(nom_, den_);
    }

    Fraction operator*(const Fraction &obj)
    {
        long lr_fac = gcd(nom, obj.den);
        long rl_fac = gcd(den, obj.nom);

        long nom_ = (nom / lr_fac)*(obj.nom / rl_fac);
        long den_ = (den / rl_fac)*(obj.den/lr_fac);

        return Fraction(nom_, den_);
    }

    double toDouble(void)
    {
        return ((double) nom / den);
    }

private:
    long nom, den;

    void reduce(void)
    {
        long factor = gcd(nom, den);

        nom /= factor;
        den /= factor;
    }

    long gcd(long a, long b)
    {
        return (a % b == 0) ? b : gcd(b, a%b);
    }
};

double probB(void);

double suffixSum(int[],int,int);

int searchMin(int[],int,int,double);

int main(void)
{
    long n, d;

    cin >> n >> d;

    Fraction a(n,d);

    cin >> n >> d;

    Fraction b(n,d);

    Fraction c = a + b;

    Fraction e = a * b;

    cout << "c: " << c.toDouble() << '\n';

    cout << "e: " << e.toDouble() << '\n';
    //int T;
    //stringstream ss;

    //cin >> T;

    //for (int i = 0; i < T; i++)
    //{
    //    ss << "Case #" << i+1 << ": ";
    //    ss << fixed << probB() << '\n';
    //}

    //cout << ss.str();

    return 0;
}

double probB(void)
{
    int N, K;
    int *V = nullptr;
    double EX = 0.0;

    cin >> N >> K;

    V = new int[N];

    for (int i = 0; i < N; i++) cin >> V[i];

    sort(V, V+N);

    EX = suffixSum(V, N, 0) / N;

    if (K > 0)
    {
        for (int i = 0; i < K; i++)
        {
            int s = searchMin(V, 0, N-1, EX);

            EX = suffixSum(V, N, s) / N + EX * s / N;
        }
    }

    return EX;
}

double suffixSum(int V[], int N, int s)
{
    double sum = 0.0;

    for (int i = s;i < N; i++) sum += V[i];

    return sum;
}

int searchMin(int V[], int lf, int rt, double EX)
{
    if (lf < rt)
    {
        int m = (lf + rt) / 2;

        if (V[m] < EX) 
            return searchMin(V, m+1, rt, EX);
        else 
            return searchMin(V, lf, m, EX);
    }
    else return lf;
}
