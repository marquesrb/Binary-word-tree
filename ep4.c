#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"


string readLine( FILE *infile ) {
    string line;
    int n, ch;
    n = 0;
    line = malloc( 100+1 );
    while ( (ch = getc( infile) ) != '\n' && ch != EOF ) {
       if ( n >= 100 ) {
          free( line );
          exit( EXIT_FAILURE );
       }
       line[n++] = ch;
    }
    if ( n == 0 && ch == EOF ) {
      free( line );
      return NULL;
    }
    line[n] = '\0';
    return line;
}

int main( int argc, char *argv[] ){
  //Tabela
  Tab * tab = NULL;

  //Arquivo
  FILE *file;
  file = fopen(argv[1], "r");

  //Auxiliares
  int k = 0, j = 0;
  string aux;
  aux = malloc(80); 
  string palavras; 

  if( file == NULL ) exit( EXIT_FAILURE );

  while( ( palavras = readLine( file ) ) != NULL ){ 
    k++; 
    int i;

    for( i = 0; i <= strlen( palavras ) ; i++ ){ 
      int n = palavras[i];
      if( ( n >= 65 && n <= 90 ) || ( n >= 97 && n <= 122 ) ) aux[j++] = palavras[i]; 
      else{ 
        aux[j++] = '\0';
        if( strlen(aux) > 0) inserir( &tab, aux, k ); 
        j = 0;     
      }
    }

  }

  imprimir( tab );
  free( aux );
  free( tab );
  fclose( file );

}




