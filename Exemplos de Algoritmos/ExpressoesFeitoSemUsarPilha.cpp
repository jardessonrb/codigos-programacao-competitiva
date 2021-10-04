#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool match(char A, char B){
  if(A == '{' && B == '}')
    return true;
  if(A == '(' && B == ')')
    return true;
  if(A == '[' && B == ']')
    return true;
  return false;
}


int main(){
  int N;
  vector<char> pilha;
  string t;

  cin >> N;
  while (N--)
  {
    cin >> t;
    for(int i = 0; i < t.size(); i ++ ){
      if(pilha.empty()){
        pilha.push_back(t[i]);
        continue;
      }
      if(match(pilha.back(), t[i])){
        pilha.pop_back();
      }else {
        pilha.push_back(t[i]);
      }
    }
    if(pilha.size() == 0){
      cout << 'S' << endl;
    }else{
      cout << 'N' << endl;
    }
    pilha.clear();
  }


}


