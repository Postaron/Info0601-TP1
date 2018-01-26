#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include "ncurses.h"

#define LARGEUR 20 /* Largeur de la fenêtre */
#define HAUTEUR 10 /* Hauteur de la fenêtre */
#define POSX 20	/* Position horizontale de la fenêtre */
#define POSY 5	 /* Position verticale de la fenêtre */

int main(void)
{
	int ch;

	/* Initialisation de ncurses */
	ncurses_initialiser();
	ncurses_couleurs();
	printw("Pressez F2 pour quitter le programme. Utilisez les flèches pour déplacer le curseur.\n");
	printw("Bonjour");
	refresh();

	/* Routine principale */
	while ((ch = getch()) != KEY_F(2))
	{
		ch = getch();
		switch (ch)
		{
		case '1':
			attron(COLOR_PAIR(1));
			break;

		case '2':
			attron(COLOR_PAIR(2));
			break;

		case '3':
			attron(COLOR_PAIR(3));
			break;
		}
		refresh();
	}
	ncurses_stopper();
	return EXIT_SUCCESS;
}
