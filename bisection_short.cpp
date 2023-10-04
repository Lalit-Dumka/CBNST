#include <iostream>
#include <cmath>

using namespace std;

double f(double n) {
    return n * n - 2 * n - 1;
}

int main() {
    double p, n, bi;
    cout << "Enter Initial Positive Root (where f(x) is positive):" << endl;
    cin >> p;
    cout << "Enter Initial Negative Root (where f(x is negative):" << endl;
    cin >> n;

    int c = 0;
    do {
        bi = (p + n) / 2;
        f(bi) > 0 ? p = bi : n = bi;
        if (c++ == 500) break;
    }while (fabs(p - n) > 1e-7);

    cout << "Root is: " << bi << endl;
    cout << "Value of Function: " << f(bi) << endl;
    return 0;
}
