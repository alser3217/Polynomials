#ifndef __LINE_TABLE_H__
#define __LINE_TABLE_H__

#include <vector>

#include "base_table.h"

class Arr_Table : public BaseTable {
  std::vector<Data> data;
  int size = 0;
public:
  Arr_Table() : BaseTable() {}
  void delete(const string& key);
  void insert(const Data& d);
  Data* find(const string& key); 
  void print();
  ~Arr_Table();
};

#endif