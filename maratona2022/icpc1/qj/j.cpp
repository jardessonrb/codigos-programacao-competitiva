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
vector<int> soma;
vector<int> joga;
int n, k;

void calc(int inicio, int fim, int jogada){
    if(fim >= joga.size()) return;
    int ans = 0;
    cout << "jogada " << jogada << " inicio " << inicio << " fim " << fim << endl;
    while(inicio < fim){
        if(joga[inicio] - joga[inicio + 1] <= k){
            ans++;
            inicio += 2;

            if(inicio == fim) break;
        }else {
            inicio++;
        }
    }

    soma.push_back(soma[soma.size() - 1] + ans);

    calc(inicio, pow(2, jogada + 1), (jogada+1));
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> n >> k;
    int qnt = pow(2, n);
    soma.push_back(0);

    for (int i = 0; i < qnt; i++)
    {
       int j;
       cin >> j;
       joga.push_back(j);
    }
    sort(joga.begin(), joga.end());
    reverse(joga.begin(), joga.end());

    int pausa = 2;
    int ans = 0, p = 1;
    for (int i = 0; i < qnt; i++)
    {
        if(joga[i] - joga[i + 1] <= k){
            ans++;
            i++;
            continue;
        }else {
            if(i + 1 == pow(2, p) - 1){
                soma.push_back(soma.back() + ans);
                p++;
            }
            continue;
        }
    }
    
    // calc(0, 2, 1);
    for(auto x : soma) ans += x;

    cout << ans << endl;

    return 0;
}

/*
3 2
20
14
10
6
4
3
2
1

== 2

2 5
9
1
6
4
== 3

2 2
9
1
6
4

== 1
*/