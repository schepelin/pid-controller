TEST_RUNNER_FILENAME=test_runner
CXX_PATH?=/usr/local/include

generate_test_runner_code:
	echo "---------- Generating code for test runner ----------"
	cxxtestgen --error-printer -o $(TEST_RUNNER_FILENAME).cpp PIDTestSuite.h

test: generate_test_runner_code
	g++  -o $(TEST_RUNNER_FILENAME) -I .  -I $(CXX_PATH) $(TEST_RUNNER_FILENAME).cpp PID.cpp
	echo "---------- Tests output ----------"
	./$(TEST_RUNNER_FILENAME)
