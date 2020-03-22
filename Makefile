TARGET=server client
SERVERDIR=Servidor
CLIENTDIR=Cliente

.PHONY: all
all: $(TARGET)

server:
	make -C $(SERVERDIR)

client:
	make -C $(CLIENTDIR)

.PHONY: clean
clean:
	make -C $(CLIENTDIR) clean
	make -C $(SERVERDIR) clean
