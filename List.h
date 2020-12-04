#pragma once
#include "WorldTime.h"
struct DoubleList //описание узла списка
{
    WorldTime* data; //информационное поле
    DoubleList* next; //указатель на следующий элемент
    DoubleList* prev; //указатель на предыдущий элемент
};
DoubleList* head; //указатель на первый элемент списка
//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************
void AddList(bool tz,short z)
{
    DoubleList* node = new DoubleList; //создание нового элемента
    if (!tz) 
    {
        node->data = new WorldTime; //присвоение элементу значения
    }
    else
    {
        node->data = new WorldTime(z);
    }
    
    if (head == NULL) //если список пуст
    {
        node->next = node; //установка указателя next
        node->prev = node; //установка указателя prev
        head = node; //определяется голова списка
    }
    else
    {
        DoubleList* p = head;
        p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        p->prev = node;
    }
    std::cout << "\nЭлемент добавлен...\n\n";
}
//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************
void DeleteList(int number)
{
    if (head == NULL) { std::cout << "\nСписок пуст\n\n";  }
    else if (head->next==NULL)
    {
        head = NULL;
        delete head;
       
    }
    else
    {
        DoubleList* a = head;
        while (a->data->get_num() != number && a->next != NULL) { a = a->next; }
        if (a->data->get_num() != number)std::cout << "Не существует элемента под номером " << number << "\n";
        else
        {
            if (a == head) head = a->next;
            a->prev->next = a->next;
            a->next->prev = a->prev;
            delete a;
        }
    }
    std::cout << "\nЭлемент удален...\n\n";
}
//*************************ВЫВОД СПИСКА*************************
void PrintList()
{
    if (head == NULL) std::cout << "\nСписок пуст\n\n";
    else
    {
        DoubleList* a = head;
        std::cout << "\nЭлементы списка: ";
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
    if (head == NULL) std::cout << "\nСписок пуст\n\n";
    else
    {

        DoubleList* a = head;
        do
        {

            a->data->print_f();
            a = a->next;
        } while (a != head); std::cout << "\nСписок записан в файл\n";
    }
}

void Compare_country_time(unsigned short n1, unsigned short n2)
{
    if (head == NULL) { std::cout << "\nСписок пуст\n\n"; }
    else if (head->next == NULL)
    {
        std::cout << "Добавьте хотя бы 2 элемента для сравнения\n";
    }
    else
    {
        DoubleList* a = head;
        DoubleList* b = head;
        while (a->data->get_num() != n1 && a->next != NULL) { a = a->next; }
        while (b->data->get_num() != n2 && b->next != NULL) { b = b->next; }
        if (a->data->get_num() != n1)std::cout << "Не существует элемента под номером " << n1 << "\n";
        else if (b->data->get_num() != n2)std::cout << "Не существует элемента под номером " << n2 << "\n";
        else
        {
            std::cout << "Разница во времени между выбраными странами " << a->data->compare_country_time(*b->data) << " часа(ов)\n";
        }
    }
}