/*
 * 2513.cpp
 *
*/
 
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ;
typedef long long ll;
const int inf = 987654321;
const int mod = 0 ;
int n,k,s;
vector <ii > v;
vector<ii> v2;
bool cmp(const ii & a,const ii & b){
    return a.first > b.first;
}
int main(){
    scanf("%d%d%d",&n,&k,&s);
    for(int i = 1 ; i<= n; i++) {
        int loc,num;
        scanf("%d%d",&loc,& num);
        if(loc < s){
            v.push_back(ii(loc,num));
        }
        else {
            v2.push_back(ii(loc,num));
        }
    }
    sort (v.begin(),v.end()) ;
    sort (v2.begin(),v2.end(),cmp);
    int vol = k  ;
    int bus = s  ;
    int sum = 0 ;
    for(int i =0 ; i<v.size() ; i++){
        int now_loc = v[i].first;
        int now_student = v[i].second;
        if(bus!= now_loc){
            sum += abs(bus-now_loc);
            bus= now_loc;
        }
        if(now_student <vol){
            vol-=now_student;
        }
        else if (now_student == vol){ //한번만 갔다와도됨
            vol=k;
            sum+=abs(bus-s);
            bus = s;
        }
        else {  //여러번 갔다온다
            now_student -= vol;
            sum+= 2* abs(bus-s);
            vol = k ;
            int temp = now_student/vol;
            if (now_student%vol ==0 ){
                sum+=(temp-1)* abs(bus-s) *2;
                sum+= abs(bus-s);
                bus = s;
                vol = k ;
            }else {
                sum+=(temp)* abs(bus-s) *2;
                vol = k ;
                vol -= now_student%vol;
            }
 
        }
    }
    for(int i= 0 ; i<v2.size() ; i++){
        int now_loc = v2[i].first;
        int now_student = v2[i].second;
        if(bus <= s){
            vol = k ;
            sum+= abs(bus-now_loc);
            bus = now_loc;
        }
         
        if(bus!= now_loc){
            sum += abs(bus-now_loc);
            bus= now_loc;
        }
        if(now_student <vol){
            vol-=now_student;
        }
        else if (now_student == vol){
            vol = k;
            sum+= abs(bus-s);
            bus = s;
        }
        else {  //여러번 갔다온다
            now_student -= vol;
            sum+= 2* abs(bus-s);
            vol = k ;
            int temp = now_student/vol;
            if (now_student%vol ==0 ){
                sum+=(temp-1)* abs(bus-s) *2;
                sum+= abs(bus-s);
                bus = s;
                vol = k ;
            }else {
                sum+=(temp)* abs(bus-s) *2;
                vol = k ;
                vol -= now_student%vol;
            }
             
        }
    }
    if (bus == s){
         
    }else {
        sum+= abs (bus - s );
    }
     
    printf("%d\n",sum);
     
     
    return 0 ;
}

