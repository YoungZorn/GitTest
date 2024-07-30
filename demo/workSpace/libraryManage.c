//
// Created by YoungZorn on 2024/6/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ͼ����Ϣ�ṹ��
typedef struct {
    char book_name[100];
    char author_name[100];
    char category[20];
    char publisher[100];
    char publish_date[20];
    float price;
    char status[10]; // "�ѽ�"��"�ѻ�"
    char borrower_name[100];
    char borrower_gender[10];
    char borrower_id[20];
} Book;

// ��������
void add_book();
void display_books();
void search_by_book_name();
void search_by_author_name();
void delete_returned_books();
void modify_borrowed_books();
void save_books();
void load_books();

// ȫ�ֱ���
Book books[100];
int book_count = 0;
const char *filename = "books.dat";

int main() {
    int choice;
    load_books();

    while (1) {
        printf("\nͼ����Ϣ����ϵͳ\n");
        printf("1. ͼ����Ϣ¼��\n");
        printf("2. ͼ����Ϣ���\n");
        printf("3. ��ѯ����\n");
        printf("4. ͼ����Ϣɾ��\n");
        printf("5. ͼ����Ϣ�޸�\n");
        printf("6. �˳�\n");
        printf("����������ѡ��(1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("1. ��������ѯ\n");
                printf("2. ����������ѯ\n");
                printf("����������ѡ��(1-2): ");
                int sub_choice;
                scanf("%d", &sub_choice);
                if (sub_choice == 1) {
                    search_by_book_name();
                } else if (sub_choice == 2) {
                    search_by_author_name();
                } else {
                    printf("��Чѡ��\n");
                }
                break;
            case 4:
                delete_returned_books();
                break;
            case 5:
                modify_borrowed_books();
                break;
            case 6:
                save_books();
                printf("�˳�ϵͳ��\n");
                exit(0);
                break;
            default:
                printf("��Чѡ��\n");
                break;
        }
    }

    return 0;
}

void add_book() {
    if (book_count >= 100) {
        printf("ͼ��洢������\n");
        return;
    }

    Book new_book;
    printf("����������: ");
    scanf("%s", new_book.book_name);
    printf("������������: ");
    scanf("%s", new_book.author_name);
    printf("����������: ");
    scanf("%s", new_book.category);
    printf("��������浥λ: ");
    scanf("%s", new_book.publisher);
    printf("���������ʱ��: ");
    scanf("%s", new_book.publish_date);
    printf("������۸�: ");
    scanf("%f", &new_book.price);
    printf("���������״̬(�ѽ�/�ѻ�): ");
    scanf("%s", new_book.status);
    if (strcmp(new_book.status, "�ѽ�") == 0) {
        printf("���������������: ");
        scanf("%s", new_book.borrower_name);
        printf("������������Ա�: ");
        scanf("%s", new_book.borrower_gender);
        printf("�����������ѧ��: ");
        scanf("%s", new_book.borrower_id);
    } else {
        strcpy(new_book.borrower_name, "");
        strcpy(new_book.borrower_gender, "");
        strcpy(new_book.borrower_id, "");
    }

    books[book_count++] = new_book;
    printf("ͼ����Ϣ��¼�롣\n");
}

void display_books() {
    for (int i = 0; i < book_count; i++) {
        printf("\n����: %s\n", books[i].book_name);
        printf("������: %s\n", books[i].author_name);
        printf("�����: %s\n", books[i].category);
        printf("���浥λ: %s\n", books[i].publisher);
        printf("����ʱ��: %s\n", books[i].publish_date);
        printf("�۸�: %.2f\n", books[i].price);
        printf("����״̬: %s\n", books[i].status);
        if (strcmp(books[i].status, "�ѽ�") == 0) {
            printf("����������: %s\n", books[i].borrower_name);
            printf("�������Ա�: %s\n", books[i].borrower_gender);
            printf("������ѧ��: %s\n", books[i].borrower_id);
        }
        printf("\n");
    }
}

void search_by_book_name() {
    char book_name[100];
    printf("����������: ");
    scanf("%s", book_name);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].book_name, book_name) == 0) {
            printf("\n����: %s\n", books[i].book_name);
            printf("������: %s\n", books[i].author_name);
            printf("�����: %s\n", books[i].category);
            printf("���浥λ: %s\n", books[i].publisher);
            printf("����ʱ��: %s\n", books[i].publish_date);
            printf("�۸�: %.2f\n", books[i].price);
            printf("����״̬: %s\n", books[i].status);
            if (strcmp(books[i].status, "�ѽ�") == 0) {
                printf("����������: %s\n", books[i].borrower_name);
                printf("�������Ա�: %s\n", books[i].borrower_gender);
                printf("������ѧ��: %s\n", books[i].borrower_id);
            }
            found = 1;
            printf("\n");
        }
    }
    if (!found) {
        printf("δ�ҵ����������ͼ����Ϣ��\n");
    }
}

void search_by_author_name() {
    char author_name[100];
    printf("������������: ");
    scanf("%s", author_name);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].author_name, author_name) == 0) {
            printf("\n����: %s\n", books[i].book_name);
            printf("������: %s\n", books[i].author_name);
            printf("�����: %s\n", books[i].category);
            printf("���浥λ: %s\n", books[i].publisher);
            printf("����ʱ��: %s\n", books[i].publish_date);
            printf("�۸�: %.2f\n", books[i].price);
            printf("����״̬: %s\n", books[i].status);
            if (strcmp(books[i].status, "�ѽ�") == 0) {
                printf("����������: %s\n", books[i].borrower_name);
                printf("�������Ա�: %s\n", books[i].borrower_gender);
                printf("������ѧ��: %s\n", books[i].borrower_id);
            }
            found = 1;
            printf("\n");
        }
    }
    if (!found) {
        printf("δ�ҵ������������ͼ����Ϣ��\n");
    }
}

void delete_returned_books() {
    int i = 0;
    while (i < book_count) {
        if (strcmp(books[i].status, "�ѻ�") == 0) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;
        } else {
            i++;
        }
    }
    printf("�ѻ���ͼ����Ϣ��ɾ����\n");
}

void modify_borrowed_books() {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].status, "�ѽ�") == 0) {
            strcpy(books[i].status, "�ѻ�");
            strcpy(books[i].borrower_name, "");
            strcpy(books[i].borrower_gender, "");
            strcpy(books[i].borrower_id, "");
        }
    }
    printf("�ѽ��ͼ����Ϣ���޸�Ϊ�ѻ�״̬��\n");
}

void save_books() {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("�ļ�����ʧ�ܣ�\n");
        return;
    }
    fwrite(&book_count, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), book_count, file);
    fclose(file);
    printf("ͼ����Ϣ�ѱ��档\n");
}

void load_books() {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return; // �ļ������ڣ����Լ���
    }
    fread(&book_count, sizeof(int), 1, file);
    fread(books, sizeof(Book), book_count, file);
    fclose(file);
}
