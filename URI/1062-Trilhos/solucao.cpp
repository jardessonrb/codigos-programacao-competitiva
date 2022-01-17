#include <bits/stdc++.h>

using namespace std;

int N = -1;

int main(int argc, char const *argv[]){
    
  while(N != 0)
  {
    stack<int> vagoes;
    bool flag = true;
    int num = -1;
    int first, last;

    cin >> N;
    if(N == 0) break;

    while(num != 0){
      cin >> num;
      if(num == 0) break;

      vagoes.push(num);
      first = num;
      for (int i = 1; i < N; i++)
      {
        cin >> num;
        vagoes.push(num);
      }

      last = vagoes.top();
      vagoes.pop();
      if(last < first){
        while(!vagoes.empty()){
          if(vagoes.top() <= last){
            flag = false;
            break;
          }

          last = vagoes.top();
          vagoes.pop();
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
#include <bits/stdc++.h>

using namespace std;

int N = -1;

int main(int argc, char const *argv[]){
    
  while(N != 0)
  {
    stack<int> vagoes;
    bool flag = true;
    int num = -1;
    int first, last;

    cin >> N;
    if(N == 0) break;

    while(num != 0){
      cin >> num;
      if(num == 0) break;

      vagoes.push(num);
      first = num;
      for (int i = 1; i < N; i++)
      {
        cin >> num;
        vagoes.push(num);
      }

      last = vagoes.top();
      vagoes.pop();
      if(last < first){
        while(!vagoes.empty()){
          if(vagoes.top() <= last){
            flag = false;
            break;
          }

          last = vagoes.top();
          vagoes.pop();
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
