#ifndef __INTERFACE__
#define __INTERFACE__

#include "arr_table.hxx"
#include "ordered_table.hxx"
#include "list_table.hxx"
#include "chaining_hash_table.hxx"
#include "base_table.hxx"
#include "postfix.hxx"
#include "open_access_hash_table.hxx"


namespace Tables {
	class Interface {
		std::vector<std::shared_ptr<BaseTable>> tables;
		std::shared_ptr<BaseTable> main_table;
	public:
		Interface(int choice);

		~Interface() {}

		bool add(const Data& _data);
		std::shared_ptr<Polynomial> find(const std::string& _key);
		bool remove(const std::string& _key);
		void print();
		void change(std::shared_ptr<Polynomial> _polynomial, std::string& _new_polynomial);
		double calculate(Polynomial pl, double x, double y, double z);
		std::string get_derivativeX(Polynomial pl);
		std::string get_derivativeY(Polynomial pl);
		std::string get_derivativeZ(Polynomial pl);
	};

	void StartMessage();
	void MenuMessage();

	void NotFoundMessage();
	void FindOptionsMessage();
	void ChangeSuccessMessage();

	void InsertSuccessMessage();
	void InsertFailMessage();

	void PointCalculateMessage(int result);

	void RemoveSuccessMessage();
	void RemoveFailMessage();
}

#endif
