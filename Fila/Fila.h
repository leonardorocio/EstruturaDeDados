#define MAX_FILA 50
#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct {
	int dados[MAX_FILA];
	int ini;
	int n;
//	int capacidade;
} Fila;

void mostra_fila(Fila f);
int inserir(Fila *f, int v);
void remover(Fila *f, int *info);
void inicializa_fila(Fila *f);
int fila_vazia(Fila f);
int fila_cheia(Fila f);
void desaloca_fila(Fila *f);
