#include<stdio.h>
#include<stdlib.h>

/*
1. creazione nodo (inizio, mezzo e fine);
2. stampa della lista;
3. cancellazione di un nodo (in base alla posizione del nodo e all'elemento che contiene);
4. memorizzare strutture in ogni nodo
*/

struct Node {
	int x;
	struct Node *next;
};

//AGGIUNGE UN ELEMENTO IN ULTIMA POSIZIONE
struct Node* listAppend(struct Node *head) {

	struct Node *newNode=malloc(sizeof(struct Node));
	printf("Nuovo elemento: ");
	scanf("%d", &(newNode->x));
	newNode->next=NULL;

	if(head==NULL)
		head=newNode;

	else {
		struct Node *temp=head;

		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=newNode;
	}

	return head;
}

//AGGIUNGE UN ELEMENTO IN PRIMA POSIZIONE
struct Node* listPrepend(struct Node *head) {
	
	struct Node *newNode=malloc(sizeof(struct Node));
	printf("Nuovo elemento: ");
	scanf("%d", &(newNode->x));

	newNode->next=head;
	head=newNode;

	return head;
}

//AGGIUNGE UN ELEMENTO IN POSIZIONE n
struct Node * listInsert(struct Node *head, int n) {

	if(n<=0)
		printf("Posizione non valida.");

	else{
		struct Node *newNode=malloc(sizeof(struct Node));
		printf("Nuovo elemento:");
		int x; scanf("%d", newNode->x);

		//Lista vuota
		if(head==NULL) {
			head=newNode;
			newNode->next=NULL;
			printf("Elemento aggiunto in prima posizione");
		}

		//Inserimento in prima posizione
		else if(n==1) {
			newNode->next=head;
			head=newNode;
			printf("Elemento aggiunto in prima posizione");
		}

		//Inserimento con n>1
		else {
			struct Node *temp=head;
			int i=1; //Nodo a cui punta temp

			while (temp->next!=NULL && i<n-1) {
				temp=temp->next;
				i++;
			}
			newNode->next=temp->next;
			temp->next=newNode;
			printf("\nElemento aggiunto in posizione %d.\nSe la posizione era maggiore del numero di elementi nella lista, è stato aggiunto in ultima posizione", i+1);
		}
	}
	return head;
}


//STAMPA TUTTA LA LISTA
void printList(struct Node *head) {

	if(head==NULL)
		printf("La lista non contiene elementi.\n");

	else{
		printf("Lista: ");
		while(head!=NULL) {
			printf("%d ", &(head->x));
			head=head->next;
		}
	}
}

//STAMPA TUTTA LA LISTA RICORSIVAMENTE
void recPrintList(struct Node *head) {
	if(head==NULL)
		printf(" Fine.\n");
	else {
		printf("%d", head->x);
		recPrintList(head->next);
	}
}

//STAMPA TUTTA LA LISTA RICORSIVAMENTE AL CONTRARIO
void recPrintList2(struct Node *head) {
	if(head==NULL)
		printf("\n");
	else {
		recPrintList(head->next);
		printf("%d", head->x);
	}
}


int main() {

	struct Node *head = NULL;

	int quit=0;
	while (quit==0) {

		printf("Operazioni possibili: \n0. Termina il programma.\n1. Aggiungi un elemento n volte alla fine della lista.\n2. Aggiungi un elemento n volte all'inizio della lista.\n3. Aggiungi un elemento in una posizione nella lista.\n");

		int function; scanf("%d", &function);

		if(function==0)
			quit=1;

		if(function==1) {
			printf("Numero di nuovi elementi: ");
			int n1; scanf("%d", &n1);

			for(int i=1; i<=n1; i++)
				head=listAppend(head);
		}

		if(function==2) {
			printf("Numero di nuovi elementi: ");
			int n2; scanf("%d", &n2);

			for(int i=1; i<=n2; i++)
				head=listPrepend(head);
		}

		if(function==3) {
			printf("Posizione (>0) in cui aggiungere il nuovo elemento: ");
			int n3; scanf("%d", &n3);

				head=listInsert(head, n3);
		}

		if(function==4)
			printList(head);
	}
}
