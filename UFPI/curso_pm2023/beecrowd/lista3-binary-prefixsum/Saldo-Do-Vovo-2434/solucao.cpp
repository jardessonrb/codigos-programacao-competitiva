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
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(int argc, char const *argv[]){
    optimize;

    int N, S;

    cin >> N >> S;
    int array[N + 1];

    for (int i = 1; i <= N; i++)
    {
       cin >> array[i];
    }

    vector<int> prefix_sum(N + 1, 0);

    prefix_sum[0] = S;
    for (int i = 1; i <= N; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + array[i];
    }

    sort(ALL(prefix_sum));

    cout << prefix_sum[0] << endl;

    // for(auto x : prefix_sum)
    //     cout << x << " ";    
    return 0;
}

// 3 1000
// 100
// -800
// 50

// 6 -200
// -100
// 1000
// -2000
// 100
// -50
// 2000