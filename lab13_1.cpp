#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[]) {
    double sum = 0;
    double sumSq = 0;
    double product = 1.0;
    double sumInv = 0;
    double maxVal = a[0];
    double minVal = a[0];

    for (int i = 0; i < n; i++) {
        sum += a[i];
        sumSq += a[i] * a[i];
        product *= a[i];
        sumInv += 1.0 / a[i];
        if (a[i] > maxVal) maxVal = a[i];
        if (a[i] < minVal) minVal = a[i];
    }

    b[0] = sum / n;
    b[1] = sqrt((sumSq / n) - (b[0] * b[0]));
    b[2] = pow(product, 1.0 / n);
    b[3] = n / sumInv;
    b[4] = maxVal;
    b[5] = minVal;
}
