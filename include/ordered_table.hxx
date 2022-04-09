#ifndef __ORDEREDTABLE__
#define __ORDEREDTABLE__

#include "arr_table.hxx"

namespace Tables {
	class OrderedTable : public ArrTable {
	private:
		bool find(const std::string& _key, int& pos) override;

	public:
		OrderedTable(int _size = SIZE) : ArrTable(_size) {}
		bool remove(const std::string& _key) override;
		bool insert(const Data& _data) override;
		std::shared_ptr<Polynomial> find(const std::string& _key) override;
		int find_pos(const std::string& _key);
		~OrderedTable() {};
	};
}

#endif
