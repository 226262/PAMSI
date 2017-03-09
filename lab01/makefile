CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -g
INCLUDES = -Iinc
LFLAGS = -Wall

SRCDIR := src
OBJDIR := obj
INCDIR := inc
OBJS := $(addprefix $(OBJDIR)/,main.o)  #Place objects
DEPS = $(addprefix $(INCDIR)/,)   # Place Headers
LIBS =  #-lsfml-graphics -lsfml-window -lsfml-system
NAME = engine


all:
	$(MAKE) clean
	$(MAKE) build
	$(MAKE) run

.PHONY : clean
clean:
	rm -f $(OBJDIR)/*.o *~ $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

build: $(OBJS)
	$(CXX) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBS)

run:
	./$(NAME)
