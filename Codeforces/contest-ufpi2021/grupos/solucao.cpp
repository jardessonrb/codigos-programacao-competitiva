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
int N, Q;

struct Aluno{
    int n;
    int grupo;
};

int ans = 0;
map<int, Aluno> alunos;

void adicionar(int a1, int a2){
    if(alunos[a1].grupo == alunos[a2].grupo) return;

    int gp = alunos[a2].grupo;
    for(auto &x : alunos){
        if(x.second.grupo == gp){
            x.second.grupo = alunos[a1].grupo;
        }
    }

    ans--;
}

void mostrar(){
    cout << ans << endl;
}


int main(int argc, char const *argv[]){
    optimize;
    cin >> N >> Q; 
    ans = N;
    for (int i = 1; i <= N; i++)
    {
        Aluno aluno;
        aluno.grupo = i;
        aluno.n = i;
        alunos[i] = aluno;
    }
    
    while(Q--){
        int op;

        cin >> op;

        if(op == 1){
            int a, b;

            cin >> a >> b;
            adicionar(a, b);

        }else{

            mostrar();
        }
    }


    

    return 0;
}