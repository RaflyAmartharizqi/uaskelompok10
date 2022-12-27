#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Struktur data untuk menyimpan data truk
typedef struct Truk {
  char nopol[10];
  char kode_kontainer[10];
  char tujuan[50];
  struct Truk *next;
} Truk;

// Struktur data untuk queue truk
typedef struct Queue {
  Truk *front;
  Truk *rear;
  int count;
} Queue;

// Inisialisasi queue truk
Queue initQueue(Queue *q) {
  q->front = NULL;
  q->rear = NULL;
  q->count = 0;
}

// Memeriksa apakah queue truk kosong atau tidak
int isEmpty(Queue *q) {
  return (q->count == 0);
}

// Struktur data untuk node dalam linked list
typedef struct node {
    char kode_kontainer[20];
    char tujuan[10];
    struct node* next;
} node;

// Struktur data untuk stack
typedef struct stack {
    node* top;
    int size;
    int capacity;
} stack;

// Inisialisasi stack
void init_stack(stack* s) {
    s->top = NULL;
    s->size = 0;
    s->capacity = 5;
}

//Code untuk cek kode_kontainer sudah ada atau belum====================Ini yg ditambah
int search(Queue *q, char kode_kontainer[])
{
	Truk *curr = q->front;
	while(curr != NULL)
	{
		if(strcmp(curr->kode_kontainer, kode_kontainer)==0)
		{
			return 1;
		}
		curr->next;
	}
	return 0;
}

// Menambahkan truk baru ke dalam queue
void enqueue(Queue *q, char nopol[], char kode_kontainer[], char tujuan[]) {
  Truk *newTruk = (Truk*)malloc(sizeof(Truk));
  strcpy(newTruk->nopol, nopol);
  strcpy(newTruk->kode_kontainer, kode_kontainer);
  strcpy(newTruk->tujuan, tujuan);
  newTruk->next = NULL;
  
  if (isEmpty(q)) {
    q->front = newTruk;
  } else {
    q->rear->next = newTruk;
  }
  q->rear = newTruk;
  q->count++;
}

// Push data ke stack
void push(stack* s, char* kode_kontainer, char* tujuan) {
	if (s->size >= s->capacity) {
        printf("Tumpukan kontainer sudah penuh dan truk telah dikeluarkan dari antrian\n");
        return;
    }
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->kode_kontainer, kode_kontainer);
    strcpy(new_node->tujuan, tujuan);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

// Menghapus truk yang ada di depan queue
void dequeue(Queue *q, stack *s, stack *l, stack *p) {
	
  if (isEmpty(q)) {
    printf("Antrian truk kosong!\n");
  } else {
  	if(strcmp(q->front->tujuan, "s")==0)
  	{
  		push(s, q->front->kode_kontainer, q->front->tujuan);
  		
	} else if(strcmp(q->front->tujuan, "l")==0){
		
		push(l, q->front->kode_kontainer, q->front->tujuan);
		
	} else if(strcmp(q->front->tujuan, "p")==0){
		
		push(p, q->front->kode_kontainer, q->front->tujuan);
	}
  	printf("Data yang dikeluarkan : \n");
  	printf("Nopol: %s\n", q->front->nopol);
    printf("Kode kontainer: %s\n", q->front->kode_kontainer);
    printf("Tujuan: %s\n", q->front->tujuan);
    Truk *truk = q->front;
    q->front = truk->next;
    q->count--;
    free(truk);
  }
}

void pop_stack(stack *s) {
  if (s->top >= 0) {
  	printf("Data yang dikeluarkan : \n");
    printf("Kode kontainer: %s\n", s->top->kode_kontainer);
    printf("Tujuan: %s\n", s->top->tujuan);
    node *temp = s->top;
    s->top = s->top->next;
    s->size--;
    free(temp);
  } else {
    printf("Error: Tumpukan Kontainer Kosong\n");
  }
}


// Menampilkan data dari setiap truk yang ada dalam queue
void printQueue(Queue *q) {
  if (isEmpty(q)) {
    printf("Antrian truk kosong!\n");
  } else {
  	printf("Data front berada di atas\n");
    Truk *truk = q->front;
    while (truk != NULL) {
      printf("Nopol: %s\n", truk->nopol);
      printf("Kode kontainer: %s\n", truk->kode_kontainer);
      printf("Tujuan: %s\n", truk->tujuan);
      printf("\n");
      truk = truk->next;
    }
  }
}

void print_stack(stack* s) {
    node* curr = s->top;
    if(s->top != 0)
    {
    	printf("Data top berada di atas\n");
    	while (curr != NULL) {
	        printf("Kode Kontainer: %s\n", curr->kode_kontainer);
	        printf("Tujuan: %s\n", curr->tujuan);
	        printf("\n");
	        curr = curr->next;
	    }	
	} else {
		printf("Data kontainer kosong!\n");
	}
     
}

int main() {
  Queue q;
  initQueue(&q);

  int pilihan;
  char nopol[10], kode_kontainer[10], tujuan[50];
  
  stack s, p, l;
  init_stack(&s);
  init_stack(&p);
  init_stack(&l);

  do {
  	system("cls");
    printf("Menu:\n");
    printf("1. Masukkan Truk Kontainer\n");
    printf("2. Keluarkan Truk Kontainer\n");
    printf("3. Tampilkan Data Truk Kontainer\n");
    printf("4. Tampilkan Data Kontainer Surabaya\n");
    printf("5. Tampilkan Data Kontainer Lombok\n");
    printf("6. Tampilkan Data Kontainer Papua\n");
    printf("7. Keluarkan Data Kontainer Surabaya\n");
    printf("8. Keluarkan Data Kontainer Lombok\n");
    printf("9. Keluarkan Data Kontainer Papua\n");
    printf("10. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihan);
	system("cls");
    switch (pilihan) {
      case 1:
        printf("Masukkan Nopol: ");
        scanf("%s", nopol);
        printf("Masukkan Kode kontainer: ");
        scanf("%s", kode_kontainer);
        
        printf("Masukkan Tujuan (Surabaya = s) (Lombok = l) (Papua = p): ");
        scanf("%s", tujuan);
        while (strcmp(tujuan, "s") != 0 && strcmp(tujuan, "p") != 0 && strcmp(tujuan, "l") != 0) {
        	printf("Input tujuan tidak valid! Masukkan tujuan yang valid (s/p/l): ");
        	scanf("%s", tujuan);
        }
        if(search(&q, kode_kontainer))
        {
        	printf("\nData Kode Kontainer Sudah Ada!");
		} else {
			enqueue(&q, nopol, kode_kontainer, tujuan);	
		}
        getch();
        break;
      case 2:
        dequeue(&q, &s, &l, &p);
        getch();
        break;
      case 3:
        printQueue(&q);
        getch();
        break;
      case 4:
      	print_stack(&s);
		getch();
        break;
      case 5:
      	print_stack(&l);
		getch();
        break;
      case 6:
      	print_stack(&p);
		getch();
        break;
      case 7:
      	pop_stack(&s);
		getch();
        break;
      case 8:
      	pop_stack(&l);
		getch();
        break;
      case 9:
      	pop_stack(&p);
		getch();
        break;
      case 10:
        break;
      default:
        printf("Pilihan tidak valid!\n");
        getch();
        break;
    }
  } while (pilihan != 10);

  return 0;
}


