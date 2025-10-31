typedef struct nodo{
  int info;
  struct nodo *prox;
}Nodo;

typedef struct lista {
  int tam;
  Nodo *head;
}Lista;

Lista* cria_lista();

Lista* insere_lista(Lista*, int);

Lista* remove_lista(Lista*, int);

void libera_lista(Lista*);

void printar_lista(Lista*);

int list_sum(Lista*);

void reverse_list(Lista*);

Lista* merge_sorted_lists(Lista*, Lista*);

void remove_duplicates(Lista*);

int is_palindrome(Lista*);

void rotate_list(Lista*, int);

Lista* intercalate_lists(Lista*, Lista*);

int get_kth_element(Lista*, int);

void split_list(Lista*, Lista**, Lista**);

void sort_list(Lista*);
