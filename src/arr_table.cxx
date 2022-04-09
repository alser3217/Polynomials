
#include "arr_table.hxx"

std::shared_ptr<Polynomial> Tables::ArrTable::find(const std::string& _key) {
  for (auto i : data) {
    if (i.key == _key)
      return i.polynomial;
  }
  return nullptr;
}

bool Tables::ArrTable::insert(const Data& _data) {
  int pos = -1;
  if (size == data.size())
    return false;
  if (find(_data.key) != nullptr)
    return false;
  for (auto& i : data)
    if (i.polynomial == nullptr) {
      i = _data;
      size++;

      return true;
    }

  return true;
}

bool Tables::ArrTable::remove(const std::string& _key) {
  for (auto& i : data) {
    if (i.key == _key) {
      i.key = "empty";
      i.polynomial = nullptr;
      size--;
      return true;
    }
  }

  return false;
}

void Tables::ArrTable::print() {
  for (auto& i : data)
    std::cout << i << std::endl;
}

bool Tables::ArrTable::find(const std::string& _key, int& _pos) {
  return false;
}