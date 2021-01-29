#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void FillRandPlus(int brr[], int arr[], const int nplus, int value);
void PrintPlus(int* brr, const int nplus);

void main()
{
	setlocale(LC_ALL, "Rus");

	int n;	//Размер массива
	int nplus;

	cout << "ВВедите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
// дописать алгоритм добавления элемента в массив

	nplus = ++n;
	cout << nplus << endl;
	int* brr = new int[nplus];


	
	FillRandPlus(brr, arr, nplus, value);
	brr[nplus-1] = value;
	PrintPlus(brr, nplus);
	

	delete[] arr;
	delete[] brr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void FillRandPlus(int brr[], int arr[], const int nplus, int value)
{
	for (int i = 0; i < nplus; i++)
	{
		*(brr + i) = *(arr + i);
	}
	
}

void PrintPlus(int* brr, const int nplus)
{
	for (int i = 0; i < nplus; i++)
	{
		cout << brr[i] << "\t";
	}
	cout << endl;
}