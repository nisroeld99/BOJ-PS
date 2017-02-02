/*
 * 1021_2.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> ii;

int main(){
/*
	왼쪽으로 가든, 오른쪽으로 가든 최소값을 저장한다는 개념은 _1 번 src와 유사하다. 
	다른점은 deque사용함 .

*/


    int n,m ;
    scanf("%d%d",&n,&m);
    
    deque<int>dq2;
    deque<int>dq3;
    for (int i =1 ; i<=n ;i++){   
        dq2.push_back(i);
        dq3.push_back(i);
    }
    int sum = 0;
    
    for (int i =0 ;i<m;i++){
        int sc1;
        scanf("%d",&sc1);
        int d2=0,d3=0;
        while (dq2.front() != sc1){
            dq2.push_back(dq2.front());
            dq2.pop_front();
            d2++;
        }
        dq2.pop_front();
        while (dq3.front()!=sc1){
            dq3.push_front(dq3.back());
            dq3.pop_back();
            d3++;
        }
        dq3.pop_front();
        
        if (d2 < d3){
            sum+=d2;
            for (int i =0;i<dq2.size(); i++){
                
                dq3[i]=dq2[i];
            }
            
        }else {
            sum+=d3;
            for (int i =0;i<dq3.size(); i++){
                
                dq2[i]=dq3[i];
            }
        }   
    }
    cout<<sum<<endl;   
}
