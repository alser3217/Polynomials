#ifndef __BASE_TABLE_H__
#define __BASE_TABLE_H__

#include <vector>

#include "polynomial.h"

struct Data {
  std::string key;
  std::string s_polynomial;
  Polynomial polynomial;
};

class BaseTable {
public:
  virtual Data* find(const std::string& key) = 0;
  virtual void insert(const Data& data) = 0;
  virtual void delete(const std::string& key) = 0;
  virtual void print() = 0;
  virtual ~BaseTable(){}
};


#endif