//
// Created by YoungZorn on 2024/6/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 图书信息结构体
typedef struct {
    char book_name[100];
    char author_name[100];
    char category[20];
    char publisher[100];
    char publish_date[20];
    float price;
    char status[10]; // "已借"或"已还"
    char borrower_name[100];
    char borrower_gender[10];
    char borrower_id[20];
} Book;

// 函数声明
void add_book();
void display_books();
void search_by_book_name();
void search_by_author_name();
void delete_returned_books();
void modify_borrowed_books();
void save_books();
void load_books();

// 全局变量
Book books[100];
int book_count = 0;
const char *filename = "books.dat";

int main() {
    int choice;
    load_books();

    while (1) {
        printf("\n图书信息管理系统\n");
        printf("1. 图书信息录入\n");
        printf("2. 图书信息浏览\n");
        printf("3. 查询功能\n");
        printf("4. 图书信息删除\n");
        printf("5. 图书信息修改\n");
        printf("6. 退出\n");
        printf("请输入您的选择(1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("1. 按书名查询\n");
                printf("2. 按作者名查询\n");
                printf("请输入您的选择(1-2): ");
                int sub_choice;
                scanf("%d", &sub_choice);
                if (sub_choice == 1) {
                    search_by_book_name();
                } else if (sub_choice == 2) {
                    search_by_author_name();
                } else {
                    printf("无效选择！\n");
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
                printf("退出系统。\n");
                exit(0);
                break;
            default:
                printf("无效选择！\n");
                break;
        }
    }

    return 0;
}

void add_book() {
    if (book_count >= 100) {
        printf("图书存储已满！\n");
        return;
    }

    Book new_book;
    printf("请输入书名: ");
    scanf("%s", new_book.book_name);
    printf("请输入作者名: ");
    scanf("%s", new_book.author_name);
    printf("请输入分类号: ");
    scanf("%s", new_book.category);
    printf("请输入出版单位: ");
    scanf("%s", new_book.publisher);
    printf("请输入出版时间: ");
    scanf("%s", new_book.publish_date);
    printf("请输入价格: ");
    scanf("%f", &new_book.price);
    printf("请输入存在状态(已借/已还): ");
    scanf("%s", new_book.status);
    if (strcmp(new_book.status, "已借") == 0) {
        printf("请输入借书人姓名: ");
        scanf("%s", new_book.borrower_name);
        printf("请输入借书人性别: ");
        scanf("%s", new_book.borrower_gender);
        printf("请输入借书人学号: ");
        scanf("%s", new_book.borrower_id);
    } else {
        strcpy(new_book.borrower_name, "");
        strcpy(new_book.borrower_gender, "");
        strcpy(new_book.borrower_id, "");
    }

    books[book_count++] = new_book;
    printf("图书信息已录入。\n");
}

void display_books() {
    for (int i = 0; i < book_count; i++) {
        printf("\n书名: %s\n", books[i].book_name);
        printf("作者名: %s\n", books[i].author_name);
        printf("分类号: %s\n", books[i].category);
        printf("出版单位: %s\n", books[i].publisher);
        printf("出版时间: %s\n", books[i].publish_date);
        printf("价格: %.2f\n", books[i].price);
        printf("存在状态: %s\n", books[i].status);
        if (strcmp(books[i].status, "已借") == 0) {
            printf("借书人姓名: %s\n", books[i].borrower_name);
            printf("借书人性别: %s\n", books[i].borrower_gender);
            printf("借书人学号: %s\n", books[i].borrower_id);
        }
        printf("\n");
    }
}

void search_by_book_name() {
    char book_name[100];
    printf("请输入书名: ");
    scanf("%s", book_name);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].book_name, book_name) == 0) {
            printf("\n书名: %s\n", books[i].book_name);
            printf("作者名: %s\n", books[i].author_name);
            printf("分类号: %s\n", books[i].category);
            printf("出版单位: %s\n", books[i].publisher);
            printf("出版时间: %s\n", books[i].publish_date);
            printf("价格: %.2f\n", books[i].price);
            printf("存在状态: %s\n", books[i].status);
            if (strcmp(books[i].status, "已借") == 0) {
                printf("借书人姓名: %s\n", books[i].borrower_name);
                printf("借书人性别: %s\n", books[i].borrower_gender);
                printf("借书人学号: %s\n", books[i].borrower_id);
            }
            found = 1;
            printf("\n");
        }
    }
    if (!found) {
        printf("未找到相关书名的图书信息。\n");
    }
}

void search_by_author_name() {
    char author_name[100];
    printf("请输入作者名: ");
    scanf("%s", author_name);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].author_name, author_name) == 0) {
            printf("\n书名: %s\n", books[i].book_name);
            printf("作者名: %s\n", books[i].author_name);
            printf("分类号: %s\n", books[i].category);
            printf("出版单位: %s\n", books[i].publisher);
            printf("出版时间: %s\n", books[i].publish_date);
            printf("价格: %.2f\n", books[i].price);
            printf("存在状态: %s\n", books[i].status);
            if (strcmp(books[i].status, "已借") == 0) {
                printf("借书人姓名: %s\n", books[i].borrower_name);
                printf("借书人性别: %s\n", books[i].borrower_gender);
                printf("借书人学号: %s\n", books[i].borrower_id);
            }
            found = 1;
            printf("\n");
        }
    }
    if (!found) {
        printf("未找到相关作者名的图书信息。\n");
    }
}

void delete_returned_books() {
    int i = 0;
    while (i < book_count) {
        if (strcmp(books[i].status, "已还") == 0) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;
        } else {
            i++;
        }
    }
    printf("已还的图书信息已删除。\n");
}

void modify_borrowed_books() {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].status, "已借") == 0) {
            strcpy(books[i].status, "已还");
            strcpy(books[i].borrower_name, "");
            strcpy(books[i].borrower_gender, "");
            strcpy(books[i].borrower_id, "");
        }
    }
    printf("已借的图书信息已修改为已还状态。\n");
}

void save_books() {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("文件保存失败！\n");
        return;
    }
    fwrite(&book_count, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), book_count, file);
    fclose(file);
    printf("图书信息已保存。\n");
}

void load_books() {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return; // 文件不存在，忽略加载
    }
    fread(&book_count, sizeof(int), 1, file);
    fread(books, sizeof(Book), book_count, file);
    fclose(file);
}
