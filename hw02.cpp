#include <iostream>
#include <vector>

using namespace std;

// implement matrix multiplication function
vector<vector<double>> matrixMultiply(vector<vector<double>> A, vector<vector<double>> B) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

vector<vector<double>> matrixMultiplyScalar(vector<vector<double>> A , double scalar) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] * scalar;
        }
    }

    return C;
}

vector<vector<double>> matrixPlus(vector<vector<double>> A , vector<vector<double>> B) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

vector<vector<double>> newtonSchulzInverse(vector<vector<double>> X,vector<vector<double>> A, double tolerance) {
    int n = A.size();

    vector<vector<double>> new_X;
    vector<vector<double>> I = {{1,0,0}, {0,1,0}, {0,0,1}};
    
    while (1) {
        vector<vector<double>> R = matrixMultiply(X, A);
        vector<vector<double>> R2 = matrixMultiplyScalar(matrixMultiply(R, X),-1);

        new_X = matrixPlus(matrixMultiplyScalar(X,2), R2);

        double maxDiff = 0;

        vector<vector<double>> temp = matrixMultiply(A, new_X);

        vector<vector<double>> error_mat = matrixPlus(temp , matrixMultiplyScalar(I,-1));

        // add all element in error_mat to estimate error
        for (int i = 0; i < error_mat.size(); i++) {
            for (int j = 0; j < error_mat[0].size(); j++) {
                maxDiff += abs(error_mat[i][j]);
            }
        }


        if (maxDiff < tolerance) {
            break;
        }
        X = new_X;
    }

    return new_X;
}

int main() {
    vector<vector<double>> A = {{0,1,1}, {1,1,0}, {1,0,1}};
    vector<vector<double>> guess_A = {{-0.5,0.6,0.6}, {0.6,0.6,-0.5}, {0.6,-0.5,0.5}};

    vector<vector<double>> A_1 = {{8,7,9},{2,1,3},{5,4,6}};
    vector<vector<double>> guess_A1 = {{0,1,1},{1,1,0},{1,0,1}};


    vector<vector<double>> inverseA  = newtonSchulzInverse(guess_A ,A  ,1e-5);
    vector<vector<double>> inverseA1 = newtonSchulzInverse(guess_A1,A_1,1e-5);


    // Output inverseA1
    cout << "inverseA: " << endl;
    for (int i = 0; i < inverseA.size(); i++) {
        for (int j = 0; j < inverseA[0].size(); j++) {
            cout << inverseA[i][j] << " ";
        }
        cout << endl;
    }

    // Output inverseA1
    cout << "inverseA1: " << endl;
    for (int i = 0; i < inverseA1.size(); i++) {
        for (int j = 0; j < inverseA1[0].size(); j++) {
            cout << inverseA1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

