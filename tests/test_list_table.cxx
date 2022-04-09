#include "gtest/gtest.h"

#include "list_table.hxx"

TEST(ListTable, can_create_arr_table) {
	ASSERT_NO_THROW(Tables::ListTable table);
}

TEST(ListTable, can_remove_polynomial) {
	Tables::ListTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST(ListTable, can_insert_polynomial) {
	Tables::ListTable table;
	Tables::Data data("key", std::make_shared<Polynomial>("4x1y11z1"));

	ASSERT_NO_THROW(table.insert(data));
}

TEST(ListTable, can_find_polynomial) {
	Tables::ListTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST (ListTable, cant_insert_data_with_no_unique_key) {
	Tables::ListTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("key", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (ListTable, cant_delete_not_existing_element) {
	Tables::ListTable table;

	EXPECT_EQ (false, table.remove("key"));
}

TEST (ListTable, can_delete_existing_element) {
	Tables::ListTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (true, table.remove("key"));
}

TEST (ListTable, cant_find_not_existing_element) {
	Tables::ListTable table;

	EXPECT_EQ (nullptr, table.find("key"));
}

TEST (ListTable, can_find_existing_element) {
	Tables::ListTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_NE (nullptr, table.find("key"));
}
