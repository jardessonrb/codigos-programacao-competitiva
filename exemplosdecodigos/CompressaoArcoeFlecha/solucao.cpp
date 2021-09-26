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

int N, arvore[4 * MAXN];
ll dist[MAXN];



int query(int no, int l, int r, int a, int b) 
{
    if(b < l or r < a) return 0;

    if(a <= l && r <= b) return arvore[no];

    int m = (l + r) / 2;
    int e = 2 * no;
    int d = e + 1;

    return query(e, l, m, a, b) + query(d, m + 1, r, a, b);
}


void update(int no, int l, int r, int p, int v)
{
    if(p < l or p > r) return;

    if(l == r) return void(arvore[no] += v);

    int m = (l + r) / 2;
    int e = 2 * no;
    int d = e + 1;

    update(e, l, m, p, v);
    update(d, m + 1, r, p, v);


    arvore[no] = arvore[e] + arvore[d];
}

int main(int argc, char const *argv[]){
    optimize;
    cin >> N;

    map<ll, int> mapa;

    for (int i = 0, x, y; i < N; i++)
    {
        cin >> x >> x;  
        dist[i] = (1LL * x * x) + (1LL * y * y);   

        mapa[dist[i]] = 0;
    }

    int i = 1;
    for(auto x : mapa)
    {
        mapa[x.first] = i++;
    }

    ll ans = 0;

    for(i = 0; i < N; i++)
    {
        ans += query(1, 1, N, 1, mapa[dist[i]]);

        update(1, 1, N, mapa[dist[i]], 1);
    }  


    cout << ans << endl;    

    return 0;
}