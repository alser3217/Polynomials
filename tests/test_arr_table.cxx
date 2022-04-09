#include "gtest/gtest.h"

#include "arr_table.hxx"
#include "arr_table.cxx"


TEST (ArrTable, can_create_arr_table) {
	ASSERT_NO_THROW (Tables::ArrTable table);
}

TEST (ArrTable, can_remove_polynomial) {
	Tables::ArrTable table;

	ASSERT_NO_THROW (table.remove("some_key"));
}

TEST (ArrTable, can_insert_polynomial) {
	Tables::ArrTable table;
	Tables::Data data("key", std::make_shared<Polynomial>("4x1y11z1"));

	ASSERT_NO_THROW (table.insert(data));
}

TEST (ArrTable, can_find_polynomial) {
	Tables::ArrTable table;

	ASSERT_NO_THROW (table.remove("some_key"));
}

TEST (ArrTable, cant_insert_data_with_no_unique_key) {
	Tables::ArrTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("key", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (ArrTable, cant_insert_data_in_full_table) {
	Tables::ArrTable table(1);
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("qw", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (ArrTable, cant_delete_not_existing_element) {
	Tables::ArrTable table;

	EXPECT_EQ (false, table.remove("key"));
}

TEST (ArrTable, can_delete_existing_element) {
	Tables::ArrTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (true, table.remove("key"));
}

TEST (ArrTable, cant_find_not_existing_element) {
	Tables::ArrTable table;

	EXPECT_EQ (nullptr, table.find("key"));
}

TEST (ArrTable, can_find_existing_element) {
	Tables::ArrTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_NE (nullptr, table.find("key"));
}