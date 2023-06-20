// HomeWork template project v 4.0 // 20.06.2023 //
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//#include <array>
//My own headers
#include "Service functions.h"
#include "classes.h"
#include "ComplexNumber.h"



// Homework XXX ----------------------------------------------------	

//Task 1 Fraction class with overloaded operators: + | - | / | * demo
void Task_1()
{
	//Вариант хранения объектов класса Fraction в векторе объектов вне класса (из точки вызова, с передачей указателя на этот вектор)
	std::vector<Fraction*> Available_fractions;
	//static std::vector<Fraction*> Available_fractions;
	//Fraction fraction_1(5, 7, Available_fractions), fraction_2(7,19, Available_fractions);
	Fraction fraction_1 = *new Fraction(5, 7, Available_fractions); 
	Fraction fraction_2 = *new Fraction(7, 19, Available_fractions);
	
	do
	{	
		system("cls");
		std::cout << "***\tFraction class demo\n";
		fraction_1.ShowAvailableFractions(Available_fractions);
		std::cout << "\n";
		fraction_1.ShowMethods();
		std::cout << "choose a method: ";
		int action = Get_Int_Positive();

		//fraction_1.ShowAvailableFractions();
		//fraction_1.ShowAvailableFractions(Available_fractions);

		std::cout << "\nchoose operands:";
		std::cout << "\nchoose fraction 1: ";
		int fraction_index_1 = Get_Int_Positive();
		std::cout << "choose fraction 2: ";
		int fraction_index_2 = Get_Int_Positive();

		fraction_index_1--;
		fraction_index_2--;
		
		//перегрузку используя указатели сделать не получилось
		//Fraction* Operand_1 = Available_fractions[fraction_index_1];
		//Fraction* Operand_2 = Available_fractions[fraction_index_2];


		Fraction Operand_1 = *Available_fractions[fraction_index_1];
		Fraction Operand_2 = *Available_fractions[fraction_index_2];
		
		/* // Работает!
		Fraction result_fraction = *new Fraction;
		result_fraction = *(Operand_1 + Operand_2);
		*/
		
		/*
		Fraction* result_fraction = new Fraction{};
		//*result_fraction = (Operand_1 + Operand_2); // так на один символ * больше, оставил вариант с возвратом указателя
		result_fraction = (Operand_1 + Operand_2);
		*/


		//переработанный блок операций с использованием перегрузки арифметических операторов
		switch (action)
		{
		//case 1: Available_fractions[fraction_index_1]->Add(*Available_fractions[fraction_index_2], Available_fractions); break;
		//case 1: Available_fractions.push_back(result_fraction); break;
		case 1: Available_fractions.push_back(Operand_1 + Operand_2); break;		
		//case 2: Available_fractions[fraction_index_1]->Subtract(*Available_fractions[fraction_index_2], Available_fractions); break;
		case 2: Available_fractions.push_back(Operand_1 - Operand_2); break;		
		//case 3: Available_fractions[fraction_index_1]->Multiply(*Available_fractions[fraction_index_2], Available_fractions); break;
		case 3: Available_fractions.push_back(Operand_1 * Operand_2); break;
		//case 4: Available_fractions[fraction_index_1]->Divide(*Available_fractions[fraction_index_2], Available_fractions); break;
		case 4: Available_fractions.push_back(Operand_1 / Operand_2); break;
		}
		std::cout << "\nresult - > ";
		Available_fractions[Available_fractions.size() - 1]->ShowValues();
		
		std::cout << "\n\nEsc - for exit, any key to continue";
	} while (_getch() != 27);
	Fraction::Memory_Clean(Available_fractions);
	//сам вектор std::vector<Fraction*> Available_fractions вроде должен быть уничтожен автоматически, т.к. находится в стэке (мне так кажется)
}

//Task 2 ComplexNumber class through inheritance with overloaded operators: + | - | / | * demo
void Task_2()
//void Task_2(std::string name_of_work)
{
	//std::cout << "***\t ComplexNumber class through inheritance with overloaded operators: + | - | / | * demo\n";
	std::cout << "Enter provided_at_startup_complex_number_quantity -> ";
	int provided_at_startup_complex_number_quantity = Get_Int_Positive(0,10, "it's too much, reasonable limit is 10 -> ");
	ComplexNumber_class_through_inheritance::Initialisation(provided_at_startup_complex_number_quantity);

	do
	{
		system("cls");
		std::cout << "***\t ComplexNumber class through inheritance with overloaded operators: + | - | / | * demo\n";

		ComplexNumber_class_through_inheritance::Show_List_of_available_numbers();
		ComplexNumber_class_through_inheritance::ShowMethods();
		ComplexNumber_class_through_inheritance::User_Choice_Handle();

		std::cout << "\n\nEsc - for exit, any key to continue";
	} while (_getch() != 27);
	ComplexNumber_class_through_inheritance::MemoryClean();
}


//Task 3 ComplexNumber class through including with overloaded operators: + | - | / | * demo
void Task_3()
{
	std::cout << "Enter provided_at_startup_complex_number_quantity -> ";
	int provided_at_startup_complex_number_quantity = Get_Int_Positive(0, 10, "it's too much, reasonable limit is 10 -> ");
	ComplexNumber_class_through_including::Initialisation(provided_at_startup_complex_number_quantity);

	do
	{
		system("cls");
		std::cout << "***\t ComplexNumber class through inheritance with overloaded operators: + | - | / | * demo\n";

		ComplexNumber_class_through_including::Show_List_of_available_numbers();
		ComplexNumber_class_through_including::ShowMethods();
		ComplexNumber_class_through_including::User_Choice_Handle();

		std::cout << "\n\nEsc - for exit, any key to continue";
	} while (_getch() != 27);
	ComplexNumber_class_through_including::MemoryClean();
}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 03: Classes. Operators overload");	// Homework name
	MainMenu.AddElement("Fractions with overloaded operators: + | - | / | * demo");				// Menu element 1
	MainMenu.AddElement("ComplexNumber class through inheritance with overloaded operators: + | - | / | * demo");		// Menu element 2
	MainMenu.AddElement("ComplexNumber class through including with overloaded operators: + | - | / | * demo");		// Menu element 3
	//MainMenu.AddElement("XXX");
	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

