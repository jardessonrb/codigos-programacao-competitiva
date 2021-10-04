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
int N;
int main(int argc, char const *argv[]){
    optimize;

    cin >> N;
    map<string, int> jogadas;

    while(N--){
        string jogador;
        cin >> jogador;

        jogadas[jogador]++;
    }

    if(jogadas["L"] > jogadas["Kira"]){
        cout << "L eh melhor que Kira!!!" << endl;
    }else{
        cout << "Kira eh melhor que L!!!" << endl;
    }
    return 0;
}