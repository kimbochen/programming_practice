#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>&, int, int);

void merge(vector<int>&, int, int, int);

int main(void)
{
    vector<int> A;
    int x;

    while (cin >> x)
    {
        A.emplace_back(x);
    }

    merge_sort(A, 0, A.size()-1);

    for (auto e : A) cout << e << ' ';
    cout << '\n';

    return 0;
}

void merge_sort(vector<int>& A, int lf, int rt)
{
    if (lf < rt)
    {
        int md = lf + (rt - lf) / 2;

        merge_sort(A, lf, md);
        merge_sort(A, md + 1, rt);
        merge(A, lf, md, rt);
    }
}

void merge(vector<int>& A, int start, int md, int end)
{
    int i = start, j = md + 1;
    vector<int> sublist;

    while (i <= md && j <= end)
    {
        if (A[i] < A[j])
            sublist.emplace_back(A[i++]);
        else
            sublist.emplace_back(A[j++]);
    }

    while (i <= md) sublist.emplace_back(A[i++]);

    while (j <= end) sublist.emplace_back(A[j++]);

    copy(sublist.begin(), sublist.end(), A.begin() + start);
}
