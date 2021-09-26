#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100000005
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;
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

// int plusVal(int pos, int val)
// {
//     return bit[pos] += val;
// }

// int sum(int x, int y, int z)
// {
//     int ans = 0;

//     for (int i = x; i < y; i++)
//     {
//         ans += bit[x];
//     }

//     //cout<<"ANS: "<<ans<<"ANS MODULO(X)"<<modulo(ans)<<endl;
    
//     return ans;
// }

// int decrease(int pos, int val)
// {
//     if(bit[pos] - val < 0) return bit[pos];

//     else return bit[pos] -= val;
// }

int main(int argc, char const * argv[]){
    optimize;
    int n, m, q;
    cin>>n>>m;

    for(int i = 1; i <= n; i++)
    {
        cin>>bit[i];
    }

    cin>>q;

    char esc;
    while(q--)
    {
        cin>>esc;
        int x, y, z, pos, val;

        switch(esc)
        {
            case 's':
                cin>>x>>y>>z;
                cout<<sum(x, y, z)<<endl;
                break;

            case '+':
                cin>>pos>>val;
                cout<<plusVal(pos, val)<<endl;
                break;
            
            case '-':
                cin>>pos>>val;
                cout<<decrease(pos, val)<<endl;
                break;

            default:
                break;
        }
    }

    

    return 0;
}