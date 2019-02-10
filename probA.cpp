#include <iostream>
#include <sstream>
#include <string>

#define MIN(a,b) (a < b) ? a : b

using namespace std;

void probA(void);

int solveCase(int);

int main(void)
{
    probA();

    return 0;
}

void probA(void)
{
    int T, N;
    stringstream ss;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        ss << "Case #" << i+1 << ':'
            << solveCase(N) << '\n';
    }

    cout << ss.str();
}

int solveCase(int N)
{
    string X = to_string(N);

    int i = 0, n = X.size();

    for (; i < n; i++)
    {
        if ((X[i]-'0') % 2 == 1)
        {
            X[i++] --;
            break;
        }
    }

    while (i < n) X[i++] = '8';

    return stoi(X);
}
