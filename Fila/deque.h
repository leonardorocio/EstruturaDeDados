typedef struct {
	int *dados;
	int inicio, n, capacidade;
} Deque;

void inicializa_deque(Deque *d, int size);
int deque_vazio(Deque d);
int deque_cheio(Deque d);
int inserir_fim(Deque *d, int v);
int inserir_inicio(Deque *d, int v);
int remover_fim(Deque *d, int *v);
int remover_inicio(Deque *d, int *v);
void mostra_deque(Deque d);
void desaloca_deque(Deque *d);
