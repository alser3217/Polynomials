#ifndef __ARRTABLE__
#define __ARRTABLE__

#include <vector>
#include <algorithm>

#include "base_table.hxx"


namespace Tables {

  class ArrTable : public BaseTable {
  protected:
    std::vector<Tables::Data> data;
    int size;

  private:
    virtual bool find(const std::string& _key, int& _pos) override;
  public:
    ArrTable(int _size = SIZE) : data(_size), size(0) {}

    virtual ~ArrTable() override {};

    virtual bool remove(const std::string& _key) override;
    virtual bool insert(const Tables::Data& _data) override;
    virtual std::shared_ptr<Polynomial> find(const std::string& _key) override; //

    void print() override;
  };
}

#endif
