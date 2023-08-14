#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//                                       KÜTÜPHANE OTOMASYONU
//                                   MURATHAN CANSEVER 19010011051

typedef struct Node{ // düðüm
	char name[20];
	char ISBN[20];
	char price[10];
}Node;

typedef struct Book{ // kitap
	Node date;
	struct Book*next;
}book;

book*GreatLink() { // toplu giriþ
	book*h, *tail, *p;
	h=tail=(book*)malloc(sizeof(book));
	h->next = NULL;
	int n = 0, i;
	printf("Girilecek kitap sayisini girin:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		p = (book*)malloc(sizeof(book));
		printf("Kitap adi:");
		scanf("%s",&p->date.name);
		printf("ISBN:");
		scanf("%s",&p->date.ISBN);
		printf("Fiyat:");
		scanf("%s",&p->date.price);
		p->next = NULL;
		tail->next = p;
		tail = p;
	}

	return h;
}

void Insert(book*h) { // ekleme
	book*p;
	p = (book*)malloc(sizeof(book));
	printf("Kitap Adi:");
	scanf("%s", &p->date.name);
	printf("ISBN:");
	scanf("%s", &p->date.ISBN);
	printf("Ucret:");
	scanf("%s", &p->date.price);
	p->next = h->next;
	h->next = p;
}

void Search1(book*h) { // kitap adýna göre arama
	char name[20];
	book*p = h->next;
	printf("Bulmak istediginiz kitap adini girin:");
	scanf("%s",&name);
	while (p!=NULL) {
		if (strcmp(p->date.name,name)!=0) {
			p = p->next;
		} else {
			printf("Kitap Adi	ISBN	Ucret\n");
			printf("%s		%s	%s\n",p->date.name,p->date.ISBN,p->date.price);
			return;
		}
	}
	if (p == NULL) {
		printf("Bulunamadi! \n");
	}
}

void Search2(book*h) { // ISBN'e göre arama
	char ISBN[20];
	book*p = h->next;
	printf("Bulmak istediginiz ISBN'i girin:");
	scanf("%s", &ISBN);
	while (p != NULL) {
		if (strcmp(p->date.ISBN, ISBN)!=0) {
			p = p->next;
		} else {
			printf("Kitap Adi	ISBN	Ucret\n");
			printf("%s		%s	%s\n", p->date.name, p->date.ISBN, p->date.price);
			return;
		}
	}
	if (p == NULL) {
		printf("Bulunamadi!\n");
	}
}

void update(book*h) { // ISBN'e göre guncelleme
	char ISBN[20];
	book*p = h->next;
	printf("Guncellemek istediginiz ISBN'i girin:");
	scanf("%s", &ISBN);
	while (p != NULL) {
		if (strcmp(p->date.ISBN, ISBN)!=0) {
			p = p->next;
		} else {
			printf("Kitap Adi	ISBN	Ucret\n");
			printf("%s		%s	%s\n", p->date.name, p->date.ISBN, p->date.price);
			printf("Yeni Kitap Adi:");
			scanf("%s", &p->date.name);
			printf("Yeni ISBN:");
			scanf("%s", &p->date.ISBN);
			printf("Yeni Ucret:");
			scanf("%s", &p->date.price);
			return;
		}
	}
	if (p == NULL) {
		printf("Bulunamadi!\n");
	}
}

void PrintLink(book*h) { // listeleme
	book*p;
	printf("Kitap Adi	ISBN	Ucret\n");
	for (p = h->next; p != NULL; p = p->next) {
		printf("%s		",p->date.name);
		printf("%s	", p->date.ISBN);
		printf("%s	", p->date.price);
		printf("\n");
	}

}

void delete(book*h) { // silme
	char ISBN[20]; // ISBN tek olduðu için silme ona göre
	book*p = h->next;
	book*tail = h;
	printf("Silmek istediginiz kitabin ISBN'ini girin:");
	scanf("%s", &ISBN);
	while (p != NULL) {
		if (strcmp(p->date.ISBN, ISBN)!=0) {
			p = p->next;
			tail = tail->next;
		} else {
			tail->next = p->next;
			free(p);
			return;
		}
	}
}

void menu() { // menu
	printf("--------- Kutuphane Otomasyonu --------- \n");
	printf("************ 1. Coklu Ekleme ************** \n");
	printf("************ 2. Ekleme ******************** \n");
	printf("************ 3. Basliga Gore Arama ******** \n");
	printf("************ 4. ISBN'e Gore Arama ********* \n");
	printf("************ 5. Silme ********************* \n");
	printf("************ 6. Listeleme ***************** \n");
	printf("************ 7. Guncelleme ***************** \n");
	printf("************ 8. Cikis ********************* \n");
}

void choose(book*h){ // secim islemi
	int i;
	int a = 1;

	while (a>0){
		menu();
		printf("Seciniz:");
		scanf("%d",&i);
		switch (i){
			case 1:
				h=GreatLink();
				break;
			case 2:
				Insert(h);
				break;
			case 3:
				Search1(h);
				break;
			case 4:
				Search2(h);
				break;
			case 5:
				delete(h);
				break;
			case 6:
				PrintLink(h);
				break;
			case 7:
				update(h);
				break;
			case 8:
				return;
			default:
				printf("Gecersiz secim! \n");
				a = -1;// döngü dýþýna atlama
				break;
		}
	}
}

int main() {
	book*head = NULL;
	choose(head);
	return 0;
}

