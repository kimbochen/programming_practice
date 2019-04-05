#include <algorithm>
#include <iostream>
#include <vector>

// training time = max(list) * P - sum(list)
// max(list) = prefsum[i] - prefsum[i-1]
// sum(list) = prefsum[i] - prefsum[i-P]
// preset: prefsum[0] = 0

void solve(int);

int main()
{
    int T;

    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i+1);
    }
    
    return 0;
}

void solve(int t)
{
    int N, P;

    std::cin >> N >> P;

    std::vector<int> s(N), prefsum(N+1);

    for (auto& e : s) std::cin >> e;

    std::sort(s.begin(), s.end());

    prefsum[0] = 0;

    for (int i = 1, m = N+1; i < m; i++)
    {
        prefsum[i] = s[i-1] + prefsum[i-1];
    }

    int min_train_time = 10001;

    for (int i = P, m = N+1; i < m; i++)
    {
        int max_skill, sum_skill, train_time;

        max_skill = prefsum[i] - prefsum[i-1];
        sum_skill = prefsum[i] - prefsum[i-P];
        train_time = max_skill * P - sum_skill;

        if (min_train_time > train_time)
            min_train_time = train_time;
    }

    std::cout << "Case #" << t << ": ";
    std::cout << min_train_time << std::endl;
}
