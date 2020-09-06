//Склад. Наименование товара, цена СДЕЛАТЬ БИТОВЫМИ, количество, процент торговой надбавки (5, 7, 11, 20, 25, 30). Выбор по цене. Процент торговой надбавки реализовать с помощью перечисления.
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
enum Procent
{
	pr1 = 5, pr2 = 7, pr3 = 11, pr4 = 20, pr5 = 25, pr6 = 30
} proc;

struct List
{
	char nameofTovar[50];
	unsigned price : 8; //одна ячейка памяти для хранения целых неотрицательных чисел от 0 до 255
	int	countofTovar;
};
void addElement(int& count);
void show(const int count);
void deleteElement(int& count);
void searchToPrice(const int count);
List* Rice;
List* tempRice;
FILE* f;
int main()
{
	setlocale(LC_ALL, "ru");
	int count = 0;
	int n;
	do
	{
		printf("Меню\nВвыберите пункт\n");
		printf("1-Добавить элемент\n");
		printf("2-показать все элементы\n");
		printf("3-поиск по цене\n");
		printf("4-удалить товар\n");
		std::cin >> n;
		switch (n)
		{
		case 1:
			addElement(count); break;
		case 2:
			show(count); break;
		case 3:
			searchToPrice(count); break;
		case 4:
			deleteElement(count); break;
		}
	} while (n != 0);

}
void addElement(int& count)
{
	int p;
	if (count == 0)
	{
		Rice = new List[1];	
		printf("Введите наименование товара\n");
		std::cin >> Rice[0].nameofTovar;
		printf("Введите количество товара\n");
		std::cin >> Rice[0].countofTovar;
		printf("Введите цену\n");
		int n;
		std::cin >> n;
		Rice[0].price = n;
		printf("Введите процент торговой надбавки (5, 7, 11, 20, 25, 30) \n");
		std::cin >> p;
		switch (p)
		{
		case 5:
			proc = pr1;
			break;
		case 7:
			proc = pr2;
			break;
		case 11:
			proc = pr3;
			break;
		case 20:
			proc = pr4;
			break;
		case 25:
			proc = pr5;
			break;
		case 30:
			proc = pr6;
				break;
		}
	}
	/*Есть счетчик элементов - count, мы передаем его в функцию
если он равен 0,то мы выделяем память под 1 объект и заполняем его.Затем увеличиваем счетчик на 1
Если элементы уже есть,то мы создаем временный массив, перекидываем туда уже имеющиеся рейсы,
старый массив очищаем и создаем размером на 1 больше,чем был.Затем из временного перекидываем в новый и последний элемент заполняем*/
	else
	{
		tempRice = new List[count];
		for (int i = 0; i < count; i++)
		{
			tempRice[i] = Rice[i];
		}
		delete[]Rice;
		Rice = new List[count + 1];
		for (int i = 0; i < count; i++)
		{
			Rice[i] = tempRice[i];
		}
		delete[]tempRice;
		printf("Введите наименование товара\n");
		std::cin >> Rice[count].nameofTovar;
		printf("Введите количество товара\n");
		std::cin >> Rice[count].countofTovar;
		printf("Введите цену\n");
		int n;
		std::cin >> n;
		Rice[count].price=n;
		printf("Введите процент торговой надбавки (5, 7, 11, 20, 25, 30) \n");
		std::cin >> p;
		switch (p)
		{
		case 5:
			proc = pr1;
			break;
		case 7:
			proc = pr2;
			break;
		case 11:
			proc = pr3;
			break;
		case 20:
			proc = pr4;
			break;
		case 25:
			proc = pr5;
			break;
		case 30:
			proc = pr6;
			break;
		}
	}
	count++;
}
void show(const int count)
{
	int n;
	std::cout << "Номер товара:\n" << std::endl;
	std::cin >> n;
	for (int i = 0; i < count; i++) {
		if (count != 0)
		{
			std::cout << "Наименование товара:\n" << Rice[i].nameofTovar << std::endl;
			std::cout << "Пункт количество товара:\n" << Rice[i].countofTovar << std::endl;
			std::cout << "Цена:\n" << Rice[i].price << std::endl;
			std::cout << "Процент торговой надбавки:\n" << proc << std::endl;
		}
		else
		{
			std::cout << "\nЭлементов еще нет\n";
		}
	}
}
void searchToPrice(const int count)
{
	int temp;
	std::cout << "Введите цену\n";
	std::cin >> temp;
	for (int i = 0; i < count; i++)
		if (temp == Rice[i].price)
		{
			std::cout << "Номер наименование товара:\n" << Rice[i].nameofTovar << std::endl;
			std::cout << "Пункт количество товара:\n" << Rice[i].countofTovar << std::endl;
			std::cout << "Цена:\n" << Rice[i].price << std::endl;
			std::cout << "Процент торговой надбавки:\n" << proc << std::endl;
		}
}
void deleteElement(int& count)
{
	string name;
	int flag = 0;
	std::cout << "Введите наименование товара\n";
	std::cin >> name;
	for (int i = 0; i < count; i++)
		if (Rice[i].nameofTovar == name)
			flag = 1;
	if (flag == 1)
	{
		count--;
		/*Первый цикл для того,чтобы определить,есть ли у нас элемент с таким номером.Если есть - флаг меняем на тру(1)
Если тру,то уменьшаем размер массива на 1,и если встретим нужный нам элемент,делаем доп итерацию (i++),чтобы пропустить его и записать уже следующий в новый массив*/
		List* tempMas = new List[count];
		for (int i = 0, j = 0; j < count; i++, j++)
		{
			if (Rice[i].nameofTovar == name)
			{
				i++;
			}
			tempMas[j] = Rice[i];
		}
		delete[]Rice;
		Rice = new List[count];
		for (int i = 0; i < count; i++)
			Rice[i] = tempMas[i];
		delete[]tempMas;
		std::cout << "Товар успешно удален\n";
	}
	else std::cout << "Такого товара не существует\n";
}