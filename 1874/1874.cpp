/*
 * 1874.cpp
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
     
     push는 무조건 오름차순으로 입력된다는 특성을 이해해야한다.
     
     +(push)하는 경우 : st가 비어있을 때,  혹은 현재 cnt 보다 뽑고자하는 번호보다 낮을때 무조건 push해야함
     
     -(pop)하는 경우 :  뽑고자하는 것이 top에 있을때, 뽑는다. 
     */
    int n ;
    cin >> n;
    stack<int>st;
    vector<char>dab;
    
    int vcnt = 1;
    
    
    for (int i =0 ;i<n; i++){
        int sc1;
        scanf("%d",&sc1);
        
        if (st.empty()) {  //아무것도 없으면 push함
            st.push(vcnt++);
            dab.push_back('+');
        }
        while ( st.top() != sc1 && st.top() < sc1 ){  //
            st.push(vcnt++);
            dab.push_back('+');
        }
        if ( st.top()==sc1 ){  // top에 이번 해당이 있으면, pop 한다 .
            st.pop();
            dab.push_back('-');
        }
    }
    
    
    if (! st.empty()){  //모든 프로세스가 끝났는데 , 스택이 비어있지 않다면 이는 스택수열을 완성할 수 없다는 뜻이다.
        printf("NO\n");
        return 0;
    }
    for (int i = 0 ; i<dab.size(); i++)
        printf("%c\n",dab[i]);
}
