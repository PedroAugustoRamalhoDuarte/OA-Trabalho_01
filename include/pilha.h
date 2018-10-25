#ifndef PILHA
#define PILHA
#include <stdio.h>
#include <stdlib.h>

/* "Copyright [2018] <Pedro Augusto>" */

/**
 * @file pilha.h
 * 
 * @brief Header que contém as structs e os cabeçalhos das funções de implementação de pilha
 * 
 * @author Pedro Augusto Ramalho Duarte, matrícula 17/0163717
 * 
 */

/**
 * @brief Tipo da variavel que sera armazenada pelas pilhas.
 * A struct contem um tipo int porem eh facilmente mudavel.
 */
typedef struct itemType {
  int tipoInt; /**< Variavel do tipo int*/
}ItemType;

/**
 * @brief No utilizado na pilha dinamica.
 * Contem uma informacao do tipo ItemType e um ponteiro para o proximo elemento da pilha.
 */
typedef struct node {
  ItemType info; /**< Infomarcao do no.*/
  struct node *prox; /**< Ponteiro para o proximo.*/
}Node;

/**
 * @brief Pilha Dinamica.
 * Contem um ponteiro para o proximo e um int que representa o tamanho maximo que a pilha pode ter.
 */
typedef struct pilha_dinaminca {
  int max_size; /**< Int que guarda a informacao do tamanho maximo.*/
  Node *topo; /**< Ponteiro para o topo.*/
}Pilha_din;

/**
 * @brief Pilha Estatica.
 * Contem um ponteiro para o proximo e um int que representa o tamanho maximo que a pilha pode ter.
 */
typedef struct pilha_estatica {
  int max_size; /**< Int que guarda a informacao do tamanho maximo.*/
  int size; /**< Int que guarda a informacao da quantidade de itens ja adicionados.*/
  ItemType *info; /**< Array do tipo ItemType.*/
}Pilha_est;


//----------------------------- Pilha Dinamica ---------------------------
/** 
 * @brief Cria uma pilha vazia
 * A Funcao define o tamanho maximo da pilha e a cria
 *
 * @param max_size - Define o tamanho máximo da pilha
 *
 * @return Pilha - retorna o ponteiro da pilha propiamente dita
 */
Pilha_din* createStack(float max_size);

/**
 * @brief Introduz um elemento na pilha
 * Funcao que adiciona um elemento no topo da pilha do tipo int
 * 
 * @param Pilha - Pilha na qual o elemento vai ser inserido
 * @param Item - Elemento que vai ser inserido
 *
 * @return 1 - Retorna 1 caso consiga inserir o item
 * @return 0 - Retorna 0 caso nao consiga inserir o item
 */
int push(Pilha_din* pi, ItemType item);

/**
 * @brief Remove um elemento na pilha
 * Funcao que remove um elemento e o retorna por meio de um parametro de entrada
 * 
 * @param Pilha - Pilha na qual o elemento vai ser removido
 * @param Retorno - Passa o endereco para retornar a variavel
 *
 * @return 1 - Retorna 1 caso consiga remover o item com sucesso
 * @return 0 - Retorna 0 caso nao consiga remover o item
 */
int pop(Pilha_din* pi, ItemType* retorno);

/**
 * @brief Mostra o elemento que esta no topo da pilha
 * Funcao que retorna o topo por meio de um parametro de entrada
 * 
 * @param Pilha - pilha na qual o elemento vai ser removido
 * @param Retorno - passa o endereco para retornar a variavel
 *
 * @return 1 - Retorna 1 caso consiga retornar o item com sucesso
 * @return 0 - Retorna 0 caso nao consiga retornar o item
 */
int top(Pilha_din* pi, ItemType* retorno);

/**
 * @brief Muda o max_size
 * Funcao que muda o max_size se possivel
 *
 * @param Pilha - pilha na qual o tamanho podera ser mudado
 * @param Tamanho - novo possivel tamanho da pilha
 *
 * @return 0 - Retorna 0 se o tamanho for negativo ou se for menor que o orignal 
 * @return 1 - Retorna 1 se o tamanho for maior o igual ao original
 */
int setSize(Pilha_din* pi, int new_max_size);

/**
 * @brief Mostra quantos elementos ja foram inseridos na pilha
 * Funcao que retorna quantos elementos ja foram inserios na pilha
 *
 * @param Pilha - pilha na qual sera mostrada quantos elementos foram inseridos
 *
 * @return Size - Quantos eles ja foram inseridos
 */
int size(Pilha_din* pi);

/** 
 * @brief Mostra se a pilha esta cheia
 * Funcao que retorna 0 ou 1 dependendo se a pilha esta cheia ou n
 *
 * @param Pilha - pilha na qual sera mostrada se esta cheia
 *
 * @return 1 - Retorna 1 se estiver cheia
 * @return 0 - Retorna 0 se nao estiver cheia
 */
