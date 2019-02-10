#include <iostream>
#include <sstream>
#include <string>

#define MIN(a,b) (a < b) ? a : b

using namespace std;

string probA(void);

inline bool isEven(char);

int main(void)
{
    int T;
    stringstream ss;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        ss << "Case #" << i+1 << ':' << probA();
    }

    cout << ss.str();

    return 0;
}

string probA(void)
{
    string N;

    cin >> N;

    int M, P, Q;
    int n = N.size();

    string X = N;
    
    for (int i = 0; i < n; i++)
    {
        if (!isEven(X[i]))
        {
            X[i] --;

            for (int j = i+1; j < n; j++) X[j] = '8';

            break;
        }
    }

    string Y = N;

    for (int i = 0; i < n; i++)
    {
        if (!isEven(Y[i]))
        {
            if (Y[i] == '9')
            {
                Y[i] = '0';

                for (int j = i-1; j >= 0; j--)
                {
                    if (Y[j] != '8')
                    {
                        Y[j] += 2;
                        break;
                    }
                    else Y[j] = '0';
                }

                if (Y[0] == '0')
                {
                    Y = "2" + Y;
                    n ++;
                }
            }
            else Y[i] ++;

            for (int j = i+1; j < n; j++) Y[j] = '0';

            break;
        }
    }

    Q = stoi(N);

    M = Q - stoi(X);

    P = stoi(Y) - Q;

    return to_string(MIN(M,P)) + "\n";
}

bool isEven(char c)
{
    return ((c-'0') % 2 == 0);
}
