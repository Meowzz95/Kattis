#include<iostream>
#include<string>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("integerList.1.in","r",stdin);
    int tc;
    // vector<int> ans;
    cin >> tc;
    for(int a=0;a<tc;a++) {
        bool reversed = false;
        //vector<char> cmd;
        list<int> ans;
        string line;
        cin >> line;

        // for(int i =0; i <line.length();i++){
        //   cmd.push_back(line[i]);
        // }
        char dummy;
        int n;
        cin >> n;
        cin >> dummy;
        while (n--) {
            int x;
            cin >> x;
            cin >> dummy;
            ans.push_back(x);
        }
        // bool error = false;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == 'R') {
                reversed = !reversed;
            } else {
                if (!ans.empty()) {
                    if (reversed) {
                        ans.pop_back();

                    } else {
                        ans.pop_front();
                    }
                } else {
                    break;
                }

            }
        }
        // if(!ans.empty()){
        //   if(rev%2 != 0 ){
        //     reverse(ans.begin(),ans.end());
        // }
        // for(int i =0; i <drop; i ++)
        //   ans.erase(ans.begin());

        if (!ans.empty()) {
            cout << "[";
            if (reversed) {
                int k = 0;
                for (auto it = ans.rbegin(); it != ans.rend(); advance(it, 1)) {

                    if (k)
                        cout << ',';
                    k++;
                    //cout<<"printing"<<endl;
                    cout << *it;
                }
            } else {
                int k = 0;
                for (auto it = ans.begin(); it != ans.end(); advance(it, 1)) {
                    if (k)
                        cout << ',';
                    k++;
                    cout << *it;
                }

            }

            cout << ']';
            cout << endl;

            // cout << "[";
            // int i =0;
            // for(auto const &it :ans){
            //   if (i)
            //     cout <<"," ;
            //   i++;
            //   cout <<it;
            // }
            //   cout << "]" << endl;
        } else
            cout << "error" << endl;
    }
    return 0;
}
