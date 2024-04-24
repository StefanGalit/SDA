#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void add_new_doc_in_queue(Document** queue, Queue* refr, int id, char* name, int total_lines, int left_lines) {
    Document* new_doc = (Document*)malloc(sizeof(Document));
    new_doc->doc_id = id;
    new_doc->doc_name = strdup(name);
    new_doc->total_nr_of_lines = total_lines;
    new_doc->left_lines_to_print = left_lines;
    new_doc->next = NULL;

    if (*queue == NULL) {
        *queue = new_doc;
        refr->front = new_doc;
    } else {
        Document* temp = *queue;
        while (temp->next) {
            temp = temp->next;
        }
        refr->rear = new_doc;
        temp->next = new_doc;
    }
}

void delete_a_document_from_queue(Document** refr, int id) {
    if (*refr == NULL) {
        printf("Coada de documente este goala\n");
        return;
    }

    Document* curr_node = *refr;
    Document* pre_node = NULL;

    while (curr_node != NULL) {
        if (curr_node->doc_id == id) {
            if (pre_node == NULL) {
                *refr = curr_node->next;
                free(curr_node);
                return;
            } else {
                pre_node->next = curr_node->next;
                free(curr_node);
                return;
            }
        }
        pre_node = curr_node;
        curr_node = curr_node->next;
    }
}

Printer* initialize_printer(int id, int time_to_print) {
    Printer* printer = (Printer*)malloc(sizeof(Printer));
    printer->printer_id = id;
    printer->time_to_print = time_to_print;
    printer->printer_doc = NULL;
    printer->next = NULL;
    return printer;
}

void add_printer(Printer** printer_list, int id, int time_to_print) {
    Printer* new_printer = initialize_printer(id, time_to_print);
    if (*printer_list == NULL) {
        *printer_list = new_printer;
    } else {
        Printer* temp = *printer_list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_printer;
    }
}

void delete_printer(Printer** printers_list, int printer_id) {
    if (*printers_list == NULL) {
        printf("Coada de imprimante este goala\n");
        return;
    }

    Printer* curr_node = *printers_list;
    Printer* pre_iter_printer = NULL;

    while (curr_node) {
        if (curr_node->printer_id == printer_id) {
            if (pre_iter_printer == NULL) {
                *printers_list = curr_node->next;
                free(curr_node);
                return;
            } else {
                pre_iter_printer->next = curr_node->next;
                free(curr_node);
                return;
            }
        }
        pre_iter_printer = curr_node;
        curr_node = curr_node->next;
    }
}

Printer* pop_printer(Printer** printers_refr) {
    Printer* iter = *printers_refr;
    while (iter != NULL) {
        if (iter->printer_doc == NULL || iter->printer_doc->left_lines_to_print == 0) {
            return iter;
        } else {
            iter = iter->next;
        }
    }
    return NULL;
}

Document* pop_document(Queue* element) {
    if (element->front == NULL)
        return NULL;

    Document* temp = element->front;
    element->front = element->front->next;
    return temp;
}

void distribute_documents(Document** docs_queue, Queue* element, Printer** printers_list) {
    if (*docs_queue == NULL || *printers_list == NULL) {
        printf("Nu exista documente sau imprimante disponibile.\n");
        return;
    }

    Printer* curr_printer = *printers_list;
    Document* selected_doc = NULL;
    Printer* selected_printer = NULL;

    int available_printers = 0;

    while (curr_printer != NULL) {
        if ((curr_printer->printer_doc == NULL) || (curr_printer->printer_doc->left_lines_to_print <= 0)) {
            available_printers++;
        }
        curr_printer = curr_printer->next;
    }

    if (available_printers == 0) {
        printf("Nu exista imprimante disponibile\n");
        return;
    } else {
        Document* temp = *docs_queue;
        while (temp != NULL) {
            selected_printer = pop_printer(printers_list);

            if (selected_printer != NULL) {
                selected_printer->printer_doc = temp;
                printf("Documentul = %s(%d/%d) a fost alocat la imprimanta %d cu timpul %d\n",
                       selected_printer->printer_doc->doc_name,
                       selected_printer->printer_doc->left_lines_to_print,
                       selected_printer->printer_doc->total_nr_of_lines,
                       selected_printer->printer_id,
                       selected_printer->time_to_print);
                temp = temp->next;
            }
        }
    }
}

