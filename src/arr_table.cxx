
#include "arr_table.hxx"

Polynomial* Tables::ArrTable::find(const std::string& _key) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i].key == _key) {
      return data[i].polynomial;
    }
  }
  return nullptr;
}

void Tables::ArrTable::insert(const Tables::Data& _data) {
  if (find(_data.key) != nullptr)
    throw "already exists!";
  data.push_back(_data);
}

void Tables::ArrTable::remove(const std::string& _key) {
  int pos = 0;
  pos = find_remove(_key);
  if (pos == -1)
    throw "no such element!";
  data.erase(data.begin() + pos);    
}

void Tables::ArrTable::print() {
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i] << std::endl;
  }
}

int Tables::ArrTable::find_remove(const std::string& _key) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i].key == _key)
      return i;
  }
  return -1;
}
