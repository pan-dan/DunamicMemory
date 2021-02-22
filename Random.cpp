#include <iostream>

template <typename T>void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Random(arr[i][j]);
			/*arr[i][j] = rand() % 100;*/
		}
	}
}

template<typename T>void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
	{
		variable = double(rand() % 10000) / 100;
	}
	else if (typeid(variable) == typeid(char))
	{
		variable = rand();
	}
	else
	{
		variable = T(); //«аписываем переменную по умолчанию
	}

}

#ifdef One_DimensionalArray
template <typename T> void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Random(arr[i]);
		/**(arr + i) = rand() % 100;*/
	}
}


#endif