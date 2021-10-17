#include <iostream>
#include <climits>
#include <vector>


void merge(std::vector<int>& A, int p, int q, int r)
{
    std::vector<int> L(q - p + 2), R(r - q + 1);

    for (int i = 0; i < L.size() - 1; i++) L[i] = A[i + p];
    L[L.size() - 1] = INT_MAX;

    for (int j = 0; j < R.size() - 1; j++) R[j] = A[j + q + 1];
    R[R.size() - 1] = INT_MAX;

    for (int k = p, i = 0, j = 0; k < r + 1; k++)
    {
        if (L[i] < R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void mergeSort(std::vector<int>& A, int p, int r)
{
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main(void)
{
    std::vector<int> A;
    int num;

    while (std::cin >> num) {
        A.emplace_back(num);
    }

    mergeSort(A, 0, A.size() - 1);

    for (const int &e : A) std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}
