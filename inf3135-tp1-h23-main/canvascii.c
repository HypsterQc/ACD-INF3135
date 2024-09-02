#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 40
#define MAX_WIDTH 80
#define USAGE "\
Usage: %s [-n HEIGHT,WIDTH] [-s] [-k] [-p CHAR]\n\
          [-h ROW] [-v COL] [-r ROW,COL,HEIGHT,WIDTH]\n\
          [-l ROW1,COL1,ROW2,COL2] [-c ROW,COL,RADIUS]\n\
Draws on an ASCII canvas. The canvas is provided on stdin and\n\
the result is printed on stdout. The dimensions of the canvas\n\
are limited to at most 40 rows and at most 80 columns.\n\
\n\
If no argument is provided, the program prints this help and exit.\n\
\n\
Canvas options:\n\
  -n HEIGHT,WIDTH           Creates a new empty canvas of HEIGHT rows and\n\
                            WIDTH columns. Should be used as first option,\n\
                            otherwise, the behavior is undefined.\n\
                            Ignores stdin.\n\
  -s                        Shows the canvas and exit.\n\
  -k                        Enables colored output. Replaces characters\n\
                            between 0 and 9 by their corresponding ANSI\n\
                            colors:\n\
                              0: black  1: red      2: green  3: yellow\n\
                              4: blue   5: magenta  6: cyan   7: white\n\
\n\
Drawing options:\n\
  -p CHAR                   Sets the pen to CHAR. Allowed pens are\n\
                            0, 1, 2, 3, 4, 5, 6 or 7. Default pen\n\
                            is 7.\n\
  -h ROW                    Draws an horizontal line on row ROW.\n\
  -v COL                    Draws a vertical line on column COL.\n\
  -r ROW,COL,HEIGHT,WIDTH   Draws a rectangle of dimension HEIGHTxWIDTH\n\
                            with top left corner at (ROW,COL).\n\
  -l ROW1,COL1,ROW2,COL2    Draws a discrete segment from (ROW1,COL1) to\n\
                            (ROW2,COL2) with Bresenham's algorithm.\n\
  -c ROW,COL,RADIUS         Draws a circle centered at (ROW,COL) of\n\
                            radius RADIUS with the midpoint algorithm.\n\
"


struct canvas {
    char pixels[MAX_HEIGHT][MAX_WIDTH]; // A matrix of pixels
    unsigned int width;                 // Its width
    unsigned int height;                // Its height
    char pen;                           // The character we are drawing with
};

enum error {
    OK = 0, // Everything is ok
    ERR_WRONG_PIXEL = 1, // Wrong pixel value in canvas
    ERR_CANVAS_TOO_HIGH = 2, // Canvas is too high
    ERR_CANVAS_TOO_WIDE = 3, // Canvas is too wide
    ERR_CANVAS_NON_RECTANGULAR = 4, // Canvas is non rectangular
    ERR_UNRECOGNIZED_OPTION = 5, // Unrecognized option
    ERR_MISSING_VALUE = 6, // Option with missing value
    ERR_WITH_VALUE = 7  // Problem with value
};

void error_msg(const char *program_name, enum error numerror, char commande[2]) {
    switch (numerror) {
        case ERR_WRONG_PIXEL:
            printf( "Error: wrong pixel value %s\n", commande);
            printf(USAGE, program_name);
            break;
        case ERR_CANVAS_TOO_HIGH:
            printf( "Error: canvas is too high (max height: 40)\n");
            printf(USAGE, program_name);
            break;
        case ERR_CANVAS_TOO_WIDE:
            printf( "Error: canvas is too wide (max width: 80)\n");
            printf(USAGE, program_name);
            break;
        case ERR_CANVAS_NON_RECTANGULAR:
            printf( "Error: canvas should be rectangular\n");
            printf(USAGE, program_name);
            break;
        case ERR_UNRECOGNIZED_OPTION:
            printf( "Error: unrecognized option %s\n", commande);
            printf(USAGE, program_name);
            break;
        case ERR_MISSING_VALUE:
            printf( "Error: missing value with option %s\n", commande);
            printf(USAGE, program_name);
            break;
        case ERR_WITH_VALUE:
            printf( "Error: incorrect value with option %s\n", commande);
            printf(USAGE, program_name);
            break;
        default:
            printf( "Error: erreur inconnue %s\n", commande);
            printf(USAGE, program_name);
    }
    exit(numerror);
}

