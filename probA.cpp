#include <iostream>
#include <sstream>
#include <string>

#define MIN(a,b) (stoi(a) < stoi(b)) ? a : b

using namespace std;

string probA(void);

int main(void)
{
    int T;
    stringstream ss;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        ss << "Case #" << i+1 << ':';
        
        ss << probA() << '\n';
    }

    cout << ss.str();

    return 0;
}

string probA(void)
{
    string N;

    cin >> N;

    string X = N;
    int i = 0, n = X.size();

    while (i < n && (X[i]-'0') % 2 == 0) i++;

    X[i++] --;

    while (i < n) X[i++] = '8';

    return X;
}
