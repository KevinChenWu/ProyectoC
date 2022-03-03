#include <stdio.h>
#include <gtk/gtk.h>


// Variables globales.
GtkBuilder *builder;
GtkWidget *menu_window;
GtkWidget *juego_window;



GtkWidget *boton_jugar;
GtkWidget *boton_salir;

GtkWidget *boton_00;
GtkWidget *boton_01;
GtkWidget *boton_02;
GtkWidget *boton_10;
GtkWidget *boton_11;
GtkWidget *boton_12;
GtkWidget *boton_20;
GtkWidget *boton_21;
GtkWidget *boton_22;

GtkWidget *boton_jugar_nuevo;
GtkWidget *boton_volver;

GtkWidget *texto_turno;


/* Se ve los botones ya presionados.
El orden es 00, 01, 02, 10, 11, 12, 20, 21, 22. */
static int presionado[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

// Matriz con las posiciones de X y O.
static char *matriz[3][3];

// Ve a cual jugador le toca jugar.
static int turno = 0;

// Indica cuando hay ganador
static int hay_ganador = 0;

// Indica el ganador
static int ganador;

// Indica cuando hay empate
static int es_empate = 0;

// Cuenta la cantidad de turnos
static int contador = 0;

// Función que analiza si alguien gana o no después de tocar los botones del gato
int analiza_ganador(){
	contador++;
	if(turno == 0 && matriz[0][0] != NULL && matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]
	|| turno == 0 && matriz[1][0] != NULL && matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2]
	|| turno == 0 && matriz[2][0] != NULL && matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2]

	|| turno == 0 && matriz[0][0] != NULL && matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]
	|| turno == 0 && matriz[0][1] != NULL && matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1]
	|| turno == 0 && matriz[0][2] != NULL && matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2]

	|| turno == 0 && matriz[0][0] != NULL && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]
	|| turno == 0 && matriz[0][2] != NULL && matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]){
		ganador = 1;
		hay_ganador = 1;
		es_empate = 0;
		gtk_label_set_text(GTK_LABEL(texto_turno), (const gchar*) "Ganó el jugador 1");

	}

	else if(
	turno == 1 && matriz[0][0] != NULL && matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]
	|| turno == 1 && matriz[1][0] != NULL && matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2]
	|| turno == 1 && matriz[2][0] != NULL && matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2]

	|| turno == 1 && matriz[0][0] != NULL && matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]
	|| turno == 1 && matriz[0][1] != NULL && matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1]
	|| turno == 1 && matriz[0][2] != NULL && matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2]

	|| turno == 1 && matriz[0][0] != NULL && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]
	|| turno == 1 && matriz[0][2] != NULL && matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]){
		ganador = 0;
		hay_ganador = 1;
		es_empate = 0;
		gtk_label_set_text(GTK_LABEL(texto_turno), (const gchar*) "Ganó el jugador 0");
	}
	else if (contador == 9) {
		gtk_label_set_text(GTK_LABEL(texto_turno), (const gchar*) "Empate");
		es_empate = 1;
	}
	return 0;
}

// Botones dentro del menú.
void botonJugar(GtkButton *b) {
	gtk_widget_show(juego_window);
	gtk_widget_hide(menu_window);
}

// Cierra la ventana
void botonSalir(GtkButton *b) {
	gtk_widget_destroy(menu_window);
}

// Se coloca X u O al apretar uno de los botones del gato.
void accion_boton(int fila, int columna, GtkButton *b) {
	if (presionado[fila][columna] == 0 && hay_ganador == 0 && es_empate == 0) {
		if (turno == 0) {
			gtk_label_set_text(GTK_LABEL(texto_turno), (const gchar*) "Turno: jugador 1");
			matriz[fila][columna] = "O";
			gtk_button_set_label(GTK_BUTTON(b), (const gchar*) "O");
			turno = 1;
			analiza_ganador();
		}
		else if (turno == 1) {
			gtk_label_set_text(GTK_LABEL(texto_turno), (const gchar*) "Turno: jugador 0");
			matriz[fila][columna] = "X";
			gtk_button_set_label(GTK_BUTTON(b), (const gchar*) "X");
			turno = 0;
			analiza_ganador();
		}
		presionado[fila][columna] = 1;
	}
}


// Identifica cuando se apreta un boton dentro del juego gato.
void boton00(GtkButton *b) {
	accion_boton(0, 0, b);
}

void boton01(GtkButton *b) {
	accion_boton(0, 1, b);
}

void boton02(GtkButton *b) {
	accion_boton(0, 2, b);
}

void boton10(GtkButton *b) {
	accion_boton(1, 0, b);
}

void boton11(GtkButton *b) {
	accion_boton(1, 1, b);
}

void boton12(GtkButton *b) {
	accion_boton(1, 2, b);
}

void boton20(GtkButton *b) {
	accion_boton(2, 0, b);
}

void boton21(GtkButton *b) {
	accion_boton(2, 1, b);
}

void boton22(GtkButton *b) {
	accion_boton(2, 2, b);
}

// Se hace reset a todo lo ocurrido durante el juego.
void resetJuego(){
	int i;
	int j;
	turno = 0;
	gtk_button_set_label(GTK_BUTTON(boton_00), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_01), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_02), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_10), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_11), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_12), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_20), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_21), (const gchar*) "");
	gtk_button_set_label(GTK_BUTTON(boton_22), (const gchar*) "");
	gtk_label_set_text(GTK_LABEL(texto_turno), (const gchar*) "Turno: jugador 0");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			presionado[i][j] = 0;
			matriz[i][j] = NULL;
		}
	}
	hay_ganador = 0;
	ganador = 2;
	es_empate = 0;
	contador = 0;
}

// Se apreta el botón volver a jugar.
void botonJugarNuevo(GtkButton *b){
	resetJuego();
}

// Se apreta el botón volver al menú.
void botonVolver(GtkButton *b) {
	gtk_widget_show(menu_window);
	gtk_widget_hide(juego_window);
	resetJuego();
}

// main
int main(int argc, char* argv[]){

  gtk_init(&argc, &argv);

  builder = gtk_builder_new_from_file(
    "juego_interfaz.glade"
  );

  menu_window = GTK_WIDGET(
    gtk_builder_get_object(builder, "menu_window")
  );

	juego_window = GTK_WIDGET(
    gtk_builder_get_object(builder, "juego_window")
  );


  g_signal_connect(menu_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	g_signal_connect(juego_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);



	// Para utilizar todas las señales.
	gtk_builder_connect_signals(builder, NULL);

	boton_jugar = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_jugar")
  );

	boton_salir = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_salir")
  );

	boton_00 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_00")
  );

	boton_01 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_01")
  );

	boton_02 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_02")
  );

	boton_10 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_10")
  );

	boton_11 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_11")
  );

	boton_12 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_12")
  );

	boton_20 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_20")
  );

	boton_21 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_21")
  );

	boton_22 = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_22")
  );

	boton_jugar_nuevo = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_jugar_nuevo")
  );

	boton_volver = GTK_WIDGET(
    gtk_builder_get_object(builder, "boton_volver")
  );


	texto_turno = GTK_WIDGET(
    gtk_builder_get_object(builder, "texto_turno")
  );

  gtk_widget_show_all(menu_window);

  gtk_main();

  return 0;
}