int verif_borne_couleur(char c) {
    int verif = 1;
    if (c < '0' || c > '7') {
        verif = 0;
    }
    return verif;
}

void scan_fichier(struct canvas *canvas, const char *program_name) {
    int c;
    int ligne = 0, colonne = 0;
    while ((c = fgetc(stdin)) != EOF) {
        if(c == '.' || c == '0'|| c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6'|| c == '7'){
            canvas->pixels[ligne][colonne] = (char)c;
            colonne++;
        }else if(c == '\n'){
            ligne++;
            canvas->width = colonne;
            colonne = 0;
        } else {
            error_msg(program_name, ERR_WRONG_PIXEL, "-n");

        }
    }
    canvas->height = ligne;
}

struct canvas cree_matrice_vide(struct canvas canvas) {
    canvas.pen = '.';
    //printf("%d,%d\n",canvas.width,canvas.height);
    for (unsigned int i = 0; i < canvas.height; i++) {
        for (unsigned int j = 0; j < canvas.width; j++) {
            canvas.pixels[i][j] = canvas.pen;
            //printf("%c", canvas.pixels[i][j]);
        }
        //printf("\n");
    }
    return canvas;
}


int verif_negatif(char c) {
    int verif = 1;
    if (c != '-') {
        verif = 0;
    }
    return verif;
}

int verif_nombre(char c) {
    int verif = 1;
    if (c < '0' || c > '9') {
        verif = 0;
    }
    return verif;
}

int verif_virgule(char c) {
    int verif = 1;
    if (c != ',') {
        verif = 0;
    }
    return verif;
}

int verif_option(char option[2]) {
    int verif = 0;
    if (strcmp(option, "-n") == 0) {
        verif = 1;
    }else if (strcmp(option, "-s") == 0) {
        verif = 1;
    }else if (strcmp(option, "-k") == 0) {
        verif = 1;
    }else if (strcmp(option, "-p") == 0) {
        verif = 1;
    }else if (strcmp(option, "-h") == 0) {
        verif = 1;
    }else if (strcmp(option, "-v") == 0) {
        verif = 1;
    }else if (strcmp(option, "-r") == 0) {
        verif = 1;
    }else if (strcmp(option, "-l") == 0) {
        verif = 1;
    }else if (strcmp(option, "-c") == 0) {
        verif = 1;
    }

    return verif;
}

void imprime_matrice(struct canvas canvas) {
    for (unsigned int i = 0; i < canvas.height; i++) {
        for (unsigned int j = 0; j < canvas.width; j++) {
            printf("%c", canvas.pixels[i][j]);
        }
        printf("\n");
    }
}

//2e colonne non indiquer
struct canvas change_ligne(struct canvas canvas, int mod_ligne, int debut_colonne, int fin_colonne) {
    //printf("%d, %d\n", debut_colonne, fin_colonne);
    if (debut_colonne < 0) {
        fin_colonne = debut_colonne + fin_colonne;
        mod_ligne = debut_colonne + fin_colonne;

        for (int i = debut_colonne; i < fin_colonne; i++) {
            if (mod_ligne >= 0 && i >= 0) {
                canvas.pixels[mod_ligne][i] = canvas.pen;
                //printf("%c",canvas.pixels[mod_ligne][i]);
            }
        }
    } else {
        for (int i = debut_colonne; i <= fin_colonne; i++) {
            if (mod_ligne >= 0 && i >= 0) {
                canvas.pixels[mod_ligne][i] = canvas.pen;
                //printf("%c",canvas.pixels[mod_ligne][i]);
            }
        }
    }
    //printf("%d, %d\n", debut_colonne, fin_colonne);
    //printf("%d\n", mod_ligne);

