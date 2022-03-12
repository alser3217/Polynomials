#ifndef __ARRTABLE__
#define __ARRTABLE__

#include <vector>

#include "base_table.hxx"

namespace Tables {
  class ArrTable : public BaseTable {
  protected:
    std::vector<Tables::Data> data;
    int size = 0;
    // запретить копирование и оператор присваивания.
  public:
    ArrTable() : BaseTable() {}
    virtual void remove(const std::string& _key);
    virtual void insert(const Tables::Data& d);
    virtual Polynomial* find(const std::string& _key, int& pos);
    void print();
    virtual ~ArrTable() {};
  };
}

#endif