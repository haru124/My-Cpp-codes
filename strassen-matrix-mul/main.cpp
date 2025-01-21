#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > addMatrices(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();
    vector<vector<int> > result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];    }}
    return result;}
vector<vector<int> > subtractMatrices(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();
    vector<vector<int> > result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j]; }}
    return result;}
vector<vector<int> > strassenMultiply(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();
    if (n == 1) {
        vector<vector<int> > C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C; }
  int mid = n / 2;
  vector<vector<int> > A11(mid, vector<int>(mid));
    vector<vector<int> > A12(mid, vector<int>(mid));
    vector<vector<int> > A21(mid, vector<int>(mid));
    vector<vector<int> > A22(mid, vector<int>(mid));
    vector<vector<int> > B11(mid, vector<int>(mid));
    vector<vector<int> > B12(mid, vector<int>(mid));
    vector<vector<int> > B21(mid, vector<int>(mid));
    vector<vector<int> > B22(mid, vector<int>(mid));
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];} }
    vector<vector<int> > P1 = strassenMultiply(A11, subtractMatrices(B12, B22));
    vector<vector<int> > P2 = strassenMultiply(addMatrices(A11, A12), B22);
    vector<vector<int> > P3 = strassenMultiply(addMatrices(A21, A22), B11);
    vector<vector<int> > P4 = strassenMultiply(A22, subtractMatrices(B21, B11));
    vector<vector<int> > P5 = strassenMultiply(addMatrices(A11, A22), addMatrices(B11, B22));
    vector<vector<int> > P6 = strassenMultiply(subtractMatrices(A12, A22), addMatrices(B21, B22));
    vector<vector<int> > P7 = strassenMultiply(subtractMatrices(A11, A21), addMatrices(B11, B12));
    vector<vector<int> > C11 = addMatrices(subtractMatrices(addMatrices(P5, P4), P2), P6);
    vector<vector<int> > C12 = addMatrices(P1, P2);
    vector<vector<int> > C21 = addMatrices(P3, P4);
    vector<vector<int> > C22 = subtractMatrices(subtractMatrices(addMatrices(P5, P1), P3), P7);
    vector<vector<int> > C(n, vector<int>(n));
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j]; }  }
    return C;}
int main() {
    vector<vector<int> > A = {{2, 3}, {4, 5}};
    vector<vector<int> > B = {{5, 6}, {7, 8}};
    vector<vector<int> > result = strassenMultiply(A, B);
    cout << "Matrix A:" << endl;
    for (const vector<int>& row : A) {
        for (int val : row) {
            cout << val << " ";    }
        cout << endl;}
    cout << "\nMatrix B:" << endl;
    for (const vector<int>& row : B) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix C (Result):" << endl;
    for (const vector<int>& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
