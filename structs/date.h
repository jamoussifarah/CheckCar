#ifndef DATE_H
#define DATE_H

typedef struct {
    int day;
    int month;
    int year;
} Date;




Date new_date(int day, int month, int year);
int get_year(const Date *date);
int get_month(const Date *date);
int get_day(const Date *date);
const char *get_month_string(const Date *date);
void print_date(const Date *date);

#endif