#ifndef CLIENTE_H
#define CLIENTE_H

/* TAD Cliente: cadastro de clientes em lista simplesmente encadeada. */

typedef struct {
    int id_cliente;             /* Identificador único do cliente (chave primária). */
    char nome_completo[101];    /* Nome completo. */
    char cpf[12];               /* CPF com 11 dígitos e terminador '\0'. */
    char data_nascimento[11];   /* Data no formato DD/MM/AAAA. */
    char telefone[21];          /* Telefone para contato. */
    char email[101];            /* Endereço de e-mail. */
    char endereco[151];         /* Endereço do cliente. */
} Cliente;

typedef struct NoCliente {
    Cliente dados;
    struct NoCliente *proximo;
} NoCliente;

typedef struct {
    NoCliente *inicio;
} ListaClientes;

/* Inicializa a lista. Parâmetro: endereço da lista. Não retorna valor. */
void inicializar_clientes(ListaClientes *lista);

/* Libera todos os nós da lista. Parâmetro: endereço da lista. Não retorna valor. */
void liberar_clientes(ListaClientes *lista);

/* Insere um cliente no final. Parâmetros: lista e dados do cliente.
   Retorna 1 em caso de sucesso e 0 em caso de falha ou CPF/ID duplicado. */
int inserir_cliente(ListaClientes *lista, Cliente novo);

/* Remove o cliente identificado pelo ID. Parâmetros: lista e ID.
   Retorna 1 se removeu e 0 se não encontrou. */
int remover_cliente(ListaClientes *lista, int id_cliente);

/* Busca pelo ID. Parâmetros: lista e ID. Retorna ponteiro para o cliente ou NULL. */
Cliente *buscar_cliente_por_id(const ListaClientes *lista, int id_cliente);

/* Busca pelo CPF. Parâmetros: lista e CPF. Retorna ponteiro para o cliente ou NULL. */
Cliente *buscar_cliente_por_cpf(const ListaClientes *lista, const char *cpf);

/* Atualiza os dados do cliente indicado pelo ID. Retorna 1 se atualizou e 0 se não encontrou
   ou se o novo CPF já pertence a outro cliente. */
int atualizar_cliente(ListaClientes *lista, int id_cliente, Cliente novos_dados);

/* Exibe os clientes cadastrados. Parâmetro: lista. Não retorna valor. */
void listar_clientes(const ListaClientes *lista);

#endif
