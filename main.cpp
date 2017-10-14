#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include "cliente.h"
#include <pthread.h>
#include <gtk/gtk.h>

using namespace std;
static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World\n");
}
static void button_clicked(GtkWidget* widget,gpointer data){
    g_print("El botón fue presionado\n");
}

int main(int argc, char *argv[]) {


    gtk_init(&argc, &argv);

    GtkWidget* window;  //crea la variable window
    GtkWidget* button;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //crea la ventana toplevel
    button = gtk_button_new_with_label("click me");

    gtk_window_set_title(GTK_WINDOW(window),"Ventana");
    gtk_window_set_default_size(GTK_WINDOW(window),500,500);
    gtk_widget_set_size_request(button,50,50);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL); // cierra la ventana
    g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),NULL);
    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);  //hace que la ventana sea visible

    gtk_main();
    std::cout << "Hello, World!" << std::endl;

    Cliente* cliente = new Cliente(sockaddr_in());
    cliente->iniciar();
    return 0;

}

