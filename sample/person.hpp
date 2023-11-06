#pragma once

#include <string>
#include <vector>
#include <deque>

struct Person {
  std::string name;
  size_t age;
  std::vector<std::string> emails;
  std::deque<Person> friends;

};