int isFull(Pilha_din* pi);

/** 
 * @brief Mostra se a pilha esta vazia
 * Funcao que retorna 0 ou 1 dependendo se a pilha esta vazia ou n
 *
 * @param Pilha - pilha na qual sera mostrada se esta vazia
 *
 * @return 1 - Retorna 1 se estiver vazia
 * @return 0 - Retorna 0 se nao estiver vazia
 */
int isEmpty(Pilha_din* pi);

/** 
 * @brief Libera o espaco de memoria
 * Funcao que retorna 0 ou 1 dependendo se a pilha esta vazia ou n
 *
 * @param Pilha - pilha na qual sera mostrada se esta vazia
 *
 * @return 1 - Retorna 1 se estiver vazia
 * @return 0 - Retorna 0 se nao estiver vazia
 */
int destroyStack(Pilha_din* pi);


//-------------------------------- Pilha Estatica --------------------------
/** 
 * @brief Cria uma pilha vazia
 * A Funcao define o tamanho maximo da pilha e a cria
 *
 * @param max_size - Define o tamanho máximo da pilha
 *
 * @return Pilha - retorna o ponteiro da pilha propiamente dita
 */
Pilha_est* createStack(int max_size);

/**
 * @brief Introduz um elemento na pilha
 * Funcao que adiciona um elemento no topo da pilha do tipo int
 * 
 * @param Pilha - Pilha na qual o elemento vai ser inserido
 * @param Item - Elemento que vai ser inserio
 *
 * @return 1 - Retorna 1 caso consiga inserir o item
 * @return 0 - Retorna 0 caso nao consiga inserir o item
 */
int push(Pilha_est* pi, ItemType item);

/**
 * @brief Remove um elemento na pilha
 * Funcao que remove um elemento e o retorna por meio de um parametro de entrada
 * 
 * @param Pilha - Pilha na qual o elemento vai ser removido
 * @param Retorno - Passa o endereco para retornar a variavel
 *
 * @return 1 - Retorna 1 caso consiga remover o item com sucesso
 * @return 0 - Retorna 0 caso nao consiga remover o item
 */
int pop(Pilha_est *pi, ItemType *retorno);

/**
 * @brief Mostra o elemento que esta no topo da pilha
 * Funcao que retorna o topo por meio de um parametro de entrada
 * 
 * @param Pilha - pilha na qual o elemento vai ser removido
 * @param Retorno - passa o endereco para retornar a variavel
 *
 * @return 1 - Retorna 1 caso consiga retornar o item com sucesso
 * @return 0 - Retorna 0 caso nao consiga retornar o item
 */
int top(Pilha_est* pi,  ItemType* retorno);

/**
 * @brief Muda o max_size
 * Funcao que muda o max_size se possivel
 *
 * @param Pilha - pilha na qual o tamanho podera ser mudado
 * @param Tamanho - novo possivel tamanho da pilha
 *
 * @return 0 - Retorna 0 se o tamanho for negativo ou se for menor que o orignal 
 * @return 1 - Retorna 1 se o tamanho for maior o igual ao original
 */
int setSize(Pilha_est* pi, int new_max_size);

/**
 * @brief Mostra quantos elementos ja foram inseridos na pilha
 * Funcao que retorna quantos elementos ja foram inserios na pilha
 *
 * @param Pilha - pilha na qual sera mostrada quantos elementos foram inseridos
 *
 * @return Size - Quantos eles ja foram inseridos
 */
int size(Pilha_est* pi);

/** 
 * @brief Mostra se a pilha esta cheia
 * Funcao que retorna 0 ou 1 dependendo se a pilha esta cheia ou n
 *
 * @param Pilha - pilha na qual sera mostrada se esta cheia
 *
 * @return 1 - Retorna 1 se estiver cheia
 * @return 0 - Retorna 0 se nao estiver cheia
 */
int isFull(Pilha_est* pi);

/** 
 * @brief Mostra se a pilha esta vazia
 * Funcao que retorna 0 ou 1 dependendo se a pilha esta vazia ou n
 *
 * @param Pilha - pilha na qual sera mostrada se esta vazia
 *
 * @return 1 - Retorna 1 se estiver vazia
 * @return 0 - Retorna 0 se nao estiver vazia
 */
int isEmpty(Pilha_est* pi);

/** 
 * @brief Libera o espaco de memoria
 * Funcao que retorna 0 ou 1 dependendo se a pilha esta vazia ou n
 *
 * @param Pilha - pilha na qual sera mostrada se esta vazia
 *
 * @return 1 - Retorna 1 se estiver vazia
 * @return 0 - Retorna 0 se nao estiver vazia
 */
int destroyStack(Pilha_est* pi);

#endif /* PILHA */
