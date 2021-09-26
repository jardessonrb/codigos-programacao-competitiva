#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

ll tree[4 * MAXN], vetor[MAXN], N, M;


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
    build(d, m + 1, r);


    tree[no] = tree[e] + tree[d]; 
}

ll query(int no, int l, int r, int a, int b)
{
    if(b < l or r < a) return 0;

    if(a <= l && r <= b) return tree[no];

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r)/2;

    return query(e, l, m, a, b) + query(d, m+1, r, a, b);
    
}

void setElement(int no, int l, int r, int i, int v)
{
    if(i < l or i > r) return;

    if(l == r)
    {
        tree[no] = v;
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r)/2;

    setElement(e, l, m, i, v);
    setElement(d, m+1, r, i, v);

    tree[no] = tree[e] + tree[d];
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> vetor[i];
    }

    build(1, 1, N);

    // for(int i = 1; i <= 10; i++)
    // {
    //     cout << tree[i] << " ";
    // }
    // cout << '\n' << endl;

    int p, q, opcao;
    while(M--)
    {
        cin >> opcao >> p >> q;

        if(opcao == 1)
        {
            setElement(1, 1, N, p+1, q);
            
        }else
        {
            cout << query(1, 1, N, p+1, q) << endl;
        }
        
    }
    

    return 0;
}