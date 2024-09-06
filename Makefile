NB = 01
ifndef NB
	$(error NB is not set. Please provide NB, e.g., `make NB=01`)
	quit
endif
CXX		=	c++
NAME 	= 	executable
FULL_NAME=	executable${NB}
SRC 	=	main_${NB}.cpp \
			Vector.cpp \
			Matrix.cpp \
			Complex.cpp
HEADER	=	inc/Matrix.hpp \
			inc/Vector.hpp \
			inc/Complex.hpp
OBJS	=	$(addprefix obj/, $(SRC:.cpp=.o))
CXXFLAGS=	-Wall -Wextra -Werror --std=c++17 -g

all		: ${FULL_NAME}
	@echo "Compile exercice number ${NB}"

${FULL_NAME}	:	${OBJS} ${HEADER}
	${CXX} ${CXXFLAGS} -o ${FULL_NAME} ${OBJS}

obj/%.o: src/%.cpp $(HEADER)
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c $< -o $@

fclean: clean
	rm -f $(NAME)*

clean:
	rm -rf obj/

re: fclean all

.PHONY: all fclean clean re
