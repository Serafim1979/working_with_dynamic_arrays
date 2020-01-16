#include<iostream>
#include"test.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
 //----- C Style ----------------------------
    int n = 3;
    int m = 5;
    int **mas = (int**)malloc(n*sizeof(int*));

    for(int i = 0; i < n; i++)
    {
        mas[i] = (int*)malloc(m * sizeof(int));
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //mas[i][j] = rand()%21;
            *(*(mas + i) + j) = rand() % 21;
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
//----------adding a string to an array------------------

    mas = (int**)realloc(mas, (n + 1) * sizeof(int*));
    mas[n] = (int*)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++)
    {
        mas[n][i] = -100;
    }
    n++;

 //----------adding a column to an array------------------

    for(int i = 0; i < n; i++)
    {
        mas[i] = (int*)realloc(mas[i], (m + 1) * sizeof(int));
    }

    int index = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = m; j > index; j--)
        {
            mas[i][j] = mas[i][j - 1];
        }
        mas[i][index] = -101;
    }
    m++;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        free(mas[i]);
    }
    free(mas);

    cout << endl << endl;

/////////////////////////////////////////////////////////////////////
//----- C++ Style ----------------------------

    int **arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 21;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
    return 0;
}
