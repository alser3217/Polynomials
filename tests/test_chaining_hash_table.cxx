#include "gtest/gtest.h"

#include "chaining_hash_table.hxx"
#include "chaining_hash_table.cxx"


TEST(ChainingHashTable, can_create_arr_table) {
	ASSERT_NO_THROW(Tables::ChainingHashTable table);
}

TEST(ChainingHashTable, can_remove_polynomial) {
	Tables::ChainingHashTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST(ChainingHashTable, can_insert_polynomial) {
	Tables::ChainingHashTable table;
	Tables::Data data("key", std::make_shared<Polynomial>("4x1y11z1"));

	ASSERT_NO_THROW(table.insert(data));
}

TEST(ChainingHashTable, can_find_polynomial) {
	Tables::ChainingHashTable table;

	ASSERT_NO_THROW(table.remove("some_key"));
}

TEST (ChainingHashTable, cant_insert_data_with_no_unique_key) {
	Tables::ChainingHashTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (false, table.insert(Tables::Data("key", std::make_shared<Polynomial>("5x1y1z1"))));
}

TEST (ChainingHashTable, cant_delete_not_existing_element) {
	Tables::ChainingHashTable table;

	EXPECT_EQ (false, table.remove("key"));
}

TEST (ChainingHashTable, can_delete_existing_element) {
	Tables::ChainingHashTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_EQ (true, table.remove("key"));
} 

TEST (ChainingHashTable, cant_find_not_existing_element) {
	Tables::ChainingHashTable table;

	EXPECT_EQ (nullptr, table.find("key"));
}

TEST (ChainingHashTable, can_find_existing_element) {
	Tables::ChainingHashTable table;
	table.insert(Tables::Data("key", std::make_shared<Polynomial>("4x1y1z1")));

	EXPECT_NE (nullptr, table.find("key"));
} 
