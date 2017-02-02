/*
 * 10845.cpp
 *
 */
#include <iostream>
#include <queue>

using namespace std;
int main(){
    /*
	주어진대로 큐를stl을 이용해 풀어주면 된다.

     */
    queue<int> que;
    
    int choice;
    cin>>choice;
    
    string swit;
    int num;
    for (int i =0 ; i<choice ; i++){
        cin>>swit;
        if (swit == "push"){
            cin>>num;
            que.push(num);
        }
        else if (swit == "pop"){
            if (que.empty())
                cout<<-1<<endl;
            else{
                cout<<que.front()<<endl;
                que.pop();
            }
        }
        else if (swit == "size"){
            cout<<que.size()<<endl;
        }
        else if ( swit == "empty"){
            if (que.empty())
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else if ( swit == "front" ){
            if (que.empty() )
                cout<<-1<<endl;
            else
                cout<<que.front()<<endl;
        }
        else if (swit== "back"){
            if (que.empty())
                cout<<-1<<endl;
            else
                cout<<que.back()<<endl;
        }
        
    }  

}
