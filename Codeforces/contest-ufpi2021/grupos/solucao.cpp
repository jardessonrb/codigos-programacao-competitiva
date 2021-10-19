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

long pai[10000000], N;
int ans = 0;
long sz[10000000];

vector<int> conjuntos[1000000];

int find(int x){

    if(x == pai[x]) return x;

    return pai[x] = find(pai[x]);
}

void join(int u, int v){

    u = find(u);
    v = find(v);

    if(u == v) return;

    if(sz[u] > sz[v])
        swap(u, v);
        ans--;

    sz[v] += sz[u];
    sz[u] = 0;

    pai[u] = v;
}


int main(int argc, char const *argv[]){
    optimize;

    int N, Q;

    cin >> N >> Q;
    ans = N;

    for(int i = 1 ; i <= N; i++)
    {
        pai[i] = i;
        sz[i] = 1;
    }

    while(Q--){
        int op, a , b;
        cin >> op;

        if(op == 1){
            cin >> a >> b;
            join(a, b);
        }else{
            cout << ans << endl;
        }
    }
    

    return 0;
}