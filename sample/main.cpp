#include "person.hpp"
#include <iostream>
#include <texto.h>

int main() {
  Person person{"David",
               31,
               {"software@davidkennedy.dev"},
               {{"Matheus", 26}, {"Ze", 26}}};
  texto::to_json(std::cout, person);
}
