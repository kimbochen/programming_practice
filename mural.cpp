#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solveProb(void);

int main(void)
{
    int T, y;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        y = solveProb();

        cout << "Case #" << i+1 << ": " << y << '\n';
    }

    return 0;
}

int solveProb(void)
{
    int N;
    string int_str;

    cin >> N >> int_str;

    vector<int> score;

    score.reserve(N);

    for (auto c : int_str)
    {
        score.emplace_back(c-'0');
    }

    //for (auto i : score) cout << i << ' ';
    //cout << '\n';

    int max_score = 0;

    //cout << "Initial addition: ";
    for (int i = 0; i < (N+1)/2; i++)
    {
        max_score += score[i];

        //cout << score[i] << ' ';
    }
    //cout << ", sum = " << max_score << "\n\n";

    int j;

    for (int i = (N+1)/2, new_score = max_score; i < N; i++)
    {
        j = i - (N+1)/2;

        //printf("%i", new_score);

        new_score += score[i] - score[j];

        //printf(" - score[%i](%i) + score[%i](%i) = %i, ",
        //        j, score[j], i, score[i], new_score);

        max_score = max(max_score, new_score);

        //printf("max_score = %i\n", max_score);
    }

    return max_score;
}
