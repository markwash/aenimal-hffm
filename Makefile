CXXFLAGS=-g
CFLAGS=-g

CXX_TESTS=\
hffm_solution_test.h \
hffm_rand_test.h \
hffm_perm_test.h \

OBJS=\
hffm_solution.o \
hffm_mock_solution.o \
hffm_rand.o \
hffm_perm.o \

all: run_tests ${OBJS} 

run_tests: cxx_test 

cxx_test: cxx_runner
	./cxx_runner

cxx_runner: cxx_runner.cpp ${OBJS}
	g++ ${CXXFLAGS} -o $@ $^

cxx_runner.cpp: ${CXX_TESTS}
	cxxtestgen.py -o $@ --error-printer $^ 

clean:
	rm -f *.o cxx_runner.exe cxx_runner.cpp
	rm -rf build
