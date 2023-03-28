#define MAX_PILHA 50
#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct {
	int topo;
	int dados[MAX_PILHA];
} Pilha;

void inicializa_pilha(Pilha *p);
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int empilha(Pilha *p, int valor);
int desempilha(Pilha *p, int *valor);
void mostra_pilha(Pilha p);

