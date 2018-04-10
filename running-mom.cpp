#include <iostream>
using namespace std;
#include <unordered_map>
#include<vector>
unordered_map<string,vector<string>> adj;
unordered_map<string,int> state;
bool safe=false;

void dfs(string city){
    state[city]=1;
    for(auto &adjCity:adj[city]){
        if(state[adjCity]==1){
            safe=true;
            break;
        }
        if(state[adjCity]==2){
            continue;
        }
        dfs(adjCity);
    }
    state[city]=2;
}
int main(){
    //freopen("sample.in","r",stdin);
    int tc;
    cin>>tc;
    while(tc--){
        string city1,city2;
        cin>>city1>>city2;
        adj[city1].push_back(city2);
    }

    string city;
    while(cin>>city){
        cout<<city<<" ";
        state.clear();
        safe=false;
        dfs(city);
        cout<<(safe?"safe":"trapped")<<endl;
    }
}
