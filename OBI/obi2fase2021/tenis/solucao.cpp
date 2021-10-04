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

vector<int> jogadores;

int main(int argc, char const *argv[]){
    optimize;

    for (int i = 0; i < 4; i++)
    {
        int v;
        cin >> v;
        jogadores.push_back(v);
    }

    sort(ALL(jogadores));

    int res1 = (jogadores[0] + jogadores[3]);
    int res2 = (jogadores[1] + jogadores[2]);

    int maior = max(res1, res2);
    int menor = min(res1, res2);

    

    cout << (maior - menor) << endl;
    

    return 0;
}