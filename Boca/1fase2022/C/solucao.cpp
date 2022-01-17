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

long long pot(long long n, int vzs) {
    if(vzs == 0) return 1;
    long long res = n;
    for(int i = 1; i < vzs; i++) res *= n;
    return res;
}

int main(int argc, char const *argv[]){
    optimize;

    long long base;
    int alg;
    cin >> base >> alg;
    vector<pair<int,int>> num(alg);

    int sRestos = 0;
    for(int i = 0; i < alg; i++) {
        cin >> num[i].first;
        num[i].second = (num[i].first * pot(base, alg-(i+1))) % (base+1);
        sRestos += num[i].second;
    }

    sRestos %= base+1;

    if(sRestos == 0) {
        cout << "0 0" << endl;
        return 0;
    }

    for(int i = 0; i < alg; i++){
        while(num[i].first > 0) {
            num[i].first--;
            int novoR = (num[i].first * pot(base, alg-(i+1))) % (base+1);
            if((novoR - num[i].second + sRestos) % (base+1) == 0) {
                cout << i+1 << " " << num[i].first << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}