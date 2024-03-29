all: help 

run: ## Run all the command, don't forget to give the numbers n
	make exe/generator && ./exe/generator ${n} && make exe/monte_carlo

.PHONY: clean check help run
FLAGS= -O2 
# FLAGS= -g 
COMPILER_C= gcc
CREATE_FOLDER_BUILD= mkdir -p build
CREATE_FOLDER_EXE= mkdir -p exe
GENERATE_EXE= $^ -o $@ $(FLAGS)
GENERATE_O= $^ -c -o $@ $(FLAGS)

help: ## Display the availables commands
	@grep -E '(^[a-zA-Z_-]+:.*?##.*$$)|(^##)' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-10s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

clean: ## Clean the repository
	@rm -rf build exe data/data.c cppcheck.txt

check: ## Clean the quality of the code
	@cppcheck --enable=style -i src/mt19937ar.c src/ main/  2> cppcheck.txt 

# Des deux projets

# Monte Carlo

exe/monte_carlo: build/monte_carlo.o build/data.o build/main_monte_carlo.o build/mt19937ar.o ## Executable for Monte Carlo
	@$(CREATE_FOLDER_EXE) && $(COMPILER_C) $(GENERATE_EXE) -lm

build/main_monte_carlo.o: main/main_monte_carlo.c
	@$(CREATE_FOLDER_BUILD) && $(COMPILER_C) $(GENERATE_O)

build/monte_carlo.o: src/monte_carlo.c
	@$(CREATE_FOLDER_BUILD) && $(COMPILER_C) $(GENERATE_O)

build/data.o: data/data.c
	@$(CREATE_FOLDER_BUILD) && $(COMPILER_C) $(GENERATE_O)

# Generation du tableau de nombre aleatoire

exe/generator: build/mt19937ar.o build/main_generator.o build/generator.o ## Generator of numbers
	@$(CREATE_FOLDER_EXE) && $(COMPILER_C) $(GENERATE_EXE) -lm

build/main_generator.o: main/main_generator.c
	@$(CREATE_FOLDER_BUILD) && $(COMPILER_C) $(GENERATE_O)

build/mt19937ar.o: src/mt19937ar.c
	@$(CREATE_FOLDER_BUILD) && $(COMPILER_C) $(GENERATE_O)

build/generator.o: src/generator.c
	@$(CREATE_FOLDER_BUILD) && $(COMPILER_C) $(GENERATE_O)
