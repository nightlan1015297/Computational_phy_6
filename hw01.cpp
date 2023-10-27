#include <iostream>
#include <vector>

using namespace std;

void gaussianElimination(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();

    for (int i = 0; i < n - 1; i++) {
    // Eliminate the elements below the pivot element
        for (int j = i + 1; j < n; j++) {
        double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        b[j] -= factor * b[i];
        }
    }

  // Back substitution
    for (int i = n - 1; i >= 0; i--) {
    double x = b[i];
        for (int j = i + 1; j < n; j++) {
        x -= A[i][j] * b[j];
        }

    b[i] = x / A[i][i];

    }
}

int main() {
    vector<vector<double>> A = {{1, -1, -1}, {2, 2, 0}, {0, -2, 7}};
    vector<double> b = {0 ,0 ,-3};

    gaussianElimination(A, b);

    for (int i = 0; i < b.size(); i++) {
        cout << "x" << i + 1 << " = " << b[i] << endl;
    }

    return 0;
}