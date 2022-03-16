
#include "base_table.hxx"

std::ostream& Tables::operator<<(std::ostream& out, const Tables::Data& object) {
	out << object.key << " - " << object.polynomial->get_as_string() << std::endl;
	return out;
}

int Tables::hash(std::string _key, int _size) {
	int result = 0;
	for (int i = 0; i < _key.size(); i++) {
		result += static_cast<int>(_key[i]);
	}
	return result % _size;
}
