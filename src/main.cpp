#include "person.hpp"
#include "texto.hpp"
#include <iostream>

int main() {
  Person david{"David", 31, 
    {"software@davidkennedy.dev"},
    {{"Matheus", 26}, {"Ze", 26}}
  };
  to_json(std::cout, david);
}
