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
    int n, k;

    cin >> n >> k;
    int qnt = pow(2, n);
    vector<int> joga;
    for (int i = 0; i < qnt; i++)
    {
       int j;
       cin >> j;
       joga.push_back(j);
    }
    sort(joga.begin(), joga.end());
    int ans = 0;
  
    if(n > 1){
        int p = 1;
        while(pow(2, p) <= qnt){
            int index = joga.size() - pow(2, p);
            for (int i = joga.size() - 1; i > index; i--)
            {
                if(joga[i] - joga[i - 1] <= k){
                    ans++;
                    i--;
                    if(i == index) break;
                }
            }
            p++;
        }

    }else{
        if((joga[joga.size() - 1] - joga[joga.size() - 2]) <= k) ans++;
    }

    cout << ans << endl;

    return 0;
}