#pragma once
#include "WorldTime.h"
struct DoubleList //�������� ���� ������
{
    WorldTime* data; //�������������� ����
    DoubleList* next; //��������� �� ��������� �������
    DoubleList* prev; //��������� �� ���������� �������
};
DoubleList* head; //��������� �� ������ ������� ������
//**********************���������� ��������**********************
void AddList(bool tz,short z)
{
    DoubleList* node = new DoubleList; //�������� ������ ��������
    if (!tz) 
    {
        node->data = new WorldTime; //���������� �������� ��������
    }
    else
    {
        node->data = new WorldTime(z);
    }
    
    if (head == NULL) //���� ������ ����
    {
        node->next = node; //��������� ��������� next
        node->prev = node; //��������� ��������� prev
        head = node; //������������ ������ ������
    }
    else
    {
        DoubleList* p = head;
        p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        p->prev = node;
    }
    std::cout << "\n������� ��������...\n\n";
}
//***********************�������� ��������***********************
void DeleteList(int number)
{
    if (head == NULL) { std::cout << "\n������ ����\n\n";  }
    else if (head->next==NULL)
    {
        head = NULL;
        delete head;
       
    }
    else
    {
        DoubleList* a = head;
        while (a->data->get_num() != number && a->next != NULL) { a = a->next; }
        if (a->data->get_num() != number)std::cout << "�� ���������� �������� ��� ������� " << number << "\n";
        else
        {
            if (a == head) head = a->next;
            a->prev->next = a->next;
            a->next->prev = a->prev;
            delete a;
        }
    }
    std::cout << "\n������� ������...\n\n";
}
//*************************����� ������*************************
void PrintList()
{
    if (head == NULL) std::cout << "\n������ ����\n\n";
    else
    {
        DoubleList* a = head;
        std::cout << "\n�������� ������: ";
        do
        {
            a->data->print();
            a = a->next;
        } while (a != head); std::cout << "\n\n";
    }
}
void PrintList_to_f()
{
    std::ofstream file("Countries.txt");
    file << "";
    file.close();
    if (head == NULL) std::cout << "\n������ ����\n\n";
    else
    {

        DoubleList* a = head;
        do
        {

            a->data->print_f();
            a = a->next;
        } while (a != head); std::cout << "\n������ ������� � ����\n";
    }
}

void Compare_country_time(unsigned short n1, unsigned short n2)
{
    if (head == NULL) { std::cout << "\n������ ����\n\n"; }
    else if (head->next == NULL)
    {
        std::cout << "�������� ���� �� 2 �������� ��� ���������\n";
    }
    else
    {
        DoubleList* a = head;
        DoubleList* b = head;
        while (a->data->get_num() != n1 && a->next != NULL) { a = a->next; }
        while (b->data->get_num() != n2 && b->next != NULL) { b = b->next; }
        if (a->data->get_num() != n1)std::cout << "�� ���������� �������� ��� ������� " << n1 << "\n";
        else if (b->data->get_num() != n2)std::cout << "�� ���������� �������� ��� ������� " << n2 << "\n";
        else
        {
            std::cout << "������� �� ������� ����� ��������� �������� " << a->data->compare_country_time(*b->data) << " ����(��)\n";
        }
    }
}