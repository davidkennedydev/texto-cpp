#pragma once

#include "person.hpp"
#include "../include/introspecto.h"
#include <concepts>
#include <ostream>
#include <span>
#include <string>
#include <type_traits>

inline void to_json(std::ostream &out, const size_t &value) { out << value; }
inline void to_json(std::ostream &out, const double &value) { out << value; }

inline void to_json(std::ostream &out, const std::string &value) {
  out << '"' << value << '"';
}
inline void to_json(std::ostream &out, const char &value) {
  std::string str = {value};
  to_json(out, str);
}

template <typename Container>
inline void to_json_array(std::ostream &out, const Container &container) {
  out << '[';

  bool is_first_member = true;
  for (const auto &element : container) {
    if (is_first_member) {
      is_first_member = false;
    } else {
      out << ',';
    }
    to_json(out, element);
  }
  out << ']';
}

#include <vector>

template <typename T>
inline void to_json(std::ostream &out, const std::vector<T> &container) {
  to_json_array(out, container);
}

#include <deque>

template <typename T>
inline void to_json(std::ostream &out, const std::deque<T> &container) {
  to_json_array(out, container);
}

#include <array>

template <typename T, size_t S>
inline void to_json(std::ostream &out, const std::array<T, S> &container) {
  to_json_array(out, container);
}

// TODO: Replace by const reference , const reference not provided yet by
// introspecto
template <typename T>
inline void to_json(std::ostream &out, T object) {
  out << '{';

  auto personInfo = introspecto::introspect(object);

  bool is_first_member = true;
  personInfo.foreachField([&out, &is_first_member]<typename Type>(
                              std::string name, const Type content) {
    if (is_first_member) {
      is_first_member = false;
    } else {
      out << ',';
    }

    out << '"' << name << "\":";
    to_json(out, content);
  });

  out << '}';
}
