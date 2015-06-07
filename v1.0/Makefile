SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CXXFLAGS =  -Wall -g  -I $(INC)

# ************ Compilación de módulos ************
all: clean	$(BIN)/buscaminas

$(OBJ)/BuscaMinas.o : $(SRC)/BuscaMinas.cpp 
	$(CXX) -c $(CXXFLAGS) $(SRC)/BuscaMinas.cpp -o $(OBJ)/BuscaMinas.o

$(BIN)/buscaminas : $(OBJ)/BuscaMinas.o 
	$(CXX) -o $(BIN)/buscaminas $(OBJ)/BuscaMinas.o 

# ************ Modo de depuracion ************
debug: 
	$(CXX) -ggdb $(SRC)/BuscaMinas.cpp -o $(BIN)/buscaminas
	gdb $(BIN)/buscaminas
 
# ************ Limpieza ************
clean:
	echo "Limpiando..."
	-rm ./$(OBJ)/*.o ./$(BIN)/*

mrproper: clean
	-rm ./$(BIN)/* ./doc/html/*

# ************ Documentacion *************
documentation:
	doxygen doc/doxys/Doxyfile

# Abre la documentacion con goole chrome
seedocumentation:
	google-chrome doc/html/index.html
