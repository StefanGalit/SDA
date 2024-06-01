#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 100

typedef struct car
{
    char *name;
    int price;
    int age;
}car;

void add_elements(car **list, int *size);
void print_elements(car *list, int size);
void check_car_name(car *list, int size);
int check_car_price(car *list, int size,int price);
int check_car_age(car *list, int size, int age);
void free_list(car *list);
void sort_by_name(car *list, int size);
void sort_by_age(car *list, int size);
void sort_by_price(car *list, int size);;
void insert_item_start(car **list, int *size);
void insert_item_by_index(car **list, int *size);
void insert_item_end(car **list, int *size);
int find_car_by_name(car *list, int size, const char *name);
void delete_item_by_index(car **list, int *size);
  

int main ()
{
   int choice;
   
   while (true)
   {
    int chois;
    printf("Daca doriti sa lucrati cu o lista gata tastati '1'\n");
    printf("Daca doriti sa creati o lista manual tastati '2'\n");
    printf("Pentru a iesi din program tastati '0'\n");
    scanf("%d", &chois);
    
   if (chois==1)
    {
        
        FILE *file= fopen("D:\\PC Laboratory\\Lectii\\SDA_1\\cars.txt", "r");
        if (file==NULL)
        {
            perror("Eroare la deschidere");
            return 1;
        }
            int nr_of_cars = 0;
            char linie[MAX_LEN];
            while (fgets(linie, sizeof(linie), file) != NULL) {
                nr_of_cars++;
            }
        
            int size = 0;
            
            

            car *list = (car*)malloc(nr_of_cars*sizeof(car));
            fseek(file, 0, SEEK_SET);
            for(int i = 0 ; i < nr_of_cars; i++) {
                list[i].name = (char *)malloc(MAX_LEN * sizeof(char));
                fscanf(file, "%s %d %d", list[i].name,&list[i].price , &list[i].age);
                
            }
            
    

    
        for (int i = 0; i < nr_of_cars; i++) {
            printf("Automobil %d: Denumire: %s, Pret: %d, An: %d\n", i + 1, list[i].name, list[i].price, list[i].age);
        }
    while (true)
    {
    printf("---------------------------Menu-----------------------------\n");
    printf("Pentru a printa lista automobilelor tastati '1'\n");
    printf("Pentru a goli lista (eliberarea tabloului) tastati '2'\n");
    printf("Pentru a gasi automobilul dupa anumite criterii tastati '3'\n");
    printf("Pentru a sorta lista dupa anumite criterii tastati '4'\n");
    printf("Pentru a adauga un automobil la inceputul listei tastati '5'\n");
    printf("Pentru a introduce un automobil la capatul listei tastati'6'\n");
    printf("Pentru a adauga un automobil la o anumita pozitie tastati'7'\n");
    printf("Elimina un automobil din lista dupa pozitie tastati '8'\n");
    printf("Pentru a da inapoi tastati '0'\n");
    scanf("%d", &choice);
     if (choice==1)
    {
        print_elements(list,nr_of_cars);
    }
     if (choice==2)
    {
        free_list(list);
        size = 0;
        list = NULL;
        printf("-------------Lista e goala-------------\n");
    }
     if (choice==3)
    {
        while(true){
        printf("Alegeti criteriul (1.Nume: 2.Pret: 3.Anul: 0.Pentru a parasi)\n");
        int n;
        scanf("%d", &n);
        if (n==1)
        {
            char const *name;
            printf("Introduceti numele automobilului cautat: ");
            scanf("%s", name);

            int index = find_car_by_name(list, nr_of_cars, name);
            printf("aaa");
            if (index != -1) {
                 printf("Automobilul cautat este gasit:\n");
                 printf("Denumire: %s\n", list[index].name);
                 printf("Pret: %d\n", list[index].price);
                 printf("An: %d\n", list[index].age);
            } else {
                printf("Automobilul cu numele %s nu a fost gasit.\n", name);
            }

        }
        if (n==2)
        {
            int price;
            printf("Introduceti pretul automobilului cautat: ");
            scanf("%d", &price);

            int index = check_car_price(list, nr_of_cars, price);

            if (index != -1) {
                 printf("Automobilul cautat este gasit:\n");
                 printf("Denumire: %s\n", list[index].name);
                 printf("Pret: %d\n", list[index].price);
                 printf("An: %d\n", list[index].age);
                 } else {
                     printf("Automobilul cu pretul %d nu a fost gasit.\n", price);
    }

        }
        if (n==3)
        {
            int age;
            printf("Introduceti anul automobilului cautat: ");
            scanf("%d", &age);

            int index = check_car_age(list, nr_of_cars, age);

            if (index != -1) {
                 printf("Automobilul cautat este gasit:\n");
                 printf("Denumire: %s\n", list[index].name);
                 printf("Pret: %d\n", list[index].price);
                 printf("An: %d\n", list[index].age);
                 } else {
                     printf("Automobilul din %d nu a fost gasit.\n", age);
    }
        }
        if (n==0)
        {
            break;
        }
        }
    }
     if (choice==4)
    {
       while (true)
        {
            printf("Alegeti criteriul de sortare (1.Nume: 2.Pret: 3.Anul: 0.Pentru a parasi)\n");
            int n;
            scanf("%d", &n);
            if (n==1)
            {
                sort_by_name(list,nr_of_cars);
            }
            if (n==2)
            {
                sort_by_price(list,nr_of_cars);
            }
            if (n==3)
            {
                sort_by_age(list,nr_of_cars);
            }
            if (n==0)
            {
                break;
            }
        } 
        
    }
     if (choice==5)
    {
        insert_item_start(&list,&nr_of_cars);
        
    }
     if (choice==6)
    {
        insert_item_end(&list,&nr_of_cars);
        
    }
     if (choice==7)
    {
        insert_item_by_index(&list,&nr_of_cars);
        
    }  
    if (choice==8)
    {
        delete_item_by_index(&list,&nr_of_cars);
        
    }
    if (choice == 0)
    {
        break;
    }
    }
    }

    if (chois==2)
    {
        car *list = NULL;
        int size = 0;
        while (true)
   {
    printf("----------------Menu----------------\n");
    printf("Pentru a adauga automobile in baza de date introduceti '1'\n");
    printf("Pentru a printa lista automobilelor tastati '2'\n");
    printf("Pentru a goli lista (eliberarea tabloului) tastati '3'\n");
    printf("Pentru a gasi automobilul dupa anumite criterii tastati '4'\n");
    printf("Pentru a sorta lista dupa anumite criterii tastati '5'\n");
    printf("Pentru a adauga un automobil la inceputul listei tastati '6'\n");
    printf("Pentru a introduce un automobil la capatul listei tastati'7'\n");
    printf("Pentru a adauga un automobil la o anumita pozitie tastati'8'\n");
    printf("Elimina un automobil din lista dupa pozitie tastati '9'\n");
    printf("Pentru a da inapoi tastati '0'\n");
    scanf("%d", &choice);
    if (choice==1)
    {
        add_elements(&list, &size);
    }
    if (choice==2)
    {
        print_elements(list,size);
    }
    if (choice==3)
    {
        free_list(list);
        size = 0;
        list = NULL;
        printf("Lista e goala-------------\n");
    }
    if (choice == 4)
    {
        while(true){
        printf("Alegeti criteriul (1.Nume: 2.Pret: 3.Anul: 0.Pentru a parasi)\n");
        int n;
        scanf("%d", &n);
        if (n==1)
        {
            char const *name;
            printf("Introduceti numele automobilului cautat: ");
            scanf("%s", name);

            int index = find_car_by_name(list, size, name);

            if (index != -1) {
                 printf("Automobilul cautat este gasit:\n");
                 printf("Denumire: %s\n", list[index].name);
                 printf("Pret: %d\n", list[index].price);
                 printf("An: %d\n", list[index].age);
                 } else {
                     printf("Automobilul cu numele %s nu a fost gasit.\n", name);
    }

        }
        if (n==2)
        {
            int price;
            printf("Introduceti pretul automobilului cautat: ");
            scanf("%d", &price);

            int index = check_car_price(list, size, price);

            if (index != -1) {
                 printf("Automobilul cautat este gasit:\n");
                 printf("Denumire: %s\n", list[index].name);
                 printf("Pret: %d\n", list[index].price);
                 printf("An: %d\n", list[index].age);
                 } else {
                     printf("Automobilul cu pretul %s nu a fost gasit.\n", price);
    }

        }
        if (n==3)
        {
            int age;
            printf("Introduceti anul automobilului cautat: ");
            scanf("%d", &age);

            int index = check_car_age(list, size, age);

            if (index != -1) {
                 printf("Automobilul cautat este gasit:\n");
                 printf("Denumire: %s\n", list[index].name);
                 printf("Pret: %d\n", list[index].price);
                 printf("An: %d\n", list[index].age);
                 } else {
                     printf("Automobilul din %d nu a fost gasit.\n", age);
    }
        }
        if (n==0)
        {
            break;
        }
        }
    }
    if (choice==5)
    {
       while (true)
        {
            printf("Alegeti criteriul de sortare (1.Nume: 2.Pret: 3.Anul: 0.Pentru a parasi)\n");
            int n;
            scanf("%d", &n);
            if (n==1)
            {
                sort_by_name(list,size);
            }
            if (n==2)
            {
                sort_by_price(list,size);
            }
            if (n==3)
            {
                sort_by_age(list,size);
            }
            if (n==0)
            {
                break;
            }
        } 
        
    }
    if (choice==6)
    {
        insert_item_start(&list,&size);
      
    }
    if (choice==7)
    {
        insert_item_end(&list,&size);
       
    }
    if (choice==8)
    {
        insert_item_by_index(&list,&size);
        
    }
    if (choice==9)
    {
        delete_item_by_index(&list,&size);
       
    }
    if (choice==0)
    {
        break;
    }    
    }
    }
    if (chois==0)
    {
        exit(0);
    }    
   }
    return 0;
}


