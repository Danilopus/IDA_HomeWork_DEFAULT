#include "classes.h"

//::::::::::::::::::::::::::::::Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction::::::::::::::::::::::::::::::
int Fraction::MaxCommonDivider(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a > b)	a %= b;
		else		b %= a;
	}
	return a + b;
}
void Fraction::Fraction_reduction()
{
	//(Get_numerator() < 0) ? (-Get_numerator()) : (Get_numerator());
	//int max_common_divider = MaxCommonDivider(Get_numerator(), Get_denominator());
	//int max_common_divider = MaxCommonDivider((Get_numerator() < 0) ? (-Get_numerator()) : (Get_numerator()) , Get_denominator());
	//int max_common_divider = MaxCommonDivider(abs(Get_numerator()), Get_denominator());
	int max_common_divider = MaxCommonDivider(abs(Get_numerator()), abs(Get_denominator()));
	Set_numerator(Get_numerator() / max_common_divider);
	Set_denominator(Get_denominator() / max_common_divider);
}
Fraction::Fraction(int A1, int A2, std::vector<Fraction*>& Available_fractions) : _numerator(A1), _denominator(A2)
{ 
Available_fractions.push_back(this); 
Fraction_reduction(); 
}
int Fraction::ShowMethods()
{
	std::cout << "\nAvailable methods:";
	//std::cout << "\n1) Add\n2) Substract\n3) Multiply\n4) Divide\n";
	std::cout << "\n1) Add\t2) Substract\t3) Multiply\t4) Divide\n";
	//return Get_Int_Positive();
	return 0;
}
void Fraction::ShowAvailableFractions(std::vector<Fraction*> Available_fractions)
{
	std::cout << "\nAvailable fractions:";
	for (int i = 0; i < Available_fractions.size(); i++)
	{
		std::cout << "\nFraction [" << i + 1 << "] -> " << Available_fractions[i]->Get_numerator() << " / " << Available_fractions[i]->Get_denominator();
	}
}
void Fraction::Memory_Clean(const std::vector<Fraction*>& Available_fractions)
{
	for (int i = 0; i < Available_fractions.size(); i++)
		delete Available_fractions[i];
}
Fraction* Fraction::operator+(const Fraction& another_Fraction) {
	std::cout << "\n" << "var2 Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q4 ??? при объявлении Fraction* operator+(Fraction& another_Fraction) в .h все было нормально, при переносе в .cpp вдруг давай ругаться ???
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/*
Fraction* operator+(Fraction& another_Fraction)
{
	std::cout << "\n" << "var3 Using member-function & overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//*/
Fraction* Fraction::Add(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)

{	
	int new_numerator = _numerator * another_Fraction.Get_denominator() + another_Fraction.Get_numerator() * _denominator;
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
	return result_fraction;
}
Fraction* Fraction::Subtract(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_denominator() - another_Fraction.Get_numerator() * _denominator;
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
		
	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator() - another_Fraction.Get_numerator() * _denominator);
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::Multiply(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_numerator();
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
		
	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_numerator());
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::Divide(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_denominator();
	int new_denominator = _denominator * another_Fraction.Get_numerator();
	//убираем знак из знаменателя
	if (new_denominator < 0) { new_denominator = -1 * new_denominator; new_numerator = -1 * new_numerator; }
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator());
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_numerator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::operator-(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) - (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator*(const Fraction& another_Fraction) 
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._numerator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator/(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._numerator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//??? как правильно объявить friend
//Fraction* Fraction::operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2)
Fraction* operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2)
{
	std::cout << "\n" << "var1 Using friend-function const& overload parameter, return pointer" << "\n";
	int new_numerator = (Fraction_Operand_1._numerator) * (Fraction_Operand_2._denominator) + (Fraction_Operand_2._numerator) * (Fraction_Operand_1._denominator);
	int new_denominator = (Fraction_Operand_1._denominator) * (Fraction_Operand_2._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}


//::::::::::::::::::::::::::::::PhoneBook::PhoneBook::PhoneBook::PhoneBook::PhoneBook::PhoneBook::PhoneBook::PhoneBook::::::::::::::::::::::::::::::
void PhoneBook::AddEntry()
{
	PhoneBook_logical_unit* tmp_ptr = new PhoneBook_logical_unit();
	PhoneBook_logical_unit_list.push_back(tmp_ptr);
}
void PhoneBook::AddEntry(std::string FIO, std::string home_number, std::string work_number, std::string mobile_number, std::string comments)
{
	PhoneBook_logical_unit* tmp_ptr = new PhoneBook_logical_unit(FIO, home_number, work_number, mobile_number, comments);
	PhoneBook_logical_unit_list.push_back(tmp_ptr);
}
void PhoneBook::List()
{
	std::cout << "\nPhonebook list:";
	int counter = 0;
	for (auto const& it : PhoneBook_logical_unit_list)
	{
		std::cout << "\n\nEntry " << ++counter;
		it->ShowInfo();
	}
}
void PhoneBook::DeleteEntry()
{
	std::cout << "\n!!! Entry deleting !!!\n";
	this->List();
	std::cout << "\n\nChoose entry to delete: ";
	int entry_to_delete = Get_Int_Positive();
	entry_to_delete--;
	delete PhoneBook_logical_unit_list[entry_to_delete];
	PhoneBook_logical_unit_list.erase(PhoneBook_logical_unit_list.begin() + entry_to_delete);
}
int PhoneBook::SearchByName()

{
	std::string tmp_str;
	std::cout << "\nSearch name: ";
	getline(std::cin, tmp_str);
	int counter = 0;
	for (auto const& it : PhoneBook_logical_unit_list)
	{
		if (tmp_str == it->GetFIO())
		{
			std::cout << "\nFirst encount at Entry number -> " << counter + 1;
			return counter;
		}
		counter++;
	}
	std::cout << "\nno mathes found\n";
	return -1;
}
void PhoneBook::ShowMethods()

{
	std::cout << "\nAvailable methods:";
	std::cout << "\n1) Add\t2) Delete\t3) Search\t4) List\n";
}
void PhoneBook::User_Choice_Handle()
{
	std::cout << "choose a method: ";
	int action = Get_Int_Positive();
	switch (action)
	{
	case 1: AddEntry(); break;
	case 2: DeleteEntry(); break;
	case 3: SearchByName(); break;
	case 4: List(); break;
	}
}
PhoneBook::~PhoneBook()
{
	for (int i = 0; i < PhoneBook_logical_unit_list.size(); i++)
	{
		delete PhoneBook_logical_unit_list[i];
	}
}


//::::::::::::::::::::::::::::::PhoneBook_logical_unit::PhoneBook_logical_unit::PhoneBook_logical_unit::PhoneBook_logical_unit::::::::::::::::::::::::::::::
PhoneBook_logical_unit::PhoneBook_logical_unit()
{	
		std::cout << "New phonebook entry:\n";
		std::cout << "_FIO: ";
		getline(std::cin, _FIO);
		std::cout << "_home_number: ";
		getline(std::cin, _home_number);
		std::cout << "_work_number: ";
		getline(std::cin, _work_number);
		std::cout << "_mobile_number: ";
		getline(std::cin, _mobile_number);
		std::cout << "_comments: ";
		getline(std::cin, _comments);
	
}
PhoneBook_logical_unit::PhoneBook_logical_unit(std::string FIO, std::string home_number, std::string work_number, std::string mobile_number, std::string comments) :
	_FIO(FIO), _home_number(home_number), _work_number(work_number), _mobile_number(mobile_number), _comments(comments) {}
void PhoneBook_logical_unit::ShowInfo()
{
	std::cout << '\n' << "FIO           " << _FIO;
	std::cout << '\n' << "home_number   " << _home_number;
	std::cout << '\n' << "work_number   " << _work_number;
	std::cout << '\n' << "mobile_number " << _mobile_number;
	std::cout << '\n' << "comments      " << _comments;
}

////::::::::::::::::::::::::::::::Main_menu::Main_menu::Main_menu::Main_menu::Main_menu::Main_menu::Main_menu::Main_menu::::::::::::::::::::::::::::::::
void Main_menu::Show_menu()
{
		system("cls");
		std::cout << "\n\t***\t" << _menu_elements[0] << "\t***\n\n\t\n\nChoose an option: \n";
		//for (int i=1; i< _menu_elements_number; i++)		
		for (int i = 1; i < _menu_elements.size(); i++)
			std::cout << "\n" << i << ". " << _menu_elements[i];
		std::cout << "\n\n 0. Exit\n";
		std::cout << "\nYour choice: ";
}
int Main_menu::User_Choice_Handle()
{
	int choice = 0;
	choice = Get_Int_Positive();
	std::cout << "\n";
	// Обработка выбора пользователя
	if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }

	else if (choice == 1) Task_1();
	else if (choice == 2) Task_2();
	else if (choice == 3) Task_3();
	else if (choice == 4) Task_4();

	else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
	return 1;
}
int Main_menu::User_Choice_Handle(int key_code)
{
	//int input = _getch();
	//if (key_code >= 48 &&  key_code <= 58 )
		std::cout << key_code-48 << "\n\n";
	switch (key_code)
	{
	case 27: case 48: 
	{ std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0;	}
	case 49: Task_1(); break;
	case 50: Task_2(); break;
	case 51: Task_3(); break;
	case 52: Task_4(); break;
	//case 53: Task_5(); break;
	default: { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
	}
	return 1;
}


