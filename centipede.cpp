#include <allegro.h>
#include "nave.h"
#include "disparos.h"
#include "diseno.h"
//#include "spider.h"

//PANTALLA
#define ANCHO 680
#define ALTO 748

BITMAP cero;     BITMAP uno;     BITMAP dos;     BITMAP tres;     BITMAP cuatro;
BITMAP cinco;     BITMAP seis;     BITMAP siete;     BITMAP ocho;     BITMAP nueve;


void init();
void deinit();
void load_enemy(class nave E[]){
int indice=-1;
for(int i=0;i<5;i++)
    for(int j=0;j<11;j++){
        indice++;
        E[indice].inicia("level_1/hongo-especial1.bmp","",32,32,0,0,32,32,120+j*76,90+i*90);
    }
}

void pintar_enemy(class nave E[], BITMAP* buffer){
int indice=-1;
for(int i=0;i<5;i++)
    for(int j=0;j<11;j++){
        indice++;
        E[indice].pinta_nave(buffer);
    }

}

int main(){
	init();
	//IMAGENES
	BITMAP *buffer = create_bitmap(ANCHO,ALTO); //PANTALLA NEGRA
    BITMAP *portada = load_bitmap("Recursos/portada.bmp", NULL);
    BITMAP *fondo = load_bitmap("Recursos/fondo.bmp", NULL);

    PORTADA(portada);

    nave n("level_1/nave-1.bmp","level_1/disparo.bmp", 28, 32, 6, 20,30,20,ANCHO/2,ALTO-90);

    //nave e("level_1/hongo-especial1.bmp","",32,32,0,0,32,32,80,160);
    Balas disparos[n.max_disp]; //LISTA DE DISPAROS
    nave E[60];
    load_enemy(E);
	while(!key[KEY_ESC]) {

          clear_to_color(buffer,0x000000); //COLOR

          n.pinta_nave(buffer);
          n.movimiento();

          n.dispara(disparos, buffer);
            //e.pinta_nave(buffer);
	      pintar_enemy(E,buffer);
	      imprimir_fondo(fondo, buffer);

	      blit(buffer,screen, 0, 0, 0, 0, ANCHO, ALTO); //PANTALLA NEGRA
	      rest(20);
	}

	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO, ALTO, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
