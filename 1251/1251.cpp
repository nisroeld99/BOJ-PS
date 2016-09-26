#include<algorithm>
#include <iostream>
#include<vector>
#include<string>
using namespace std;
 
 
string inputS;
 
 
int main(){
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
