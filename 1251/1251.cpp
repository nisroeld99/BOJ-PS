

#include<algorithm>
#include <iostream>
#include<vector>
#include<string>
using namespace std;
 
 
string inputS;
 
 
int main(){
 
    /*
      n = 50 이므로 , 전탐색으로 O(n^3) 으로 구할수 있다. (모든 경우의 수   따져보기) 
      i ,k j 는 각각 경계선에 해당한다. 
      경계선부터 revese 하여 temp string에 저장해서 dab과 비교해주는 것을 반복한다.
      
      dab 은 zzzzzzzz로 초기화 함으로써 가장 사전 상 뒤에 있는 것으로 초기화 
      
    
    */
 
    cin>>inputS;
     
    int len= (int)inputS.size();
    string dab="zzzzzzzzzzzzz";
    string temp="";
     
    for (int i=1; i<len ; i++){
        for(int j=i+1 ; j<len ;j++){
             
            for (int k=i-1; k>=0 ;k--  ){
                temp+=inputS[k];
            }
             
            for (int p=j-1 ; p>=i ; p--){
                temp+=inputS[p];
            }
             
            for (int o=len-1; o>=j; o--){
                temp+=inputS[o];
            }
             
            if ( temp.compare(dab) < 0 ){
                dab=temp;
            }
             
            temp="";
        }
    }
 
     
    cout<<dab<<endl;
}
