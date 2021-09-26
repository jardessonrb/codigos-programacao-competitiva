#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N, sum = 0;
long double values[MAXN], tree[4 * MAXN];

void build(int no, int l, int r)
{
    if(l == r)
    {
        tree[no] = values[l];
        return;
    }

    int e = 2 * no;
    int d = e + 1;
    int m = (l + r)/2;

    build(e, l, m);
    build(d, m+1, r);

    tree[no] = tree[e] + tree[d];
}


int main(int argc, char const *argv[]){
    optimize;

    cin>> N;

    int x, y;
    double dis;
    
    for (int i = 1; i <= N; ++i)
    {
        cin >> x >> y;

        dis = sqrt((x*x)+(y*y));
        
        values[i] = dis;

    }


    // for (int i = 1; i <= N; ++i)
    // {
    //     cout << values[i] << endl;
    // }
    // cout << " \n" << endl;

    build(1 , 1 , N);

    // for (int i = 1; i <= 11; ++i)
    // {
    //     cout << tree[i] << endl;
    // }


    cout << sum << endl;

    return 0;
}