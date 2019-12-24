#include <gtest/gtest.h>
#include "../myproject/PersonAccount.h"
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

class PersonAccountTest : public ::testing::Test {
protected:
    Person::Account p;

    void SetUp() override {
        p.id = 1;
        p.first_name = "FirstName";
        p.last_name = "LastName";
    }
};

TEST_F(PersonAccountTest, map) {
    std::map<Person::Account, int> map;
    map[p] = 10;
    EXPECT_EQ(map.at(p), 10);
}

TEST_F(PersonAccountTest, unordered_map) {
    std::unordered_map<Person::Account, int> umap;
    umap[p] = 10;
    EXPECT_EQ(umap.at(p), 10);
}

TEST_F(PersonAccountTest, set) {
    std::set<Person::Account> set;
    set.insert(p);
    EXPECT_TRUE(*set.find(p) == p);
}

TEST_F(PersonAccountTest, unordered_set) {
    std::unordered_set<Person::Account> uset;
    uset.insert(p);
    EXPECT_TRUE(*uset.find(p) == p);
}
