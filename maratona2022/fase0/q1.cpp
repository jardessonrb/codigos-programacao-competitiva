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

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(int argc, char const *argv[]){
    optimize;

    int a, b, c;

    cin >> a >> b >> c;

    int mili = a * c;

    double litros = mili / 1000.0;

    double quantidade = b - litros;

    if(quantidade >= 0){
        cout << b << endl;
    }else {
        int i = 2;
        int q = b * i;
        while(litros > q){
            q = b * i;
            i++;
        }

        cout << q << endl;
    }

    return 0;
}