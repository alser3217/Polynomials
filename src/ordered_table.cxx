
#include "ordered_table.hxx"

Polynomial* Tables::OrderedTable::find(const std::string& _key) { //binary search
  if (!data.size()) {
    return nullptr;
  }
  int middle = 0, left, right;
  left = 0; right = data.size() - 1;
  while (true)
  {
    if (left > right)
      return nullptr; // значение не найдено
    middle = left + (right - left) / 2;
    if (data[middle].key.compare(_key) < 0) left = middle + 1;
    if (data[middle].key.compare(_key) > 0) right = middle - 1;
    if (!data[middle].key.compare(_key)) {
      return data[middle].polynomial;
    }
  }
}

void Tables::OrderedTable::insert(const Tables::Data& d) {
  // проверка на существуемость
  if (find(d.key) != nullptr)
    throw "already exists!";
  int pos = 0;
  pos = find_pos(d.key);
  data.emplace(data.begin() + pos, d);
}

void Tables::OrderedTable::remove(const std::string& _key) {
  int pos = 0;
  pos = find_remove(_key);
  if (pos == -1)
    throw "no such element!";
  data.erase(data.begin() + pos);
}

int Tables::OrderedTable::find_pos(const std::string& _key) {
  int i = 0;
  int tmp = 0;
  if (!data.size()) {
    return 0;
  }
  for (int i = 0; i < data.size(); i++) {
    if (data[i].key.compare(_key) > 0) {
      return i;
    }
  }
  return data.size();
}

int Tables::OrderedTable::find_remove(const std::string& _key) { //binary search
  int middle = 0, left, right;
  left = 0; right = data.size() - 1;
  while (true)
  {
    if (left > right)
      return -1; // значение не найдено
    middle = left + (right - left) / 2;
    if (data[middle].key.compare(_key) < 0) left = middle + 1;
    if (data[middle].key.compare(_key) > 0) right = middle - 1;
    if (!data[middle].key.compare(_key)) {
      return middle;
    }
  }
}