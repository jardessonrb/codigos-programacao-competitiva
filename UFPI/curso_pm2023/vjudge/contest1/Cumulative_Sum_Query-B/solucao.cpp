#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    vector<int> array(N + 1, 0), prefix(N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> array[i];

    for (int i = 1; i <= N; i++)
    {
        prefix[i] = prefix[i - 1] + array[i];
    }

    int Q;

    cin >> Q;

    while(Q--){
        int i, j;

        cin >> i >> j;

        int minI = min(i, j);
        int maxJ = max(i, j);

        cout << prefix[maxJ + 1] - prefix[minI] << endl;
    }
    

    return 0;
}