#include "struct.h"
#include <stdio.h>


int main() {
    Document* docs_queue = NULL;
    Queue element;
    element.front = NULL;
    element.rear = NULL;

    Printer* printers_list = NULL;
    Printed_docs* processed_docs = NULL;

    add_new_doc_in_queue(&docs_queue, &element, 1, "Document1", 20, 20);
    add_new_doc_in_queue(&docs_queue, &element, 2, "Document2", 15, 15);
    add_new_doc_in_queue(&docs_queue, &element, 3, "Document3", 25, 25);

    add_printer(&printers_list, 1, 3);
    add_printer(&printers_list, 2, 2);
    add_printer(&printers_list, 3, 4);

    while (!is_printed_docs(docs_queue)) {
        distribute_documents(&docs_queue, &element, &printers_list);
        update_printers_and_docs_status(&printers_list, &docs_queue, &processed_docs);
        show_current_status_of_printers_and_docs(docs_queue, printers_list, processed_docs);
    }

    free_documents(&docs_queue);
    free_printers(&printers_list);

    return 0;
}
