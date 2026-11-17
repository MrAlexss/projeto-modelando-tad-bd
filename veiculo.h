#ifndef VEICULO_H
#define VEICULO_H

/* TAD Veiculo: cadastro de veículos em lista simplesmente encadeada. */

typedef struct {
    int id_veiculo;                 /* Identificador único do veículo (chave primária). */
    char placa[8];                  /* Placa com até 7 caracteres e terminador '\0'. */
    char modelo[51];                /* Modelo do veículo. */
    char marca[51];                 /* Marca do veículo. */
    int ano;                        /* Ano de fabricação/modelo registrado. */
    char cor[31];                   /* Cor do veículo. */
    double quilometragem_atual;     /* Quilometragem atual do veículo. */
    char situacao[21];              /* Situação do veículo no sistema. */
    int id_categoria;               /* Categoria à qual o veículo está vinculado (chave estrangeira). */
} Veiculo;

typedef struct NoVeiculo {
    Veiculo dados;
    struct NoVeiculo *proximo;
} NoVeiculo;

typedef struct {
    NoVeiculo *inicio;
} ListaVeiculos;

/* Inicializa a lista. Parâmetro: endereço da lista. Não retorna valor. */
void inicializar_veiculos(ListaVeiculos *lista);

/* Libera todos os nós da lista. Parâmetro: endereço da lista. Não retorna valor. */
void liberar_veiculos(ListaVeiculos *lista);

/* Insere um veículo no final. Parâmetros: lista e dados do veículo.
   Retorna 1 em caso de sucesso e 0 em caso de falha ou ID/placa duplicados. */
int inserir_veiculo(ListaVeiculos *lista, Veiculo novo);

/* Remove o veículo identificado pelo ID. Parâmetros: lista e ID.
   Retorna 1 se removeu e 0 se não encontrou. */
int remover_veiculo(ListaVeiculos *lista, int id_veiculo);

/* Busca pelo ID. Parâmetros: lista e ID. Retorna ponteiro para o veículo ou NULL. */
Veiculo *buscar_veiculo_por_id(const ListaVeiculos *lista, int id_veiculo);

/* Busca pela placa. Parâmetros: lista e placa. Retorna ponteiro para o veículo ou NULL. */
Veiculo *buscar_veiculo_por_placa(const ListaVeiculos *lista, const char *placa);

/* Atualiza os dados do veículo indicado pelo ID. Retorna 1 se atualizou e 0 se não encontrou
   ou se a nova placa já pertence a outro veículo. */
int atualizar_veiculo(ListaVeiculos *lista, int id_veiculo, Veiculo novos_dados);

/* Exibe os veículos cadastrados. Parâmetro: lista. Não retorna valor. */
void listar_veiculos(const ListaVeiculos *lista);

#endif
