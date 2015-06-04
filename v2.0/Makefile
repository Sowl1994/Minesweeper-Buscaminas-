SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CXXFLAGS =  -Wall -g  -I $(INC)

# ************ Compilación de módulos ************
all: clean	$(BIN)/buscaminas
	./$(BIN)/buscaminas

#$(OBJ)/Tablero.o : $(SRC)/Tablero.cpp $(INC)/Tablero.h
#	$(CXX) -c $(CXXFLAGS) $(SRC)/Tablero.cpp -o $(OBJ)/Tablero.o

#$(OBJ)/CampoMinas.o : $(SRC)/CampoMinas.cpp $(INC)/CampoMinas.h
#	$(CXX) -c $(CXXFLAGS) $(SRC)/CampoMinas.cpp -o $(OBJ)/CampoMinas.o

$(OBJ)/BuscaMinas.o : $(SRC)/BuscaMinas.cpp 
	$(CXX) -c $(CXXFLAGS) $(SRC)/BuscaMinas.cpp -o $(OBJ)/BuscaMinas.o

$(BIN)/buscaminas : $(OBJ)/BuscaMinas.o 
	$(CXX) -o $(BIN)/buscaminas $(OBJ)/BuscaMinas.o 

# ************ Modo de depuracion ************
debug : 
	$(CXX) -ggdb $(SRC)/BuscaMinas.cpp -o $(BIN)/buscaminas
	gdb $(BIN)/buscaminas
 
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
