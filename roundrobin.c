#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time {
  int arrivalT;
  int burstT;
  struct time *next;
};

void push(struct time **head, struct time **tail, int arrival, int burst);

int main()
{
  int quant, quantum, i = 0, aux, arrival, burst;
  int total = 0, count = 0;
  int answeringTime = 0, waitingTime = 0, activeTime = 0;
  float answeringAv, waitingAv, activeAv;
 
  scanf("%d %d", &quant, &quantum);
 
  struct time *head = NULL;
struct time *tail = NULL;
  struct time *temp = head;
 
  temp = (struct time*)malloc(sizeof(struct time));
 
  while (i < quant) {
    scanf("%d %d", &arrival, &burst);
    push(&head,&tail, arrival, burst);
    i++;
  }
  aux = quant;
 
  for (total = 0, i = 0; aux != 0;)  {
      if (temp -> burstT <= quantum && temp -> burstT > 0) {
          total = total + temp -> burstT;
          temp -> burstT = 0;
          count = 1;
      }
      else if (temp -> burstT > 0) {
          temp -> burstT = temp -> burstT - quantum;
          total = total + quantum;
      }
      if (temp -> burstT == 0 && count == 1) {
          waitingTime += total - temp -> arrivalT - temp -> arrivalT;
          activeTime += total;
          answeringTime += total - temp -> arrivalT;
          aux--;
          count = 0;
      }
      if (temp -> next == NULL) {
          temp = head;          
      }
      else if (head -> next -> arrivalT <= total) {
          temp = temp -> next;
      }
      else {
          temp = head;
      }
  }
 
  activeAv = activeTime*1.0 / quant;
  answeringAv = answeringTime*1.0 / quant;
  waitingAv = waitingTime*1.0 / quant;
  printf("RR %.1f %.1f %.1f", activeAv, answeringAv, waitingAv);

  return 0;
}
void push(struct time **head, struct time **tail, int arrival, int burst)
{
  struct time *novo = (struct time *)malloc(sizeof(struct time));
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
