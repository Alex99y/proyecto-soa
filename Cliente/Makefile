CXX = g++
TARGET = prog
OBJECTS = Cliente.o FuncionesCliente.o
HEADERS_DIR_C = Headers/
DEPENDS = $(OBJECTS:.o=.d)
CXXFLAGS = -ansi -pedantic -Wall -std=c++11 -I $(HEADERS_DIR_C)
LDLIBS = -lcurl

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

