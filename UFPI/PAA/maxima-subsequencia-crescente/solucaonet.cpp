#include <cstdio> // scanf e printf
#include <algorithm> // lower_bound
#include <vector> // vector

using namespace std; 
#define PB push_back
vector<int> pilha;
int n;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		// declaro um iterador que guardará o elemento mais à esquerda de pilha
		// que não é menor que x
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), x);
		// se it for o fim do vector, então não há elemento que não seja menor que x
		// ou seja, todos os topos de pilha são menores ou iguais a x
		
		// logo, criamos uma nova pilha e colocamos x no seu topo
		if(it==pilha.end()) pilha.PB(x);
		
		// porém, se it apontar para alguma posição válida do vector
		// colocamos x no topo desta pilha, substintuindo o valor que it aponta por x
		else *it = x;
	}
	
	printf("%d\n", pilha.size());
    for(auto x : pilha){
        printf("%d ", x);
    }
	
	return 0;
}