#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> signs;


int processMultiple(int start,int end,int interval){
    int counter=0;
    for(int i=start;i<=end;i+=interval){
        signs.push_back(i);
        counter++;
    }
    return counter;
}

void printVector(){
    for (int i = 0; i < signs.size(); i++) {
        cout<<signs[i]<<", ";
    }
    cout<<endl;
}

int main(){
    //freopen("hardware.in", "r", stdin);
    int tc;
    cin>>tc;
    cin.get();
    while(tc--){
        signs.clear();
        string street,dummyStrAddress;
        int numOfAddr;
        getline(cin,street);

        cin>>numOfAddr;
        cin>>dummyStrAddress;
        cin.get();

        for(int i=0;i<numOfAddr;i++){
            string line;
            getline(cin,line);
            istringstream iss(line);
            //cout<<line<<endl;
            if(line[0]=='+'){
                string plus;
                int start,end,interval;
                iss>>plus;
                iss>>start;
                iss>>end;
                iss>>interval;
                int numOfAddrAdded=processMultiple(start,end,interval);
                //cout<<"---"<<numOfAddrAdded<<endl;
                i+=numOfAddrAdded-1;
                //cout<<"i "<<i<<endl;
            }
            else{
                int inputSign;
                iss>>inputSign;
                //cout<<inputSign<<endl;
                signs.push_back(inputSign);
            }
        }


        cout<<street<<endl;
        cout<<numOfAddr<<" "<<dummyStrAddress<<endl;
        int digits[10];
        for(int k=0;k<10;k++){
            digits[k]=0;
        }
        for(int k=0;k<signs.size();k++){
            int aSign=signs[k];
            while(aSign!=0){
                int cDigit=aSign%10;
                aSign/=10;
                digits[cDigit]++;
            }
        }
        int totalDigit=0;
        for(int k=0;k<10;k++){
            totalDigit+=digits[k];
            cout<<"Make "<<digits[k]<<" digit "<<k<<endl;
        }
        cout<<"In total "<<totalDigit<<" digit";
        if(totalDigit>1){
            cout<<"s";
        }
        cout<<endl;

        }

    return 0;
}