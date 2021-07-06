#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

struct Image {
	int mx = 0;
	int my = 0;
	int* pixels;
};

//функция создания изображения
void createImage(Image* img, int tmx, int tmy)
{
	img->mx = tmx;
	img->my = tmy;
	img->pixels = new int[tmx * tmy]{ 0 };
}

//функция добавления точки на изображение
void setPointImage(Image* img, int x, int y, int color)
{
	img->pixels[((img->my - 1) - y) * img->mx + x] = color;
}

//функция получение точки на изображении
int getPointImage(Image* img, int x, int y)
{
	return img->pixels[((img->my - 1) - y) * img->mx + x];
}

//функция отображения изображения на экран в pnm формате
void showImage(Image* img)
{
	for (int y = 0; y <= img->my - 1; y++)
	{
		for (int x = 0; x < img->mx; x++)
		{
			cout << img->pixels[y * img->mx + x] << " ";
		}
		cout << endl;
	}
}

//функция сохранения изображения в pnm формате
void saveImage(Image* img, string filename)
{
	filename = filename + ".pnm";
	fstream out;
	out.open(filename, fstream::out);
	out << "P1" << endl;
	out << img->mx << " " << img->my << endl;

	for (int y = 0; y <= img->my - 1; y++)
	{
		for (int x = 0; x < img->mx; x++)
		{
			out << img->pixels[y * img->mx + x] << " ";
		}
		cout << endl;
	}

	out.close();
}


bool testCreateImage()
{
	Image* im = new Image;
	createImage(im, 2, 5);

	if (im->pixels[0] == 0 && im->pixels[9] == 0 && im->mx == 2 && im->my == 5)
		return 0;

	return -1;
}

bool testGetPointImage()
{
	Image* im = new Image;
	createImage(im, 2, 5);
	im->pixels[9] = 255;

	if (getPointImage(im, 1, 0) == 255 && getPointImage(im, 1, 2) == 0)
		return 0;

	return -1;
}

bool testSetPointImage()
{
	Image* im = new Image;
	createImage(im, 2, 5);
	setPointImage(im, 1, 0, 127);
	setPointImage(im, 1, 4, 255);

	if (getPointImage(im, 1, 0) == 127 && getPointImage(im, 1, 4) == 255)
		return 0;

	return -1;
}

void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction() == 0)
		cout << "Test " << testName << " - OK" << endl;
	else
		cout << "Test " << testName << " - FAIL" << endl;
}

int main()
{
	runTest(testCreateImage, "CreateImage");
	runTest(testGetPointImage, "GetPointImage");
	runTest(testSetPointImage, "SetPointImage");

	Image* img_ptr = new Image;
	createImage(img_ptr, 6, 6);
	for (int i = 0; i < 6; i++) {
		setPointImage(img_ptr, i, i, 1);
	}
	showImage(img_ptr);
	saveImage(img_ptr, "hello_image");

	_getch();
	return 0;
}