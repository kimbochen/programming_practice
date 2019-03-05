#include <iostream>
#include <string>
#include <vector>
#define MAXSIZE 1e3+1

using vi = std::vector<int>;
using vvi = std::vector<vi>;

bool solveProb(vvi&);

int main(void)
{
    vvi matrix;

    if (solveProb(matrix) == true)
    {
        std::cout << "YES\n";

        for (int i = 0, n = matrix.size(); i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << matrix[i][j] << "\n "[j < n-1];
            }
        }
    }
    else std::cout << "NO\n";

    return 0;
}

bool solveProb(vvi &matrix)
{
    int n, a;

    std::cin >> n;

    matrix.resize(n, vi(n,0));

    vi freq(n, 0);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        freq[a] ++;
    }

    if (n % 2 == 0)
    {
        for (int i = 0, k = 0, m = n/2; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (freq[k] != 0)
                {
                    if (freq[k] % 4 == 0)
                    {
                        matrix[i][j] = matrix[m-1-i][m-1-j] = freq[k];
                        matrix[m-1-i][j] = matrix[i][m-1-j] = freq[k];
                        k ++;
                    }
                    else return false;
                }
            }
        }
    }

    return true;
}
