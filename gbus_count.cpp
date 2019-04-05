#include <iostream>
#include <sstream>

#define SIZE 5000

using namespace std;

// Binary Indexed Tree: point update: O(lg N), range sum: O(lg N)
class BIT
{
public:
    // Udpates i-th element of the original array
    void update(int i, int delta)
    {
        while (i <= SIZE)
        {
            arr[i] += delta;
            i += i & -i;
        }
    }

    // Returns the sum of the first i elements
    int rangeSum(int i)
    {
        int sum = 0;

        while (i > 0)
        {
            sum += arr[i];
            i -= i & -i;
        }

        return sum;
    }

private:
    // Stores the original array in a special way
    int arr[SIZE] = { 0 };
};

// Stores the frequency of all cities
class Freq
{
public:
    // Increment the frequency of cities from A to B
    void add(int A, int B)
    {
        // Increment the frequency by 1 for cities starting from A
        bit.update(A, 1);
        
        // Decrement the frequency by 1 for cities after B
        bit.update(B+1, -1);
    }

    // Returns the frequency of i-th city
    int query(int i)
    {
        return bit.rangeSum(i);
    }

private:
    BIT bit;
};

// Deals with the problem
void gBusCount(void);

// Solves one case
void solveCase(stringstream&);

int main(void)
{
    gBusCount();

    return 0;
}

void gBusCount(void)
{
    int T;
    stringstream ss;

    cin >> T;

    // Loop through T testcases
    for (int i = 0; i < T; i++)
    {
        ss << "Case #" << i+1 << ':';

        solveCase(ss);

        ss << '\n';

        cin.ignore();
    }

    cout << ss.str();
}

void solveCase(stringstream &ss)
{
    int N, A, B;
    Freq freq;

    cin >> N;

    // Loop through N gBuses
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;

        // Add the frequencies of cities from A to B
        freq.add(A, B);
    }

    int P, C;

    cin >> P;

    // Loop through P cities
    for (int i = 0; i < P; i++)
    {
        cin >> C;

        // Return the frequency of city C
        ss << ' ' << freq.query(C);
    }
}
