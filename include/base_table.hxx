#ifndef __BASE_TABLE__
#define __BASE_TABLE__

#include <ostream>

#include "polynomial.hxx"

namespace Tables {

  class Data {
    std::string key = "no_key";
    Polynomial* polynomial = nullptr;
  public:
    Data (std::string _key, Polynomial* _polynomial) : key(_key), polynomial(_polynomial) {}

    friend std::ostream& operator<<(std::ostream& out, const Data& object);

    friend class ArrTable;
    friend class OrderedTable;
    friend class ListTable;
  };

  int hash(std::string _key, int _size);

  class BaseTable {
  public:
    virtual Polynomial* find(const std::string& _key) = 0;
    virtual void insert(const Data& _data) = 0;
    virtual void remove(const std::string& _key) = 0;
    virtual void print() = 0;
    virtual ~BaseTable() {}
  };
}

#endif
