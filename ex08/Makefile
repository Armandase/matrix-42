CXX		=	c++
NAME 	= 	trace
SRC 	=	main.cpp
HEADER	=	inc/Matrix.hpp inc/Vector.hpp
OBJS	=	$(addprefix obj/, $(SRC:.cpp=.o))
CXXFLAGS=	-Wall -Wextra -Werror --std=c++17 -g

all		:	${NAME}

${NAME}	:	${OBJS} ${HEADER}
			${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

obj/%.o: src/%.cpp $(HEADER)
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf obj/


re: fclean all

.PHONY: all fclean clean re
