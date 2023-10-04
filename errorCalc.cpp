#include<bits/stdc++.h>
using namespace std;

double round(double n) {
    return ((int)(n * 100 + 0.5)) / 100.0;
}

int main() {
    double true_val, obs_val;
    cout << "Enter the true value:" << endl;
    cin >> true_val;
    cout << "Enter the observed value:" << endl;
    cin >> obs_val;

    double abs_error = true_val - obs_val;
    double real_error = abs_error / true_val;
    double pre_error = real_error * 100;

    cout << "Absolute error: " << abs_error << endl;
    cout << "Relative error: " << real_error << endl;
    cout << "Percentage error: " << pre_error << endl;
    cout << "Rounded absolute error: " << round(abs_error) << endl;
    cout << "Rounded real error: " << round(real_error) << endl;
    cout << "Rounded percentage error: " << round(pre_error) << endl;

    return 0;
}