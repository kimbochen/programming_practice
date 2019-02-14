#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int probC(void);

void readInput(int&,string**,int&,char**);

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
    int L, N;
    char *S = nullptr;
    string *dict = nullptr;

    readInput(L, &dict, N, &S);

    for (int i = 0; i < N; i++) cout << S[i] << "\n"[i<N-1];

    return 0;
}
void readInput(int &L, string **p_dict, int &N, char **p_S)
{
    cin >> L;

    string *dict = new string[L];

    for (int i = 0; i < L; i++) cin >> dict[i];

    cin.ignore();

    char S1, S2;
    int A, B, C, D;

    cin >> S1 >> S2 >> N >> A >> B >> C >> D;

    int *x = new int[N];

    x[0] = (int) S1;
    x[1] = (int) S2;
    for (int i = 2; i < N; i++)
    {
        x[i] = (A * x[i-1] + B * x[i-2] + C) % D;
    }

    char *S = new char[N];

    S[0] = S1;
    S[1] = S2;
    for (int i = 2; i < N; i++)
    {
        S[i] = (char)(97 + (x[i] % 26));
    }

    *p_dict = dict;
    *p_S = S;
}
