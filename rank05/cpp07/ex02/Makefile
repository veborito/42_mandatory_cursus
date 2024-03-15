TARGET = array

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=leak

SRC = 										\
		main.cpp							\

all : $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f *.o

re: fclean $(TARGET)

# Phony targets
.PHONY: all clean re fclean

