# ProyectoC
Universidad de Costa Rica

Escuela de Ingeniería Eléctrica

Curso IE-0117 Programación Bajo Plataformas Abiertas

III-2021

Estudiante 1: Kevin Chen Wu

Carné: B92215

Estudiante 2: Jorge Luis Sancho Chaverri

Carné: B77150

Estudiante 3: Javier Elías Saca López

Carné: B66418
 
Este es el repositorio del proyecto de C para el curso

La interfaz fue diseñada para mostrarse en ventana pequeña, si lo agranda la letra se ve diminuta.

Para poder compilar es necesario tener pkg-config ya que se utiliza en dicho proceso para llamar bibliotecas instaladas.

El compilador usado es el GCC:
[How To Install GCC Compiler On Ubuntu?](https://linuxtect.com/how-to-install-gcc-compiler-on-ubuntu/)

Página de ayuda para instalar pkg-config:
[Cómo instalar pkg-config en Ubuntu](https://howtoinstall.co/es/pkg-config)

Otro que debe tener es el GTK3 instalado:
[Setup C/GTK+ Programming Tools On Ubuntu For Beginners](https://www.ubuntubuzz.com/2018/11/setup-cgtk-programming-tools-on-ubuntu-for-beginners.html)

Se recomienda también tener Glade instalado:
[Cómo instalar glade en Ubuntu](https://howtoinstall.co/es/glade)

Para utilizar el makefile se debe tener make instalado:
[Cómo instalar make en Ubuntu](https://howtoinstall.co/es/make)

Se puede instalar el GCC y make con solo instalar build-essential:
[How to Install GCC (build-essential) on Ubuntu 20.04](https://linuxize.com/post/how-to-install-gcc-on-ubuntu-20-04/)

El makefile tiene los siguientes objetivos:

- all: compila el código fuente y se ejecuta el ejecutable generado denominado **gato**.
- compilar: solo compila el código fuente y genera el ejecutable en el directorio actual.
- ejecutar: solo ejecuta el ejecutable denominado **gato**.
- limpiar: sirve para eliminar el ejecutable **gato**.

Ya que se está trabajando con GTK3 y Glade, al GCC se le debe pasar la opción ***`pkg-config --cflags --libs gtk+-3.0`***
para que GCC busque los encabezados (archivos.h) necesarios de la biblioteca GTK3 y construya el ejecutable basado en dicha biblioteca.
