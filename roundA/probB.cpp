#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

double probB(void);

double suffixSum(double[],int,int);

int searchMin(double[],int,int,double);

int main(void)
{
    int T;
    stringstream ss;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        ss << "Case #" << i+1 << ": ";
        ss << fixed << probB() << '\n';
    }

    cout << ss.str();

    return 0;
}

double probB(void)
{
    int N, K;
    double *V = nullptr;
    double EX = 0.0;

    cin >> N >> K;

    V = new double[N];

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

double suffixSum(double V[], int N, int s)
{
    double sum = 0.0;

    for (int i = s;i < N; i++) sum += V[i];

    return sum;
}

int searchMin(double V[], int lf, int rt, double EX)
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
