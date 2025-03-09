#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

const int M = 500, N = 500, X = 500;

vector<vector<int>> gerarMatriz(int linha, int coluna) {
  vector<vector<int>> mat(linha, vector<int>(coluna));
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      mat[i][j] = rand() % 10;
    }
  }
  return mat;
}

vector<vector<int>> multiplicaLinha(const vector<vector<int>> &A, const vector<vector<int>> &B) {
  vector<vector<int>> C(M, vector<int>(X,0));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < X; k++) {
        C[i][k] += A[i][j] * B[j][k];
      }
    }
  }
  return C;
}

int main() {
  srand(time(nullptr));

  vector<vector<int>> A = gerarMatriz(M, N);
  vector<vector<int>> B = gerarMatriz(N, X);

  auto start = high_resolution_clock::now();
  vector<vector<int>> C = multiplicaLinha(A, B);
  auto end = high_resolution_clock::now();
  cout << "Tempo (linha-maior): " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

  return 0;
}
