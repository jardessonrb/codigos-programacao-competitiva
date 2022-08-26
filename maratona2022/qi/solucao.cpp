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
int ans = 0;

void completar(string &s1, string &s2){
    for (int i = s1.size() - 1; i < s2.size() - 1; i++)
    {
        s1[s1.size()] = s2[i];
        ans++;
    }
    
}

void remover(string &s1, string &s2){
    
}
int main(int argc, char const *argv[]){
    optimize;

    string s1, s2;

    cin >> s1 >> s2;
    if(s1.size() <= s2.size()){
        completar(s1, s2);
        cout << s1 << " " << s2 << endl;
    }else{
        remover(s1, s2);
    }

    cout << ans << endl;

    return 0;
}