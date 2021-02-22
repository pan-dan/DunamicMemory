#include <iostream>

template <typename T>void push_row_back(T**& arr, int& m, const int n, T value)
{
	//1 ������ �������� ������ ����������
	T** buffer = new T * [m + 1]{};

	//2 �������� ������ ����� ������� � �������� ������ ����������

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}

	//3 ������� ��������� ������ ����������
	delete[] arr;


	//4 �������, ��� ����� - ��� ����� ������
	arr = buffer;

	//5 ������ � ����� ������� ���� ����� ��� ���������� ��� ����� ������
	buffer[m] = new T[n]{};

	// ������������� �������
	for (int i = 0; i < n; i++)
	{
		buffer[m][i] = value;
	}

	//6 ����� ���������� ������ � ������, ���������� ��� ����� ������������� �� ����
	m++;


}
template <typename T>void push_row_front(T**& arr, int& m, const int n, T value)
{

	T** buffer = new T * [m + 1]{};
	buffer[0] = new T[n]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr;

	for (int i = 0; i < n; i++)
	{
		buffer[0][i] = value;
	}


	arr = buffer;
	m++;
}
template <typename T>void insert_row(T**& arr, int& m, const int n, T value, int index)
{
	if (index > m)return;
	T** buffer = new T * [m + 1]{};


	//for (int i = 0; i < m + 1; i++)
	//{
	//	buffer[i] = new int[n] {};
	//}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new T[n]{};
	for (int i = index; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	for (int i = 0; i < n; i++)
	{
		buffer[index][i] = rand();
	}
	arr = buffer;

	/*arr[index] = new int[n] {};*/
	m++;
}


template <typename T>void push_col_back(T**& arr, const int m, int& n, T value)
{
	T** buffer = new T * [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}

	delete[] arr;
	arr = buffer;


	for (int i = 0; i < m; i++)
	{
		arr[i][n] = value;
	}
	n++;

}
template <typename T>void push_col_front(T**& arr, const int m, int& n, T value)
{
	T** buffer = new T * [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		delete arr[i];
	}
	delete[] arr;

	for (int i = 0; i < m; i++)
	{
		buffer[i][0] = value;
	}

	arr = buffer;
	n++;
}
template <typename T>void insert_col(T**& arr, const int m, int& n, T value, int index)
{
	if (index > m)return;
	T** buffer = new T * [m] {};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1]{};

		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}

		for (int z = index; z < n; z++)
		{
			buffer[i][z + 1] = arr[i][z];
		}

		delete arr[i];
	}
	delete[] arr;

	for (int i = 0; i < m; i++)
	{
		buffer[i][index] = value;
	}

	arr = buffer;
	n++;
}


template <typename T>void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m - 1]{};

	for (int i = 0; i < m - 1; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;
	--m;

}
template <typename T>void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m - 1]{};

	for (int i = 0; i < m - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;

	arr = buffer;
	--m;

}
template <typename T>void erase_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [m - 1]{};

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;


	arr = buffer;
	m--;
}


template <typename T>void pop_col_back(T**& arr, const int m, int& n)
{
	T** buffer = new T * [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template <typename T>void pop_col_front(T**& arr, const int m, int& n)
{
	T** buffer = new T * [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;
}
template <typename T>void erase_col(T**& arr, const int m, int& n, int index)
{
	if (index >= m)return;

	T** buffer = new T * [m] {};


	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1]{};

		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}

		for (int z = index; z < n; z++)
		{
			buffer[i][z] = arr[i][z + 1];
		}

		delete arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;
}

#ifdef One_DimensionalArray

template <typename T>
void push_back_mutable(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer;		// ����� ������� �������� ������ arr �� ������ brr
	arr[n] = value;
	n++;
}


//��������� �������� � ������ �������
template <typename T>
void push_front_mutable(T*& arr, int& n, T value)
{
	// 1. ������ �������� ������ ������� �������
	T* buffer = new T[n + 1]{};
	// 2. �������� �������� �� ��������� ������� � �������� (�� ��������� �� 1 �������)
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	// 3. ������� ������
	delete[] arr;
	// 4. �������a�� ��������� �� ����� ������ �������
	arr = buffer;
	// 5. ��������� �������� � ������ �������
	arr[0] = value;
	// 6. ����������� ����� �������
	n++;
}

template <typename T>
void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
	//1 �������
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}*/

	/*for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}*/

	//2 �������
	for (int i = 0; i < n; i++)
	{
		//if (i < index)  buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];

	}
	delete[] arr;

	arr = buffer;
	arr[index] = value;
	n++;
}

template <typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer;
}

template <typename T>
void pop_front(T*& arr, int& n)
{
	T* buffer = new T[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	arr = buffer;

}

template <typename T>
void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[--n];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	arr = buffer;
}
#endif // One-DimensionalArray

