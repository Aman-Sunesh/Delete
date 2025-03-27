#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "data.h"

using namespace std;

int findPivotIndex(int l, int r)
{
    return (l + r) / 2;
}

void quickSort(vector<Data>& A, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int pivotIndex = findPivotIndex(l, r);
    Data pivot = A[pivotIndex];

    swap(A[pivotIndex], A[r]);

    int i = l;

    for (int j = l; j < r; j++)
    {
        if (A[j] < pivot)
        {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[r]);

    quickSort(A, l, i - 1);
    quickSort(A, i + 1, r);
}

vector<Data> generateData(int n)
{
    vector<Data> v;
    v.reserve(n);

    for (int i = 0; i < n; i++)
    {
        v.push_back(Data(i));
    }
    return v;
}

void testPrintArrays() // Call this function in main.cpp if you want to see the actual sorted values
{
    for (int n = 2; n <= 1024; n *= 2)
    {
        vector<Data> original = generateData(n);

        cout << "Array size " << n << " - Original array:" << endl;

        for (size_t i = 0; i < original.size(); i++)
        {
            cout << original[i].getUnweighted() << " ";
        }

        cout << endl;

        vector<Data> sorted = original;
        quickSort(sorted, 0, sorted.size() - 1);

        cout << "Array size " << n << " - Sorted array:" << endl;

        for (size_t i = 0; i < sorted.size(); i++)
        {
            cout << sorted[i].getUnweighted() << " ";
        }

        cout << "\n\n";
    }
}


void test() 
{
    for (int n = 2; n <= 1024; n *= 2) {
        vector<Data> original = generateData(n);

        vector<Data> quickSorted = original;
        vector<Data> stdSorted = original;
        
        quickSort(quickSorted, 0, quickSorted.size() - 1);
        sort(stdSorted.begin(), stdSorted.end());
        
        bool passed = true;
        for (int i = 0; i < n; i++) 
        {
            if (quickSorted[i].getUnweighted() != stdSorted[i].getUnweighted()) 
            {
                passed = false;
                break;
            }
        }

        if (passed) 
        {
            cout << "Size " << n << ": Test PASSED." << endl;
        } 
        
        else 
        {
            cout << "Size " << n << ": Test FAILED." << endl;
        }
    }
}


int main()
{
    test();
    cout << endl << endl;

    cout << left << setw(10) << "n" << setw(15) << "mysort" << setw(12) << "std::sort" << endl;
    cout << "===================================" << endl;

    for (int n = 2; n <= 8192; n *= 2)
    {
        vector<Data> v = generateData(n);
        Data::comparison_count = 0;

        vector<Data> copy1 = v;
        vector<Data> copy2 = v;

        Data::comparison_count = 0;
        quickSort(copy1, 0, copy1.size() - 1);
        long quickSortComparisons = Data::comparison_count;

        Data::comparison_count = 0;
        sort(copy2.begin(), copy2.end());
        long stdSortComparisons = Data::comparison_count;

        cout << left << setw(10) << n << setw(15) << quickSortComparisons << setw(12) << stdSortComparisons << endl;
    
        // My algorithm does fewer comparisons for n from 2-8192. However, if you start increasing n greater than 8192, 
        // std::sort eventually starts using fewer number of comparisons to sort the elements of the vector.
    }

    return 0;
}