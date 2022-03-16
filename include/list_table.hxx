#ifndef __LISTTABLE__
#define __LISTTABLE__

#include "base_table.hxx"
#include "list.hxx"

namespace Tables {
	class ListTable : public BaseTable {
		List<Tables::Data> data;
		int size = 0;
	public:
		Polynomial* find(const std::string& _key);
		int find_remove(const std::string& _key);
		void insert(const Data& _data);
		void remove(const std::string& _key);
		void print();
	  ~ListTable() {}
	};
}

#endif