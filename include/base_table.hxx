#ifndef __BASE_TABLE__
#define __BASE_TABLE__

#include <ostream>

#include "polynomial.hxx"

namespace Tables {

  class Data {
    std::string key = "no_key";
    std::string s_polynomial = "no name";
    Polynomial* polynomial = nullptr;
  public:
    Data (std::string _key, std::string _s_polynomial, Polynomial* _polynomial) : key(_key),
      s_polynomial(_s_polynomial), polynomial(_polynomial) {}

    friend std::ostream& operator<<(std::ostream& out, const Data& object);

    friend class ArrTable;
    friend class OrderedTable;
  };

  class BaseTable {
  public:
    virtual Polynomial* find(const std::string& _key, int& pos) = 0;
    virtual void insert(const Data& _data) = 0;
    virtual void remove(const std::string& _key) = 0;
    virtual void print() = 0;
    virtual ~BaseTable() {}
  };

}

#endif
