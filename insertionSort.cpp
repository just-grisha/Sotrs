#include<iostream> 
#include<stdio.h> 
#include <cmath> 
#include <cstring> 
#include<string> 
#include <vector> 
#include<algorithm>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    long long dur = 0;
    ofstream fout("output.txt");
    for (int k = 1; k <= 1000; k++) {
        int* arr = new int[10000000];
        for (int i = 0; i < 10000000; i++) {
            arr[i] = rand();
        }
        auto arr_size = 10000000;

        auto start = high_resolution_clock::now();

        insertionSort(arr, arr_size);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        dur += duration.count();

        fout << k << " Ïîïûòêà " << duration.count() << "Ìèêðîñåê" << endl;
        cout << k << " Ïîïûòêà " << duration.count() << " Ìèêðîñåêóíä" << endl;

        delete[] arr;
    }