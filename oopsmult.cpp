#include <iostream>
using namespace std;

class matrix {
  int arr[10][10];
  int rows, cols;

public:
  void getmatrix(int r, int c) {
    this->rows = r;
    this->cols = c;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << "Enter arr[" << i << "][" << j << "] : ";
        cin >> arr[i][j];
      }
    }
  }

  void printmatrix() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << arr[i][j] << " ";
      }
      cout << "\n";
    }
  }

  matrix multiply(matrix m2) {
    matrix M;
    M.rows = rows;
    M.cols = m2.cols;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < m2.cols; j++) {
        M.arr[i][j] = 0;
        for (int k = 0; k < cols; k++) {
          M.arr[i][j] = M.arr[i][j] + (arr[i][k] * m2.arr[k][j]);
        }
      }
    }

    return M;
  }
};

int main() {
  matrix M1, M2, M3;
  M1.getmatrix(2, 2);
  M2.getmatrix(2, 2);
  M3 = M1.multiply(M2);
  M3.printmatrix();

  return 0;
}
