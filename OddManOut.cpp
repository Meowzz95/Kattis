#include <iostream>
#include <map>

using namespace std;

int main(){
    freopen("OddManOut.in","r",stdin);

    int tc;
    cin>>tc;
    for (int i = 0; i < tc; i++) {
        int size;
        cin>>size;
        map<int,bool> m;
        for (int k = 0; k < size; k++) {
            int code;
            cin>>code;
            try{
                m.at(code);
                m.erase(code);
            }
            catch(exception &e){
                m.emplace(code, true);
            }
        }
        int oddCode=m.begin()->first;
        cout<<"Case #"<<(i+1)<<": "<<oddCode<<endl;
    }
    return 0;
}