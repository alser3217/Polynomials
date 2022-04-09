
#include "polynomial.hxx"
#include "arr_table.hxx"
#include "ordered_table.hxx"
#include "list_table.hxx"
#include "chaining_hash_table.hxx"
#include "interface.hxx"
#include "open_access_hash_table.hxx"

using namespace Tables;


int main() {
	std::vector<Data> elements;
	elements.reserve(SIZE);
	int choice = 0;
	StartMessage();
	std::cin >> choice;
	Interface interface(choice);
	while (choice) {
		MenuMessage();
		std::cin >> choice;
		switch (choice) {
			case 1: {
				int tmp = 0;
				int f_choice = 0;
				std::shared_ptr<Polynomial> pl;
				std::string key;
				system("cls");
				std::cout << "Enter key: " << std::endl;
				std::cin >> key;
				if ((pl = interface.find(key)) == nullptr)
				  NotFoundMessage();
				else {
					system("cls");
					std::cout << *pl << std::endl;
					FindOptionsMessage();
					std::cin >> f_choice;
					switch (f_choice) {
						case 1: {
							std::string new_polynomial;
							std::cout << "Enter new polynomial: " << std::endl;
							std::cin >> new_polynomial;
							interface.change(pl, new_polynomial);
							ChangeSuccessMessage();
							break;
						}

						case 2: {
							double x, y, z;
							double result;
							std::cout << "Enter coordinates of point: " << std::endl;
							std::cin >> x >> y >> z;
							result = interface.calculate(*pl, x, y, z);
							PointCalculateMessage(result);
							break;
						}

						case 3: {
							std::string new_key;
							std::string result = interface.get_derivativeX(*pl);
							std::cout << "Enter key for the result polynomial: " << std::endl;
							std::cin >> new_key;
							if (!interface.add(Data(new_key, std::make_shared<Polynomial>(result))))
								InsertFailMessage();
							else
								InsertSuccessMessage();

							break;
						}

						case 4: {
							std::string new_key;
							std::string result = interface.get_derivativeY(*pl);
							std::cout << "Enter key for the result polynomial: " << std::endl;
							std::cin >> new_key;
							if (!interface.add(Data(new_key, std::make_shared<Polynomial>(result))))
								InsertFailMessage();
							else
								InsertSuccessMessage();

							break;
						}

						case 5: {
							std::string new_key;
							std::string result = interface.get_derivativeZ(*pl);
							std::cout << "Enter key for the result polynomial: " << std::endl;
							std::cin >> new_key;
							if (!interface.add(Data(new_key, std::make_shared<Polynomial>(result))))
								InsertFailMessage();
							else
								InsertSuccessMessage();
							break;
						}
					}
				}
				break;
			}

			case 2: {
				std::string key;
				std::string polynomial;
				system("cls");
				std::cout << "Enter key: " << std::endl;
				std::cin >> key;
				std::cout << "Enter polynomial: " << std::endl;
				std::cin >> polynomial;
				elements.push_back(Data(key, std::make_shared<Polynomial>(polynomial)));
				if (!interface.add(elements.back()))
					InsertFailMessage();
				else
					InsertSuccessMessage();
				break;
			}

			case 3: {
				std::string key;
				system("cls");
				std::cout << "Enter key: " << std::endl;
				std::cin >> key;
				if (!interface.remove(key))
					RemoveFailMessage();
				else
					RemoveSuccessMessage();
				break;
			}

			case 4: {
				system("cls");
				std::cout << "Printing table..." << std::endl;
				interface.print();
				break;
			}

			case 5: {
				std::vector<Polynomial> polynomials;
				Polynomial result;
				std::string new_key;
				std::vector<std::string> infix_divide;
				std::shared_ptr<Polynomial> pl;
				std::string infix;
				TPostfix postfix;
				std::cout << "Enter arithmetic expression: " << std::endl;
				std::cin >> infix;
				postfix.set_infix(infix);
				infix_divide = postfix.get_infix_divide();
				for (auto& i : infix_divide) {
					if ((pl = interface.find(i)) != nullptr) {
						polynomials.push_back(Polynomial(*pl));
					}
				}
				result = postfix.calculate(polynomials);
				std::cout << "Ener key for the result polynomial: " << std::endl;
				std::cin >> new_key;
				if (!interface.add(Data(new_key, std::make_shared<Polynomial>(result))))
					InsertFailMessage();
				else
					InsertSuccessMessage();
				break;
			}
		}
	}
	return 0;
} 

//std::chrono
//профилировщики

/*
int main() {
	Tables::BaseTable* table001 = new Tables::OpenAccessHashTable;
	Tables::Data data001("abcd5", std::make_shared<Polynomial>("11x1y1z1")); //*
	Tables::Data data002("1abcr", std::make_shared<Polynomial>("5x1y1z1"));
	Tables::Data data003("1abct", std::make_shared<Polynomial>("6x1y1z1"));
	Tables::Data data004("1abcde", std::make_shared<Polynomial>("7x1y1z1"));
	Tables::Data data005("1abcdef", std::make_shared<Polynomial>("8x1y1z1"));
	Tables::Data data006("1abcp", std::make_shared<Polynomial>("9x1y1z1"));
	Tables::Data data007("1abcg", std::make_shared<Polynomial>("10x1y1z1"));
	table001->print();
	std::cout << std::endl;
	table001->insert(data001);
	table001->insert(data002);
	table001->insert(data003);
	table001->insert(data004);
	table001->insert(data005);
	table001->insert(data006);
	table001->insert(data007); 
	table001->print();
	std::cout << std::endl;
	std::cout << *table001->find("1abcdef") << std::endl;
	table001->remove("1abcp");
	table001->remove("1abcr");
	table001->remove("1abcg");
	table001->print();
	std::cout << "Something" << std::endl;
	return 0;
} 
*/