    return canvas;
}

struct canvas change_colonne(struct canvas canvas, int mod_colonne, int debut_ligne, int fin_ligne) {
    if (debut_ligne < 0) {
        fin_ligne = debut_ligne + fin_ligne;
        mod_colonne = debut_ligne + fin_ligne;

        for (int i = debut_ligne; i < fin_ligne; i++) {
            if (mod_colonne >= 0 && i >= 0) {
                canvas.pixels[i][mod_colonne] = canvas.pen;
                //printf("%c",canvas.pixels[i][mod_colonne]);
            }
        }
    } else {
        for (int i = debut_ligne; i <= fin_ligne; i++) {
            if (mod_colonne >= 0 && i >= 0) {
                canvas.pixels[i][mod_colonne] = canvas.pen;
                //printf("%c",canvas.pixels[i][mod_colonne]);
            }
        }
    }
    return canvas;
}

struct canvas genere_rectangle(struct canvas canvas, int ligneY1, int colonneX1, int ligneY2, int colonneX2) {

    canvas = change_ligne(canvas, ligneY1, colonneX1, colonneX2);
    //printf("test ligneY1: %d, %d, %d, %d, %c \n",ligneY1, colonneX1, ligneY2, colonneX2, canvas.pen);

    canvas = change_colonne(canvas, colonneX1, ligneY1, ligneY2);
    //printf("test colonneX1: %d, %d, %d, %d, %c \n",ligneY1, colonneX1, ligneY2, colonneX2, canvas.pen);

    canvas = change_ligne(canvas, ligneY2, colonneX1, colonneX2);
    //printf("test ligneY2: %d, %d, %d, %d, %c \n",ligneY1, colonneX1, ligneY2, colonneX2, canvas.pen);

    canvas = change_colonne(canvas, colonneX2, ligneY1, ligneY2);
    //printf("test colonneX2: %d, %d, %d, %d, %c \n",ligneY1, colonneX1, ligneY2, colonneX2, canvas.pen);

    return canvas;
}


struct canvas option_L(struct canvas canvas, int x0, int y0, int x1, int y1) {

    int deplacementX = abs(x1 - x0);
    int sensX = x0 < x1 ? 1 : -1;
    int deplacementY = -abs(y1 - y0);
    int sensY = y0 < y1 ? 1 : -1;
    int error = deplacementX + deplacementY;
    int e2;

    while (1) {
        if (x0 >= 0 && y0 >= 0) {
            canvas.pixels[x0][y0] = canvas.pen;
        }
        if (x0 == x1 && y0 == y1) { break; }
        e2 = 2 * error;
        if (e2 >= deplacementY) {
            if (x0 == x1) { break; }
            error = error + deplacementY;
            x0 = x0 + sensX;
        }
        if (e2 <= deplacementX) {
            if (y0 == y1) { break; }
            error = error + deplacementX;
            y0 = y0 + sensY;
        }
    }
    return canvas;
}

