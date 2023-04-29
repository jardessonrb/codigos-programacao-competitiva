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

bool isPrimo(int x){
   
    double raiz = sqrt(x);
    
    for (int i = 2; i <= raiz; i++)
    {
        if(x % i == 0) return false;
    }
    
    return true;
}

int main(int argc, char const *argv[]){
    optimize;

    int n;

    cin >> n;
    while(n--){
        int x;

        cin >> x;

        cout << x << (isPrimo(x) ? " eh primo" : " nao eh primo") << endl;
    }
    

    return 0;
}