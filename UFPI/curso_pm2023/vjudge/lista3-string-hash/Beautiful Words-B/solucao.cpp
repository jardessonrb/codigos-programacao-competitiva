#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXV 1010
#define ll long long
#define ld long double
#define pii pair<int, int>
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define int long long
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

const int MOD = 1e9 + 3;
const int base = 101;
const int MAXN = 2e5 + 100;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N, M;

struct StringHash {
    vector<int> hashs;
    StringHash(string& input){
        hashs = vector<int>(input.length(), 0);
    }

    int get_hash(int a, int b){

    }
};

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> M;
    string palavra;
    vector<string> pls(M);

    cin >> palavra;
    for (int i = 0; i < M; i++)
        cin >> pls[i];
    


    return 0;
}