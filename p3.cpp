#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream inputFile("input.txt");
    ofstream o("output.txt");
    int T; // Number of test cases
    inputFile >> T;
    int caseNum = 0;

    while (T--)
    {   
        caseNum++;
        int n;
        inputFile>>n;
        string s;
        inputFile>>s;
        int q;
        inputFile>>q;
        unordered_map<int,int> mp;
        while(q--){
            int qi;
            inputFile>>qi;
            mp[qi]++;
        }
        for(auto it: mp){
            if(it.second%2==1){
                int qi = it.first;
            for(int x = qi;x<=n;x+=qi){
                if(s[x-1]=='0'){
                    s[x-1]='1';
                }
                else{
                    s[x-1]='0';
                }
            }
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                s[i] = '0';
                cnt++;
                int fac = i+1;
                for(int j = i+fac;j<n;j+=fac){
                    if(s[j]=='0'){
                        s[j]='1';
                    }
                    else{
                        s[j]='0';
                    }
                }
            }
        }
        o<<"Case #"<<caseNum<<": "<<cnt<<endl;
    }
    
}