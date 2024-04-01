all:  test s21_math.a run gcov getCoverage createHTML gcov_report

test: tests.c s21_math.c
	gcc -Wall -Werror -Wextra tests.c s21_math.c -o tests -lcheck --coverage

run: test
	./tests||true

gcov:
	gcov s21_math.c

getCoverage: gcov
	lcov --capture --directory . --output-file coverage.info

createHTML: getCoverage
	genhtml coverage.info --output-directory out
	
s21_math.a: s21_math.c
	gcc -c s21_math.c -o s21_math.o
	ar rcs s21_math.a s21_math.o

#lcov
gcov_report: createHTML
	open out/index.html
	
clean:
	rm -f tests *.gcno *.gcda *.gcov *.info *.o *.a && rm -rf out

