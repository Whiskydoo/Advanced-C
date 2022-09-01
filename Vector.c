#include<stdio.h>
#include<stdlib.h>
//Thiết lập kiểu dữ liệu cho mỗi Node dữ liệu

typedef struct node{
    int data;
    struct node *next;
}node;

//Thiết lập kiểu dữ liệu cho Vector gồm có phần tử đầu và cuối để dễ quản lý

typedef struct{
    struct node *head;
    struct node *tail;
}list;

// Hàm khởi tạo Vector

list l;
void Initial()
{
    l.head = NULL;
    l.tail = NULL;
}
//Hàm tạo Node

struct node *creatNode(int data)
{
    // Cấp phát bộ nhớ cho Node cần tạo

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    
    //Kiểm tra xem Node vừa tạo có được không vì có thể máy tính hết bộ nhớ và không thể được

    if(temp==NULL)
    {
        printf("Memorry allocation is unsuccessful");
        exit(0);
    }

    //Thực hiện gán dữ liệu cho Node

    else
    {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

//Hàm thêm một phần tử mới vào vị trí sau cùng

void push_back(int data)
{
    struct node *temp = creatNode(data);
    //Nếu danh sách rỗng thì HEAD == NULL ta gán phần tử đầu tiên của vector là temp
    if(l.head == NULL)
    {
        l.head = temp;
        l.tail = temp;
    }
    else
    {
        l.tail->next = temp;
        l.tail = temp;
    }
}

//Hàm giải phóng bộ nhớ và khởi tạo lại vector

void clear()
{
    node* p = l.head;
    node* q = l.head;
    if (l.head == NULL)
    {
        return;
    }
    while(p->next != NULL)
    {
        p = p->next;
        free(q);
        q = p;
    }
    free(q);
    Initial();
}

//Hàm assign(size, value) khởi tạo 1 mảng có số lượng SIZE các phần tử có giá trị VALUE

void assignVector(int size, int value)
{
    clear();
    Initial();
    for(int i = 0; i < size; i++)
    {
        push_back(value);
    }
}

// Hàm xóa đi phần tử cuối cùng của vector

void pop_back()
{
    //Không có phần tử trong danh sách.
    if(l.head==NULL)
    {
        printf("!!ERROR: There is not any element in linked-list:");
        return;
    }
    //Khi danh sách chỉ còn 2 phần tử
    else if (l.head->next == l.tail)
    {
        free(l.tail);
        l.tail = l.head;
    }
    else if (l.head == l.tail)
    {
        free(l.head);
        Initial();
    }
    else
    {
        struct node *p = l.head;
        while(p->next!=l.tail)
        {
            p = p->next;
        }
        p->next = NULL;
        free(l.tail);
        l.tail = p;
    }
    
}

//Hàm insert(position, value) chèn phần từ mới có giá trị VALUE vào sau vị trí được chỉ định POSITION.

void insertVector(int position, int value)
{
    //Check size của danh sách
    int sizeOfLinkedList = 0;
    struct node *p = l.head;
    while(p!=NULL)
    {
        sizeOfLinkedList++;
        p = p->next;
    }
    //Check POSITION có nằm trong phạm vi index của danh sách không?

    if(position >= sizeOfLinkedList)
    {
        printf("\n!!ERROR: Out of range of Linked-list\n");
        return;
    }
    else if(position == sizeOfLinkedList - 1)
    {
        push_back(value);
    }
    else
    {
        p = l.head;
        for(int i = 0; i < position; i++ )
        {
            p = p->next;
        }
        node *temp = creatNode(value);
        temp->next = p->next;
        p->next = temp;
    }

}

//Hàm in ra giá trị của vector

void printVector()
{
    struct node* p = l.head;
    if(p == NULL)
    {
        printf("\nThis Vector is empty!!\n");
    }
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

//Hàm lấy ra phần tử đầu tiên của vector

void front()
{
    if(l.head==NULL)
    {
        printf("\nVector is empty: \n");
    }
    printf("\nFirst element of vector: %d\n", l.head->data);
}

//Hàm lấy ra phần tử cuối cùng của vector

void back()
{
    if(l.head==NULL)
    {
        printf("\nVector is empty: \n");
    }
    printf("\nLast element of vector: %d\n", l.tail->data);
}

//Hàm lấy ra phần tử thứ n của vector đếm từ 0

void at(int position)
{
    node* p = l.head;
    int i = 0;
    while(i != position)
    {
        p = p->next;
        i++;
    }
    printf("\nElement at position %d is: %d ", position, p->data);
}

//Hàm cho biết số lượng phần tử của vector

void size()
{
    node* p = l.head;
    int i = 0;
    while(p != NULL)
    {
        p = p->next;
        i++;
    }
    printf("\nSize of vector is  %d", i);
}

void empty()
{
    if(l.head==NULL)
        printf("\nVector is empty\n");
    else
        printf("\nVector is not empty\n");
}
typedef struct{
    void (*push_back)(int);
    void (*printVector)();
    void (*assignVector)(int, int);
    void (*pop_back)();
    void (*insertVector)(int, int);
    void (*front)();
    void (*back)();
    void (*at)(int);
    void (*size)();
    void (*clear)();
    void (*empty)();
}vector;
void Init_Vector(vector *vector_name)
{
    vector_name->push_back = push_back;
    vector_name->printVector = printVector;
    vector_name->assignVector = assignVector;
    vector_name->pop_back = pop_back;
    vector_name->insertVector = insertVector;
    vector_name->front = front;
    vector_name->back = back;
    vector_name->at = at;
    vector_name->size = size;
    vector_name->clear = clear;
    vector_name->empty = empty;
}
#define vector(type_name) \
vector type_name; \
Init_Vector(&type_name); 

void main()
{
    vector(A);
    A.assignVector(4, 10);
    printf("\nAssign: ");
    A.printVector();
    clear();
    printf("\nVector after being cleared:");
    A.printVector();
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    printf("Vector after pushing back: ");
    A.printVector();
    A.pop_back();
    printf("\nVector after popping back the last element: ");
    A.printVector();
    A.insertVector(1, 100);
    printf("\nAfter inserting: ");
    A.printVector();
    A.front();
    A.back();
    A.at(1);
    A.size();
    A.empty();
    A.clear();
    printf("\nClear vector: \n");
    A.printVector();
}