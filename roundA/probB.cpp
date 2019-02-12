#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

double probB(void);

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

    for (int i = 0; i < N; i++)
    {
        cin >> V[i];

        EX += V[i];
    }

    EX /= N;

    if (K > 0)
    {
        for (int i = 0; i < K; i++)
        {
            double sum = 0.0;
    
            for (int i = 0; i < N; i++)
            {
                sum += max(EX, V[i]);
            }
    
            EX = sum / N;
        }
    }

    return EX;
}
