FLAGS = -g

SRCS = main.cpp AdvString.cpp RelFile.cpp RawPage.cpp PageHeader.cpp Page.cpp VMPage.cpp FSMPage.cpp PageHandler.cpp
OBJS = $(SRCS:.cpp=.o)
LIBS = -I./headers/

.PHONY: all clean

$(OBJS): $(SRCS)
	g++ -c $(FLAGS) $(SRCS) 

all:


	g++ -o program $(OBJS) 

clean:
	rm -f program
	rm -f *.o
