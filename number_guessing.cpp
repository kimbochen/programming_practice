#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void solveProb(void);

int main(void)
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solveProb();
    }

    return 0;
}

void solveProb(void)
{
    int A, B, N;

    cin >> A >> B >> N;

    B ++;

    int guess = (A + B) / 2;
    string judge;

    while (true)
    {
        cout << guess << endl;

        cin >> judge;

        if (judge == "TOO_BIG")
        {
            B = guess;
            guess = (guess + A) / 2;
        }
        else if (judge == "TOO_SMALL")
        {
            A = guess;
            guess = (guess + B) / 2;
        }
        else if (judge == "CORRECT")
        {
            break;
        }
        else abort();
    }
}
