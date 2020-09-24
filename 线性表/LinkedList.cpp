#include<stdio.h>
#include<stdlib.h>
/**
 * ��ͷ���ĵ������ʵ�� 
 * 
 */
typedef struct Node{
    int data;
    struct Node* next;// ָ��
    
}Node, *LinkedList;
// ��ʼ��
void Init(LinkedList &list){
    list = NULL;
}
// β�巨���������
bool Insert(LinkedList& list, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(!list){// ��� ͷΪ NULL���Ͱ����ݸ�ͷ
        list = temp;
    }else{// ͷ��ΪNUll�������ӵ�β�ڵ�
        Node* p = list;
        while(p->next){// �ҵ�β�ڵ�
            p = p->next;
        }
        p->next = temp;// ���ӵ�β�ڵ�
    }   
    return true;
}
// ͷ�巨���������
bool HeadInsert(LinkedList& list, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    // ���ڵ����ӵ�ͷǰ�棬���ͷΪNULL����Ҳ�������
    temp->next = list;
    list = temp;
    return true;
}
// �ҵ���i���ڵ�
Node* GetElem(LinkedList& list, int index){
    if(index < 1) return NULL;// index��Ч
    Node* p = list;
    for(int i = 1; i < index && p; i++){// �ҵ���index���ڵ㣬ֱ��pΪNULL
        p = p->next;
    }
    return p;// ���ص�index���ڵ㣬���index > len����βNULL
}
// ɾ��һ���ڵ�
bool Delete(LinkedList& list, int index, int& data){
    if(index <= 0 || !list) return false;
    if(index == 1){// ���Ҫɾ��ͷ�ڵ㣬��Ҫ����ͷ���Ȼ��ɾ��
        Node* del = list;
        list = list->next;// ��ͷ�ڵ����
        data = del->data;// ��¼Ҫɾ����ֵ
        free(del);
        return true;
    }
    Node* p = GetElem(list, index - 1);// ��ȡ��Ҫɾ����Ԫ��
    if(p){// �������NULL
        Node* del = p->next;
        p->next = del->next;
        data = del->data;// ��¼Ҫɾ����ֵ
        free(del);
        return true;
    }
    return false;
}
// ��ȡ������
int GetLen(LinkedList list){
    int i = 0;
    while(list){
        i++;
        list = list->next;
    }
    return i;
}
// ��ͷ��β�����������
void Show(LinkedList list){
    printf("����(%d):  ", GetLen(list));
    while(list){
        printf("%d,", list->data);
        list = list->next;
    }
    printf("\n");
}


int main(){

    
    LinkedList head = (LinkedList)malloc(sizeof(Node));// ���������ͷ��㣨Ҳ���Ǵ��������ˣ�
    Init(head);
    Insert(head, 3);
    Insert(head, 4);
    Show(head);
    int x;
    if(Delete(head, 1, x)){
        printf("ɾ���ɹ�!");
    }else{
        printf("ɾ��ʧ��!");
    }
    Show(head);

    Insert(head, 5);
    Insert(head, 6);
    HeadInsert(head, 7);
    Show(head);
    if(Delete(head, 3, x)){
        printf("ɾ���ɹ�!");
    }else{
        printf("ɾ��ʧ��!");
    }
    Show(head);

    system("pause");
    return 0;
}
