
#include <vector>
#include <memory>

#include "interface.hxx"

Tables::Interface::Interface(int choice) {
	switch (choice) {
		case 1: {
			main_table = std::make_shared<Tables::ArrTable>();
			tables.push_back(std::make_shared<Tables::OrderedTable>());
			tables.push_back(std::make_shared<Tables::ListTable>());
			tables.push_back(std::make_shared<Tables::ChainingHashTable>());
			tables.push_back(std::make_shared<Tables::OpenAccessHashTable>());

			break;
		}

		case 2: {
			main_table = std::make_shared<Tables::OrderedTable>();
			tables.push_back(std::make_shared<Tables::ArrTable>());
			tables.push_back(std::make_shared<Tables::ListTable>());
			tables.push_back(std::make_shared<Tables::ChainingHashTable>());
			tables.push_back(std::make_shared<Tables::OpenAccessHashTable>());

			break;
		}

		case 3: {
			main_table = std::make_shared<Tables::ListTable>();
			tables.push_back(std::make_shared<Tables::ArrTable>());
			tables.push_back(std::make_shared<Tables::OrderedTable>());
			tables.push_back(std::make_shared<Tables::ChainingHashTable>());
			tables.push_back(std::make_shared<Tables::OpenAccessHashTable>());

			break;
		}

		case 4: {
			main_table = std::make_shared<Tables::ChainingHashTable>();
			tables.push_back(std::make_shared<Tables::ArrTable>());
			tables.push_back(std::make_shared<Tables::OrderedTable>());
			tables.push_back(std::make_shared<Tables::ListTable>());
			tables.push_back(std::make_shared<Tables::OpenAccessHashTable>());

			break;
		}

		case 6: {
			main_table = std::make_shared<Tables::OpenAccessHashTable>();
			tables.push_back(std::make_shared<Tables::ArrTable>());
			tables.push_back(std::make_shared<Tables::OrderedTable>());
			tables.push_back(std::make_shared<Tables::ListTable>());
			tables.push_back(std::make_shared<Tables::ChainingHashTable>());

			break;
		}
	}
}
void Tables::StartMessage() {
	std::cout << "Demo-program of demonstrating Polynomial class capability." << std::endl << std::endl;
	std::cout << "Choose one from the following tables: " << std::endl << std::endl;
	std::cout << "1. ArrayTable." << std::endl << std::endl;
	std::cout << "2. OrderedTable." << std::endl << std::endl;
	std::cout << "3. ListTable." << std::endl << std::endl;
	std::cout << "4. ChainingHashTable." << std::endl << std::endl;
	std::cout << "5. TreeTable." << std::endl << std::endl;
	std::cout << "6. OpenAddressingTable." << std::endl << std::endl;
}

void Tables::MenuMessage() {
	system("cls");
	std::cout << "Choose from the following options: " << std::endl << std::endl;
	std::cout << "1. Find element." << std::endl << std::endl;
	std::cout << "2. Add element." << std::endl << std::endl;
	std::cout << "3. Remove element." << std::endl << std::endl;
	std::cout << "4. Print table." << std::endl << std::endl;
	std::cout << "5. Enter arithmetic expression." << std::endl << std::endl;
	std::cout << "0. Exit." << std::endl << std::endl;
}

void Tables::NotFoundMessage() {
	int choice;
	system("cls");
	std::cout << "No such element!" << std::endl << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

void Tables::FindOptionsMessage() {
	std::cout << "Choose from the following options: " << std::endl << std::endl;
	std::cout << "1. Change polynomial." << std::endl << std::endl;
	std::cout << "2. Calculate polynomial's value in a point." << std::endl << std::endl;
	std::cout << "3. Get derivative by x." << std::endl << std::endl;
	std::cout << "4. Get derivative by y." << std::endl << std::endl;
	std::cout << "5. Get derivative by z." << std::endl << std::endl;
	std::cout << "0. Exit." << std::endl << std::endl;
}

void Tables::InsertSuccessMessage() {
	system("cls");
	int choice;
	std::cout << "Polynomial was successfully inserted into table." << std::endl << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

void Tables::InsertFailMessage() {
	system("cls");
	int choice;
	std::cout << "Polynomial already exists in this table!" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

void Tables::RemoveSuccessMessage() {
	int choice;
	system("cls");
	std::cout << "Polynomial was successfully removed. " << std::endl << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

bool Tables::Interface::add(const Data& _data) {
	bool success = true;
	success = main_table->insert(_data);
	for (auto& i : tables)
		success = i->insert(_data); 

	return success;
}

std::shared_ptr<Polynomial> Tables::Interface::find(const std::string& _key) {
	return main_table->find(_key);
}

void Tables::Interface::print() {
	int choice = 0;
	main_table->print();
	std::cout << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

bool Tables::Interface::remove(const std::string& _key) {
	bool success = true;
	success = main_table->remove(_key);
	for (auto& i : tables)
		success = i->remove(_key);

	return success;
}

void Tables::RemoveFailMessage() {
	int choice = 0;
	system("cls");
	std::cout << "No such element in the table!" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

void Tables::Interface::change(std::shared_ptr<Polynomial> _polynomial, std::string& _new_polynomial) {
	_polynomial->change(_new_polynomial);
}

void Tables::ChangeSuccessMessage() {
	int choice = 0;
	system("cls");
	std::cout << "Polynomial was successfully changed." << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

double Tables::Interface::calculate(Polynomial pl,  double x, double y, double z) {
	return pl.value(x, y, z);
}

void Tables::PointCalculateMessage(int result) {
	int choice;
	system("cls");
	std::cout << "Result: " << result << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cin >> choice;
}

std::string Tables::Interface::get_derivativeX(Polynomial pl) {
	return pl.derivativeX();
}

std::string Tables::Interface::get_derivativeY(Polynomial pl) {
	return pl.derivativeY();
}

std::string Tables::Interface::get_derivativeZ(Polynomial pl) {
	return pl.derivativeZ();
}