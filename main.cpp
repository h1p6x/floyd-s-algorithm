#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <locale.h>
//������������ �������� ���� = 100
#define inf 101

using namespace std;

void printMatrix(vector<vector<int> >& matrix, int numberOfVert)
{
    for (int i = 0; i < numberOfVert; i++)
    {
        for (int j = 0; j < numberOfVert; j++)
        {
            if (matrix[i][j] == inf)
            {
                cout << "inf" << " ";
            }
            else
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

//matrix - ������� ���������
void Floyd(vector<vector<int> >& matrix, int numberOfVert)
{
    //����������� �� ���� �������� � ���� ����� �������� ����
    //����� ������� k
    for (int k = 0; k < numberOfVert; k++) // �� ������ ���� ������������� k��� �������������� �������
    {
        for (int i = 0; i < numberOfVert; i++) // ������ ������������� ������� ���������
        {
            for (int j = 0; j < numberOfVert; j++)
            {
                //����� �������� ����� ����� ������������ ����� ������
                //� ������ ����� i <-> k + k <-> j (���� ����� k ������ �������)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main()
{
    setlocale(0, "");
    ifstream file("input.txt");
    int numberOfVert;
    file >> numberOfVert;
    cout << "���������� ������ � �����: " << numberOfVert << endl;

    // ������� ����� � ������ ����� �����(101 - ����� ���, 0 ����� � ����)
    vector<vector<int> > matrix(numberOfVert, vector<int>(numberOfVert));
    //��������� ������� ����� �����
    for (int i = 0; i < numberOfVert; i++)
    {
        for (int j = 0; j < numberOfVert; j++)
        {
            file >> matrix[i][j];
        }
    }

    file.close();

    cout << "\n������� ����� �����: " << endl;
    printMatrix(matrix, numberOfVert);
    Floyd(matrix, numberOfVert);
    cout << "\n������� ���������� �����: " << endl;
    printMatrix(matrix, numberOfVert);

    matrix.clear();
    matrix.shrink_to_fit();
    return 0;
}
