#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 2000020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

ll tree[4 * MAXN], vetor[MAXN];

void build(int no, int l, int r)
{
    if(l == r)
    {
        tree[no] = vetor[l];
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r)/2;

    build(e, l, m);
    build(d, m+1, r);

    tree[no] = tree[e] + tree[d];
}

//4 1 2 2 4
ll query(int no, int l, int r, int a, int b) 
{
    if(b < l or r < a) return 0;

    if(a <= l && r <= b) return tree[no];

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r) / 2;
    
    // cout << "E =" << e << " D = "<<d<<" M = " << m <<endl;
    // cout << "Query E = "<< query(e, l, m, a, b) << endl;
    // cout << "Query D = "<< query(d, m + 1, r, a, b) << endl;

    return query(e, l, m, a, b) + query(d, m + 1, r, a, b);
}


int main(int argc, char const *argv[]){
    optimize;
    int N, Q;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        cin >> vetor[i];
    }


    build(1, 1, N);

    // for (int i = 1; i < 15; i++)
    // {
    //     cout << tree[i] << " \n"[i == 14];
    // }

    int a, b;
    while(Q--)
    {
        cin >> a >> b;

        cout << query(1, 1, N, a, b) << endl;        
    }
    

    return 0;
}