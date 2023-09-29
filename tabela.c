#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Link * buidLink( Link *link, int linha ){ 
  if ( link == NULL ) {
    link = (Link*)malloc( sizeof( Link ) );
    link->linha = linha;
    link->igual = 1;
    link->prox = NULL;
  } 
  else {
    if( link->linha == linha ) {
      link->igual++;
      return link;
    }
    link->prox = buidLink( link->prox, linha ); 
    return link;
    }
}

Tab * inserir( Tab **tab, string palavra, int linha ){ 
  Tab *aux = *tab;
  while( aux ){
    if( strcmp(aux->palavra, palavra ) == 0 ) { 
      if( aux->link->linha == linha ) {
      aux->link->igual++; 
      return aux;
      }
      else{
        aux->link->prox = buidLink( aux->link->prox, linha ); 
        return aux;
      }
    }
    if( strcmp( aux->palavra, palavra ) > 0) tab = &aux->esq;
    else tab = &aux->dir;

    aux = *tab;
  }
  aux = malloc( sizeof(Tab) );
  aux->link = malloc( sizeof(Link) );
  aux->link->prox = NULL;
  aux->palavra =  malloc( strlen(palavra)+1 );
  strcpy( aux->palavra, palavra );
  aux->dir = NULL;
  aux->esq = NULL;
  aux->link->igual = 1;
  aux->link->linha = linha;
  *tab = aux;
}

void imprimir( Tab *raiz ){
    if ( raiz ){
        imprimir( raiz->esq );
        printf( "\n\n%s: ", raiz->palavra );
        
        if( raiz->link->igual == 1 ){
          printf( "%d ", raiz->link->linha );
        }
        else printf( "%d(%d) ", raiz->link->linha, raiz->link->igual );
    
        while( raiz->link->prox ){
          if( raiz->link->prox->igual == 1 ) printf( "%d ", raiz->link->prox->linha );
          else printf("%d(%d) ", raiz->link->prox->linha, raiz->link->prox->igual);
          raiz->link->prox  = raiz->link->prox->prox;
        }
        imprimir(raiz->dir);
    }
}