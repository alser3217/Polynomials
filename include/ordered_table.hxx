
#include "arr_table.hxx"

namespace Tables {
	class OrderedTable : public ArrTable {
	public:
		OrderedTable() : ArrTable() {}
		void remove(const std::string& _key);
		void insert(const Tables::Data& d);
		Polynomial* find(const std::string& _key, int& pos);
		int find_pos(std::string _key);
		~OrderedTable() {};
	};

}