#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void CalcSum(int** a, const int rowCount, const int colCount, int& S);
void CalcN(int** a, const int rowCount, const int colCount, int& k);
void Zero(int** a, const int rowCount, const int colCount);


int main()
{
	srand((unsigned)time(NULL));
	int Low = -42;
	int High = 51;
	int rowCount = 7;
	int colCount = 6;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	int S = 0;
	int k = 0;
	CalcSum(a, rowCount, colCount, S);
	CalcN(a, rowCount, colCount, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Zero(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
	{
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
		{
			if (a[i1][0] >  a[i1 + 1][0]	// Сортування за першим стовпцем (зростання)
			|| (a[i1][0] == a[i1 + 1][0] 
			&&  a[i1][1] <  a[i1 + 1][1])	// Сортування за другим стовпцем (спадання)
			|| (a[i1][0] == a[i1 + 1][0] 
			&&  a[i1][1] == a[i1 + 1][1] 
			&&  a[i1][2] >  a[i1 + 1][2]))  // Сортування за третім стовпцем (зростання)  
			Change(a, i1, i1 + 1, colCount);
		}
	}
}


void Change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[row1][j];         // значення з першого рядка у змінну
		a[row1][j] = a[row2][j];  // значення з 2 у 1 рядок
		a[row2][j] = tmp;         // значення зі змінної у 2 рядок
	}
}

void CalcSum(int** a, const int rowCount, const int colCount, int& S)
{
	S = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
			{
				S += a[i][j];
			}
}

void Zero(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
			{
				a[i][j] = 0;
			}
}

void CalcN(int** a, const int rowCount, const int colCount, int& k)
{
	k = 0; // кількість елементів
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!((a[i][j] > 0) && (a[i][j] % 5 == 0)))
			{
				k++;
			}
}