#include "gtest/gtest.h"

#include "ordered_table.hxx"

TEST(OrderedTable, can_create_arr_table) {
	ASSERT_NO_THROW(Tables::OrderedTable table);
}

TEST(OrderedTable, can_remove_polynomial) {
	Tables::OrderedTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST(OrderedTable, can_insert_polynomial) {
	Tables::OrderedTable table;
	Tables::Data data("key", std::make_shared<Polynomial>("4x1y11z1"));

	ASSERT_NO_THROW(table.insert(data));
}

TEST(OrderedTable, can_find_polynomial) {
	Tables::OrderedTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST (OrderedTable, cant_insert_data_with_no_unique_key) {
	Tables::OrderedTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("key", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (OrderedTable, cant_insert_data_in_full_table) {
	Tables::OrderedTable table(1);
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("qw", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (OrderedTable, cant_delete_not_existing_element) {
	Tables::OrderedTable table;

	EXPECT_EQ (false, table.remove("key"));
}

TEST (OrderedTable, can_delete_existing_element) {
	Tables::OrderedTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (true, table.remove("key"));
}

TEST (OrderedTable, cant_find_not_existing_element) {
	Tables::OrderedTable table;

	EXPECT_EQ (nullptr, table.find("key"));
}

TEST (OrderedTable, can_find_existing_element) {
	Tables::OrderedTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_NE (nullptr, table.find("key"));
}