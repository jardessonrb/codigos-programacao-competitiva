#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ull unsigned long long 
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int N, Q;

int main(int argc, char const *argv[]){
    optimize;

    cin >> N  >> Q;
    map<ull, string> gamers;
    vector<ull> t;
    while(N--){
        ull point;
        string name;
        cin >> point >> name;
        gamers[point] = name;
        t.push_back(point);
    }

    sort(ALL(t));

    while(Q--){
        int op;
        cin >> op;
        ull v = t[t.size() - op];
        
        cout << gamers[v] << endl;
    }
    

    return 0;
}