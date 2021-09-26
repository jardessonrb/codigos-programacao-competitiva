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
stack<char> nodos;

bool isImpar(int length){
    
    return (length % 2) == 0;
}

int main(int argc, char const *argv[]){
    optimize;

    int C;

    cin >> C;
    while(C--){
        int N;
        string s1, s2, res = "";
        cin >> N >> s1 >> s2;

        if(isImpar(s1.size())){
            nodos.push(s1[0]);

            for(int i = (s1.size()/2) - 1; i >= 1; i--){
                nodos.push(s1[i]);
            }
        }

        while(!nodos.empty()){
            res += nodos.top();
            nodos.pop();
        }

        cout << res << endl;
    }
    

    return 0;
}