#include "stdafx.h"

using namespace std;

typedef vector<double> matrix1D;
typedef vector<matrix1D> matrix2D;

matrix2D OverlayValues(const matrix2D& coeffMatrix, const matrix1D& valueVector, int col)
{
    size_t rows = coeffMatrix.size();
    size_t cols = coeffMatrix.at(0).size();
    matrix2D newMatrix(rows, matrix1D(cols));
    for (size_t i{}; i < rows; ++i)
        for (size_t j{}; j < cols; ++j)
            newMatrix.at(i).at(j) = coeffMatrix.at(i).at(j);
    for (size_t i{}; i < rows; ++i)
        newMatrix.at(i).at(col) = valueVector.at(i);
    return newMatrix;
}

void DisplayEquations(const matrix2D& coeffMatrix, const matrix1D& valueVector)
{
    size_t rows = coeffMatrix.size();
    size_t cols = coeffMatrix.at(0).size();
    for (size_t i{}; i < rows; ++i)
    {
        bool firstTerm = true;
        for (size_t j{}; j < cols; ++j)
        {
            double c = coeffMatrix.at(i).at(j);
            if (c != 0)
            {
                if (c < 0)
                    if (firstTerm)
                        cout << "-";
                    else
                        cout << " - ";
                else if (!firstTerm)
                    cout << " + ";
                if (abs(c) != 1)
                    cout << abs(c);
                cout << "x" + to_string(j + 1);
                if (c != 0)
                    firstTerm = false;
            }
        }
        cout << " = " << valueVector[i] << endl;
    }
    cout << endl;
}

matrix2D CreateReducedMatrix(const matrix2D& A, size_t skipRow, size_t skipCol)
{
    size_t rowsA = A.size();
    size_t colsA = A.at(0).size();
    matrix2D B(rowsA - 1, matrix1D(colsA - 1, 0));
    size_t rowB{};
    for (size_t rowA{}; rowA < rowsA; rowA++)
    {
        if (rowA == skipRow)
            continue;
        size_t colB{};
        for (size_t colA{}; colA < colsA; colA++)
        {
            if (colA == skipCol)
                continue;
            B.at(rowB).at(colB) = A.at(rowA).at(colA);
            colB++;
        }
        rowB++;
    }
    return B;
}

void CalcDeterminant(const matrix2D& A, double& det, double f = 1)
{
    size_t rowsA = A.size();
    size_t colsA = A.at(0).size();
    if (rowsA == 2 && colsA == 2)
        det += f * (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    else
    {
        for (size_t rowA{}; rowA < rowsA; rowA++)
        {
            matrix2D B = CreateReducedMatrix(A, rowA, 0);
            double f2 = A.at(rowA).at(0);
            if (rowA % 2 == 1)
                f2 *= -1;
            CalcDeterminant(B, det, f * f2);
        }
    }
    return;
}

int main()
{
    const matrix2D coeffMatrix
    {
        { 1,2,1,-1 },
        { 3,2,4,4 },
        { 4,4,3,4 },
        { 2,0,1,5 } };

    //const matrix2D coeffMatrix
    //{ { 1,2,1,-1 },
    //{ 3,6,4,4 },
    //{ 4,4,3,4 },
    //{ 2,0,1,5 } };

    //const matrix2D coeffMatrix
    //{ { 1,2,1,-1 },
    //{ 3,6,4,4 },
    //{ 4,8,3,4 },
    //{ 2,4,1,5 } };

    const matrix1D valueVector{ 5, 16, 22, 15 };

    //const matrix2D coeffMatrix{ {1,0},{0,-1} };
    //const matrix1D valueVector{ -1,1 };

    cout << fixed << setprecision(0);

    DisplayEquations(coeffMatrix, valueVector);

    double detCoeff{};
    CalcDeterminant(coeffMatrix, detCoeff);

    if (detCoeff == 0)
    {
        cout << "This system is linearly dependent and" << endl
             << "therefore is not uniquely solveable!" << endl;
    }
    else
    {
        size_t cols = coeffMatrix.at(0).size();
        for (size_t j{}; j < cols; j++)
        {
            matrix2D unkMatrix = OverlayValues(coeffMatrix, valueVector, j);
            double detUnknown{};
            CalcDeterminant(unkMatrix, detUnknown);
            cout << "x" + to_string(j + 1) << " = "
                 << detUnknown / detCoeff << endl;
        }
    }

    cout << endl;
    return 0;
}
