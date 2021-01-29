#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void FillRandPlus(int brr[], int arr[], const int nplus, int value);


void main()
{
	setlocale(LC_ALL, "Rus");

	int n;	//������ �������
	int nplus;

	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
// �������� �������� ���������� �������� � ������

	nplus = ++n;
	int* brr = new int[nplus];


	
	FillRandPlus(brr, arr, nplus, value);
	brr[nplus-1] = value;
	Print(brr, nplus);
	

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

