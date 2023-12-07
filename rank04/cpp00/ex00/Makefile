TARGET = megaphone

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

# Build target

all : $(TARGET)

$(TARGET): megaphone.cpp
	$(CXX) $(CXXFLAGS) megaphone.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f *.o

re: fclean $(TARGET)

# Phony targets
.PHONY: all clean re fclean
