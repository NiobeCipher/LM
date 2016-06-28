#include "Pich.h"

struct mDate
{
    int dd,mm,yyyy;
};

struct Jarvis
{
    int b_id;
    char b_title[50];
    char b_genre[20];
    char b_author[20];
    int s_id;
    char s_name[20];
    int record;
    struct mDate issued;
    struct mDate due;
}b[500],s[500],is[500];

