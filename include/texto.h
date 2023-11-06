#pragma once

#include <cstddef>
#include <ostream>

namespace texto {
void to_json(std::ostream &out, const size_t &value);
void to_json(std::ostream &out, const double &value);
void to_json(std::ostream &out, const std::string &value);
void to_json(std::ostream &out, const char &value);

template <typename T> void to_json(std::ostream &out, T object);
} // namespace texto

#include "../src/texto.hpp"
 
