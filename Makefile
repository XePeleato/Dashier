# Project: Dashier
# Makefile created by Dev-C++ 5.11

#CPP      = g++.exe
#CC       = gcc.exe
#WINDRES  = windres.exe
OBJ      = main.o dutils.o config.o
LINKOBJ  = main.o dutils.o config.o
#LIBS     = -L"Z:/Dev-Cpp/MinGW64/lib" -L"Z:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -lwinmm -static-libgcc
#INCS     = -I"Z:/Dev-Cpp/MinGW64/include" -I"Z:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"Z:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
#CXXINCS  = -I"Z:/Dev-Cpp/MinGW64/include" -I"Z:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"Z:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"Z:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
#BIN      = Dashier.exe
#CXXFLAGS = $(CXXINCS) 
#CFLAGS   = $(INCS) 
#RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

dutils.o: dutils.c
	$(CC) -c dutils.c -o dutils.o $(CFLAGS)

config.o: config.c
	$(CC) -c config.c -o config.o $(CFLAGS)