void add_elements(car **list,int *size)
{
    printf("Introdu nr de automobile\n");
    scanf("%d", size);
    
    *list=(car *)malloc(*size * sizeof(car));
    for (int i = 0; i < *size; i++)
    {
        printf("Introdu denumirea automobilului\n");
        scanf("%s", (*list)[i].name);
        printf("Introdu pretul automobilului\n");
        scanf("%d", &(*list)[i].price);
        printf("Introduceti anul lansarii\n");
        scanf("%d", &(*list)[i].age);
    }
    
}
void print_elements(car *list, int size)
{
    printf("Lista automobilelor:\n");
    for (int i = 0; i < size; i++) {
        printf("Nume: %s, Pret: %d, Varsta: %d\n", list[i].name, list[i].price, list[i].age);
    }
}
int find_car_by_name(car *list, int size, const char *name) {
    
    for (int i = 0; i < size; i++) {
        if (strcmp((*(list + i)).name, name) == 0) {
            return i; 
        }
    }
    return -1; 
}


int check_car_price(car *list, int size,int price)
{
    
    for (int i = 0; i < size; i++)
    {
        if (list[i].price==price)
        {
           return i; 
        } 
        
    }
    return -1;
}

int check_car_age(car *list, int size, int age)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i].age==age)
        {
            return i;
        }
        
    }
    
    return -1;
}
void free_list(car *list)
{
    free(list);
}

