#ifndef __OPEN_ACCESS_HASH_TABLE__
#define __OPEN_ACCESS_HASH_TABLE__

#include "arr_table.hxx"

namespace Tables {

	class OpenAccessHashTable : public BaseTable {
		std::vector<Data> data;
		int size;

	private:
		bool find(const std::string& _key, int& pos) override { return true; }
	public:
		OpenAccessHashTable(int _size = SIZE) : data(_size), size(0) {}

		~OpenAccessHashTable() {};
		bool insert(const Data& _data);
		std::shared_ptr<Polynomial> find(const std::string& _key) override;
		bool remove(const std::string& _key) override;
		void print() override;
	};
}


#endif
