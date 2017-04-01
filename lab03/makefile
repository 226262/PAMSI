CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -g -O2
INCLUDES = -Iinc
LFLAGS = -Wall

SRCDIR := src
OBJDIR := obj
INCDIR := inc
SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJS := $(addprefix $(OBJDIR)/,$(SRC:$(SRCDIR)/%.cpp=%.o))  #Place objects
LIBS =  #-lsfml-graphics -lsfml-window -lsfml-system
NAME = engine


all:
	$(MAKE) --no-print-directory cle
	$(MAKE) --no-print-directory -j bui
	$(MAKE) --no-print-directory run

.PHONY : clean
cle:
	rm -f $(OBJDIR)/*.o *~ $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

bui: $(OBJS)
	$(CXX) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBS)

run:
	./$(NAME)

val:
	valgrind --tool=memcheck --leak-check=full ./$(NAME)
