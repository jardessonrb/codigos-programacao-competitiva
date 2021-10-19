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
int N, M;

vector<int> ilhas[100001];

bool verifica(int i, int j)
{
    for(auto it : ilhas[i])
    {
        if(it == j) return true;
    }

    return false;
}

void criaPonte(int i, int j)
{
    ilhas[i].push_back(j);
    ilhas[j].push_back(i);
}

int main(int argc, char const * argv[]){
    optimize;

    cin>>N>>M;

    int T,A,B;
    for (int i = 1; i <= M; i++)
    {
        cin>>T>>A>>B;

        if(T == 0)
        {
            cout<<(verifica(A, B) ? 1 : 0)<<endl;
        }
        else criaPonte(A, B);
    }
    
    return 0;
}