CC= gcc 
CFLAGS= -Wall -Werror -Wextra -std=c11          
TFLAGS = -lcheck -lpthread -lm
TEST=test
OPEN = open

ifeq ($(shell uname), Linux)
	OPEN = xdg-open
	TFLAGS += -lrt -lsubunit -lgcov
endif

all: my_string.a

clean:
	rm -rf *.a && rm -rf *.gcda
	rm -rf *.o && rm -rf *.gcno
	rm -rf report && rm -rf *.info  
	rm -rf $(TEST)
               
test: my_string.a
	$(CC) -o $(TEST) $(TEST).c  my_string.a $(TFLAGS) 
	./$(TEST)

my_string.a:
	$(CC)  -c my_string.c -o my_string.o
	ar rcs my_string.a my_string.o
	ranlib my_string.a

gcov_report: 
	$(CC) --coverage -o $(TEST) $(TEST).c my_string.c $(TFLAGS)   
	./$(TEST)
	lcov -t "$(TEST)" -o $(TEST).info -c -d . --rc branch_coverage=1
	genhtml -o report $(TEST).info --rc branch_coverage=1
	open ./report/index.html

rebuild: clean all
