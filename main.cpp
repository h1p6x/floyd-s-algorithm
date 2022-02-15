#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <locale.h>
//Максимальное значение веса = 100
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

//matrix - матрица смежности
void Floyd(vector<vector<int> >& matrix, int numberOfVert)
{
    //Пробегаемся по всем вершинам и ищем более короткий путь
    //через вершину k
    for (int k = 0; k < numberOfVert; k++) // на каждой фаза просмотриваем kтую дополнительную вершину
    {
        for (int i = 0; i < numberOfVert; i++) // заново просмотриваем матрицу смежности
        {
            for (int j = 0; j < numberOfVert; j++)
            {
                //Новое значение ребра равно минимальному между старым
                //и суммой ребер i <-> k + k <-> j (если через k пройти быстрее)
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
    cout << "Количество вершин в графе: " << numberOfVert << endl;

    // Матрица меток с весами ребер графа(101 - ребра нет, 0 ребро в себя)
    vector<vector<int> > matrix(numberOfVert, vector<int>(numberOfVert));
    //Считываем матрицу весов ребер
    for (int i = 0; i < numberOfVert; i++)
    {
        for (int j = 0; j < numberOfVert; j++)
        {
            file >> matrix[i][j];
        }
    }

    file.close();

    cout << "\nМатрица весов ребер: " << endl;
    printMatrix(matrix, numberOfVert);
    Floyd(matrix, numberOfVert);
    cout << "\nМатрица кратчайших путей: " << endl;
    printMatrix(matrix, numberOfVert);

    matrix.clear();
    matrix.shrink_to_fit();
    return 0;
}
