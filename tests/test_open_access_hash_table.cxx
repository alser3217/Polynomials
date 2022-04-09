#include "gtest/gtest.h"

#include "open_access_hash_table.hxx"
#include "open_access_hash_table.cxx"


TEST(OpenAccessHashTable, can_create_arr_table) {
	ASSERT_NO_THROW(Tables::OpenAccessHashTable table);
}

TEST(OpenAccessHashTable, can_remove_polynomial) {
	Tables::OpenAccessHashTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST(OpenAccessHashTable, can_insert_polynomial) {
	Tables::OpenAccessHashTable table;
	Tables::Data data("key", std::make_shared<Polynomial>("4x1y11z1"));

	ASSERT_NO_THROW(table.insert(data));
}

TEST(OpenAccessHashTable, can_find_polynomial) {
	Tables::OpenAccessHashTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST (OpenAccessHashTable, cant_insert_data_with_no_unique_key) {
	Tables::OpenAccessHashTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("key", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (OpenAccessHashTable, cant_insert_data_in_full_table) {
	Tables::OpenAccessHashTable table(1);
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("qw", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (OpenAccessHashTable, cant_delete_not_existing_element) {
	Tables::OpenAccessHashTable table;

	EXPECT_EQ (false, table.remove("key"));
}

TEST (OpenAccessHashTable, can_delete_existing_element) {
	Tables::OpenAccessHashTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (true, table.remove("key"));
}

TEST (OpenAccessHashTable, cant_find_not_existing_element) {
	Tables::OpenAccessHashTable table;

	EXPECT_EQ (nullptr, table.find("key"));
}

TEST (OpenAccessHashTable, can_find_existing_element) {
	Tables::OpenAccessHashTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_NE (nullptr, table.find("key"));
}
