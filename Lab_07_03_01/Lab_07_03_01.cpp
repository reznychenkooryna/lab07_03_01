#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
bool Part1_CountRowsWithZero(int** a, const int rowCount, const int colCount, int& count);
void Part2_LongestSeriesColumn(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -17;
    int High = 15;

    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int count = 0;
    if (Part1_CountRowsWithZero(a, rowCount, colCount, count))
        cout << "count = " << count << endl;
    else
        cout << "there are no zero elements" << endl;
    cout << endl;

    Part2_LongestSeriesColumn(a, rowCount, colCount);
    cout << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool Part1_CountRowsWithZero(int** a, const int rowCount, const int colCount, int& count)
{
    bool result = false;
    count = 0;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] == 0)
            {
                count++;
                result = true;
                break;
            }
        }
    }

    return result;
}

void Part2_LongestSeriesColumn(int** a, const int rowCount, const int colCount)
{
    cout << "Saddle points: max in row & min in col" << endl;
    cout << setw(4) << "No" << setw(8) << "Col" << setw(12) << "MaxLen" << endl;

    int No = 0;
    int globalMaxLen = 1;
    int bestCol = 0;

    for (int j = 0; j < colCount; j++)
    {
        int currentLen = 1;
        int maxLenInCol = 1;

        for (int i = 1; i < rowCount; i++)
        {
            if (a[i][j] == a[i - 1][j])
                currentLen++;
            else
                currentLen = 1;

            if (currentLen > maxLenInCol)
                maxLenInCol = currentLen;
        }

        cout << setw(4) << ++No << setw(8) << j << setw(12) << maxLenInCol << endl;

        if (maxLenInCol > globalMaxLen)
        {
            globalMaxLen = maxLenInCol;
            bestCol = j;
        }
    }

    cout << "Column with the longest identical series: " << bestCol << " (length = " << globalMaxLen << ")" << endl;
}