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

int N, K;

char cartas[] = {'A','2','3', '4', '5', '6', '7', '8', '9', 'D', 'Q', 'J', 'k'};

map<int, bool> vez;

bool equals(int j)
{
	char carta = jogador[j][0];

	for (int i = 1; i < 4; ++i)
	{
		if(carta != jogador[j][i]) return false;
	}

	return true;
}


int menorIndice(int j)
{
	for (int i = 0; i < 13; ++i)
	{
		if(cartas[j] == cartas[i])
			return i;
	}
}


int main(int argc, char const *argv[]){
    optimize;

    cin>> N >> K;

    char jogador[N][5];
     vez[K] = false;
    
    for (int i = 1; i <= N; i++)
    {
    	for(int j = 0; j <= 3; j++)
    	{
    		cin>>jogador[i][j];
    	}
    }

    while(true)
    {
    	if(equals(K) == true && vez[K] != false)
    	{
    		break;
    	}
    	else
    	{

    	}
    }


    cout << K <<endl;

    return 0;
}