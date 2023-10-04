#include <iostream>
#include <vector>
using namespace std;

void createtable(vector<vector<int>>& v, int n) {
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    for (int i = 2; i < n + 1; i++) { 
        for (int j = 0; j < n - i + 1; j++) {
            v[j][i] = v[j + 1][i - 1] - v[j][i - 1];
        }
    }
}

double forward(vector<vector<int>>& v, int x, int n) {
    double y = v[n / 2][1];
    double u = (double)(x - v[n / 2][0]) / (v[1][0] - v[0][0]); 
    double u1 = u;
    int neg = 1, post = 1, fact = 1;
    for (int i = 2; i <= n; i++) { 
        y += (u1 * v[n / 2][i]) / fact;
        fact = fact * i;
        if (i % 2 == 0) {
            u1 *= (u + post);
            post++;
        } else {
            u1 *= (u - neg);
            neg++;
        }
    }
    return y;
}

double backward(vector<vector<int>>& v, int x, int n) {
    double y = v[n / 2][1];
    double u = (double)(x - v[n / 2][0]) / (v[1][0] - v[0][0]); 
    double u1 = u;
    int c = 2;
    int post = 1, neg = 1, fact = 1;
    for (int i = 2; i <= n; i++) {
        y += (u1 * v[n / 2][i]) / fact;
        fact = fact * i;
        if (--c == 0) {
            c = 2;
            post--;
        }
        if (i % 2 == 0) {
            u1 *= (u - neg);
            neg++;
        } else {
            u1 *= (u + post);
            post++;
        }
    }
    return y;
}

int main() {
    int n;
    cout<<"ENTER THE SIZE OF TABLE"<<endl;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n + 1, 0));
    createtable(v, n);
    cout << "Table is " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    int x;
    cout << "Enter the value that you want to get from forward method: ";
    cin >> x;
    cout << "Solution from forward: " << forward(v, x, n) << endl;

    cout << "Enter the value that you want to get from backward method: ";
    cin >> x;
    cout << "Solution from backward: " << backward(v, x, n) << endl;

    return 0;
}
