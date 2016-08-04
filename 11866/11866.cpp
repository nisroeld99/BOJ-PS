#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
  
deque<int> dq;
  
void jose(int n,int m){
    printf("<");
      
    for (int i =0  ;i<n;i++){
        for (int j=0; j<m-1;j++){
            int temp =dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        printf("%d",dq.front());
        dq.pop_front();
        if (!dq.empty())
            printf(", ");
          
    }
      
      
    printf(">\n");
  
}
int main(){
    int n,m;
      
    scanf("%d%d",&n,&m);
      
    for (int i = 1 ; i<=n;i++)
        dq.push_back(i);
      
    jose(n,m);
}
