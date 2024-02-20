CXX = g++

CXXFLAGS = -std=c++11 -Wall -fsanitize=address

TARGET = Chess

SRCS = Chess.cpp Rook.cpp AI.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawns.cpp Position.cpp Queen.cpp Soldier.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = rook.hpp AI.hpp Bishop.hpp Board.hpp King.hpp Knight.hpp Pawns.hpp Position.hpp Queen.hpp Soldier.hpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
