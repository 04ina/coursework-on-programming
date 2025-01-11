FLAGS = -g

SRCS = main.cpp AdvString.cpp RelFile.cpp RawPage.cpp PageHeader.cpp Page.cpp VMPage.cpp FSMPage.cpp PageHandler.cpp MainPage.cpp InitPage.cpp
OBJS = $(SRCS:.cpp=.o)
LIBS = -I./headers/

.PHONY: all clean

$(OBJS): $(SRCS)
	g++ -g -c $(FLAGS) $(SRCS) 

all:


	g++ -o page_inspect $(OBJS) 

clean:
	rm -f page_inspect 
	rm -f *.o
