#ifndef __BASE_TABLE__
#define __BASE_TABLE__

#include <ostream>

#include "polynomial.hxx"


namespace Tables {

  const int SIZE = 10;

  enum class STATUS {EMPTY, OCCUPIED, DELETED};

  class Data {
    std::string key;
    std::shared_ptr<Polynomial> polynomial;

    STATUS status;
  public:
    Data(std::string _key = "empty", std::shared_ptr<Polynomial> _polynomial = nullptr, STATUS _status = STATUS::EMPTY) : key(_key), polynomial(_polynomial), status(_status) {}

    Data(const Data& _data) : key(_data.key), polynomial(_data.polynomial), status(_data.status) {} 

    Data& operator=(const Data& _data) {
      if (this == &_data)
        return *this;
      key = _data.key;
      polynomial = _data.polynomial;
    }

    ~Data() {} 

    friend std::ostream& operator<<(std::ostream& out, const Data& object);

    friend class ArrTable;
    friend class OrderedTable;
    friend class ListTable;
    friend class ChainingHashTable;
    friend class Interface;
    friend class OpenAccessHashTable;
  };

  int hash(const std::string& _key, int _size);
  int oa_hash(const std::string& _key, int _size, int _i);

  class BaseTable {
  private:
    virtual bool find(const std::string& _key, int& _pos) = 0;
  public:
    BaseTable() {}

    virtual ~BaseTable() {}

    virtual std::shared_ptr<Polynomial> find(const std::string& _key) = 0;
    virtual bool insert(const Data& _data) = 0;
    virtual bool remove(const std::string& _key) = 0;

    virtual void print() = 0;
  };
}

#endif
