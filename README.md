Texto
===

A library to provide serialization for C++ components _as any other_ **modern programming language**.

# How it works

1. Include `texto.h`
2. Run `introspecto` at your `main.cpp` file
3. call `to_json` function passing the output stream and whatever data

```c++
  texto::to_json(std::cout, person);
```



# Dependencies

- C++ STL _(commonly already included in the toolchain/OS)_
- GCC/Clang compiler with **C++23** support _(commonly the default compiler)_
- introspecto-cpp headers and binary


