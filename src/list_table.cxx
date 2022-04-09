
#include "list_table.hxx"

std::shared_ptr<Polynomial> Tables::ListTable::find(const std::string& _key) {
	for (auto i : data)
		if (i.key == _key)
			return i.polynomial;
	return nullptr;
}

bool Tables::ListTable::insert(const Data& _data) {
	int pos = 0;
	std::cout << data.size() << std::endl;
	if (find(_data.key, pos))
		return false;
	if (size == data.size()) {
		std::cout << "here!" << std::endl;
		return false;
	}
	data.push_front(_data);
	size++;

	return true;
}

bool Tables::ListTable::remove(const std::string& _key) {
	int pos = 0;
	bool success = false;
	success = find(_key, pos);
	if (!success)
		return false;
	std::list<Data>::iterator range_begin = data.begin();
	std::advance(range_begin, pos);
	data.erase(range_begin);
	size--;

	return true;
}

void Tables::ListTable::print() {
	for (auto i : data)
		std::cout << i << std::endl;
}

bool Tables::ListTable::find(const std::string& _key, int& pos) {
	int counter = 0;
	for (auto i : data) {
		if (i.key == _key) {
			pos = counter;

			return true;
		}
		counter++;
	}

	return false;
}

