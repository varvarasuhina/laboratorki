#pragma warning(disable:4996)

#include <stdio.h>

#include <string.h>

#include <locale.h>

// функция чтения строк из файла в массив lines длиной n

void read(char lines[][100], int* n)

{

FILE* f1; // файловая переменная

char fname[100]; // имя файла

// открыть входной файл

strcpy(fname, "input.txt");

f1 = fopen(fname, "r");

if (f1 == NULL)

printf("Файл %s не был открыт!\n", fname);

else if (feof(f1))

printf("Файл %s пуст!\n", fname);

// если файл открыт успешно, считать данные в массив строк

else

{

(*n) = 0;

printf("\nСодержимое входного файла: \n");

while (fgets(lines[*n], 100, f1))

{

lines[*n][strlen(lines[*n]) - 1] = '\0';

printf("%s\n", lines[*n]);

(*n)++;

}

}

// закрыть входной файл

fclose(f1);

}

// функция записи заданных строк в файл из массива lines длиной n

void write(char lines[][100], int n)

{

FILE* f2; // файловая переменная

char fname[100]; // имя файла

int k; // счетчик цикла

// открыть выходной файл

strcpy(fname, "output.txt");

f2 = fopen(fname, "w");

if (f2 == NULL)

printf("Файл %s не был открыт!\n", fname);

// если файл открыт успешно, записать данные в выходной файл согласно условию

else

{

int cnt; cnt = 0; // количество символов в файле

printf("\nСодержимое выходного файла: \n");

for (k = 0; k < n; k++)

if (lines[k][0] == lines[k][strlen(lines[k]) - 1])

{

fprintf(f2, "%s\n", lines[k]);

printf("%s\n", lines[k]);

cnt += strlen(lines[k]);

}

printf("Запись в файл завершена!\n");

printf("Количество символов в файле: %d\n", cnt);

}

// закрыть выходной файл

fclose(f2);

}

int main()

{

system("chcp 1251");

char lines[100][100]; // массив строк

int n; // размер массива

n = 0;

read(lines, &n);

write(lines, n);

return 0;

}
