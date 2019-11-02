#include<iostream>
#include<time.h>
#include<ctime>

using namespace std;

void imprimir(int arreglo[], int tam) {
	for (int i = 0; i < tam; i++)
	{
		std::cout << arreglo[i] << " ";
	}
	std::cout << std::endl;
}

void bubbleSort(int arreglo[], int tam, int tam2) {
	int temp = 0; // creo variable temporal donde almacenare el valor que quiero mover
	unsigned long int c = 0;
	bool orden = true;
	for (int i = 0; i < tam - 1; i++)
	{
		orden = true;
		for (int j = 1; j < tam2; j++)//
		{
			c++;
			if (arreglo[j] < arreglo[j - 1]) {// intercambia de lugar la mayor por la menor.
				temp = arreglo[j];
				arreglo[j] = arreglo[j - 1]; // cuando ya esta ordenado hace iteraciones de mas.
				arreglo[j - 1] = temp;
				orden = false;
			}
			//imprimir(arreglo, tam); //Imprime la lista.
		}
		if (orden) break;
		tam2--;
	}
	std::cout << c << " iteraciones reales\n";
}
void insertionSort(int arreglo[], int tam, int pos = 0, int temp = 0) {//creamos una variable para almacenar el dato que vamos a insertar, y una que useamos para saber posision 
	unsigned long int c = 0;
	for (int i = 0; i < tam; i++)
	{
		pos = i;
		temp = arreglo[i];
		while ((pos > 0) && (arreglo[pos - 1] > temp))// mietras el numero anterior sea mayor se ira moviendo el dato hacia la "izquierda".
		{
			//imprimir(arreglo, tam); //Imprime la lista.
			c++;
			arreglo[pos] = arreglo[pos - 1];
			pos--;

		}
		arreglo[pos] = temp;// inserta el menor a la izquierda.
	}
	std::cout << c << " iteraciones reales\n";
}
void seleccionSort(int arreglo[], int tam, int temp = 0, int min = 0) { // hacemos  una variable que contenga el dato minimo, y una que guarde la posision del dato minimo
	unsigned long int c = 0;
	bool orden;
	for (int i = 0; i < tam; i++)
	{
		orden = true;
		min = i;// ponemos la posicion de hasta la izquierda como la menor, asi si detectamos otro numero mas pequenio
		for (int j = i + 1; j < tam; j++)
		{
			c++;
			//imprimir(arreglo, tam); //Imprime la lista.
			if (arreglo[j] < arreglo[min]) // encuentra el dato minimo del arreglo
			{
				min = j;

			}
			if ((j != 0) && (arreglo[j] < arreglo[j - 1])) {
				orden = false;
			}
		}
		if (orden) break;
		temp = arreglo[i]; // Intercambia de lugar el menor con el de hasta la izquierda.
		arreglo[i] = arreglo[min];// Intercambia de lugar el menor con el de hasta la izquierda.
		arreglo[min] = temp;// Intercambia de lugar el menor con el de hasta la izquierda.
	}
	std::cout << c << " iteraciones reales\n";
}
unsigned long int vueltas = 0; 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{ 
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
	vueltas++;
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1], *R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;

}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
// funcion de geeks for geeks

int *output;
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) 
{ 
    output = new int[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(int arr[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp); 
		delete output;
	}

} 
void heapify(int arr[], int n, int root) {
	int largest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	if (l < n && arr[l] > arr[largest])		largest = l;
	if (r < n && arr[r] > arr[largest])		largest = r;
	if (largest != root)
	{
		swap(arr[root], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void createArrOrdenado(int *&arreglo, int tam) {
	arreglo = new int[tam];
	for (int i = 0; i < tam; i++)
	{
		arreglo[i] = i;
	}
}

void createArrDesordenado(int *&arreglo, int tam) {
	arreglo = new int[tam];
	for (int i = 0; i < tam; i++)
	{
		arreglo[i] = tam - i;
	}
}

void createArrRandom(int *&arreglo, int tam) {
	arreglo = new int[tam];
	for (int i = 0; i < tam; i++)
	{
		arreglo[i] = rand()%tam;
	}
}

void deleteArr(int *arreglo) {
	delete[] arreglo;
}

int main() {
	int *arreglo, opc = 0, tam = 100;
	unsigned t1, t2;
	createArrRandom(arreglo, tam);
	t1 = clock();
	t2 = clock();
	cout << (double(t2 - t1) / CLOCKS_PER_SEC) << endl;

	while (opc != 10)
	{
		imprimir(arreglo, tam);
		std::cout << "1 BubbleSort\n2 inserionSort\n";
		std::cout << "3 seleccionSort\n4 quickSort\n";
		std::cout << "5 para crear un arreglo ordenado\n";
		std::cout << "6 para crear un arreglo desordenado\n";
		std::cout << "7 para crear un arreglo random\n";
		std::cout << "8 Heap sort\n 9 Merge sort" << std::endl;
		std::cout << "10 SALIR" << std::endl;
		std::cin >> opc;
		switch (opc)
		{
		case 1:

			t1 = clock();
			bubbleSort(arreglo, tam, tam); // Acomoda arreglos de menor a mayor.
			t2 = clock();
			cout << "Tiempo " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
			//imprimir(arreglo, 5); //Imprime la lista.
			break;
		case 2:
			t1 = clock();
			insertionSort(arreglo, tam);// Acomoda arreglos de menor a mayor.
			t2 = clock();
			cout << "Tiempo " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
			//imprimir(arreglo, tam); //Imprime la lista.
			break;
		case 3:

			t1 = clock();
			seleccionSort(arreglo, tam);// Acomoda arreglos de menor a mayor.
			t2 = clock();
			cout << "Tiempo " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
			//imprimir(arreglo, tam); //Imprime la lista.
			break;
		case 4:
			if (true)
			{
				int equis = 0;
				t1 = clock();
				quickSort(arreglo, equis, tam - 1);// Acomoda arreglos de menor a mayor.
				t2 = clock();
				cout << "Tiempo " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
				std::cout << std::endl << "Iteraciones :" << vueltas << std::endl;
			}
			//imprimir(arreglo, tam); //Imprime la lista.
			break;
		case 5:
			deleteArr(arreglo);
			std::cout << "De que tamanio quiere el arreglo?" << std::endl;
			cin >> tam;
			createArrOrdenado(arreglo, tam);
			break;
		case 6:
			deleteArr(arreglo);
			std::cout << "De que tamanio quiere el arreglo?" << std::endl;
			cin >> tam;
			createArrDesordenado(arreglo, tam);
			break;
		case 7:
			deleteArr(arreglo);
			std::cout << "De que tamanio quiere el arreglo?" << std::endl;
			cin >> tam;
			createArrRandom(arreglo, tam);
			break;
		case 8:
			t1 = clock();
			heapSort(arreglo, tam);
			t2 = clock();
			cout << "Tiempo " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
			break;
		case 9:
			t1 = clock();
			mergeSort(arreglo, 0, tam - 1);
			t2 = clock();
			cout << "Tiempo " << (double(t2 - t1) / CLOCKS_PER_SEC) << " segundos" << endl;
			break;
		default:
			break;
		}
	}

	std::cin.ignore();
	std::cin.get();
	delete[] arreglo;
	return 0;
}