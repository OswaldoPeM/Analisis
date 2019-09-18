#include<iostream>
#include<time.h>
#include<ctime>

using namespace std;

int fibbonacciRecursiva(int n);
int fibbonacciNoRecursiva(int n);
int fibonacciFormulaExplicita(int n);

int main() {
	unsigned t1, t2;
	int n = 0;
	for ( n = 0; n < 43; n++)
	{

	t1 = clock();
	cout << fibbonacciNoRecursiva(n) << endl;
	t2 = clock();
	cout << (double(t2 - t1) / CLOCKS_PER_SEC) << endl;
	
	t1 = clock();
	cout << fibbonacciRecursiva(n) << endl;
	t2 = clock();
	cout << (double(t2 - t1) / CLOCKS_PER_SEC) << endl<<endl;
	}
	system("pause");
	return 0;
}

int fibbonacciRecursiva(int n)
{
	if (n < 2)return n;
	return fibbonacciRecursiva(n-2)+fibbonacciRecursiva(n-1);
}

int fibbonacciNoRecursiva(int n)
{
	int A = 0;	
	int	B = 1;
	int C;

	for (int i = 1; i < n; i++)
	{
		C = A + B;
		A = B;
		B = C;
	}

	return B;
}

int fibonacciFormulaExplicita(int n)
{
	return 0;
}
