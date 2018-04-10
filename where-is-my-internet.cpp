#include <bits/stdc++.h>

using namespace std;
int main(){
    //freopen("3.in","r",stdin);
    int n,size;
    cin>>n>>size;
    vector<vector<int>> al;
    vector<int> state;
    state.assign(n+1,0);
    al.assign(n+1,vector<int>());
    for(int i=0;i<size;i++){
        int num1,num2;
        cin>>num1>>num2;
        al[num1].push_back(num2);
        al[num2].push_back(num1);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        auto c=q.front();
        q.pop();
        state[c]=1;
        for(int i=0;i<al[c].size();i++){
            auto next=al[c][i];
            if(state[next]==1){
                continue;
            }
            q.push(next);
        }
    }
    bool found=false;
    for(int i=1;i<state.size();i++){
        if(state[i]==0){
            cout<<i<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"Connected"<<endl;
    }


}
