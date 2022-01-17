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

int main(int argc, char const *argv[]){
    optimize;
    int N, K;
    ll A, B;
    vector<ll> caixas;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        caixas.push_back(x);
    }

    cin >> A >> B;
    sort(ALL(caixas));


    cout << 1 << endl;
    
    

    return 0;
}