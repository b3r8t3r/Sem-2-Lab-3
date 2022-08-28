#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <locale>
#include <string>
#include <Windows.h>
#include <map>
#include <stdlib.h>

using namespace std;

typedef map<double, double> MP;

void vivod(MP& FunctResults,int count) {
	for (auto values: FunctResults) {
		cout << fixed << setprecision(3) << ++count << ":\t|\tx = " << values.first << "\t|\ty = " << values.second << endl;
	}
}

void funct1() { //Задание №1
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << "Задание №1: Вычислить и вывести на экран или в файл в виде таблицы значения функции, \nзаданной графически, на интервале от Xнач до Xкон с шагом dx. Интервал и шаг задать таким образом, \nчтобы проверить все ветви программы. Таблица должна иметь заголовок и шапку." << endl;
	int count = 0;
	map <double, double> FunctResults;
	double x = 0, y = 0, x_begin = -5, x_end = 5, dx = 0.1;
	cout << "Введите начало и конец интервала, а также его шаг: " << endl;
	cin >> x_begin >> x_end >> dx;
	cout << endl << "Таблица результатов вычисления значений данного графика функций" << endl << "————————————————————————————————————————————————" << endl << "№\t|\tX\t\t|\tY" << endl << "————————————————————————————————————————————————" << endl;
	for (x = x_begin; x <= x_end; x += dx) {
		if ((x <= -2) || (x >= 2)) {
			FunctResults[x] = (abs(x) - 2) / 3;
		}
		if ((x > -2) && (x < 2) && (x != 0)) {
			FunctResults[x] = log(abs(1 / tan(x / 2)));
		}
	}
	vivod(FunctResults, count);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

double n = 1;

double Summary(double x, double deep) {	//Функция для расчета значения y(x)
	double sum, element, k;
	for (sum = 0, element = 1; fabs(element) >= deep; n++) {
		sum += element;
		k = (4 * n - 5) / (4 * n);
		element = element*k*(-x);
	}
	return (sum);
}

void funct2() {	//Задание №2
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << "Задание №2: Вычислить и вывести на экран в виде таблицы значения функции, \nзаданной с помощью степенного ряда, на интервале от Xнач до Xкон с шагом dx с \nточностью E (вводится пользователем).Таблица должна иметь заголовок и шапку. \nКаждая строка таблицы должна содержать значение аргумента, значение функции и \nколичество просуммированных членов ряда." << endl << endl;
	int count;
	double x, y, deep = 0.0001, x_begin, x_end, dx;
	cout << "Введите начало и конец интервала, а также его шаг (в пределах от |x|<1): " << endl;
	cin >> x_begin >> x_end >> dx;
	while ((abs(x_begin) > 1) && (abs(x_end) > 1)) {
		cout << "Вы неверно введи пределы: |x|<1. Попробуйте еще раз." << endl << "Введите начало и конец интервала:";
		cin >> x_begin >> x_end;
	}
	int f = 0;
	cout << "Введите точность определяемого значения:\n: ";
	cin >> f;
	deep = 1 * pow(10, -f);
	cout << endl << "Сравнение результатов вычисления ряда Тейлора для функции (1+x)^(1/4) и результатов функции (1+x)^(1/4)" << endl << "————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl << "№\t|\tX\t\t|\tКол-во членов ряда\t|\tРяд Тейлора\t|\tОригинальная функция (1+x)^(1/4)" << endl << "————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
	for (x = x_begin, count = 1; x <= x_end; x += dx, count++) {
		if (abs(x)<dx/10) continue;
		y = Summary(x, deep);
		cout << fixed << setprecision(f) << count << "\t|\tx = " << x << "\t|\tn = "<< n <<"\t\t|\tsum = " << y << "\t|\t(1 + " << x << ")^(1/4) = " << pow((1 + x), (1 / 4.0)) << endl;
		n = 1;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void funct3() {	//Задание №3
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Задание №3: Реализовать a^x mod p Сравнения по модулю простого числа через теорему Ферма и свойства сравнений." << endl;
	int a = 2, b = 11, p = 8;	//a - основание, b - степень, p - делитель
	cout << "Введите a, b и p: " << endl;
	cin >> a >> b >> p;
	cout << "a^b mod p = " << a << "^" << b << " mod " << p << " = ";
	b %= (p - 1);
	a %= p;
	int result = 1;	//остаток от деления
	if (b == 0) result = 0;
	for (int x = 1; x <= b; x++) {
		result *= a;
		result %= p;
	}
	cout << result << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void funct4() {	//Задание №4
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Задание №4: Реализовать обобщенный алгоритм Евклида для вычисления с*d mod m=1." << endl;
	int b = 262, a = 22, rDecrease1 = b, rZero = a, r = 0, q = 0;
	cout << "Введите b и a: " << endl;
	cin >> b >> a;
	rDecrease1 = b;
	rZero = a;
	while (rZero>0) {
		q = rDecrease1 / rZero;
		r = rDecrease1 - q * rZero;
		rDecrease1 = rZero;
		rZero = r;
	}

	cout << "НОД(" << a << ", " << b << ") = " << rDecrease1 << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int mod(int x_a, int y_a, int z_a){	//Нахождение секретного ключа шифрования

	for (; x_a < z_a; x_a++)
	{
		if (x_a * y_a % z_a == 1) {
			return x_a;
		}
	}

}

int gcd(int x, int y){	//Нахождение НОД
	return y ? gcd(y, x % y) : x;
}
 
//int RashAlgEv(int a, int b) {
//	int x = 0, y = 0, x_1 = 1, x_2 = 0, y_1 = 1, y_2 = 0, q, r,z=0 ,i=0;
//	while (b > 0) {
//		i++;
//		cout << "Итерация №" << i << endl;
//		q = a / b;	//Результат целочисленного деления 
//		cout << "q = a / b = " << a << " / " << b << " = " << q << endl;
//		r = a - q * b;	//Остаток от деления
//		cout << "r = a - q * b = " << a << " - " << b << " * " << q << " = " << a << " - " << b * q << " = " << r << endl;
//		x = x_2 - q * x_1;
//		cout << "x = x_2 - q * x_1 = " << x_2 << " - " << q << " * " << x_1 << " = " << x_2 << " - " << q * x_1 << " = " << x << endl;
//		y = y_2 - q * y_1;
//		cout << "y = y_2 - q * y_1 = " << y_2 << " - " << q << " * " << y_1 << " = " << y_2 << " - " << q * y_1 << " = " << y << endl << endl;
//		a = b;
//		cout << "a = b = " << a << endl;
//		b = r;
//		cout << "b = r = " << b << endl;
//		x_2 = x_1;
//		cout << "x_2 = x_1 = " << x_2 << endl;
//		x_1 = x;
//		cout << "x_1 = x = " << x_1 << endl;
//		y_2 = y_1;
//		cout << "y_2 = y_1 = " << y_2 << endl;
//		y_1 = y;
//		cout << "y_1 = y = " << y_1 << endl << endl;
//	}
//
//	z = a;
//	cout << "Вне цикла:" << endl << "z = a = " << z << endl;
//	x = x_2;
//	cout << "x = x_2 = " << x << endl;
//	y = y_2;
//	cout << "y = y_2 = " << y << endl;
//	return abs(z);
//}

typedef tuple <int, int, int> TP;

TP RashAlgEv(int a, int b) {
	tuple<int,int,int> X = { a,1,0 }, Y = { b,0,1 }, T = { 0,0,0 };
	int q = 0,i = 0;
	
	while (get<0>(Y) != 0) {
		cout << "Итерация №" << i << endl;
		cout << "X: ( " << get<0>(X) << ", " << get<1>(X) << ", " << get<2>(X) << " )" << endl;
		cout << "Y: ( " << get<0>(Y) << ", " << get<1>(Y) << ", " << get<2>(Y) << " )" << endl;
		q = get<0>(X) / get<0>(Y);
		cout << "q = x1 / y1 = " << get<0>(X) << " / " << get<0>(Y) << " = " << q << endl;
		T = { get<0>(X) % get<0>(Y),get<1>(X) - q * get<1>(Y),	get<2>(X) - q * get<2>(Y) };
		cout << "T: ( " << get<0>(X) << " % " << get<0>(Y) << " = " << get<0>(T) << ", " << get<1>(X) << " - " << q << " * " << get<1>(Y) << " = " << get<1>(T) << ", " << get<2>(X) << " - " << q << " * " << get<2>(Y) << " = "  << get<2>(T) << " )" << endl;
		X = Y;
		cout << "X = Y = (" << get<0>(X) << " "<< get<1>(X) << " " << get<2>(X) << ")" << endl;
		Y = T;
		cout << "Y = T = (" << get<0>(Y) << " " << get<1>(Y) << " " << get<2>(Y) << ")" << endl << endl;
		i++;
	}
	cout << "X: ( " << get<0>(X) << " " << get<1>(X) << " " << get<2>(X) << " )" << endl;
	cout << "Y: ( " << get<0>(Y) << " " << get<1>(Y) << " " << get<2>(Y) << " )" << endl;
	cout << "T: ( " << get<0>(T) << " " << get<1>(T) << " " << get<2>(T) << " )" << endl;
	cout << "d = " << get<0>(X) << ", u = " << get<1>(X) << ", v = " << get<2>(X) << endl;
	return X;
}

int AlgEv(int num, int pow, int mod) {	//Расширенный алгоритм Евклида для нахождения остатка от деления числа num в степени pow на число mod
	//cout << "----------------------------------" << endl << "Проверка расширенного алгоритма Евклида на работоспособность" << endl << "Принятые значения: " << endl << "число (num) - " << num << ", степень числа (pow) - " << pow << ", делитель (num) - " << num << endl << endl;
	pow = pow % (mod - 1);
	num %= mod;
	//cout << "Измененные значения:" << endl << "num = " << num << ", pow = " << pow << ", mod = " << mod << endl;
	//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << "Начало цикла для вычисления остатка от деления" << endl;
	int result = 1;
	//cout << "i < " << pow << endl;
	for (int i = 1; i <= pow; i++) {
		//cout << "i = " << i << endl;
		//cout << result << " *= " << num << " = ";
		result *= num;
		//cout << result << endl << result << "%=" << mod << " = ";
		result %= mod;
		//cout << result << endl << endl;
	}
	//cout << "Конец цикла для вычисления остатка от деления" << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	return(result);
}

string encode(string str, int key) {	//Шифровка Гронсфельда

	int keyLen = 0;
	for (int temp = key; temp > 0; keyLen++) {	//Вычисление длины ключа
		temp /= 10;
	}

	for (int i = 0, t1; i < str.length(); i++) {
		t1 = pow(10, i % keyLen);	//Вычисляем переменный сдвиг
		str[i] += ((key / t1) % 10);
	}

	return str;
}

string decode(string str, int key) {	//Дешифровка по Гронсфельду

	int keyLen = 0;
	for (int temp = key; temp > 0; keyLen++) {
		temp /= 10;
	}

	for (int i = 0, t1; i < str.length(); i++) {
		t1 = pow(10, i % keyLen);
		str[i] -= ((key / t1) % 10); 
	}

	return str;
}

int public_key_1(int p_a, int q_a) {
	int N_a = p_a * q_a;

	return N_a;
}

int public_key_2(int p_a, int q_a) {
	int fi_N = (p_a - 1) * (q_a - 1);
	
	return fi_N;
}

void funct5() {	//Задание №5
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Задание №5: Написать программу, использующую алгоритм шифрования данных RSA для преобразования исходного текста." << endl;
	int p_a, q_a, N_a, Y_a, fi_N, key_encode, key_decode, e, result, X_a = 1;	//p_a, q_a - части для нахождения открытого ключа шифрования; N_a, Y_a - открытые ключи шифрования
	string str, str_encode, str_decode;	//Текст для шифровки/дешифровки
	cout << "------------------------------------------------" << endl << "Действия от лица пользователя №1:" << endl << "------------------------------------------------" << endl << "Введите 3 простых числа" << endl;
	cin >> p_a >> q_a >> Y_a;
	cout << "Первые 2 числа - это ваш приватный ключ" << endl;

	N_a = public_key_1(p_a, q_a);
	fi_N = public_key_2(p_a, q_a);

	while (gcd(Y_a, fi_N) == 0) {	//Проверка на то, являются ли ключи взаимно простыми
		cout << "Числа не взаимно простые, введите новое простое число" << endl;
		cin >> Y_a;
	}

	cout << "Открытые ключи пользователя №1 (доступны всем): " << N_a << " и " << Y_a << endl;

	cout << "------------------------------------------------" << endl << "Действия от лица пользователя №2:" << endl << "------------------------------------------------" << endl << "Вам нужно закодировать какое-либо сообщение и передать его пользователю №1" << endl;
	cout << "Введите ключ (число сдвигов в слове) и само слово:" << endl;
	cin >> key_encode;
	cin.ignore(32767, '\n');
	getline(cin, str);

	str_encode = encode(str, key_encode);
	cout << "Это ваше зашифрованное слово" << endl << str_encode << endl;

	e = AlgEv(key_encode, Y_a, N_a);	//Зашифрованное число сдвигов
	cout << "Теперь пользователь №2 отправляет зашифрованный сдвиг пользователю №1 : e = " << e << endl;

	cout << "------------------------------------------------" << endl << "Действия от лица пользователя №1:" << endl << "------------------------------------------------" << endl << "Вам пришло зашифрованное письмо от пользователя №2" << endl << "Расшифровка сообщения прошла успешно: ";
	key_decode = AlgEv(e, mod(X_a, Y_a, fi_N), N_a);	//Расшифрованное число сдвигов
	str_decode = decode(str_encode, key_decode);
	cout << str_decode << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void Fibonachi() {
	int num_1 = 0, num_2 = 1, k = 0, n;
	cout << "Введите выводимое количество чисел из ряда Фибоначчи:" << endl;
	cin >> n;
	cout << "Числа Фибоначчи:" << endl << num_1 << " " << num_2 << " ";
	for (int i = 0; i < n-2; i++) {
		k = num_1 + num_2;
		num_1 = num_2;
		num_2 = k;
		cout << k << " ";
	}
}

int main() {
	//funct1();
	//funct2();
	funct3();
	//funct4();
	//funct5();
	//Fibonachi();
	//TP test;
	//test = RashAlgEv(28,19);
	

	return 0;
}