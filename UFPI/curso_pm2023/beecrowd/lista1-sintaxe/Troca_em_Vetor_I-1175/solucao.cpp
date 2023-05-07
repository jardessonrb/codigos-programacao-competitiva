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

int main(int argc, char const *argv[]){
    optimize;
    int VALUES = 20;
    int array[VALUES];

    for (int i = 0; i < VALUES; i++)
    {
       cin >> array[i];
    }

    for (int i = 0; i < VALUES; i++)
    {
        cout << "N["<< i <<"] = " << array[VALUES - i - 1] << endl;
    }
    
    
    

    return 0;
}