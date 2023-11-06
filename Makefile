all: texto_sample

texto_sample: sample/main.cpp include/texto.h .introspecto_generated.h
	g++ -std=c++2b $< -I./include -o $@

clean:
	-rm -f texto_sample .*_generated.h

.introspecto_generated.h: bin/introspecto ./sample/main.cpp
	-./$^ 2> $@.log

test: texto_sample
	./$<

.PHONY = test clean 
