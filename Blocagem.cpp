#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

const int M = 500, N = 500, X = 500;
const int BLOCK_SIZE = 32; // Ajustável para otimização do cache

vector<vector<int>> gerarMatrix(int linha, int coluna) {
    vector<vector<int>> mat(linha, vector<int>(coluna));
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            mat[i][j] = rand() % 10;
        }
    }
    return mat;
}

vector<vector<int>> multiplicaBlocagem(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    vector<vector<int>> C(M, vector<int>(X, 0));
    for (int ii = 0; ii < M; ii += BLOCK_SIZE) {
        for (int jj = 0; jj < X; jj += BLOCK_SIZE) {
            for (int kk = 0; kk < N; kk += BLOCK_SIZE) {
                for (int i = ii; i < min(ii + BLOCK_SIZE, M); ++i) {
                    for (int k = kk; k < min(kk + BLOCK_SIZE, N); ++k) {
                        for (int j = jj; j < min(jj + BLOCK_SIZE, X); ++j) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
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
    vector<vector<int>> C = multiplicaBlocagem(A, B);
    auto end = high_resolution_clock::now();
    cout << "Tempo (blocagem): " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    return 0;
}
