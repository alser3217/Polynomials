
#include "base_table.hxx"

std::ostream& Tables::operator<<(std::ostream& out, const Tables::Data& object) {
	out << object.key << " - " << object.s_polynomial << std::endl;
	return out;
}
