  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall -std=c++11

  # the build target executable:
  TARGET = main

  TEST = ./tests/tests.cpp

  all: $(TARGET)

  $(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o risingCity $(TARGET).cpp
	$(CC) $(CFLAGS) -o test $(TEST)

  clean:
	$(RM) risingCity
	$(RM) test