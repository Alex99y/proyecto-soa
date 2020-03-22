# Makefile del servidor
CXX = g++
TARGET = prog
OBJECTS = Funciones_Servidor.o Servidor.o
HEADERS_DIR_S = Headers/
DEPENDS = $(OBJECTS:.o=.d)
CXXFLAGS = -ansi -pedantic -Wall -std=c++11 -I $(HEADERS_DIR_S)
LDLIBS = -lnet -lpthread

.PHONY: all
all: CXXFLAGS += -O3 -DNDEBUG
all: $(TARGET)

.PHONY: debug
debug: CXXFLAGS += -g
debug: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS)

-include $(DEPENDS)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $*.cpp -o $*.o
	$(CXX) -MM $(CXXFLAGS) $*.cpp > $*.d

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJECTS) $(DEPENDS)

