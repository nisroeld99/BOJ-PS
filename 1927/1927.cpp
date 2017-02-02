/*
 * 1927.cpp
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
	/* priority_queue  stl을 연습해보자      */
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int> >pq;
    while (n--){
        int sc1;
        scanf("%d",&sc1);
        if (sc1==0){
            if (pq.empty()) printf("0\n");
            else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
        else {
            pq.push(sc1);
        }       
    }
}
