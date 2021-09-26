#include <bits/stdc++.h>

using namespace std;

int N = -1;

int main(int argc, char const *argv[]){
    
  while(N != 0)
  {
    stack<int> vagoes, estacao;
    bool flag = true;
    int num = -1;
    int first, last;

    cin >> N;
    if(N == 0) break;

    while(num != 0){
      cin >> num;
      if(num == 0) break;

      vagoes.push(num);
      for (int i = 1; i < N; i++)
      {
        cin >> num;
        vagoes.push(num);
      }

      int proximo = 0;

      while(!vagoes.empty()){
        int top = vagoes.top();
        vagoes.pop();
        if(top == proximo || top == N){
          proximo = top - 1;
        }else{
          if(estacao.empty()){
              estacao.push(top);
          }else if(top > estacao.top()){
              estacao.push(top);
          } else{
            if(estacao.top() == proximo){
              proximo = estacao.top() - 1;
              estacao.pop();
              estacao.push(top);
            }else{
              flag = false;
              break;
            }
          }
        }
      }

     
      cout << (flag ? "Yes" : "No") << endl;
    }

    if(num == 0){
        cout << endl;
    }
  }
      return 0;
}
