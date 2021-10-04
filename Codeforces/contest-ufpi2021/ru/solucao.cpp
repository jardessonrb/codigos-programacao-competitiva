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

int N, Q;
ll bit[MAXN];

void add(int pos, int val)
{
    for(; pos < MAXN; pos +=(pos & -pos))
    {
        bit[pos]+=val;
    }
}


int query(int pos)
{
    int ans = 0;

    for(; pos > 0; pos -=(pos & -pos))
    {
        ans += bit[pos];
    }
    
    return ans;
}


int main(int argc, char const *argv[]){
    optimize;

    map<int, int> pratos;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        bit[i] = 0;
    }
    
    int op, p, a, b;
    while(Q--){

        cin >> op;
        if(op == 1){
            cin >> p;
            add(p, 1);
        }else{

            cin >> a >> b;
            cout << query(b) - query(a-1) << endl;
        }
    }
    

    return 0;
}