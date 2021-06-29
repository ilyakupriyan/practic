#include <iostream>
#include <conio.h>
#include <time.h>

#define SIZE_DEST 300
#define SIZE_MAS 1000

int mas[SIZE_MAS];

//функция определения количества копируемых элементов
int def_elements() {
	unsigned int size = 0;
	std::cout << "Number of copying from arr1 to arr2" << std::endl;
	std::cin >> size;
	//защита от переполнения копированного массива
	while (size > SIZE_DEST) {
		std::cout << "Invalide size" << std::endl;
		std::cin >> size;
	}
	return size;
}

//функция копирования элементов из одного массива в другой
void copyMas(int* source, int* dest, int size) {
	for (int a = 0; a < size; a++) 
		dest[a] = source[a];
}

//функция вывода массива
void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	srand(time(NULL)); //засеивание рандома
	unsigned int number = 0; //переменная для хранения количества копируемых элементов
	int dest[SIZE_DEST] = { 0 };
	
	//заполняем массив mas[]
	for (int i = 0; i < SIZE_MAS; i++)
		mas[i] = rand() % 100;

	number = def_elements();
	copyMas(&mas[0], &dest[0], number);

	//результат (для mas только та часть, которая соизмерима с копированным массивом)
	std::cout << "Array mas" << std::endl;
	printArr(&mas[0], SIZE_DEST);
	std::cout << "Array dest" << std::endl;
	printArr(&dest[0], SIZE_DEST);

	_getch();
	return 0;
}