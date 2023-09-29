typedef char *string;

typedef struct Link{
  int linha;
  int igual;
  struct Link *prox;
} Link;

typedef struct Tab {
  string palavra; 
  Link *link; //linha, igualdade e prox
  struct Tab * esq;
  struct Tab * dir; 
} Tab;


//Inserir dados na tabela
Tab * inserir( Tab **tab, string palavra, int linha );

//Constroi uma lista encadeada para palavras repetidas 
Link * buidLink( Link *link, int linha );

void imprimir( Tab *raiz );


