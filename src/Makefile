CFLAGS = -Wall -Wextra -Werror
CC = -gcc -std=c11
SOURCE = s21_*.c
TARGET = s21_decimal
TEST_SOURCE = tests/*.c

all: s21_decimal.a

s21_decimal.a:
	$(CC) $(CFLAGS) $(SOURCE) -c
	ar rc $(TARGET).a *.o
	@rm *.o

clean:
	@rm -rf *.o *.a *.gcno *.gcda coverage.info test_runner coverage_report a.out

test: clean s21_decimal.a
	$(CC) $(CFLAGS) $(TEST_SOURCE) s21_decimal.a -o test_runner -lcheck -lm -lpthread
	-./test_runner

clang_format:
	clang-format -style=google -i *.c *.h
	clang-format -style=google -i tests/*.c tests/*.h

style:
	clang-format -style=google -n *.c *.h
	clang-format -style=google -n tests/*.c tests/*.h

valgrind: s21_decimal.a
	$(CC) $(CFLAGS) $(TEST_SOURCE) s21_decimal.a -o test_runner -lcheck -lsubunit -lm -lpthread
	./test_runner
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test_runner

gcov_report: clean
	$(CC) --coverage $(CFLAGS) $(SOURCE) -c
	ar rc $(TARGET).a *.o
	@rm *.o
	ranlib s21_decimal.a
	$(CC) --coverage $(CFLAGS) $(TEST_SOURCE) s21_decimal.a -o test_runner -lcheck -lm -lpthread
	./test_runner
	lcov --capture --directory . --output-file coverage.info
	#lcov --remove coverage.info '/usr/*' --output-file coverage.info
	lcov --remove coverage.info 'src/tests/*' --output-file coverage.info
	lcov --remove coverage.info 'src/s21_in_out_dec.c' --output-file coverage.info
	lcov --remove coverage.info 'src/s21_help.c' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
	open ./coverage_report/index.html


win:
	$(CC) $(CFLAGS) main.c s21_is_less.c s21_div.c s21_is_greater_or_equal.c s21_from_float_to_decimal.c s21_round.c s21_floor.c s21_is_less_or_equal.c s21_function_compare.c s21_is_equal.c s21_sub.c s21_add.c s21_help.c s21_mul.c s21_truncate.c s21_negate.c s21_from_decimal_to_float.c s21_from_decimal_to_int.c s21_from_int_to_decimal.c s21_in_out_dec.c s21_get_bit.c s21_set_bit.c s21_get_power.c s21_set_power.c -o test_main -lm -lsubunit
	./test_main

.PHONY: all clean
