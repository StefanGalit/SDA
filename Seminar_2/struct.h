

#ifndef SEMINAR_2_STRUCT_H
#define SEMINAR_2_STRUCT_H
typedef struct Document {
    int doc_id;
    char* doc_name;
    int total_nr_of_lines;
    int left_lines_to_print;
    struct Document* next;
} Document;

typedef struct Printer {
    int printer_id;
    int time_to_print;
    Document* printer_doc;
    struct Printer* next;
} Printer;

typedef struct {
    Document* front;
    Document* rear;
} Queue;

typedef struct Printed_docs {
    int doc_id;
    char* doc_name;
    int total_nr_of_lines;
    int left_lines_to_print;
    struct Printed_docs* next;
} Printed_docs;

void add_new_doc_in_queue(Document** queue, Queue* refr, int id, char* name, int total_lines, int left_lines);


void delete_a_document_from_queue(Document** refr, int id);

Printer* initialize_printer(int id, int time_to_print);

void add_printer(Printer** printer_list, int id, int time_to_print);

void delete_printer(Printer** printers_list, int printer_id);

Printer* pop_printer(Printer** printers_refr);

Document* pop_document(Queue* element);

void distribute_documents(Document** docs_queue, Queue* element, Printer** printers_list);

int is_printed_docs(Document* docs_queue);

void add_finished_doc_to_procesed_list(Document** printers_doc, Printed_docs** processed_docs);

void update_printers_and_docs_status(Printer** printers_list, Document** docs_queue, Printed_docs** processed_docs);

void show_current_status_of_printers_and_docs(Document* docs_queue, Printer* printers_list, Printed_docs* printed_docs);

void free_documents(Document** docs_queue);

void free_printers(Printer** printers_list);



#endif
