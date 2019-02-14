#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int probC(void);

void readInput(vector<string>&,string&);

int main(void)
{
    int T;
    stringstream ss;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        ss << "Case #" << i+1;
        ss << ": " << probC() << '\n';
    }

    cout << ss.str();

    return 0;
}

int probC(void)
{
    string S;
    vector<string> dict;

    readInput(dict, S);

    return 0;
}
void readInput(vector<string> &dict, string &S)
{
    int L;
    cin >> L;

    dict.reserve(L);

    string s;
    for (int i = 0; i < L; i++) 
    {
        cin >> s;
        dict.emplace_back(s);
    }

    cin.ignore();

    char S1, S2;
    int N, A, B, C, D;

    cin >> S1 >> S2 >> N >> A >> B >> C >> D;

    vector<int> x(N);

    x[0] = (int) S1;
    x[1] = (int) S2;
    for (int i = 2; i < N; i++)
    {
        x[i] = (A * x[i-1] + B * x[i-2] + C) % D;
    }

    S.reserve(N);

    S += S1;
    S += S2;
    for (int i = 2; i < N; i++)
    {
        S += (char)(97 + (x[i] % 26));
    }
}
