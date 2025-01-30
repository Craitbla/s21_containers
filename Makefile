CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lgtest -lgtest_main -lstdc++ -lgcov

OBJ_DIR = obj
TEST_DIR = tests

TESTS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TESTS))

TARGET = s21_test

CLANG = clang-format -i

ifeq ($(OS), Windows_NT)
	SYSTEM := Windows
else
    SYSTEM := $(shell uname -s)
endif
ifeq ($(SYSTEM), Linux)
	TEST_FLAGS += -lsubunit -lrt -lm
	OPEN = xdg-open
	LEAKS = valgrind --tool=memcheck --leak-check=yes
endif
ifeq ($(SYSTEM), Darwin)
	OPEN = open
	CFLAGS += -ld_classic
	TEST_FLAGS += -ld_classic
	LEAKS = leaks --atExit --
	LCOV_FLAGS = --ignore-errors inconsistent
endif

all: test

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

test: build
	./$(TARGET)

build: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -o $(TARGET) $(TEST_FLAGS)
	
-include $(TEST_OBJECTS:.o=.d)

$(OBJ_DIR)/%.d: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MM -MT $(@:.d=.o) $< > $@
	
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

fsan: CFLAGS += -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable
fsan: test

gcov_report:
	$(CC) $(GCOV_FLAGS) $(TESTS) -o report.out $(TEST_FLAGS)
	./report.out
	lcov --capture --directory . --output-file coverage.info $(LCOV_FLAGS)
	lcov --remove coverage.info '/usr/*' '*/$(TEST_DIR)/*' --output-file coverage.info
	genhtml -o report coverage.info
	rm -f *.gcno *.gcda *.info *.gcov *.out
	$(OPEN) ./report/index.html

clean:
	@rm -f *.o *.a *.out *.gcno *.gcda $(TARGET)
	@rm -rf report $(OBJ_DIR)
	
clean_obj:
	@rm -rf $(OBJ_DIR)

rebuild: clean all

clang:
	$(CLANG) $(TEST_DIR)/*.cpp *.h containers/*.h containers_plus/*.h

leaks: build
	$(LEAKS) ./$(TARGET)
