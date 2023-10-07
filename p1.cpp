#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ifstream inputFile("input.txt");
    int T; // Number of test cases
    inputFile >> T;
    int cnt = 0;
    ofstream o("output.txt");

    for (int i = 0; i < T; i++) {
        cnt++;
        int n;
        inputFile >> n;
        vector<int> arr(n);
        for(int j = 0; j < n; j++) {
            inputFile>>arr[j];
        }
        sort(arr.begin(), arr.end());
        double ans = 0;
        if(n!=5){
            ans = (arr[n-1]+arr[n-2])/2.0-(arr[1]+arr[0])/2.0;
        }
        else{
            ans = (arr[n-1]+arr[n-2])/2.0-(arr[2]+arr[0])/2.0;
            ans = max(ans,(arr[n-1]+arr[n-3])/2.0-(arr[1]+arr[0])/2.0);
        }
        o<<"Case #"<<cnt<<": "<<ans<<endl;


        
    }
}