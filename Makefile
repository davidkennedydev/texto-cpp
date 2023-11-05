all: texto

texto: src/main.cpp src/texto.hpp .introspecto_generated.h
	g++ -std=c++23 $< -o $@

clean:
	-rm texto .*_generated.h

.introspecto_generated.h: bin/introspecto ./src/main.cpp
	-./$^ 2> $@.log

test: texto
	./$<

.PHONY = test clean 
