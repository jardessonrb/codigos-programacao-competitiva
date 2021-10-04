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

ll bit[11][MAXN];
int N, M, Q;
ll nums[MAXN];

void add(ll bit[], int p, int v)
{
    for(; p < MAXN; p += (p & -p))
    {
        bit[p] += v;
    }
}

ll sum(ll bit[], int p)
{
    ll ans = 0;

    for(; p; p -= (p & -p))
        ans += bit[p];
    
    return ans;
}

ll query(int l, int r, int m)
{
    return sum(bit[m], r) - sum(bit[m], l - 1);
}

int main(int argc, char const * argv[]){
    optimize;

    cin>> N >> M;

    for(int i = 1; i <= N; i++)
    {
        cin>> nums[i];

        add(bit[nums[i] % M], i, nums[i]);
    }
    
    cin>> Q;

    char op;

    int l, r, m;

    while(Q--)
    {
        cin>> op >> l >> r;

        if(op == 's')
        {
            cin>> m;

            cout << query(l, r, m) <<endl;
        }

        else if(op == '+')
        {
            add(bit[nums[l] % M], l, -nums[l]);

            nums[l] += r;

            add(bit[nums[l] % M], l, nums[l]);

            cout << nums[l] << endl;
        }

        else
        {
            if(nums[l] >= r)
            {
                add(bit[nums[l] % M], l, -nums[l]);

                nums[l] -= r;

                add(bit[nums[l] % M], l, nums[l]);
            }

            cout << nums[l] << endl;
        }
        
    }



    return 0;
}