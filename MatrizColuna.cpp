#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

const int M = 500, N = 500, X = 500;

vector<vector<int>> gerarMatrix(int linha, int coluna) {
    vector<vector<int>> mat(linha, vector<int>(coluna));
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            mat[i][j] = rand() % 10;
        }
    }
    return mat;
}

vector<vector<int>> multiplicaColuna(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    vector<vector<int>> C(M, vector<int>(X, 0));
    for (int j = 0; j < X; ++j) {
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < M; ++i) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    srand(time(nullptr));

    vector<vector<int>> A = gerarMatrix(M, N);
    vector<vector<int>> B = gerarMatrix(N, X);

    auto start = high_resolution_clock::now();
    vector<vector<int>> C = multiplicaColuna(A, B);
    auto end = high_resolution_clock::now();
    cout << "Tempo (coluna-maior): " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    return 0;
}
