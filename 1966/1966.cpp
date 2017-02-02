/*
 * 1966.cpp
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
	deque 를 이용해 구현했다.
	dequeu에는 pair<int,int > 를 써서 <우선순위 , 프린트값 ,> 을 저장해놓음
	그리고 주어진 논리대로 for 문 구현 하기  
*/

    int tc;
    cin >> tc;
    deque<ii> dq;
    while (tc--){
        int n , m;
        scanf("%d%d",&n,&m);
        for (int i = 0 ; i<n;i++){
            int sc1;
            scanf("%d",&sc1);
            dq.push_back(ii( sc1 ,i ));   
        }
        int cnt =1;
        while (!dq.empty()){
            int maxx = dq[0].first;
            bool ok =true;
            for (int i = 0;i<dq.size(); i++){
                if (maxx < dq[i].first ){
                    dq.push_back(dq[0]);
                    dq.pop_front();
                    dq.shrink_to_fit();
                    ok = false;
                    break;
                }
            }
            if (ok){
                if (dq.front().second == m){
                    cout << cnt <<endl;
                    break;
                }
                else {
                    dq.pop_front();
                    dq.shrink_to_fit();
                    cnt++;
                }
            }
        }
        while (!dq.empty()){
            dq.pop_front();
        }
    }
}
