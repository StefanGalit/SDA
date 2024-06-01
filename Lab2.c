#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct artist
{
    char *name;
    char *album;
    char nomination[50];
    int year;
    int streams;
    struct artist * next;
}artist;

typedef struct List
{
    artist*head;
}List;

List * create_list()
{
    List * list= malloc(sizeof(List));
    list -> head = NULL;
    return list;
  
}




void sort_by_name(List *list);
void sort_by_year(List *list);
void sort_by_streams(List *list);
void sort_by_nomination(List *list);
void sort_by_album(List *list);
void add_artist();
void print_list(List *list);
artist * find_artist_by_name(List *list,char *checked_name);
artist * check_artist_by_nomination();
artist * check_artist_by_album();
artist * check_artist_by_year();
artist * check_artist_by_streams();
void free_list();
void add_artist_at_start(List *list, const char *name, const char *album, const char *nomination, int year, int streams);
void add_artist_at_end(List *list, const char *name, const char *album, const char *nomination, int year, int streams);
void insert_item_by_index(List *list, const char *name, const char *album, const char *nomination, int year, int streams, int index);
void delete_item_by_index(List *list, int position);
void reverse_list(List *list);
void clear_list(List *list);

int main ()
{
    int choice;
    List *my_list = create_list();
    add_artist(my_list, "Travis Scott", "1", "Winner", 2022, 100);
    add_artist(my_list, "Don", "2", "Nominated", 2023, 120);
    add_artist(my_list, "Taylor Swift", "3", "Nominated", 2021, 150);
    add_artist(my_list, "Kanye West", "4", "Nominated", 2020, 200);
    add_artist(my_list, "Roddy Ricch", "5", "", 2023, 120);
    sort_by_album(my_list);

    /*
    printf("Sorted by Name:\n");
    print_list(my_list);
    free_list(my_list);*/
    
    while (true)
    {
        printf("---------------------------Menu-----------------------------\n");
        printf("1.Pentru a printa lista artistilor tastati\n");
        printf("2.Pentru a goli lista (eliberarea tabloului) \n");
        printf("3.Pentru a gasi artistul dupa anumite criterii \n");
        printf("4.Pentru a sorta lista dupa anumite criterii \n");
        printf("5.Pentru a adauga un artist la inceputul listei \n");
        printf("6.Pentru a introduce un artist la capatul listei \n");
        printf("7.Pentru a adauga un artist la o anumita pozitie '\n");
        printf("8.Elimina un artist din lista dupa pozitie\n");
        printf("9.Inversarea listei\n");
        
        scanf("%d", &choice);
        if (choice == 1)
        {
            print_list(my_list);
        }
        if (choice == 2)
        {
            clear_list(my_list);
            free_list(my_list);
        }
        if (choice==3)
        {
            while(true){
            printf("Alegeti criteriul (1.Nume: 2.Album: 3.Nominatie: 4.An: 5.Streams: 0.Pentru a parasi)\n");
            int n;
            scanf("%d ", &n);
            if (n==1)
            {
                char *name;
                name = (char*)malloc(50*sizeof(char));
                printf("Introduceti numele artistului\n");
                scanf("%[^\n] ", name);
                artist *found_artist = find_artist_by_name(my_list, name);
                if (found_artist != NULL)
                {
                    printf("Artistul cautat:\n");
                    printf("Name: %s\n", found_artist->name);
                    printf("Album: %s\n", found_artist->album);
                    printf("Nominatie: %s\n", found_artist->nomination);
                    printf("Year: %d\n", found_artist->year);
                    printf("Streams: %d\n", found_artist->streams);
                }
                else
                {
                    printf("Artistul nu a fost gasit\n");
                }
                free(name);
            }
            if (n==2)
            {
                char *album;
                album = (char*)malloc(50*sizeof(char));
                scanf("[^\n]", album);
                artist *found_artist = check_artist_by_album(my_list, album);

                if (found_artist != NULL)
                {
                    printf("\nArtistul cautat:\n");
                    printf("Name: %s\n", found_artist->name);
                    printf("Album: %s\n", found_artist->album);
                    printf("Nominatie: %s\n", found_artist->nomination);
                    printf("Year: %d\n", found_artist->year);
                    printf("Streams: %d\n", found_artist->streams);
                }
                else
                {
                    printf("Artistul nu a fost gasit\n");
                }
                free(album);
            }
            if (n==3)
            {
                const char nomination_to_find[50];
                scanf("%s", nomination_to_find);
                artist *found_artist = check_artist_by_nomination(my_list, nomination_to_find);

                if (found_artist != NULL)
                {
                    printf("\nArtistul cautat:\n");
                    printf("Name: %s\n", found_artist->name);
                    printf("Album: %s\n", found_artist->album);
                    printf("Nominatie: %s\n", found_artist->nomination);
                    printf("Year: %d\n", found_artist->year);
                    printf("Streams: %d\n", found_artist->streams);
                }
                else
                {
                    printf("Artistul nu a fost gasit\n");
                }
            }
            if (n==4)
            {
                int year;
                scanf("%d", &year);
                artist *found_artist = check_artist_by_year(my_list, year);

                if (found_artist != NULL)
                {
                    printf("\nArtistul cautat:\n");
                    printf("Name: %s\n", found_artist->name);
                    printf("Album: %s\n", found_artist->album);
                    printf("Nominatie: %s\n", found_artist->nomination);
                    printf("Year: %d\n", found_artist->year);
                    printf("Streams: %d\n", found_artist->streams);
                }
                else
                {
                    printf("Artistul nu a fost gasit\n");
                }
            }
            if (n==5)
            {
                int streams;
                scanf("%d", &streams);
                artist *found_artist = check_artist_by_streams(my_list, streams);

                if (found_artist != NULL)
                {
                    printf("\nArtistul cautat:\n");
                    printf("Name: %s\n", found_artist->name);
                    printf("Album: %s\n", found_artist->album);
                    printf("Nominatie: %s\n", found_artist->nomination);
                    printf("Year: %d\n", found_artist->year);
                    printf("Streams: %d\n", found_artist->streams);
                }
                else
                {
                    printf("Artistul nu a fost gasit\n");
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
                    printf("Alegeti criteriul de sortare (1.Nume: 2.Album: 3.Nominatie: 4.An: 5.Streams 0.Pentru a parasi)\n");
                    int n;
                    scanf("%d", &n);
                    if (n==1)
                    {
                        sort_by_name(my_list);
                        printf("\nLista sortata dupa nume:\n");
                        print_list(my_list);
                        free_list(my_list);
                    }
                    if (n==2)
                    {
                        sort_by_album(my_list);
                        printf("\nLista sortata dupa album:\n");
                        print_list(my_list);
                    }
                    if (n==3)
                    {
                        sort_by_nomination(my_list);
                        printf("\nLista sortata dupa nominatie:\n");
                        print_list(my_list);
                    }
                    if (n==3)
                    {
                        sort_by_year(my_list);
                        printf("\nLista sortata dupa an:\n");
                        print_list(my_list);
                    }
                    if (n==3)
                    {
                        sort_by_streams(my_list);
                        printf("\nLista sortata dupa streams:\n");
                        print_list(my_list);
                    }
                    if (n==0)
                    {
                        break;
                    }
                    } 
                
            }   
        if (choice == 5)
        {
            char name[50];
            char album[50];
            char nomination[50];
            int year;
            int streams;
            printf("Intoduceti numele, albumul, nominatia, anul si streamurile artistului");
            scanf("%s", name);
            scanf("%s", album);
            scanf("%s", nomination);
            scanf("%d", &year);
            scanf("%d", &streams);
            add_artist_at_start(my_list,name,album,nomination,year,streams);
            
        }
        if (choice == 6)
        {
            char name[50];
            char album[50];
            char nomination[50];
            int year;
            int streams;
            printf("Intoduceti numele, albumul, nominatia, anul si streamurile artistului");
            scanf("%s", name);
            scanf("%s", album);
            scanf("%s", nomination);
            scanf("%d", &year);
            scanf("%d", &streams);
            add_artist_at_end(my_list,name,album,nomination,year,streams);
            
        }
        if (choice == 7)
        {
            char name[50];
            char album[50];
            char nomination[50];
            int year;
            int streams;
            int position;
            printf("Intoduceti numele, albumul, nominatia, anul si streamurile artistului\n");
            scanf("%s", name);
            scanf("%s", album);
            scanf("%s", nomination);
            scanf("%d", &year);
            scanf("%d", &streams);
            printf("Introduceti pozitia\n");
            scanf("%d", &position);

            insert_item_by_index(my_list,name,album,nomination,year,streams,position);
            
        }
        if (choice==8)
        {
            int position;
            printf("Introduceti pozitia\n");
            scanf("%d", &position);
            delete_item_by_index(my_list, position);
        }
        if (choice == 9)
        {
            reverse_list(my_list);
            print_list(my_list);
        }
        
             
          

        

        
    }
    


    /*print_list(myList);
    clear_list(myList);
    printf("\nList after clearing:\n");
    print_list(myList);
    free_list(myList);*/





    /*
     // Print the initial list
    printf("Initial List:\n");
    print_list(myList);

    // Reverse the list
    reverse_list(myList);

    // Print the reversed list
    printf("\nReversed List:\n");
    print_list(myList);

    // Free allocated memory
    free_list(myList);*/
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    // Free allocated memory
    
    // Sort the list by name
    /*sort_by_name(myList);

    // Print the sorted list
    printf("Sorted by Name:\n");
    print_list(myList);

    // Sort the list by year
    sort_by_year(myList);

    // Print the sorted list
    printf("\nSorted by Year:\n");
    print_list(myList);

    // Sort the list by streams
    sort_by_streams(myList);

    // Print the sorted list
    printf("\nSorted by Streams:\n");
    print_list(myList);

    // Sort the list by nomination
    sort_by_nomination(myList);

    // Print the sorted list
    printf("\nSorted by Nomination:\n");
    print_list(myList);

    // Free the list
    free_list(myList);*/

    


return 0;
    
}


void add_artist(List *list, const char *name, const char *album, const char *nomination, int year, int streams)
{
    artist * new_artist = malloc(sizeof(artist));
    /*new_artist->name = malloc(strlen(name) + 1);
    strcpy(new_artist->name, name);*/
    new_artist->name = strdup(name);
    //strcpy(new_artist->album, album);
    new_artist->album = strdup(album);
    strcpy(new_artist->nomination, nomination);
    new_artist->year=year;
    new_artist->streams=streams;

    new_artist->next = list->head;
    list->head = new_artist;


}
void free_artist(artist *a) {
    free(a->name);
    free(a);
}
void free_list(List *list) {
    artist *current = list->head;
    artist *next;

    while (current != NULL) {
        next = current->next;
        free_artist(current);
        current = next;
    }

    free(list);
}
void print_list(List *list)
{
    artist *current = list->head;

    printf("List of Artists:\n");

    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Album: %s\n", current->album);
        printf("Nomination: %s\n", current->nomination);
        printf("Year: %d\n", current->year);
        printf("Streams: %d\n", current->streams);
        printf("\n");

        current = current->next;
    }
}
void add_artist_at_start(List *list, const char *name, const char *album, const char *nomination, int year, int streams)
{
    artist *new_artist = malloc(sizeof(artist));
    new_artist->name = strdup(name);
    new_artist->album = strdup(album);
    strcpy(new_artist->nomination, nomination);
    new_artist->year = year;
    new_artist->streams = streams;

    new_artist->next = list->head;
    list->head = new_artist;
}

void add_artist_at_end(List *list, const char *name, const char *album, const char *nomination, int year, int streams)
{
    artist *new_artist = malloc(sizeof(artist));
    new_artist->name = strdup(name);
    new_artist->album = strdup(album);
    strcpy(new_artist->nomination, nomination);
    new_artist->year = year;
    new_artist->streams = streams;
    new_artist->next = NULL;

    if (list->head == NULL)
    {
        // If the list is empty, set the new artist as the head
        list->head = new_artist;
    }
    else
    {
        // Traverse to the end of the list
        artist *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Add the new artist at the end
        current->next = new_artist;
    }
}

void insert_item_by_index(List *list, const char *name, const char *album, const char *nomination, int year, int streams, int index)
{
     if (index <= 0)
    {
        printf("Invalid index. Index must be greater than 0.\n");
        return;
    }

    artist *new_artist = malloc(sizeof(artist));
    new_artist->name = strdup(name);
    new_artist->album = strdup(album);
    strcpy(new_artist->nomination, nomination);
    new_artist->year = year;
    new_artist->streams = streams;

    if (index == 1 || list->head == NULL)
    {
        // Add at the beginning if the index is 1 or the list is empty
        new_artist->next = list->head;
        list->head = new_artist;
    }
    else
    {
        // Traverse to the desired index
        artist *current = list->head;
        int i = 1;
        while (i < index - 1 && current->next != NULL)
        {
            current = current->next;
            i++;
        }

        // Insert the new artist at the desired index
        new_artist->next = current->next;
        current->next = new_artist;
    }

}

artist * find_artist_by_name(List *list,char *checked_name)
{
    artist *current= list->head;

    while (current != NULL)
    {
        if (strcmp(current->name, checked_name)==0)
        {
            return current;
        }
        current= current->next;
    }
    return NULL;
}

artist * check_artist_by_album(List *list, const char *checked_album)
{
    artist *current= list->head;
    while (current!=NULL)
    {
        if (strcmp(current->album, checked_album)==0)
        {
            return current;
        }
        current= current->next;
        
    }
    return NULL;
    
}
artist *check_artist_by_nomination(List *list, const char *checked_nomination)
{
    artist *current = list->head;
    while (current != NULL)
    {
        if (strcmp(current->nomination, checked_nomination) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
artist * check_artist_by_year(List *list, int year)
{  
    artist *current = list->head;
    while (current!=NULL)
    {
        if (current->year==year)
        {
            return current;
        }
        current=current->next;
    }
    
    return NULL;
}

artist * check_artist_by_streams(List *list, int streams)
{
    artist * current= list->head;
    while (current!=NULL)
    {
        if (current->streams==streams)
        {
            return current;
        }
        current= current->next;
    }
    
}

void delete_item_by_index(List *list, int position)
{
    if (position==1)
    {
        artist *temp=list->head;
        list->head=list->head->next;
        free_artist(temp);
        return;
    }

    artist *current=list->head;
    for (int i = 1; i < position-1 && current->next!=NULL; i++)
    {
        current=current->next;
        
    }
    
    artist *temp= current->next;
    current->next=current->next->next;
    free_artist(temp);  
}

void sort_by_name(List *list)
{
    artist *current;
    artist *next;
    artist *temp;
    int swapped;

    do
    {
        swapped = 0;
        current = list->head;

        while (current != NULL && current->next != NULL)
        {
            next = current->next;

            if (strcmp(current->name, next->name) > 0)
            {
                // Swap the artists if they are in the wrong order
                if (current == list->head)
                {
                    list->head = next;
                }
                else
                {
                    artist *prev = list->head;
                    while (prev->next != current)
                    {
                        prev = prev->next;
                    }
                    prev->next = next;
                }
                current->next = next->next;
                next->next = current;
                temp = current;
                current = next;
                next = temp;

                swapped = 1;
            }

            current = current->next;
        }

    } while (swapped);
}

void sort_by_year(List *list)
{
    artist *current;
    artist *next;
    artist *temp;
    int flag;

    do
    {
        flag = 0;
        current = list->head;

        while (current != NULL && current->next != NULL)
        {
            next = current->next;

            if (current->year > next->year)
            {
                // Swap the artists if they are in the wrong order
                if (current == list->head)
                {
                    list->head = next;
                }
                else
                {
                    artist *prev = list->head;
                    while (prev->next != current)
                    {
                        prev = prev->next;
                    }
                    prev->next = next;
                }
                current->next = next->next;
                next->next = current;
                temp = current;
                current = next;
                next = temp;

                flag = 1;
            }

            current = current->next;
        }

    } while (flag);
}

void sort_by_streams(List *list)
{
    artist *current;
    artist *next;
    artist *temp;
    int flag;

    do
    {
        flag = 0;
        current = list->head;

        while (current != NULL && current->next != NULL)
        {
            next = current->next;

            if (current->streams > next->streams)
            {
                // Swap the artists if they are in the wrong order
                if (current == list->head)
                {
                    list->head = next;
                }
                else
                {
                    artist *prev = list->head;
                    while (prev->next != current)
                    {
                        prev = prev->next;
                    }
                    prev->next = next;
                }
                current->next = next->next;
                next->next = current;
                temp = current;
                current = next;
                next = temp;

                flag = 1;
            }

            current = current->next;
        }

    } while (flag);
}

void sort_by_nomination(List *list)
{
    artist *current;
    artist *next;
    artist *temp;
    int flag;

    do
    {
        flag = 0;
        current = list->head;

        while (current != NULL && current->next != NULL)
        {
            next = current->next;

            if (strcmp(current->nomination, next->nomination) > 0)
            {
                // Swap the artists if they are in the wrong order
                if (current == list->head)
                {
                    list->head = next;
                }
                else
                {
                    artist *prev = list->head;
                    while (prev->next != current)
                    {
                        prev = prev->next;
                    }
                    prev->next = next;
                }
                current->next = next->next;
                next->next = current;
                temp = current;
                current = next;
                next = temp;

                flag = 1;
            }

            current = current->next;
        }

    } while (flag);
}
void sort_by_album(List *list)
{
    artist *current;
    artist *next;
    artist *temp;
    int swapped;

    do
    {
        swapped = 0;
        current = list->head;

        while (current != NULL && current->next != NULL)
        {
            next = current->next;

            if (strcmp(current->album, next->album) > 0)
            {
                // Swap the artists if they are in the wrong order
                if (current == list->head)
                {
                    list->head = next;
                }
                else
                {
                    artist *prev = list->head;
                    while (prev->next != current)
                    {
                        prev = prev->next;
                    }
                    prev->next = next;
                }
                current->next = next->next;
                next->next = current;
                temp = current;
                current = next;
                next = temp;

                swapped = 1;
            }

            current = current->next;
        }

    } while (swapped);
}


void reverse_list(List *list)
{
    artist *current = list->head;
    artist *prev = NULL;
    artist *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

void clear_list(List *list)
{
    artist *current = list->head;
    artist *next;

    while (current != NULL)
    {
        next = current->next;
        free_artist(current);
        current = next;
    }

    list->head = NULL;
}





void findmiddle(List * list)
{
    
}


































