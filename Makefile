CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRCS = main.cpp Paint.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = output

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
