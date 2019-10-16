all: 
	make monte_carlo

.PHONY: clean check
# FLAGS= -O2 
FLAGS= -g 
GENERATE_EXE= mkdir -p build && gcc $^ -o $@ $(FLAGS)
GENERATE_O= mkdir -p build && gcc $^ -c -o $@ $(FLAGS)
clean: 
	rm -rf build/* generator monte_carlo cppcheck.txt

check:
	@cppcheck --enable=style -i src/mt19937ar.cpp src/ 2> cppcheck.txt 

# Compilation Separee

## Des deux projets


## Monte Carlo

monte_carlo: build/monte_carlo.o build/data.o build/main_monte_carlo.o build/mt19937ar.o
	$(GENERATE_EXE) -lm

build/main_monte_carlo.o: main_monte_carlo.c
	$(GENERATE_O)

build/monte_carlo.o: src/monte_carlo.c
	$(GENERATE_O)

data/data.c: generator
	./generator ${n}

build/data.o: data/data.c
	$(GENERATE_O)

## Generation du tableau de nombre aleatoire

generator: build/mt19937ar.o build/main_generator.o build/generator.o
	$(GENERATE_EXE) -lm

build/main_generator.o: main_generator.c
	$(GENERATE_O)

build/mt19937ar.o: src/mt19937ar.c
	$(GENERATE_O)

build/generator.o: src/generator.c
	$(GENERATE_O)
