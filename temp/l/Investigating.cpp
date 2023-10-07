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
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

const int MOD = 1e6 + 100;
const int base = 101;
const int MAXN = 2e5 + 100;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool lotus[MOD];
vector<int> regs;
int maxima = -1;

struct Sapo {
    int pos;
    
    void upd(int newPos){
        lotus[this->pos] = false;
        lotus[newPos] = true;
        this->pos = newPos;
        regs.push_back(newPos);
    }

    void add(int p){
        this->pos = p;
    }

};


int getLotus(int init, int fim){
    for (int i = init + 1; i <= fim; i++)
    {
        if(!lotus[i]){
            return i;
        }
    }

    maxima++;
    return maxima;
    
}

map<int, Sapo> sapos;
int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    memset(lotus, 0, sizeof(lotus));
    for (int i = 1; i <= N; i++)
    {
        int pos;
        cin >> pos;
        maxima = max(maxima, pos);
        lotus[pos] = true;
        Sapo sapo;
        sapo.add(pos);
        sapos[i] = sapo;
    }

    int saltos;
    cin >> saltos;

    for (int i = 0, sap; i < saltos; i++)
    {
        cin >> sap;

        int pos = getLotus(sapos[sap].pos, maxima);
        sapos[sap].upd(pos);

    }

    for (int i = 0; i < regs.size(); i++)
    {
        cout << regs[i] << endl;
       
    }

    return 0;
}