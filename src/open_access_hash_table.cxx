
#include "open_access_hash_table.hxx"

std::shared_ptr<Polynomial> Tables::OpenAccessHashTable::find(const std::string& _key) {
	int i = 0, j = 0;
	do {
		j = oa_hash(_key, data.size(), i);
		if (data[j].key == _key)
			return data[j].polynomial;
		i++;
	} while (data[j].status != STATUS::EMPTY && data[j].status != STATUS::EMPTY && i != SIZE);

	return nullptr;
}

bool Tables::OpenAccessHashTable::insert(const Tables::Data& _data) {
	int i = 0, j = 0;
	if (size == data.size())
		return false;
	if (find(_data.key) != nullptr)
		return false;
	do {
		j = oa_hash(_data.key, data.size(), i);
		if (data[j].status == STATUS::EMPTY || data[j].status == STATUS::DELETED) {
			data[j] = _data;
			data[j].status = STATUS::OCCUPIED;
			size++;

			return true;
		}
		i++;
	} while (i != SIZE);

	return false;
}

bool Tables::OpenAccessHashTable::remove(const std::string& _key) {
	int i = 0, j = 0;
	do {
		j = oa_hash(_key, data.size(),  i);
		if (data[j].key == _key) {
			data[j].key = "empty";
			data[j].polynomial = nullptr;
			data[j].status = STATUS::DELETED;
			size--;

			return true;
		} 
		i++;
	} while (i != SIZE);

	return false;
}

void Tables::OpenAccessHashTable::print() {
	for (auto& i : data)
		std::cout << i << std::endl;
}