// Funcție pentru verificarea dacă toate documentele au fost complet printate
int is_printed_docs(Document* docs_queue) {
    while (docs_queue != NULL) {
        if (docs_queue->left_lines_to_print > 0) {
            return 0; // Există documente neprintate
        }
        docs_queue = docs_queue->next;
    }
    return 1; // Toate documentele au fost printate complet
}


void add_finished_doc_to_procesed_list(Document** printers_doc, Printed_docs** processed_docs) {
    Printed_docs* iter_printed_list = NULL;
    Printed_docs* new_doc = (Printed_docs*)calloc(1, sizeof(Printed_docs));
    new_doc->doc_id = (*printers_doc)->doc_id;
    new_doc->doc_name = strdup((*printers_doc)->doc_name);
    new_doc->total_nr_of_lines = (*printers_doc)->total_nr_of_lines;
    new_doc->left_lines_to_print = (*printers_doc)->left_lines_to_print;
    (*printers_doc) = NULL;

    iter_printed_list = *processed_docs;

    if (iter_printed_list == NULL) {
        *processed_docs = new_doc;
    } else {
        while (iter_printed_list->next != NULL) {
            iter_printed_list = iter_printed_list->next;
        }
        iter_printed_list->next = new_doc;
    }
}

void update_printers_and_docs_status(Printer** printers_list, Document** docs_queue, Printed_docs** processed_docs) {
    Printer* curr_printer = *printers_list;

    while (curr_printer != NULL) {
        if (curr_printer->printer_doc != NULL && curr_printer->printer_doc->left_lines_to_print > 0) {
            curr_printer->printer_doc->left_lines_to_print -= curr_printer->time_to_print;

            if (curr_printer->printer_doc->left_lines_to_print <= 0) {
                printf("Documentul %s(0/%d) s-a tiparit cu imprimanta %d\n",
                       curr_printer->printer_doc->doc_name,
                       curr_printer->printer_doc->total_nr_of_lines,
                       curr_printer->printer_id);

                add_finished_doc_to_procesed_list(&curr_printer->printer_doc, processed_docs);

                delete_a_document_from_queue(docs_queue, curr_printer->printer_doc->doc_id);
            }
        }
        curr_printer = curr_printer->next;
    }
}


void show_current_status_of_printers_and_docs(Document* docs_queue, Printer* printers_list, Printed_docs* printed_docs) {
    Printed_docs* temp_printed = printed_docs;
    printf("Documentele tiparite:\n");
    while (temp_printed != NULL) {
        printf("Documentul %d: %s (%d/%d)\n",
               temp_printed->doc_id,
               temp_printed->doc_name,
               temp_printed->left_lines_to_print,
               temp_printed->total_nr_of_lines);
        temp_printed = temp_printed->next;
    }

    printf("\nCoada de documente neprocesate:\n");
    Document* temp_doc = docs_queue;
    while (temp_doc != NULL) {
        printf("Documentul %d: %s (%d/%d)\n",
               temp_doc->doc_id,
               temp_doc->doc_name,
               temp_doc->left_lines_to_print,
               temp_doc->total_nr_of_lines);
        temp_doc = temp_doc->next;
    }

    printf("\nLista de imprimante:\n");
    Printer* temp_printer = printers_list;
    while (temp_printer != NULL) {
        printf("Imprimanta %d: timp de imprimare %d\n",
               temp_printer->printer_id,
               temp_printer->time_to_print);
        temp_printer = temp_printer->next;
    }
}

void free_documents(Document** docs_queue) {
    Document* temp_doc;
    while (*docs_queue != NULL) {
        temp_doc = *docs_queue;
        *docs_queue = (*docs_queue)->next;
        free(temp_doc->doc_name);
        free(temp_doc);
    }
}

void free_printers(Printer** printers_list) {
    Printer* temp_printer;
    while (*printers_list != NULL) {
        temp_printer = *printers_list;
        *printers_list = (*printers_list)->next;
        free(temp_printer);
    }
}