#ifndef __LISTTABLE__
#define __LISTTABLE__

#include "base_table.hxx"

#include <list>

namespace Tables {
	class ListTable : public BaseTable {
		std::list<Data> data;
		int size = 0;

	private:
		bool find(const std::string& _key, int& pos) override;

	public:

		ListTable(int _size = SIZE) : data(_size), size(0) {}

		std::shared_ptr<Polynomial> find(const std::string& _key) override;
		bool insert(const Data& _data) override;
		bool remove(const std::string& _key) override;
		void print() override;
	  ~ListTable() {}
	};
}

#endif