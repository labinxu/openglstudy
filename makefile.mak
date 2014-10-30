LIBDIRS = -L/local/lib
INCDIRS = -I/local/include -I/usr/include
CC = g++
LIBS = -lopengl32 -lglut -lglu32
RM = rm

EXE = main.exe
OBJS = main.o cgfxopengl.o

SRCS = $(wildcard tools/oldsrc/*.cpp)
#replace suffix cpp with o
OBJS = $(patsubst %.cpp,%.o,$(SRCS))


$(EXE):$(OBJS)
	$(CC) $(INCDIRS) $(LIBDIRS) -o $@ $^ $(LIBS)
%.o:%.cpp
	$(CC) $(INCDIRS) $(LIBDIRS) -o $@ -c $^

clean:
	$(RM) $(EXE) $(OBJS)
