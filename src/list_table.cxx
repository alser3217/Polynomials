
#include "list_table.hxx"

Polynomial* Tables::ListTable::find(const std::string& _key) {
	for (int i = 0; i < data.size(); i++)
		if (data[i].key == _key)
			return data[i].polynomial;
	return nullptr;
}

void Tables::ListTable::insert(const Data& _data) {
	if (find(_data.key) != nullptr)
		throw "already exists!";
	data.push_back(_data);
}

void Tables::ListTable::remove(const std::string& _key) {
	int pos = 0;
	pos = find_remove(_key);
	if (pos == -1)
		throw "no such element";
	data.remove(pos);
}

int Tables::ListTable::find_remove(const std::string& _key) {
	for (int i = 0; i < data.size(); i++)
		if (data[i].key == _key)
			return i;
	return -1;

}

void Tables::ListTable::print() {
	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << std::endl;
	}
}