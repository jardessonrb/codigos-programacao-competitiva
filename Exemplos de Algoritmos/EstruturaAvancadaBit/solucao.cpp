
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 200020
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

int bit[MAXN], N;

/*
Estrutura avançada BIT
*/

//Função de adicionar
void add(int pos, int val)
{
  
  for( ; pos < MAXN ; pos += (pos & -pos))
  {
    bit[pos]+= val;
  }
  
}

//Função de mudar valores
int query(int pos)
{ 
  int ans = 0;
  
  for( ;pos > 0 ; pos -= (pos & -pos))
  {
    ans+=bit[pos];  
  }
  return ans;
}

int main(int argc, char const *argv[])
{
	optimize;
  
  while ((cin >> N) && N!=0){
    for(int i = 0; i <= N; i++) bit[i] = 0;
    
    int ans = 0;
    for(int i = 0, x; i < N; i++)
    {
      cin >> x;
      
      ans += query(N) - query(x - 1);
      add(x, 1);
    }
    
    cout << (ans % 2 ? "Marcelo" : "Carlos") << endl;
  }
  
	return 0;
}

