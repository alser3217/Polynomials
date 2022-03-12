#include "arr_table.hxx"

Polynomial* Tables::ArrTable::find(const std::string& _key, int& _pos) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i].key == _key) {
      _pos = i;
      return data[i].polynomial;
    }
  }
  return nullptr;
}

void Tables::ArrTable::insert(const Tables::Data& _data) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i].key == _data.key)
      throw "already exists.";
  }
  data.push_back(_data);
}

void Tables::ArrTable::remove(const std::string& _key) {
  int pos = 0;
  find(_key, pos);
  data.erase(data.begin() + pos);    
}

void Tables::ArrTable::print() {
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i] << std::endl;
  }
}
