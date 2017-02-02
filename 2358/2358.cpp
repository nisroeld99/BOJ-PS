/*
 * 2358.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> ii;

int main(){
    	
    /*  x축 y축에 평행한 '직선'을 찾자
	
	x,y에 대해서 각각 sorting한 후, 
	
	인접한 것이 같으면, 이는 평행한 직선이라는 뜻 

	set. size  출력하기 .

     */

    int n;
    cin >> n;
    vector<int >x;
    vector<int >y;
    for (int i = 0 ;i<n;i++){
        int sc1,sc2;
        scanf("%d%d",&sc1,&sc2);
        x.push_back(sc1);
        y.push_back(sc2);       
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    set<int>mp1;
    set<int>mp2;
    
    for (int i = 0 ; i<x.size()-1; i++){
        if (x[i]==x[i+1])
            mp1.insert(x[i]);
    }
    for (int i=0 ; i<y.size()-1; i++){
        if( y[i]==y[i+1])
            mp2.insert(y[i]);
    }
    cout << mp1.size() +mp2.size()<<endl;
}
