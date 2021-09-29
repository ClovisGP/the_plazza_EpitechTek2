##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##
CC =	g++

RSC_DIR = src

SRC_BINARY =	$(RSC_DIR)/main.cpp					\
				$(RSC_DIR)/errorGestion.cpp			\
				$(RSC_DIR)/argGestion.cpp			\
				$(RSC_DIR)/commandManagement.cpp	\
				$(RSC_DIR)/commandTraitement.cpp	\
				$(RSC_DIR)/kitchenManagement.cpp	\
				$(RSC_DIR)/fifoManagement.cpp		\
				$(RSC_DIR)/Kitchen.cpp				\
				$(RSC_DIR)/Pizza.cpp				\
				$(RSC_DIR)/GlobalData.cpp

BINARY	=	plazza

ERRORFLAG =	-Wall -Werror

all:
	$(CC) -o $(BINARY) $(SRC_BINARY) $(ERRORFLAG) -lpthread
clean:
	rm -rf *.o *.a *.so

fclean: clean
	rm -rf $(BINARY)

re:	clean all
