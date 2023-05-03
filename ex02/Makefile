CPP = main.cpp PmergeMe.cpp
HPP = PmergeMe.hpp
OBJ = $(CPP:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
NAME = PmergeMe

all: $(NAME)

%.o: %.cpp $(HPP)
	$(CXX) $(CXXFLAGS) -c $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
