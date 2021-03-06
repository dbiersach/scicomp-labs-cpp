#include "stdafx.h"

using namespace std;

template <typename T> size_t MedianOfThree(T &a, T &b, T &c,
        size_t ai, size_t bi, size_t ci)
{
    // Implement your code here
    return ci;
}

template <typename T> size_t QuicksortPartition(vector<T> &A, size_t lo, size_t hi)
{
    size_t ci = (int)(0.5*(lo + hi) + 0.5);
    size_t pivotIndex = MedianOfThree(A[lo], A[ci], A[hi], lo, ci, hi);
    T pivot = A[pivotIndex];

    size_t i = lo;
    size_t j = hi;
    while (true)
    {
        while (A[i] <= pivot && i < pivotIndex)
            i++;
        while (A[j] >= pivot && j > pivotIndex)
            j--;
        if (i == pivotIndex && j == pivotIndex)
            return pivotIndex;

        T tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;

        if (i == pivotIndex)
            pivotIndex = j;
        else if (j == pivotIndex)
            pivotIndex = i;
    }
}

template <typename T> void Quicksort(vector<T> &A, size_t lo, size_t hi)
{
    if (lo < hi)
    {
        size_t p = QuicksortPartition<T>(A, lo, hi);
        if (p > 0)
            Quicksort<T>(A, lo, p - 1);
        Quicksort<T>(A, p + 1, hi);
    }
}

template <typename T> void Quicksort(vector<T> &A)
{
    if (A.size() <= 1)
        return;
    Quicksort(A, 0, A.size() - 1);
}


int main()
{
    seed_seq seed{ 2016 };
    default_random_engine generator{ seed };
    uniform_int_distribution<> distribution(1, 10);

    vector<int> nums(100000,5);

    for(size_t i{}; i < 20; i++)
        nums.at(i) = distribution(generator);

    auto startTime = chrono::steady_clock::now();

    Quicksort(nums);

    auto endTime = chrono::steady_clock::now();

    auto totalTime = duration_cast<chrono::milliseconds>
                     (endTime - startTime).count();

    cout.imbue(std::locale(""));
    cout << "Total run time (ms): "
         << totalTime << endl;

    cout << endl << "First twenty elements:" << endl;
    for(int i=0; i < 20; i++)
        cout << nums.at(i) << " ";
    cout << endl;

    cout << endl << "Last twenty elements:" << endl;
    for(int i=20; i > 0; i--)
        cout << nums.at(nums.size()-i) << " ";
    cout << endl;

    return 0;
}

