#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <windows.h>
#include <conio.h>

extern void Task_1();
extern void Task_2();
extern void Task_3();
extern void Task_4();


class Main_menu
{
	std::vector<std::string> _menu_elements;
public:
	void AddElement(std::string menu_element){	_menu_elements.push_back(menu_element);	}
	void Show_menu();
	int User_Choice_Handle();
	int User_Choice_Handle(int key_code);
};

class Fraction
{
//private:
	int _numerator { 1 };
	int _denominator { 1 };	
	//static Fraction* Available_fractions;
	//static std::vector<Fraction*>* Available_fractions_pointer_to_vector;
	int MaxCommonDivider(int a, int b);
	void Fraction_reduction();
public:	
	Fraction(int A1, int A2, std::vector<Fraction*>& Available_fractions);// : _numerator(A1), _denominator(A2){	Available_fractions.push_back(this); Fraction_reduction();	}
	Fraction(std::vector<Fraction*>& Available_fractions) {	Available_fractions.push_back(this); }
	Fraction(int new_numerator, int new_denominator) : _numerator{ new_numerator }, _denominator{ new_denominator }	{ Fraction_reduction(); }
	Fraction() {}
	~Fraction()
	{
		//как получить доступ к внешнему вектору, в котором содержатся указатели на все объекты, 
		//которые надо удалить, если деструктор не принимает параметров???
	}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q2 Почему не могу заменить?
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	void Set_numerator(int numerator){	_numerator = numerator;	}
	//void Set_numerator(int numerator): _numerator{ numerator } {} //????????
	void Set_denominator(int denominator){	_denominator = denominator;	}
	int Get_numerator()	{	return _numerator;	}
	int Get_denominator(){	return _denominator;	}
	void ShowValues(){	std::cout << this->Get_numerator() << " / " << this->Get_denominator();	}
	int ShowMethods();
	void ShowAvailableFractions(std::vector<Fraction*> Available_fractions);
	static void Memory_Clean(const std::vector<Fraction*>& Available_fractions);		
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q1 Почему при передаче аргумента по константной ссылке перестают работать геттеры?
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::	
  
	//Overload operators - reference returned -----------------------------------------

	/*
	const Fraction& operator+(const Fraction& another_Fraction)
	{
		std::cout << "\n" << "Using const& overload parameter" << "\n";
		int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
		int new_denominator = (this->_denominator) * (another_Fraction._denominator);
		Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
		return *result_fraction;
	}
	//*/

	/*
	const Fraction& operator+(Fraction& another_Fraction)
	{
		std::cout << "\n" << "Using & overload parameter" << "\n";
		int new_numerator = this->_numerator * another_Fraction.Get_denominator() + another_Fraction.Get_numerator() * this->_denominator;
		int new_denominator = this->_denominator * another_Fraction.Get_denominator();
		Fraction* result_fraction = new Fraction(new_numerator, new_denominator);	
		return *result_fraction;
	}
	//*/

	/*
	friend const Fraction& operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2)
	{
		std::cout << "\n" << "Using friend const& overload parameter, return reference" << "\n";

		int new_numerator = (Fraction_Operand_1._numerator) * (Fraction_Operand_2._denominator) + (Fraction_Operand_2._numerator) * (Fraction_Operand_1._denominator);
		int new_denominator = (Fraction_Operand_1._denominator) * (Fraction_Operand_2._denominator);
		Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
		return *result_fraction;
	}
	//*/

	//Overload operators - pointer returned -----------------------------------------

	// перегрузка оператора через friend не может принять только указатели на операнды (нужны объекты или ссылки):
	//		friend Fraction* operator+(Fraction* Fraction_Operand_1, Fraction* Fraction_Operand_2) - такое только через глобальную перегрузку видимо???

	//*
	friend Fraction* operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2);
	//*/

	// Выводы:
	
	//1 у компилятора в приоритете использование перегрузки через функции-члены
	//2 только потом пытается  использовать friend, причем это проихсодит даже если friend подходит, а member нет!
	//3 также компилятор предпочитает использовать варианты перегрузок с параметрами с простой ссылкой вместо const&
	//4* при попытке выноса определения у friend функции VS пытается вынести его рядом с main (вместо classes.cpp)

	Fraction* operator+(const Fraction& another_Fraction);		
	
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q4 ??? при объявлении Fraction* operator+(Fraction& another_Fraction) в .h все было нормально, при переносе в .cpp вдруг давай ругаться ???
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Fraction* operator+(Fraction& another_Fraction);

	Fraction* operator+(Fraction& another_Fraction)
	{
		std::cout << "\n" << "var3 Using member-function & overload parameter, pointer return" << "\n";
		int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
		int new_denominator = (this->_denominator) * (another_Fraction._denominator);
		Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
		return result_fraction;
	}

	/*
	Fraction* operator+(const Fraction* another_Fraction)
	{
		std::cout << "\n" << "Using friend pointer overload parameter" << "\n";
		int new_numerator = (this->_numerator) * (another_Fraction->_denominator) + (another_Fraction->_numerator) * (this->_denominator);
		int new_denominator = (this->_denominator) * (another_Fraction->_denominator);
		//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
		Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
		//return result_fraction;
		return result_fraction;
	}
	*/

	Fraction* Add(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);
	Fraction* Subtract(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);
	Fraction* Multiply(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);
	Fraction* Divide(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);	

	Fraction* operator-(const Fraction& another_Fraction);
	Fraction* operator*(const Fraction& another_Fraction);
	Fraction* operator/(const Fraction& another_Fraction);
};


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q3 Как перегрузить вот такое (принимаем указатели на операнды)?
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/*
Fraction* operator+(Fraction* Fraction_Operand_1, Fraction* Fraction_Operand_2)
{
	int new_numerator = (Fraction_Operand_1->_numerator) * (Fraction_Operand_2._denominator) + (Fraction_Operand_2._numerator) * (Fraction_Operand_1._denominator);
	int new_denominator = (Fraction_Operand_1._denominator) * (Fraction_Operand_2._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//*/

class PhoneBook_logical_unit
{
	std::string _FIO;
	std::string _home_number;
	std::string _work_number;
	std::string _mobile_number;
	std::string _comments;
public:
	PhoneBook_logical_unit();
	PhoneBook_logical_unit(std::string FIO, std::string home_number, std::string work_number, std::string mobile_number, std::string comments);
	std::string GetFIO() { return _FIO; }
	void ShowInfo();
};

class PhoneBook
{
	//private:		
	std::vector<PhoneBook_logical_unit*> PhoneBook_logical_unit_list;

public:
	PhoneBook() {}
	// Когда функция Task_2() завершит работу, объявленные объекты в ней (в стэке) будут автоматически уничтожаться
	// Но все объекты созданные в динамичской памяти останутся, если не удалить их явно. Что и сделаем в деструкторе:
	~PhoneBook();
	void AddEntry();
	void AddEntry(std::string FIO, std::string home_number, std::string work_number, std::string mobile_number, std::string comments);
	void List();
	void DeleteEntry();
	int SearchByName();
	void ShowMethods();
	void User_Choice_Handle();
};

//попробовать через наследование
//class PhoneBook : public PhoneBook_logical_unit;
