
#include "ordered_table.hxx"

std::shared_ptr<Polynomial> Tables::OrderedTable::find(const std::string& _key) { // binary search
  if (data.empty()) {
    return nullptr;
  }
  int middle = 0, left, right;
  left = 0; right = size - 1;
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

bool Tables::OrderedTable::insert(const Tables::Data& _data) {
  Data tmp1, tmp2;
  if (find(_data.key) != nullptr)
    return false;
  if (size == data.size())
    return false;
  int pos = 0;
  if (!size) {
    data[pos] = _data;
    size++;
    return true;
  }
  else {
    pos = find_pos(_data.key);
    tmp1 = data[pos];
    data[pos] = _data;
      for (int i = pos + 1; i < size; i++) {
        tmp2 = data[i];
        data[i] = tmp1;
        tmp1 = tmp2;
      }
      if (tmp1.key != "empty")
        data[size] = tmp1;
    size++;
    return true;
  }
  return false;
}

bool Tables::OrderedTable::remove(const std::string& _key) {
  Data tmp1, tmp2;
  int pos = 0;
  bool success = false;
  success = find(_key, pos);
  if (!success)
    return false;
  for (int i = pos; i < size - 1; i++) {
    data[i] = data[i + 1];
  }
  data[size - 1].key = "empty";
  data[size - 1].polynomial = nullptr;
  size--;
  return true;
}

int Tables::OrderedTable::find_pos(const std::string& _key) {
  int i = 0;
  int tmp = 0;
  if (!size) {
    return 0;
  }
  for (int i = 0; i < size; i++) {
    if (data[i].key.compare(_key) > 0 && data[i].key != "empty") {
      return i;
    }
  }

  return size;
}

bool Tables::OrderedTable::find(const std::string& _key, int& pos) {
  int middle = 0, left, right;
  left = 0; right = size - 1;
  while (true)
  {
    if (left > right)
      return false; // значение не найдено
    middle = left + (right - left) / 2;
    if (data[middle].key.compare(_key) < 0) left = middle + 1;
    if (data[middle].key.compare(_key) > 0) right = middle - 1;
    if (!data[middle].key.compare(_key)) {
      pos = middle;

      return true;
    }
  }
}
