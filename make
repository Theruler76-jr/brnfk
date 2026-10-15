CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iheader
LDFLAGS = -static -static-libstdc++ -static-libgcc

TARGET = brnfk

SOURCES = \
	src/main.cpp \
	src/header.cpp \
	src/interpreter.cpp \
	src/preprocessor.cpp \
	src/error_handling.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
