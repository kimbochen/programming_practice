// https://codeforces.com/contest/1399/problem/A

#include <algorithm>
#include <iostream>
#include <vector>

void remove_smallest() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int &ai : a) {
        std::cin >> ai;
    }

    std::sort(a.begin(), a.end());

    bool remove_to_one = true;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > 1) {
            remove_to_one = false;
            break;
        }
    }
    
    std::cout << (remove_to_one ? "YES" : "NO") << '\n';
}

int main(void) {
    int t;
    std::cin >> t;

    for (int ti = 0; ti < t; ti++) {
        remove_smallest();
    }

    return 0;
}
