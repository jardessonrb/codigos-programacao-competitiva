#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 1000010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int arvore[4 * MAXN], N , Q, nums[MAXN];

void build(int no, int l, int r)
{
    //Nó folha
    if(l == r)
    {
        arvore[no] = nums[l];
        return;
    }


    //Filho esquerdo e filho direito
    int esquerdo = (2 * no); 
    int direito  = esquerdo + 1;
    int intervalo = (l + r)/2; //meio do vetor

    build(esquerdo, l, intervalo);
    build(direito, intervalo + 1, r);

    //Junta as informações dos dois filhos, esquerdo e direito.
    //aqui que são feitas as operações de filho máximo, minimo as 4 operações
    arvore[no] = arvore[esquerdo] + arvore[direito];

}

void update(int no, int l, int r, int p, int v)
{
    if(p < l or r < p) return; //Aqui eu verifico se estou fora do intervalo

    if(l == r) //Aqui eu vejo se já cheguei em um nó folha, que é [l, r] sendo l == r
    {
        arvore[no] = v;
        return;
    }
    //Eu pego quem são os filhos
    int e = ( 2 * no);
    int d = e + 1;
    //Eu separo o meio do vetor
    int m = (l + r)/2;

    //Aqui eu continuo meu update no filho esquerdo e direito
    //quando eu ainda não cheguei em um nó folha
    update(e, l, m, p, v);
    update(d, m+1, r, p, v);

    //Se eu atualizei um filho, eu tenho que atualizar meu nó principal
    //como se fosse o pai de todos.
    arvore[no] = arvore[e] + arvore[d];
}

int query(int no, int l, int r, int a, int b)
{
    //Fora do intervalo de busca, retorne um valor neutro, na soma é 0(zero)
    if(b < l or r < a) return 0;

    //Está totalmente contido no intervalo, retorne o valor precalculado
    if(a <= l && r <= b) return arvore[no];

    int e = (2 * no);
    int d = e + 1 ;
    int m = (l + r)/2;

    //A soma total é a soma dos filhos que fazem parte da resposta

    return query(e, l, m, a, b) + query(d, m+1, r, a, b);
}


int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> Q;

    for(int i = 1;  i <= N; i++)
    {
        cin >> nums[i];
    }   

    build(1, 1, N);

    // Listando o vetor com os valores dos nós correspondentes
    // for (int i = 1; i <= 32; i++)
    // {
    //     cout << arvore[i] << " \n"[i == 31];
    // }
    

    int k, p, op;

    while(Q--)
    {
        cin >> op;

        if(op == 0)
        {
            cin >> k >> p;

            update(1, 1, N, k, p);
        }
        else
        {
            cin >> k;

            cout << query(1, 1, N, 1, k) << endl;
        }
    }

    return 0;
}