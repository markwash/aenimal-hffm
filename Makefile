CXXFLAGS=-g
CFLAGS=-g

CXX_TESTS=\
hffm_solution_test.h\

OBJS=\

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