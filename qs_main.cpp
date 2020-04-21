#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

int partition(int *numbers, int left, int right)
{
    int pivot = numbers[(left + right) / 2];
    int i = left - 1, j = right + 1;

    while (true)
    {
        do
        {
            i++;
        } while (numbers[i] < pivot);
        do
        {
            j--;
        } while (numbers[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(numbers[j], numbers[i]);
    }
}

void sort(int *numbers, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(numbers, left, right);

        sort(numbers, left, pivot);
        sort(numbers, pivot + 1, right);
    }
}

void quickSort(int *numbers, int array_size)
{
    sort(numbers, 0, array_size - 1);
}

int main()
{
    int *brr;
    int n;

    fstream fin;
    fin.open("input.txt",ios::in);
    if (fin.is_open())
    {
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fin.close();
    }
    quickSort(brr, n);
    fstream fout;
    fout.open("output.txt",ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}