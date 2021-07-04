#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>

using namespace std;

const double g = 9.81;

struct list_phys {
    double pos = 0;
    double spd = 0;
    double accel = -g;
    double time = 0;
    string direct = "Up";
    list_phys* next = NULL;
};

//функция вывода списка с метками
void printMarks(list_phys* mark) {
    cout.precision(3);
    cout << setw(8) << left << "Time" 
         << setw(9) << left << "Speed" 
         << setw(12) << left << "Height" 
         << setw(16) << left << "Acceleretion" 
         << setw(13) << left << "Direction" << endl;


    while (mark != NULL) {
        cout << setw(8) << left << mark->time
             << setw(9) << left << mark->spd
             << setw(12) << left << mark->pos
             << setw(16) << left << mark->accel
             << setw(13) << left << mark->direct << endl;
        mark = mark->next;
    }
}

//функиця проверки времени на принадлежность промежутка до 1-го падения
int testTime(double start_v, double t) {
    static double time_max = (2 * start_v) / g;
    if (t > time_max || t < 0)
        return -1;
    return 0;
}

//функция определния направления движения тела
string direction(double v) {
    if (v > 0)
        return "Up";
    if (v == 0)
        return "Not defined";
    if (v < 0)
        return "Down";
}

//функция определения высоты в момент времени
double position(double start_v, double t) {
    return start_v * t - (g * t * t) / 2;
}

//функция определения скорости в момент времени
double speed(double start_v, double t) {
    return start_v - g * t;
}

//фукнция добавления метки в список
void pushMark(list_phys* marks, list_phys* new_mark) {
    list_phys* copy_mark = marks;

    while (copy_mark->next != NULL)
        copy_mark = copy_mark->next;
    copy_mark->next = new_mark;

    //записываем значения скорости, высоты и направления движения для заданного времени
    new_mark->spd = speed(marks->spd, new_mark->time);
    new_mark->pos = position(marks->spd, new_mark->time);
    new_mark->direct = direction(new_mark->spd);
}

static void runTest(int (*testFunction)(), const string& testName)
{
    if (testFunction() == 0)
        cout << "Test " << testName << " - OK" << endl;
    else
        cout << "Test " << testName << " - FAIL" << endl;
}

int main() {
    //здесь надо вставить тесты основных функций

    double v, t_mark = 0, mass; //переменные для хранения нач. скорости, метки времени полета и массы
    list_phys* marks = new list_phys; //список меток времен
    list_phys* temp; //адрем нового элемента списка

    cout << "Mass of object: ";
    cin >> mass;
    cout << "Start speed: ";
    cin >> marks->spd; //первый элемент списка зарезервирован под начальные характеристики

    //ввод меток времени
    while (t_mark != -2) {
        cout << "Mark of time (-2 is the end of entering): ";
        cin >> t_mark;
        while (  (testTime(marks->spd, t_mark)) == -1 && t_mark != -2) {
            cout << "Incorrect time. Enter the correct time!" << endl;
            cout << "Mark of time (-2 is the end of entering): ";
            cin >> t_mark;
        }

        //создаем новый элемент списка и сохраняем в нее метку времени
        if (t_mark != -2) {
            temp = new list_phys;
            temp->time = t_mark;
            pushMark(marks, temp);
        }
    }

    printMarks(marks);
    _getch();
    return 0;
}