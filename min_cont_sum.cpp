/*
INPUT: A = {} and K
OUTPUT: The minimum size of S such that
S is a contiguous subset of A and sum(S) == K
*/

#include <iostream>
#include <vector>

using namespace std;

int minContSumBruteForce(vector<int>& A, int K)
{
/*
    EXAMPLE:
    A = {2, 1, 3}, K = 6
    All possible S are:
    {2}, {1}, {3}
    {2, 1}, {1, 3}
    {2, 1, 3}

    ALGO:
    * Enumerate all possible S:
        S = {A[i], A[i + 1], ..., A[i + l - 1]}
        l: length of S, l = 1 to n
        i: initial index, i = 0 to n - l
    * Calculate sum of S
    * if sum == K: return l
    * If no possible S, return -1;

    TIME COMPLEXITY:
    For each l, there are (n - l) summations of l elements.
    Therefore, \sum{l = 1}{n} (n - l) * l = O(n ^ 3)
*/
    int n = A.size();

    for (int l = 1; l <= n; l++) {
        for (int i = 0, sum = 0; i <= n - l; i++, sum = 0) {
            for (int j = i; j < i + l; j++) sum += A[j];
            if (sum == K) return l;
        }
    }

    return -1;
}

int minContSum(vector<int>& A, int K)
{
/*
    ALGO:
    * Calculate the prefix sum of A:
        P[0] = A[0]
        P[i] = P[i - 1] + A[i]
        i: index, i = 1 to n - 1
    * Enumerate the sum of all possible S:
        1. sum = P[l - 1]
        2. sum = P[i + l] - P[i]
        l: length of S, l = 1 to n
        i: index, i = 0 to n - l - 1
    * if sum == K: return l
    * if no possible S, return -1;

    TIME COMPLEXITY:
    * Calculate prefix sum takes O(1) for each of the n elements --> O(n)
    * Enumerate all possible S includes \sum{l = 1}{n} (n - l - 1) iterations,
      each iteration take O(1) --> O(n ^ 2)
*/
    int n = A.size() + 1;
    vector<int> P(n);

    P[0] = 0;
    for (int i = 1; i < n; i++) {
        P[i] = P[i - 1] + A[i - 1];
    }

    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            if ((P[i + l] - P[i]) == K) return l;
        }
    }

    return -1;
}

int minContSumBIT(vector<int>& A, int K)
{
}

int main()
{
    vector<int> A;
    int K, a;

    cin >> K;
    while (cin >> a) {
        A.emplace_back(a);
    }

    // cout << minContSumBruteForce(A, K) << '\n';
    // cout << minContSum(A, K) << '\n';
    cout << minContSumBIT(A, K) << '\n';

    return 0;
}
