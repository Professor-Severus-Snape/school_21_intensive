#ifndef SRC_STATE_SORT_H_
#define SRC_STATE_SORT_H_


struct my_struct {
    int year, month, day, hour, minutes, seconds, status, code;
};


int get_date(int *day, int *month, int *year, int *error, FILE *pfile);

struct my_struct read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);


FILE* file_init(char *filename, int *error);
void file_close(FILE* log_file);
int get_menu_num();
char *input_from_user();
void output_file(FILE *pfile);

int compare_two_num(int num1, int num2);
int compare_two_record(struct my_struct *record1, struct my_struct *record2);
void sort(FILE *pfile);
struct my_struct input_record_from_cmd();


#endif
