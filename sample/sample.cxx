
#include "polynomial.hxx"
#include "arr_table.hxx"
#include "ordered_table.hxx"

int main() {
	Tables::BaseTable* table001 = new Tables::OrderedTable;
	Tables::Data data001("abcd","4xyz", new Polynomial("4x1y1z1"));
	Tables::Data data002("abcr","5xyz", new Polynomial("5x1y1z1"));
	Tables::Data data003("abct","6xyz", new Polynomial("6x1y1z1"));
	Tables::Data data004("abcde","7xyz", new Polynomial("7x1y1z1"));
	Tables::Data data005("abcdef","8xyz", new Polynomial("8x1y1z1"));
	Tables::Data data006("abcp","9xyz", new Polynomial("9x1y1z1"));
	Tables::Data data007("abcg","10xyz", new Polynomial("10x1y1z1"));
	table001->insert(data001);
	table001->insert(data002);
	table001->insert(data003);
	table001->insert(data004);
	table001->insert(data005);
	table001->insert(data006);
	table001->insert(data007); 
	table001->print(); 
	std::cout << std::endl;
	table001->remove("abcd");
	table001->print(); 
	return 0;
}