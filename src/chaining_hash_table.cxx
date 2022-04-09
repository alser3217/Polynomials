
#include "chaining_hash_table.hxx"

std::shared_ptr<Polynomial> Tables::ChainingHashTable::find(const std::string& _key) {
	int key = hash(_key, data.size());
	for (auto i : data[key])
		if (i.key == _key)
			return i.polynomial;
	return nullptr;
} 

bool Tables::ChainingHashTable::insert(const Data& _data) {
	int pos = 0;
	int key = hash(_data.key, data.size());
	if (size == data.size())
		return false;
	if (find(_data.key, pos))
		return false;
	data[key].push_front(_data);
	size++;

	return true;
}

bool Tables::ChainingHashTable::remove(const std::string& _key) {
	int pos = 0;
	bool success = false;
	int key = hash(_key, data.size());
	std::list<Data>::iterator range_begin = data[key].begin();
	success = find(_key, pos);
	if (!success)
		return false;
	std::advance(range_begin, pos);
	data[key].erase(range_begin);
	size--;

	return true;
}

void Tables::ChainingHashTable::print() {
	int counter = 0;
	for (auto i : data) {
		for (auto j : data[counter])
			std::cout << j << std::endl;
		counter++;
	}
}

bool Tables::ChainingHashTable::find(const std::string& _key, int& pos) {
	int key = hash(_key, data.size());
	int counter = 0;
	for (auto i : data[key]) {
		if (i.key == _key) {
			pos = counter;

			return true;
		}
		counter++;
	}

	return false;
}
