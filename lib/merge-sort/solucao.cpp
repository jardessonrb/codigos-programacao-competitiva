#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void merge(int array[], int inicio, int meio, int fim){
    int maxIndexArray1 = meio - inicio + 1;
    int maxIndexArray2 = fim - meio;

    int arrayTemp1[maxIndexArray1], arrayTemp2[maxIndexArray2];
    
    for (int i = 0; i < maxIndexArray1; i++)
        arrayTemp1[i] = array[inicio + i];

    for (int j = 0; j < maxIndexArray2; j++)
        arrayTemp2[j] = array[meio + 1 + j];
    
    int i = 0, j = 0, k = inicio;

    while(i < maxIndexArray1 && j < maxIndexArray2){
        if(arrayTemp1[i] <= arrayTemp2[j]){
            array[k] = arrayTemp1[i];
            i++;
        }else {
            array[k] = arrayTemp2[j];
            j++;
        }
        k++;
    }

    while(i < maxIndexArray1){
        array[k] = arrayTemp1[i];
        i++;
        k++;
    }

    while(j < maxIndexArray2){
        array[k] = arrayTemp2[j];
        j++;
        k++;
    }
}


void mergeSort(int array[], int inicio, int fim){
    if(inicio >= fim) return;

    auto meio = inicio + (fim - inicio) / 2;

    mergeSort(array, inicio, meio);
    mergeSort(array, meio + 1, fim);
    merge(array, inicio, meio, fim);
}

void print(int array[], int size){
    // int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    
}

int main(int argc, char const *argv[]){
    optimize;

    int array[] = {9, 3, 6, 2, 8, 5, 1, 4, 7};

    int size = sizeof(array) / sizeof(array[0]);

    print(array, size);
    mergeSort(array, 0, size - 1);
    cout << endl;
    print(array, size);

    return 0;
}