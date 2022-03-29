# atividade4
## Proposito do código

>O código exige uma quantidade de processos, seguido do valor do quantum. Para conseguir pegar as informacoes do arrival time e o burst time de cada processo, foi feito um while, tendo o loop infinito como condição de parada. todas as informações dos processos serao colocadas em uma fila para que o round robin determine a ordem e o tempo de execução dos processos. no final, o codigo terá como saida as medias do tempo ativo, do tempo de resposta e do tempo de espera

## makefile

> FUNÇÕES:
> Make - compila o código e gera o binário
> Make run - compila o código.
> Make clear - apaga o binário.

## Struct

c
struct time {
    int arrivalT;
    int burstT;
    struct time *next;
};

## Função
> PUSH- adiciona o node time na fila, caso a fila nao exista, ele cria a fila.
void push(struct time **head, struct time **tail, int arrival, int burst)
{
  struct tempo *novo = (struct tempo *)malloc(sizeof(struct tempo));
  if (novo != NULL){
    novo-> arrivalT = arrival;
    novo -> burstT = burst;
    novo->next = NULL;
   
    if (*head == NULL){
      *head = novo;
      *tail = novo;
    }
        else{
      (*tail)->next = novo;
      *tail = novo;
    }
  }
}

## Variaveis
> variaveis que recebem o input do codigo:
  int quant, quantum, aux, arrival, burst;
> contadores para os loops
  int total = 0, i = 0, count = 0;
> acumuladores que armazenam os devidos timing de cada processo
  int answeringTime = 0, waitingTime = 0, activeTime = 0;
> variaveis que recebem a media dos tempos de todos os processos
  float answeringAv, waitingAv, activeAv;


 
## Lógica
> a lógica utilizada no codigo segue as demandas do round robin, onde um quantum é determinado e, de acordo com a chegada dos processos e respeitando o tempo do quantum, os processos são processados. De acordo com a logica, foi possivel determinar o tempo de espera, o tempo de respostas e o tempo de execução de todos os processos.

## Print
>  a saída do código é a media dos tempos armazenadas durante a logica guardadas nas variaveis activeAv, answeringAv e waitingAv
printf("RR %.1f %.1f %.1f", activeAv, answeringAv, waitingAv);
