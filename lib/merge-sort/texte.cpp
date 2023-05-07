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
    int maxArray1 = meio - inicio + 1; //basicamento vai do inicio ao meio. exemplo 0 a 10 aí (5 - 0 + 1) = 6 ou seja 0 até < 6
    int maxArray2 = fim - meio; //segue a mesma ideia, so que (10 - 5) = 5 vai de 0 até < 5, no final 4 + 5 = 9 o index maximo

    int arrayTemp1[maxArray1], arrayTemp2[maxArray2]; //Cria dois array temporários para armazenar os sub arrays ordenados;

    for (int i = 0; i < maxArray1; i++)
        arrayTemp1[i] = array[inicio + i];
    for (int j = 0; j < maxArray2; j++)
        arrayTemp2[j] = array[meio + 1 + j];
    
    int right = 0, left = 0, indexInicio = inicio;

    while(right < maxArray1 && left < maxArray2)
    {
        if(arrayTemp1[right] < arrayTemp2[left]){
            array[indexInicio] = arrayTemp1[right];
            right++;
        }else {
            array[indexInicio] = arrayTemp2[left];
            left++;
        }
        indexInicio++;
    }

    while(right < maxArray1){
        array[indexInicio] = arrayTemp1[right];
        right++;
        indexInicio++;
    }

    while(left < maxArray2){
        array[indexInicio] = arrayTemp2[left];
        left++;
        indexInicio++;
    }
}

void mergeSort(int array[], int inicio, int fim){
    if(inicio >= fim) return;

    int meio = inicio + (fim - inicio) / 2;
    mergeSort(array, inicio, meio);
    mergeSort(array, meio + 1, fim);
    merge(array, inicio, meio, fim);

}

int main(int argc, char const *argv[]){
    optimize;

    int array[] = {9, 3, 6, 2, 8, 5, 1, 4, 7};
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    mergeSort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    

    return 0;
}