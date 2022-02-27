all:
	gcc -o gato juego_codigo.c `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
	./gato
compilar:
	gcc -o gato juego_codigo.c `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

ejecutar:
	./gato

limpiar:
	rm gato

