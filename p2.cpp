#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
        if (n > 1) {
        factors.push_back(n);
    }
    
    return factors;
}

int main(){
    ifstream inputFile("input.txt");
    ofstream o("output.txt");
    int T; // Number of test cases
    inputFile >> T;
    int cnt = 0;

    while (T--) {
        cnt++;
        int p;
        inputFile >> p;

        vector<int> factors = primeFactors(p);
        long long sum = 0;
        for (int f: factors)
        {
            sum+= f;
        }
        if(sum>41){
            o<<"Case #"<<cnt<<": -1"<<endl;
            continue;
        }
        

        for(int i=0;i<41-sum;i++){
            factors.push_back(1);
        }
        factors.insert(factors.begin(),factors.size());
        o<<"Case #"<<cnt<<": ";

        for(int x: factors){
            o<<x<<" ";
        }
        o<<endl;

    }
}