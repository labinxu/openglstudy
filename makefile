.PHONY:all clean

LIBDIRS = -L/local/lib
INCDIRS = -I/local/include -I/usr/include
LIBS = -lopengl32 -lglut -lglu32
DIR_DLLS = $(wildcard tools/libs/*.dll)

RM = rm
RMFLAGS = -rf
CC = g++
MKDIR = mkdir


#replace suffix cpp with o
#OBJS = $(SRCS:.cpp=.o)
EXE = main.exe

#prepare directorys
DIR_OBJS = objs
DIR_EXES = exes
DIR_DEPS = deps

SRCS = $(wildcard project/*.cpp)
SRCSNODIR = $(patsubst project/%.cpp, %.cpp, $(SRCS))

OBJS = $(addprefix $(DIR_OBJS)/,$(SRCSNODIR))
OBJS := $(patsubst %.cpp, %.o, $(OBJS))

DIRS = $(DIR_OBJS) $(DIR_EXES) #$#(DIR_DEPS)
DEPS = $(SRCS:.cpp=.dep)
DEPS := $(addprefix $(DIR_DEPS)/, $(DEPS))




all:$(DIRS) $(EXE) $(SRCS)
#$(#DIR_DEPS)

$(DIRS):
	$(MKDIR) $@

$(EXE):$(OBJS)
	$(CC) $(INCDIRS) $(LIBDIRS) -o $(DIR_EXES)/$@ $^ $(LIBS)
$(OBJS):$(SRCS)
	$(CC) -o $@ -c $^
	cp $(DIR_DLLS) $(DIR_EXES)

clean:
	$(RM) $(RMFLAGS) $(DIRS)
list:
	@echo "$(OBJS)"