void sort_by_name(car *list, int size)
{
  for (int i = 0; i < size-1; i++)
  {
    for (int j = 0; j < size-i-1; j++)
    {
        if (strcmp((*(list+j)).name,(*(list+j+1)).name)>0)
        {
             car temp = list[j];
             list[j] = list[j + 1];
             list[j + 1] = temp;
        }   
    }
    
  }
  
}
void sort_by_price(car *list, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (list[j].price>list[j+1].price)
            {
               car temp = list[j];
               list[j] = list[j + 1];
               list[j + 1] = temp;
            }
            
        }
        
    }
    
}
void sort_by_age(car *list, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (list[j].age>list[j+1].age)
            {
                car temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
            
        }
        
    }
    
}
void insert_item_start(car **list, int *size)
{
    *size+=1;
    *list=(car*)realloc(*list, *size*sizeof(car));
    for (int i = *size-1 ;i >0; i--)
    {
        (*list)[i]=(*list)[i-1];
    }
    printf("Introduceti detalii pentru noul automobil la inceput:\n");
    printf("Nume: ");
    scanf("%s", (*list)[0].name);
    printf("Pret: ");
    scanf("%d", &(*list)[0].price);
    printf("Varsta: ");
    scanf("%d", &(*list)[0].age);
    
}
void insert_item_by_index(car **list, int *size)
{
    *size+=1;
    *list=(car*)realloc(*list, *size*sizeof(car));
    int index;
    printf("Introduceti pozitia\n");
    scanf("%d", &index);
    for (int i = *size-1; i >index-1; i--)
    {
        (*list)[i]=(*list)[i-1];
    }
     printf("Introduceti detalii pentru noul automobil la pozitia %d:\n", index);
    printf("Nume: ");
    scanf("%s", (*list)[index-1].name);
    printf("Pret: ");
    scanf("%d", &(*list)[index-1].price);
    printf("Varsta: ");
    scanf("%d", &(*list)[index-1].age);
    

}
void insert_item_end(car **list, int *size)
{
    *size+=1;
    *list=(car*)realloc(*list, *size*sizeof(car));
    printf("Nume: ");
    scanf("%s", (*list)[*size-1].name);
    printf("Pret: ");
    scanf("%d", &(*list)[*size-1].price);
    printf("Varsta: ");
    scanf("%d", &(*list)[*size-1].age);
}
void delete_item_by_index(car **list, int *size) {
    int index;

    printf("Introduceti pozitia elementului de sters: ");
    scanf("%d", &index);

    if (index >= 1 && index <= *size) {
        for (int i = index - 1; i < *size - 1; i++) {
            (*list)[i] = (*list)[i + 1];
        }
        *size -= 1;
        *list = (car *)realloc(*list, *size * sizeof(car));
        printf("Elementul de la pozitia %d a fost sters.\n", index);
    } else {
        printf("Index invalid. Operatiunea de stergere nu a fost efectuata.\n");
    }
}


