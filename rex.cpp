#include <iostream>
#include <vector>

int rex(std::vector<int> &v, int min_sum, int max_sum, int len)
{
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += v[i];
    }

    int num_methods = 0;
    for (int i = len; i < v.size(); ++i) {
        if (sum >= min_sum && sum <= max_sum) {
            num_methods++;
        }
        sum = sum + v[i] - v[i - len];
    }

    return num_methods;
}

int main()
{
    int N, A, B;

    std::cin >> N >> A >> B;

    std::vector<int> num(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> num[i];
    }

    int num_methods = 0;
    for (int i = 1; i < N + 1; ++i) {
        num_methods += rex(num, i * A, i * B, i);
    }

    std::cout << num_methods << '\n';

    return 0;
}

