#include <algorithm>
#include <iostream>
#include <vector>


int hoarePartition(std::vector<int>& A, int p, int r)
{
    int pivot = A[p], i = p - 1, j = r + 1;

    while (true)
    {
        do i++; while (A[i] < pivot);
        do j--; while (A[j] > pivot);

        if (i < j)
            std::swap(A[i], A[j]);
        else
            return j;
    }
}

void quicksort(std::vector<int>& A, int p, int r)
{
    if (p < r) {
        int q = hoarePartition(A, p, r);
        quicksort(A, p, q);
        quicksort(A, q + 1, r);
    }
}

int main(void)
{
    std::vector<int> A;
    int num;

    while (std::cin >> num) {
        A.emplace_back(num);
    }

    quicksort(A, 0, A.size() - 1);

    for (const int& e : A) std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}