struct canvas option_C(struct canvas canvas, int x0, int y0, int radius) {

    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;
    if (x0 >= 0 && y0 + radius >= 0) {
        canvas.pixels[x0][y0 + radius] = canvas.pen;
    }
    if (x0 >= 0 && y0 - radius >= 0) {
        canvas.pixels[x0][y0 - radius] = canvas.pen;
    }
    if (x0 + radius >= 0 && y0 >= 0) {
        canvas.pixels[x0 + radius][y0] = canvas.pen;
    }
    if (x0 - radius >= 0 && y0 >= 0) {
        canvas.pixels[x0 - radius][y0] = canvas.pen;
    }
    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x + 1;
        if (x0 + x >= 0 && y0 + y >= 0) {
            canvas.pixels[x0 + x][y0 + y] = canvas.pen;
        }
        if (x0 - x >= 0 && y0 + y >= 0) {
            canvas.pixels[x0 - x][y0 + y] = canvas.pen;
        }
        if (x0 + x >= 0 && y0 - y >= 0) {
            canvas.pixels[x0 + x][y0 - y] = canvas.pen;
        }
        if (x0 - x >= 0 && y0 - y >= 0) {
            canvas.pixels[x0 - x][y0 - y] = canvas.pen;
        }
        if (x0 + y >= 0 && y0 + x >= 0) {
            canvas.pixels[x0 + y][y0 + x] = canvas.pen;
        }
        if (x0 - y >= 0 && y0 + x >= 0) {
            canvas.pixels[x0 - y][y0 + x] = canvas.pen;
        }
        if (x0 + y >= 0 && y0 - x >= 0) {
            canvas.pixels[x0 + y][y0 - x] = canvas.pen;
        }
        if (x0 - y >= 0 && y0 - x >= 0) {
            canvas.pixels[x0 - y][y0 - x] = canvas.pen;
        }
    }
    return canvas;
}

