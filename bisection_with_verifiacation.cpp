#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double n) {
    return n * n - 2 * n - 1;
}

vector<double> shriDharacharya(double a, double b, double c) {
    double r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    vector<double> roots;
    roots.push_back(r1);
    roots.push_back(r2);
    return roots;
}

int main() {
    double p, n, bi, bi_val;
    cout << "Enter Initial Positive Root (where f(x) is positive):" << endl;
    cin >> p;
    cout << "Enter Initial Negative Root (where f(x) is negative):" << endl;
    cin >> n;

    // Check if the initial values are valid
    if (f(p) * f(n) > 0) {
        cout << "Invalid initial values. f(p) and f(n) should have opposite signs." << endl;
        return 1;
    }

    int c = 0;
    do {
        bi = (p + n) / 2;
        bi_val = f(bi);
        if (bi_val > 0) {
            p = bi;
        } else {
            n = bi;
        }
        if (c++ == 50) break;
    } while (fabs(p - n) > 1e-7);

    cout << "Root is : " << bi << endl;
    cout << "Number of Iteration : " << c << endl;
    cout << "Value of Function : " << f(bi) << endl;
    vector<double> roots = shriDharacharya(1, -2, -1);
    cout << "Roots by Shri Dharacharya's Formula : " << roots[0] << " and " << roots[1] << endl;
    return 0;
}
