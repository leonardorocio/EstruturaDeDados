// Constantes de erro
#define ERRO_LISTA_VAZIA	-1
#define ERRO_POS_INVALIDA	-2

// Elemento de lista
typedef struct eleDuplo {
	void *info;
	struct eleDuplo *suc, *ant;
} EleDuplo;

// Cabeçalho de lista
typedef struct {
	EleDuplo *cabeca;
	int tamInfo, qtd;
} LDE;

// Lista Simplesmente Encadeada
void inicializa_lista( LDE *p, int t );
int lista_vazia ( LDE l );
int insere_inicio( LDE *p, void *info );
int remove_inicio( LDE *p, void *info );
int insere_fim( LDE *p, void *info );
int remove_fim( LDE *p, void *info );
int insere_pos( LDE *p, void *info , int pos );
int remove_pos( LDE *p, void *info , int pos );
int le_valor( LDE l, void *info , int pos );
int modifica_valor( LDE l, void *info , int pos );
int insere_ordem( LDE *p, void *info , int (*compara)(void*, void*) );
void mostra_lista( LDE l, void (*mostra)(void *) );
void mostra_lista_invertida(LDE l, void (*mostra)(void*));
void limpa_lista( LDE *l );

int conta_elementos( LDE l ); // Função inútil na prática, pois temos o campo 'qtd'.

