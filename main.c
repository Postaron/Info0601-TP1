#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include "ncurses.h"

#define HAUTEUR 10
#define LARGEUR 20

int main(void)
{
	/**
	 * Détermination position fenêtre de couleur : celle du milieu, le centre au-dessus du centre du terminal.
	 * Largeur fenêtre : 10, hauteur : 20.
	 * Écart entre fenêtre : 5.
	 */
	WINDOW *fenetre = NULL;
	int ch, err, sourisX, sourisY, bouton, posX, posY;
	const int centreWX = COLS / 2, centreWY = LINES / 2;
	char message[] = "Bonjour";
	/* Initialisation de ncurses */
	ncurses_initialiser();
	ncurses_souris();
	scrollok(stdscr, TRUE);
	ncurses_couleurs();
	printw("Pressez F2 pour quitter le programme. Utilisez les flèches pour déplacer le curseur.\n");
	posY = centreWY;
	posX = centreWX - ((int)strlen(message));
	move(posY, posX);
	refresh();
	printw(message);
	/* Routine principale */
	while ((ch = getch()) != KEY_F(2))
	{

		switch (ch)
		{
		case KEY_MOUSE:
			if (souris_getpos(&sourisX, &sourisY, &bouton) == OK)
			{
			}
			break;
		case '1':
			attroff(COLOR_PAIR(2));
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(1));
			break;
		case '2':
			attroff(COLOR_PAIR(1));
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
			break;
		case '3':
			attroff(COLOR_PAIR(2));
			attroff(COLOR_PAIR(1));
			attron(COLOR_PAIR(3));
			break;
		}
		err = move(1, 0);
		if (err == ERR)
		{
			fprintf(stderr, "Erreur, move curseur\n");
			ncurses_stopper();
			exit(EXIT_FAILURE);
		}
		refresh();
		printw(message);
	}
	ncurses_stopper();
	return EXIT_SUCCESS;
}
