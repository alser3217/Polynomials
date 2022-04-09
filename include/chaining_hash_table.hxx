#ifndef __CHAINING_HASH_TABLE_
#define __CHAINING_HASH_TABLE_


#include <vector>

#include "base_table.hxx"

#include <list>
#include <iterator>

namespace Tables {
	class ChainingHashTable : public BaseTable {
    std::vector<std::list<Data>> data;//*
    int size;
  private:
    bool find(const std::string& _key, int& pos) override;

	public:
    ChainingHashTable(int _size = SIZE) : data(_size), size(0) {}
    bool remove(const std::string& _key) override;
    bool insert(const Data& _data) override;
    std::shared_ptr<Polynomial> find(const std::string& _key) override;
    void print() override;
    ~ChainingHashTable() {};
	};
}

#endif
