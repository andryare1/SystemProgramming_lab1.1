#include <iostream>
#include <stdexcept>
#include <array>
#include "RTriangle.h"

using namespace std;

int main() {
    int numbers_triangles;
    while (true) {
        cout << "Введите количество треугольников: ";
        cin >> numbers_triangles;
        if (cin.good() && numbers_triangles > 0) {
            break;
        } else {
            cout << "Не может быть 0 или меньше треугольников. Пожалуйста, введите снова." << endl;
            cin.clear(); // Сбрасываем флаг ошибки
            while (cin.get() != '\n'); // Игнорируем оставшиеся символы в строке
        }
    }

    RTriangle* triangles = new RTriangle[numbers_triangles];

    for (int i = 0; i < numbers_triangles; i++) {
        double a, b;
        while (true) {
            cout << "Введите катет A треугольника " << i + 1 << ": ";
            cin >> a;
            if (cin.good() && a > 0) {
                break;
            } else {
                cout << "Катет A должен быть больше 0. Введите снова." << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
        }

        while (true) {
            cout << "Введите катет B треугольника " << i + 1 << ": ";
            cin >> b;
            if (cin.good() && b > 0) {
                break;
            } else {
                cout << "Катет B должен быть больше 0. Введите снова." << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
        }

        try {
            triangles[i] = RTriangle(a, b);
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return 0;
        }
    }

    cout << endl << "ВЫБЕРИТЕ НУЖНОЕ ДЕЙСТВИЕ\n1- увеличить размер стороны на %\n2- уменьшить размер стороны на %\n3- вычислить радиус описанной окружности\n4- вычислить полупериметр\n5- определить значения углов\n0 - выйти из программы";

    while (true) {
        int choice;
        cout << endl << "Ваш выбор действия: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        int index_triangle;
        while (true) {
            cout << "Выберите какой треугольник вы хотите выбрать (всего их " << numbers_triangles << "): ";
            cin >> index_triangle;
            if (cin.good() && index_triangle >= 1 && index_triangle <= numbers_triangles) {
                break;
            } else {
                cout << "Недопустимый индекс треугольника. Пожалуйста, введите снова." << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
        }

        switch (choice) {
            case 1: {
                char side_choice;
                cout << "Выберите сторону A или B: ";
                cin >> side_choice;

                double percent;
                cout << "Введите процент увеличения: ";
                cin >> percent;

                if (side_choice == 'A' || side_choice == 'a') {
                    triangles[index_triangle - 1].resizeAPlus(percent);
                    cout << "Сторона изменена: " << triangles[index_triangle - 1].getA() << endl;
                } else {
                    triangles[index_triangle - 1].resizeBPlus(percent);
                    cout << "Сторона изменена: " << triangles[index_triangle - 1].getB() << endl;
                }
                break;
            }
            case 2: {
                char side_choice;
                cout << "Выберите сторону A или B: ";
                cin >> side_choice;

                double percent;
                cout << "Введите процент уменьшения: ";
                cin >> percent;

                if (side_choice == 'A' || side_choice == 'a') {
                    double newA = triangles[index_triangle - 1].getA() * (1 - percent / 100);
                    if (newA > 0) {
                        triangles[index_triangle - 1].resizeAMinus(percent);
                        cout << "Сторона изменена: " << triangles[index_triangle - 1].getA() << endl;
                    } else {
                        cout << "Сторона A не может быть меньше или равна 0." << endl;
                    }
                } else if (side_choice == 'B' || side_choice == 'b') {
                    double newB = triangles[index_triangle - 1].getB() * (1 - percent / 100);
                    if (newB > 0) {
                        triangles[index_triangle - 1].resizeBMinus(percent);
                        cout << "Сторона изменена: " << triangles[index_triangle - 1].getB() << endl;
                    } else {
                        cout << "Сторона B не может быть меньше или равна 0." << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Радиус описанной окружности: " << triangles[index_triangle - 1].getRadius() << endl;
                break;
            case 4:
                cout << "Полупериметр: " << triangles[index_triangle - 1].getHalfMeter() << endl;
                break;
            case 5: {
                array<double, 3> angles = triangles[index_triangle - 1].getAngle();
                for (double angle : angles) {
                    cout << angle << " ";
                }
                cout << endl;
                break;
            }
            default:
                cout << "Нет такого варианта" << endl;
                break;
        }
    }

    delete[] triangles; 
    return 0;
}
