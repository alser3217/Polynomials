
#include "polynomial.hxx"
#include "arr_table.hxx"
#include "ordered_table.hxx"
#include "list_table.hxx"

int main() {
	Tables::BaseTable* table001 = new Tables::ListTable;
	Tables::Data data001("abcd", new Polynomial("4x1y1z1"));
	Tables::Data data002("1abcr", new Polynomial("5x1y1z1"));
	Tables::Data data003("1abct", new Polynomial("6x1y1z1"));
	Tables::Data data004("1abcde", new Polynomial("7x1y1z1"));
	Tables::Data data005("1abcdef", new Polynomial("8x1y1z1"));
	Tables::Data data006("1abcp", new Polynomial("9x1y1z1"));
	Tables::Data data007("1abcg", new Polynomial("10x1y1z1"));
	table001->insert(data001);
	table001->insert(data002);
	table001->insert(data003);
	table001->insert(data004);
	table001->insert(data005);
	table001->insert(data006);
	table001->insert(data007); 
	table001->print();
	table001->remove("1abcp");
	std::cout << std::endl;
	std::cout << *table001->find("1abcg") << std::endl;
	table001->print();
	return 0;
}