#include <fstream>

#include "monom.hxx"

double Monom::get_coeff() {
	return coeff;
}

int Monom::get_degree() {
	return degree;
}

std::ostream& operator<<(std::ostream& os, const Monom& mn) {
	os << mn.coeff << " " << mn.degree;
	return os;
}

bool operator>(const Monom& mn1, const Monom& mn2) {
	return mn1.degree > mn2.degree;
}

bool operator<(const Monom& mn1, const Monom& mn2) {
	return mn1.degree < mn2.degree;
}

bool operator==(const Monom& mn1, const Monom& mn2) {
	return mn1.degree == mn2.degree;
}

Monom& Monom::operator=(const Monom& mn) {
	if (this == &mn)
		return *this;
	coeff = mn.coeff;
	degree = mn.degree;
	return *this;
}

std::string Monom::getDerivativeX() {
	std::string result;
	double new_c;
	std::string new_coeff;
	int x_p = 0, y_p = 0, z_p = 0;
	x_p = get_degree() / 100;
	y_p = (get_degree() / 10) % 10;
	z_p = get_degree() % 10;
	if (coeff > 0)
		result += '+';
	else
		result += '-';
	if (!x_p) {
		result += '0';
		result += 'x';
		result += std::to_string(0);
		result += 'y';
		result += std::to_string(0);
		result += 'z';
		result += std::to_string(0);
		return result;
	}
	if (x_p == 1) {
		result += std::to_string(coeff);
		result += 'x';
		result += std::to_string(0);
		result += 'y';
		result += std::to_string((y_p));
		result += 'z';
		result += std::to_string((z_p));
		return result;
	}
	else {
		new_c = coeff * (x_p--);
		new_coeff = std::to_string(new_c);
		result += new_coeff;
		result += 'x';
		result += std::to_string((x_p));
		result += 'y';
		result += std::to_string((y_p));
		result += 'z';
		result += std::to_string((z_p));
		return result;
	}
}

std::string Monom::getDerivativeY() {
	std::string result;
	double new_c;
	std::string new_coeff;
	int x_p = 0, y_p = 0, z_p = 0;
	x_p = get_degree() / 100;
	y_p = (get_degree() / 10) % 10;
	z_p = get_degree() % 10;
	if (coeff > 0)
		result += '+';
	else
		result += '-';
	if (!y_p) {
		result += '0';
		result += 'x';
		result += std::to_string(0);
		result += 'y';
		result += std::to_string(0);
		result += 'z';
		result += std::to_string(0);
		return result;
	}
	if (y_p == 1) {
		result += std::to_string(coeff);
		result += 'x';
		result += std::to_string((x_p));
		result += 'y';
		result += std::to_string(0);
		result += 'z';
		result += std::to_string((z_p));
		return result;
	}
	else {
		new_c = coeff * (y_p--);
		new_coeff = std::to_string(new_c);
		result += new_coeff;
		result += 'x';
		result += std::to_string((x_p));
		result += 'y';
		result += std::to_string((y_p));
		result += 'z';
		return result;
	}
}

std::string Monom::getDerivativeZ() {
	std::string result;
	double new_c;
	std::string new_coeff;
	int x_p = 0, y_p = 0, z_p = 0;
	x_p = get_degree() / 100;
	y_p = (get_degree() / 10) % 10;
	z_p = get_degree() % 10;
	if (coeff > 0)
		result += '+';
	else
		result += '-';
	if (!z_p) {
		result += '0';
		result += 'x';
		result += std::to_string(0);
		result += 'y';
		result += std::to_string(0);
		result += 'z';
		result += std::to_string(0);
		return result;
	}
	if (z_p == 1) {
		result += std::to_string(coeff);
		result += 'x';
		result += std::to_string((x_p));
		result += 'y';
		result += std::to_string((y_p));
		result += 'z';
		result += std::to_string(0);
		return result;
	}
	else {
		new_c = coeff * (z_p--);
		new_coeff = std::to_string(new_c);
		result += new_coeff;
		result += 'x';
		result += std::to_string((x_p));
		result += 'y';
		result += std::to_string((y_p));
		result += 'z';
		result += std::to_string((z_p));
		return result;
	}
}