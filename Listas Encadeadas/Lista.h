// Constantes de erro
#define ERRO_LISTA_VAZIA	-1

// Elemento de lista
typedef struct ele {
	void *info;
	struct ele *proximo;
} Elemento;

// Cabeçalho de lista
typedef struct {
	Elemento *cabeca;
	int tamInfo, qtd;
} Lista;

void inicializa_lista( Lista *p, int t );
int lista_vazia ( Lista l );
int insere_inicio( Lista *p, void *info );
int remove_inicio( Lista *p, void *info );
int remove_fim(Lista *l, void *info);
void mostra_lista( Lista l, void (*mostra)(void *) );
int inserir_fim(Lista *l, void *info);
void desaloca_lista( Lista *l);

