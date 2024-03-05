TARGET = base 

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

SRC = 										\
		main.cpp							\
		Base.cpp						\

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

