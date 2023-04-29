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
    //Refazer
    int n;

    cin >> n;
    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i < 46; i++)
    {
        fibo.push_back(fibo[i-1] + fibo[i-2]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << fibo[i] << ((i + 1) < n ? " " : "");
    }
    cout << endl;
    
    return 0;
}