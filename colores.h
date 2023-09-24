#ifndef COLORES_H
# define COLORES_H

/*
	Para poder usar un color, basta con añadirlo a un printf
en un %s. Ejemplo:
		printf("%s", COLOR_BLUE);

	Es necesario cada vez que se quiera dejar de escribir un color
llamar a la macro COLOR_RESET:
		printf("%s%s, COLOR_BLUE, COLOR_RESET");
*/

/* COLOR_RESET*/
# define COLOR_RESET "\x1b[0m"

/**************/
/* TEXT COLRO */
/**************/
# define COLOR_BLACK	"\x1B[30m"
# define COLOR_RED		"\x1B[31m"
# define COLOR_GREEN	"\x1B[32m"
# define COLOR_YELLOW	"\x1B[33m"
# define COLOR_BLUE		"\x1B[34m"
# define COLOR_MAGENTA	"\x1B[35m"
# define COLOR_CYAN		"\x1B[36m"
# define COLOR_WHITE	"\x1B[37m"

/********************/
/* BACKGROUND COLOR */
/********************/
# define BCOLOR_BLACK		"\x1B[40m"
# define BCOLOR_RED			"\x1B[41m"
# define BCOLOR_GREEN		"\x1B[42m"
# define BCOLOR_YELLOW		"\x1B[43m"
# define BCOLOR_BLUE		"\x1B[44m"
# define BCOLOR_MAGENTA		"\x1B[45m"
# define BCOLOR_CYAN		"\x1B[46m"
# define BCOLOR_WHITE		"\x1B[47m"

/******************/
/* PERSONAL COLOR */
/******************/
/*
Para crear un numero, se sigue la siguiente estuctura:
   > Color de texto: "\x1B[38;2;R;G;Bm"
   > Color de fondo: "\x1B[48;2;R;G;Bm"
Basta con variar los valores R, G y B según el sistema RGB
	("https://htmlcolorcodes.com/es/")

*/
# define COLOR_LIGHTGREEN	"\x1B[38;2;17;245;120m"
# define COLOR_DIRTYGREEN	"\x1B[38;2;56;216;130m"
#endif