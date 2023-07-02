#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

struct Chute{
    int x, e;

    Chute(int chute, int erro): x(chute), e(erro){}

    bool operator < (const Chute &chute){
        return chute.x > x;
    }
};

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    vector<Chute> chutes(N, {0, 0});

    for (int i = 0; i < N; i++)
    {
        cin >> chutes[i].x;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> chutes[i].e;
    }

    sort(ALL(chutes));

    map<ll, ll> contagem;

    ll ans = -1;

    ll chute1 = chutes[0].x - chutes[0].e;

    for(auto chute : chutes){
        ll ch1 = chute.x - chute.e;
        ll ch2 = chute.x + chute.e;

        if(ch1 > 0 ){
            contagem[ch1]++;
            ans  = max(ans, contagem[ch1]);
        }

        if(ch2 > 0){
            contagem[ch2]++;
            ans  = max(ans, contagem[ch2]);
        }
    }
    
    for(auto mapa : contagem){
        if(ans == 1){
            if(mapa.second == 1){
                cout << mapa.first << " = " << mapa.second <<  endl;
            }
        }else {
            if(mapa.second >= ans){
                cout << mapa.first << " = " << mapa.second <<  endl;
            }
        }
        
    }

    return 0;
}