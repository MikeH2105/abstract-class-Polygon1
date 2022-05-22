//Створити абстрактний клас “Багатокутник”.Клас повинен містити методи для обчислення периметра, знаходження площі і ін.
//Побудувати похідний клас “Трикутник” і прямокутник, що містить також методи для знаходження довжин медіан, висот трикутника
#include <iostream>
#include<cmath>
#include<windows.h>
using namespace std;
class	Polygon {// створюємо базовий клас Багатокутник
public:
	virtual double getArial() = 0 {//віртуальна функція отримання площі трикутника базового класу 
	}
	virtual double GetPerimeter() = 0 { //віртуальна функція отримання площі трикутника базового класу
	}
};


class Triangle : public Polygon {//Похідний клас Трикутник від базового класу Багатокутник.
private:
	double AB, BC, CA;//змінні для сторін трикутника
	double Mediana = 0;//змінна для Медіани трикутника
	double Hight;//Змінна для висоти трикутника
public:
	Triangle(int AB, int BC, int CA) {
		this->AB = AB;
		this->BC = BC;
		this->CA = CA;
	}


	double medianaTriangle() {//метод знаходження медіани...
		Mediana = (sqrt(2 * pow(AB, 2) + 2 * pow(BC, 2) + 2 * pow(CA, 2))) / 2;
		return Mediana;
	}


	double heightTriangle() {//метод знаходження висоти трикутника...
		double sTriangl = 1;//змінна для знаходження площі для вирахування висоти
		sTriangl = (1 / 4) * (sqrt(AB + BC + CA) * (BC + CA - AB) * (AB + CA - BC) * (AB + BC - CA));
		Hight = 2 * sTriangl / AB;
		return Hight;

	}


	double getArial() override
	{
		return (Hight * AB) / 2;
	}


	double GetPerimeter() override
	{
		return AB + BC + CA;
	}

	~Triangle() {};

};

class Rectangl : public Polygon {//Похідний клас Прямокутник від базового класу Багатокутник.
private:
	int AB, BC; //створюємо змінні для сторін прямокутника

public:
	Rectangl(int AB, int BC) {
		this->AB = AB;
		this->BC = BC;
	}

	double heithgRectangle() {//функція знаходження висоти прямокутника = його сторона...
		return AB;
	}


	double getArial() override
	{
		return (AB * BC);
	}


	double GetPerimeter() override
	{
		return AB + BC * 2;
	}

	~Rectangl() {};


};


int main() {
	SetConsoleOutputCP(1251);
	Triangle A(5, 7, 9);
	Rectangl B(5, 7);
	cout << "Медіана трикутника = " << A.medianaTriangle() << endl;
	cout << "Висота трикутника = " << A.heightTriangle() << endl;
	cout << "Площа трикутника = " << A.getArial() << endl;
	cout << "Периметр трикутника = " << A.GetPerimeter() << endl;
	cout << "Висота прямокутника = " << B.heithgRectangle() << endl;
	cout << "Площа прямокутника = " << B.getArial() << endl;
	cout << "Периметр прямокутника = " << B.GetPerimeter() << endl;
}