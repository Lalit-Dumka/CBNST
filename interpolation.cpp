#include <bits/stdc++.h>
using namespace std;

void create_table(vector<vector<int>>&v, int n){
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<n-i+1; j++){
            v[j][i] = v[j+1][i-1] - v[j][i-1];
        }
    }
}

void print_table(vector<vector<int>>&v, int n){
    cout<<"Table :"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i+1; j++){
            cout<<v[i][j]<<"   ";
        }
        cout<<endl;
    }
}

float forwardInterpolation(vector<vector<int>>&v, int n, int x){
    int sum = v[0][1];
    float u = (float)(x - v[0][0]) / (v[1][0] - v[0][0]);
    float u1 = u;
    int fact = 1;
    for(int i=2; i<=n; i++){
        sum += (u1 * v[0][i]) / fact;
        u1 *= (u - i + 1);
        fact *= i;
    }
    cout<<"Value at "<<x<<" is "<<sum<<endl;
    return sum;
}

float backwardInterpolation(vector<vector<int>>&v, int n, int x){
    int sum = v[n-1][1];
    float u = (float)(x - v[n-1][0]) / (v[1][0] - v[0][0]);
    float u1 = u;
    int fact = 1;
    for(int i=2; i<=n; i++){
        sum += (u1 * v[n-i][i]) / fact;
        u1 *= (u + i - 1);
        fact *= i;
    }
    cout<<"Value at "<<x<<" is "<<sum<<endl;
    return sum;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n, vector<int>(n+1, 0));
    create_table(v, n);
    print_table(v, n);
    int x;
    cin>>x;
    forwardInterpolation(v, n, x);
    backwardInterpolation(v, n, x);

    return 0;
}

// 5
// 1891 46
// 1901 66
// 1911 81
// 1921 93
// 1931 101
// 1925