int main(int argc, char *argv[]) {
    struct canvas canvas;
    canvas.pen = '7';
    char originePen;
    //canvas pen ligne colonne
    int ligne = -1, colonne = -1, ligneY1 = 0, colonneX1 = 0, ligneY2 = 0, colonneX2 = 0, mod_ligne = 0, mod_colonne = 0, x0 = 0, y0 = 0, x1 = 0, y1 = 0, rayon = 0;
    int cmpt_num = 0;
    int cmpt_virgule = 0;
    int cmpt_neg = 0;

    if (!isatty(STDIN_FILENO)) {
        scan_fichier(&canvas, argv[0]);
        ligne = canvas.width;
        colonne = canvas.height;
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-n") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (verif_negatif(c)) {
                        error_msg(argv[0], ERR_WITH_VALUE, "-n");
                    }else if(!verif_nombre(c)){
                        if(!verif_virgule(c)){
                            error_msg(argv[0], ERR_WITH_VALUE, "-n");
                        }else{
                            cmpt_virgule++;
                        }
                    }else if(cmpt_virgule > 1){
                        error_msg(argv[0], ERR_WITH_VALUE, "-n");
                    }
                }
                if(sscanf(argv[i], "%d, %d", &canvas.height, &canvas.width) != 2){
                    error_msg(argv[0], ERR_MISSING_VALUE, "-n");
                }else{
                    if (canvas.height > MAX_HEIGHT){
                        error_msg(argv[0], ERR_CANVAS_TOO_HIGH,"-n");
                    }else if (canvas.width > MAX_WIDTH){
                        error_msg(argv[0], ERR_CANVAS_TOO_WIDE, "-n");
                    }else{
                        ligne = canvas.width;
                        colonne = canvas.height;
                        originePen = canvas.pen;
                        canvas = cree_matrice_vide(canvas);
                        canvas.pen = originePen;
                    }
                }

            } else if (strcmp(argv[i], "-s") == 0) {
                imprime_matrice(canvas);
                exit(OK);

            } else if (strcmp(argv[i], "-h") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (verif_negatif(c)) {
                        error_msg(argv[0], ERR_WITH_VALUE, "-h");
                    }else if(!verif_nombre(c)){
                        if(!verif_virgule(c)){
                            error_msg(argv[0], ERR_WITH_VALUE, "-h");
                        }else{
                            cmpt_virgule++;
                        }
                    }else if(cmpt_virgule > 1){
                        error_msg(argv[0], ERR_WITH_VALUE, "-h");
                    }
                }
                if (cmpt_neg > 1) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-h");
                } else {
                    cmpt_neg = 0;
                }

                sscanf(argv[i], "%d", &mod_ligne);
                //faire une boucle qui trace une ligne de la grosseur du pen
                //printf("option -h: %d\n", mod_ligne);
                canvas = change_ligne(canvas, mod_ligne, 0, ligne);
            } else if (strcmp(argv[i], "-v") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (!verif_nombre(c)) {
                        if (!verif_negatif(c)) {
                            error_msg(argv[0], ERR_WITH_VALUE, "-v");
                        } else {
                            cmpt_neg++;
                        }
                    }
                }
                if (cmpt_neg > 1) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-v");
                } else {
                    cmpt_neg = 0;
                }

                sscanf(argv[i], "%d", &mod_colonne);
                //faire une boucle qui trace une colonne de la grosseur du pen
                //printf("option -v: \n");
                canvas = change_colonne(canvas, mod_colonne, 0, colonne);
            } else if (strcmp(argv[i], "-r") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (verif_negatif(c)) {
                        if (j != 0) {
                            j--;
                            c = argv[i][j];
                            if (!verif_virgule(c)) {
                                exit(7);
                            } else {
                                j = j + 2;
                                c = argv[i][j];
                                if (!verif_nombre(c)) {
                                    exit(7);
                                } else {
                                    cmpt_num++;
                                }
                            }
                        } else {
                            j++;
                            c = argv[i][j];
                            if (verif_nombre(c)) {
                                cmpt_num++;
                                j++;
                                c = argv[i][j];
                                if (verif_virgule(c)) {
                                    cmpt_virgule++;
                                } else if (!verif_nombre(c)) {
                                    exit(7);
                                } else {
                                    cmpt_num++;
                                }
                            }
                        }
                    } else if (verif_nombre(c)) {
                        cmpt_num++;
                        j++;
                        c = argv[i][j];
                        if (verif_virgule(c)) {
                            cmpt_virgule++;
                        } else if (!verif_nombre(c)) {
                            error_msg(argv[0], ERR_WITH_VALUE, "-r");
                        }
                    } else {
                        error_msg(argv[0], ERR_WITH_VALUE, "-r");
                    }
                }
                if (cmpt_num < 4) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-r");
                }
                if (cmpt_virgule != 3) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-r");
                } else {
                    cmpt_neg = 0;
                    cmpt_virgule = 0;
                    cmpt_num = 0;
                }

                sscanf(argv[i], "%d,%d,%d,%d", &ligneY1, &colonneX1, &ligneY2, &colonneX2);
                //faire une boucle qui vas trancfere linformation au methode -h et -v affin de genere un rectangle
                //printf("option -r: \n");
                canvas = genere_rectangle(canvas, ligneY1, colonneX1, ligneY2, colonneX2);
            } else if (strcmp(argv[i], "-l") == 0) {
                i++;

                sscanf(argv[i], "%d,%d,%d,%d", &x0, &y0, &x1, &y1);
                //faire une boucle qui trace un segment, ligne vertical, voir site
                canvas = option_L(canvas, x0, y0, x1, y1);
                //printf("option -l: \n");
            } else if (strcmp(argv[i], "-c") == 0) {
                i++;

                sscanf(argv[i], "%d,%d,%d", &x0, &y0, &rayon);
                //faire une boucle qui trace un cercle, voir site
                canvas = option_C(canvas, x0, y0, rayon);
                //printf("option -c: \n");
            } else if (strcmp(argv[i], "-p") == 0) {
                i++;
                if(verif_option(argv[i])){
                    canvas.pen = 7;
                }else if(verif_borne_couleur(canvas.pen)){
                    canvas.pen = sscanf(argv[i], "%c", &canvas.pen);
                }else{
                    exit(7);
                }

                //si -p sans argv alors retourne default 7
                //modifier la grosseur du pen, default 7.
                //printf("option -p: %c\n", canvas.pen);
            } else if (strcmp(argv[i], "-k") == 0) {
                for (unsigned int h = 0; h < canvas.height; h++) {
                    for (unsigned int w = 0; w < canvas.width; w++) {
                        if (canvas.pixels[h][w] == 0) {
                            printf("\033[40m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 1) {
                            printf("\033[41m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 2) {
                            printf("\033[42m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 3) {
                            printf("\033[43m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 4) {
                            printf("\033[44m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 5) {
                            printf("\033[45m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 6) {
                            printf("\033[46m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 7) {
                            printf("\033[47m %d \033[0m", canvas.pixels[h][w]);
                        }
                    }
                    printf("\n");
                }
            } else {
                exit(5);
            }
        }
        imprime_matrice(canvas);
        exit(OK);
    } else if (argc == 1) {
        printf(USAGE, argv[0]);
    } else if (strcmp(argv[1], "-n") == 0) {

        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-n") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (verif_negatif(c)) {
                        error_msg(argv[0], ERR_WITH_VALUE, "-n");
                    }else if(!verif_nombre(c)){
                        if(!verif_virgule(c)){
                            error_msg(argv[0], ERR_WITH_VALUE, "-n");
                        }else{
                            cmpt_virgule++;
                        }
                    }else if(cmpt_virgule > 1){
                        error_msg(argv[0], ERR_WITH_VALUE, "-n");
                    }
                }
                if(sscanf(argv[i], "%d, %d", &canvas.height, &canvas.width) != 2){
                    error_msg(argv[0], ERR_MISSING_VALUE, "-n");
                }else{
                    if (canvas.height > MAX_HEIGHT){
                        error_msg(argv[0], ERR_CANVAS_TOO_HIGH,"-n");
                    }else if (canvas.width > MAX_WIDTH){
                        error_msg(argv[0], ERR_CANVAS_TOO_WIDE, "-n");
                    }else{
                        ligne = canvas.width;
                        colonne = canvas.height;
                        originePen = canvas.pen;
                        canvas = cree_matrice_vide(canvas);
                        canvas.pen = originePen;
                    }
                }

            } else if (strcmp(argv[i], "-s") == 0) {
                imprime_matrice(canvas);
                exit(OK);

            } else if (strcmp(argv[i], "-h") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (verif_negatif(c)) {
                        error_msg(argv[0], ERR_WITH_VALUE, "-h");
                    }else if(!verif_nombre(c)){
                        if(!verif_virgule(c)){
                            error_msg(argv[0], ERR_WITH_VALUE, "-h");
                        }else{
                            cmpt_virgule++;
                        }
                    }else if(cmpt_virgule > 1){
                        error_msg(argv[0], ERR_WITH_VALUE, "-h");
                    }
                }
                if (cmpt_neg > 1) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-h");
                } else {
                    cmpt_neg = 0;
                }

                sscanf(argv[i], "%d", &mod_ligne);
                //faire une boucle qui trace une ligne de la grosseur du pen
                //printf("option -h: %d\n", mod_ligne);
                canvas = change_ligne(canvas, mod_ligne, 0, ligne);
            } else if (strcmp(argv[i], "-v") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (!verif_nombre(c)) {
                        if (!verif_negatif(c)) {
                            error_msg(argv[0], ERR_WITH_VALUE, "-v");
                        } else {
                            cmpt_neg++;
                        }
                    }
                }
                if (cmpt_neg > 1) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-v");
                } else {
                    cmpt_neg = 0;
                }

                sscanf(argv[i], "%d", &mod_colonne);
                //faire une boucle qui trace une colonne de la grosseur du pen
                //printf("option -v: \n");
                canvas = change_colonne(canvas, mod_colonne, 0, colonne);
            } else if (strcmp(argv[i], "-r") == 0) {
                i++;
                for (int j = 0; argv[i][j] != '\0'; j++) {
                    char c = argv[i][j];
                    if (verif_negatif(c)) {
                        if (j != 0) {
                            j--;
                            c = argv[i][j];
                            if (!verif_virgule(c)) {
                                exit(7);
                            } else {
                                j = j + 2;
                                c = argv[i][j];
                                if (!verif_nombre(c)) {
                                    exit(7);
                                } else {
                                    cmpt_num++;
                                }
                            }
                        } else {
                            j++;
                            c = argv[i][j];
                            if (verif_nombre(c)) {
                                cmpt_num++;
                                j++;
                                c = argv[i][j];
                                if (verif_virgule(c)) {
                                    cmpt_virgule++;
                                } else if (!verif_nombre(c)) {
                                    exit(7);
                                } else {
                                    cmpt_num++;
                                }
                            }
                        }
                    } else if (verif_nombre(c)) {
                        cmpt_num++;
                        j++;
                        c = argv[i][j];
                        if (verif_virgule(c)) {
                            cmpt_virgule++;
                        } else if (!verif_nombre(c)) {
                            error_msg(argv[0], ERR_WITH_VALUE, "-r");
                        }
                    } else {
                        error_msg(argv[0], ERR_WITH_VALUE, "-r");
                    }
                }
                if (cmpt_num < 4) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-r");
                }
                if (cmpt_virgule != 3) {
                    error_msg(argv[0], ERR_WITH_VALUE, "-r");
                } else {
                    cmpt_neg = 0;
                    cmpt_virgule = 0;
                    cmpt_num = 0;
                }

                sscanf(argv[i], "%d,%d,%d,%d", &ligneY1, &colonneX1, &ligneY2, &colonneX2);
                //faire une boucle qui vas trancfere linformation au methode -h et -v affin de genere un rectangle
                //printf("option -r: \n");
                canvas = genere_rectangle(canvas, ligneY1, colonneX1, ligneY2, colonneX2);
            } else if (strcmp(argv[i], "-l") == 0) {
                i++;

                sscanf(argv[i], "%d,%d,%d,%d", &x0, &y0, &x1, &y1);
                //faire une boucle qui trace un segment, ligne vertical, voir site
                canvas = option_L(canvas, x0, y0, x1, y1);
                //printf("option -l: \n");
            } else if (strcmp(argv[i], "-c") == 0) {
                i++;

                sscanf(argv[i], "%d,%d,%d", &x0, &y0, &rayon);
                //faire une boucle qui trace un cercle, voir site
                canvas = option_C(canvas, x0, y0, rayon);
                //printf("option -c: \n");
            } else if (strcmp(argv[i], "-p") == 0) {
                i++;
                if(verif_option(argv[i])){
                    canvas.pen = 7;
                }else if(verif_borne_couleur(canvas.pen)){
                    canvas.pen = sscanf(argv[i], "%c", &canvas.pen);
                }else{
                    exit(7);
                }

                //si -p sans argv alors retourne default 7
                //modifier la grosseur du pen, default 7.
                //printf("option -p: %c\n", canvas.pen);
            } else if (strcmp(argv[i], "-k") == 0) {
                for (unsigned int h = 0; h < canvas.height; h++) {
                    for (unsigned int w = 0; w < canvas.width; w++) {
                        if (canvas.pixels[h][w] == 0) {
                            printf("\033[40m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 1) {
                            printf("\033[41m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 2) {
                            printf("\033[42m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 3) {
                            printf("\033[43m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 4) {
                            printf("\033[44m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 5) {
                            printf("\033[45m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 6) {
                            printf("\033[46m %d \033[0m", canvas.pixels[h][w]);
                        } else if (canvas.pixels[h][w] == 7) {
                            printf("\033[47m %d \033[0m", canvas.pixels[h][w]);
                        }
                    }
                    printf("\n");
                }
            } else {
                exit(5);
            }
        }
        imprime_matrice(canvas);
        exit(OK);
    } else {
        error_msg(argv[0], ERR_WITH_VALUE, "-n or redirection not there");
    }


    return 0;
}