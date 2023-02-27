CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -std=c11 -pedantic -g
GCOV_FLAGS		= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS	= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med #--track-fds=yes --show-leak-kinds=all
CHECK_FLAGS 	= $(shell pkg-config --cflags --libs check)

LIBRARY			= s21_matrix.a
SRC_PROJECT		= $(wildcard arithmetic/*.c operations/*.c core/*.c)
SRC_TEST		= tests/test_arithmetic.c tests/test_operations.c tests/test_matrix.c tests/test_core.c
OBJ_PROJECT		= s21_arithmetic.o s21_operations.o s21_core.o
OBJ_TEST		= test_arithmetic.o test_operations.o test_matrix.o test_core.o


all: gcov_report

$(LIBRARY): $(SRC_PROJECT)
	$(CC) $(CFLAGS) -c $(SRC_PROJECT)
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	ranlib $(LIBRARY)

test: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(CHECK_FLAGS)
	./test

gcov_report: clean $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(CHECK_FLAGS)
	./test
	lcov -t "test" -o gcov.info -c -d .
	genhtml -o report gcov.info
	rm -rf ./*.gc*
	make open

$(OBJ_TEST):
	$(CC) $(CFLAGS) -c $(SRC_TEST)

clean:
	rm -rf test
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf report
	rm -rf *.gcno
	rm -rf *.info
	rm -rf valgrind.txt

rebuild: clean test

open: 
	open report/index.html

.PHONY: all clean rebuild open clang valgrind docker

valgrind: rebuild
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clang:
	clang-format --style=google -i arithmetic/*
	clang-format --style=google -i operations/*
	clang-format --style=google -i core/*
	clang-format --style=google -i tests/*

docker:
	cd ../materials/build; sudo sh run.sh; cd ../../src