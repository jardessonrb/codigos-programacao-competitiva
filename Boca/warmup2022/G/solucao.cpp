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


int main() {
    int lin, col, np;
    vector<vector<int>> spec;
    map<string, map<char, int>> palavras;

    cin >> lin >> col;

    char tab[lin][col];

    for(int i = 0; i < lin; i++) {
        cin >> tab[i];
    }

    cin >> np;

    while(np--) {
        string palavra;
        cin >> palavra;
        map<char, int> p;

        for(int i = 0; i < palavra.size(); i++) {
            if(p.find(palavra[i]) == p.end())
                p[palavra[i]] = 0;
            else p[palavra[i]] += 1;
        }

        palavras[palavra] = p;
    }

    //Linha
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            for(auto it = palavras.begin(); it != palavras.end(); it++) {
                if((*it) tab[i][j])
            }
        }
    }

    return 0;
}