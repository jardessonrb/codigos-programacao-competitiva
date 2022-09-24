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
map<string, int> mapa;

int calc(ll c){ 
    string chave = to_string(c);
    if(mapa[chave] != 0){
        return mapa[chave];
    }
    
    int ans = 0;
    int cont = 0;
    int i = 2;
    int j = 1;
    while(cont < c){
        cont += (i + j);
        ans = (i / 2);
        i += 2;
        j++;

        mapa[to_string(cont)] = ans;

        if((cont + i) > c){
            mapa[to_string(cont)] = ans;
            break;
        }

    }

    mapa[chave] = ans;

    return ans;
}

int main(int argc, char const *argv[]){
    optimize;

    int T;

    cin >> T;

    while(T--){
        ll C;
        cin >> C;

        cout << calc(C) << endl;
    }

    return 0;
}