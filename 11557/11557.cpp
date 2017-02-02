/*
 * 11557.cpp
 *
 */
#include <iostream>
#include <map>
using namespace std;

int main(){
    
    /*
	10808알파벳 개수와 유사 
	하지만 , 알파벳은 26개로 고정되어있지만 
	학교이름은 무수히 많으므로 map 을 사용해야한다. 
	(map ppt 참조) 	
    */

    int tc;
    scanf("%d",&tc);
    map<string,int> mp;
    while(tc--){
        mp.clear();
        int num;
        scanf("%d",&num);
        while(num--){
            string s;
            int num2;
            cin >> s;
            scanf("%d",  &num2);
            mp[s]+= num2;
            
        }
        int maxx_cnt = -1000;
        string dab ;
        
        for (auto it : mp){
            if (it.second > maxx_cnt) {
                maxx_cnt  = it.second;
                dab = it.first;
                
            }
        }
        cout<<dab<<endl;
        
    }
}
