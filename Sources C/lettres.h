#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 1000
#define HELP "\033[1;34mDinyd-W\n_______________\n\033[0m\nUtilisation : dinyad-w [ text ]\nPar defaut, les mots s'affichent sur différentes lignes. Utilesez des tirets comme séparateurs au lieu des espaces pour le corriger.\nEx : \033[1;32mdinyad-w  Je-suis.\033[0m\n\n"


//Les tableaux représentant les lettres

char t_[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char  lt_A[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,1,1,0,0,1,1,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_B[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_C[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_D[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,1,0},
                {0,1,1,0,0,0,0,0,1,0},
                {0,1,1,0,0,0,0,0,1,0},
                {0,1,1,0,0,0,0,0,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };


char lt_E[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };
 
char lt_F[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_G[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,1,1,1,1,0},
                {0,1,1,0,0,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_H[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_I[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_J[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,1,1,1,1,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,1,1,0,0,1,1,0,0,0},
                {0,1,1,0,0,1,1,0,0,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,0,1,1,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_K[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,0,0,0,1,1,0},
                {0,1,1,1,0,0,1,1,1,0},
                {0,1,1,1,0,1,1,1,0,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,1,1,1,1,1,1,0,0,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,1,0,0,1,1,1,0},
                {0,1,1,1,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_L[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_M[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,0,0,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,1,1,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_N[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,0,0,0,1,1,0},
                {0,1,1,1,1,0,0,1,1,0},
                {0,1,1,0,1,1,0,1,1,0},
                {0,1,1,0,0,1,1,1,1,0},
                {0,1,1,0,0,0,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,0,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_O[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_P[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_Q[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,1},
                {0,0,0,0,0,0,0,1,1,1},
              };

char lt_R[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_S[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_T[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_U[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char lt_V[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,1,1,0,0,1,1,0,0},
                {0,0,1,1,0,0,1,1,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_W[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,1,1,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,1,1,0,0,1,1,0,0},
                {0,0,1,0,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_X[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,0,0,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,1,0,0,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_Y[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,0,0,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                };

char lt_Z[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,1,1,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };


char tbl_0[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };
char tbl_1[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,1,1,0,0,0,0,0,0},
                {0,1,0,0,0,0,0,0,0,0},
              };

char tbl_2[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,1,1,0,0,0,0,0,0},
                {0,1,0,0,0,0,0,0,0,0},
              };
char tbl_3[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char tbl_4[10][10]={{0,0,1,1,0,0,0,0,0,0},
                {0,0,1,1,0,0,0,0,0,0},
                {0,1,1,0,0,0,0,0,0,0},
                {1,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };
char tbl_5[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,1,1,1,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,1,1,0,0,0,1,1,0},
                {0,0,1,1,0,0,0,1,1,0},
                {0,0,0,1,0,0,1,1,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
              };
char tbl_6[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                };
char t_un[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,1,1,1,0,0,0},
                {0,0,0,1,1,1,1,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };
char t_deux[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,1,1,1,1,1,0,0},
                {0,0,1,1,0,0,0,1,1,0},
                {0,0,1,1,0,0,0,1,1,0},
                {0,0,0,0,0,0,1,1,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char t_trois[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,0,0,0,0,0,1,1,0},
                {0,0,0,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,1,1,0},
                {0,1,0,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char t_quatre[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,1,1,0,0},
                {0,0,0,0,0,1,1,1,0,0},
                {0,0,0,0,1,1,1,1,0,0},
                {0,0,0,1,1,0,1,1,0,0},
                {0,0,1,1,0,0,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char t_cinq[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };
char t_six[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };


char t_sept[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,1,1,0,0},
                {0,0,0,0,0,1,1,0,0,0},
                {0,0,0,0,1,1,0,0,0,0},
                {0,0,0,1,1,0,0,0,0,0},
                {0,0,1,1,0,0,0,0,0,0},
                {0,0,1,1,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char t_huit[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };
char t_neuf[10][10]={{0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0,0,1,0},
                {0,1,1,0,0,0,0,1,1,0},
                {0,0,1,1,1,1,1,1,1,0},
                {0,0,0,0,0,0,0,1,1,0},
                {0,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0},
              };

char t_zero[10][10]={{0,0,0,0,0,0,0,0,0,0},
                     {0,0,1,1,1,1,1,1,0,0},
                     {0,1,1,1,0,0,1,1,1,0},
                     {0,1,1,0,0,0,0,1,1,0},
                     {0,1,1,0,0,0,0,1,1,0},
                     {0,1,1,0,0,0,0,1,1,0},
                     {0,1,1,0,0,0,0,1,1,0},
                     {0,1,1,1,0,0,1,1,1,0},
                     {0,0,1,1,1,1,1,1,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                   };
                  
//Fonctions
/*void trans2(char t1[10][10], char t2[10][10]);
void getL(char tableau[10][10],char l);
void  writeC(char c);
void writeL(const char l[]);*/

