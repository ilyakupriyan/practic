#include <iostream>
#include <conio.h>
#include <time.h>

#define SIZE_DEST 300
#define SIZE_MAS 1000

int mas[SIZE_MAS];

//������� ����������� ���������� ���������� ���������
int def_elements() {
	unsigned int size = 0;
	std::cout << "Number of copying from arr1 to arr2" << std::endl;
	std::cin >> size;
	//������ �� ������������ ������������� �������
	while (size > SIZE_DEST) {
		std::cout << "Invalide size" << std::endl;
		std::cin >> size;
	}
	return size;
}

//������� ����������� ��������� �� ������ ������� � ������
void copyMas(int* source, int* dest, int size) {
	for (int a = 0; a < size; a++) 
		dest[a] = source[a];
}

//������� ������ �������
void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	srand(time(NULL)); //���������� �������
	unsigned int number = 0; //���������� ��� �������� ���������� ���������� ���������
	int dest[SIZE_DEST] = { 0 };
	
	//��������� ������ mas[]
	for (int i = 0; i < SIZE_MAS; i++)
		mas[i] = rand() % 100;

	number = def_elements();
	copyMas(&mas[0], &dest[0], number);

	//��������� (��� mas ������ �� �����, ������� ���������� � ������������ ��������)
	std::cout << "Array mas" << std::endl;
	printArr(&mas[0], SIZE_DEST);
	std::cout << "Array dest" << std::endl;
	printArr(&dest[0], SIZE_DEST);

	_getch();
	return 0;
}