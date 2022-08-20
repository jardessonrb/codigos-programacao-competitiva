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

int bit[MAXN];

void add(int pos, int val)
{
  
  for( ; pos < MAXN ; pos += (pos & -pos))
  {
    bit[pos]+= val;
  }
  
}

int query(int pos)
{ 
  int ans = 0;
  
  for( ;pos > 0 ; pos -= (pos & -pos))
  {
    ans+=bit[pos];  
  }
  return ans;
}

int main(int argc, char const *argv[]){
    optimize;
    
    int N, M;
    cin >> N >> M;
    ll array[N+10];
    for(int i = 1; i <= N; i++){
        array[i] = i;
    }

    for(int i = 0; i < M; i++){
        char op;
        ll p1, p2;

        cin >> op >> p1 >> p2;
        if(op == 'I'){
            ll q = 0;
            while((p1 + q) < (p2 - q)){
                int pos = p1 + q;
                int vl = array[pos];
                array[pos] = array[p2-q];
                array[p2-q] = vl;
                q++;
            }
        } 
        
        if(op == 'S'){
            ll soma = 0;
            while(p1 <= p2){
                soma += array[p1];
                p1++;
            }

            // cout << query(p2 - 2) - query(p1 - 1) << endl;
            cout << soma << endl;
        }
    }
    

    return 0;
}

