#ifndef STRUCTS_H
#define STRUCTS_H

#endif // STRUCTS_H
#define N 100

#include<iostream>

using namespace std;

class stack{
private:

    int mas[N];
    int uS = -1;
    //только для работы с помятью ;)
    int S = N;

public:
    //создание массива данных

    //без указания максимальной длинны стека в конструкторе


    //добавление в стек элемента
    int push(int elem){
        if (uS == S - 1)
            return 1;
        mas[++uS] = elem;
        return 0;
    }

    //проверка на пустоту
    int isEmpty(){
        if (uS == -1)
            return 1;
        else
            return 0;
    }

    //узнать индекс верхушки
    int len(){
        return uS + 1;
    }


    //изымание из стека элемента
    int pop(){
        if (uS < 0)
        {
            cout << "ERROR" << endl;
            return 0;
        }
        return mas[uS--];
    }

    //очищение стека
    int clean(){
        uS = -1;
        return 0;
    }

};

//круговая модель очереди
class queue{
private:
    int uL = -1;
    int uR = -1;
    int S = N;
    int mas[N];
public:


    //
    int inp(){
        cout <<"This is edges: " <<  uL << " " << uR << endl;
        return 0;
    }
    //добавление в очередь
    int push(int elem){
        if (uL == (uR + 1) % S)
            return 1;
        if (uL == uR){
            uL = 70;
            uR = 70;
        }

            uR += 1;
            uR %= S;

        mas[uR] = elem;
        return 0;
    }

    //проверка на пустоту очереди
    int isEmpty(){
        if (uL == -1)
            return 1;
        else
            return 0;
    }
    int len(){
        return (uR - uL + 1 + S) % S;
    }

    //удаление элемента из очереди
    int pop(){
        int elem;
        if (uL == uR){
            if (uL == -1){
                cout << "ERROR" << endl;
                return 0;
            }
            elem = mas[uL];
            uL = uR = -1;

        }
        else{
            elem = mas[uL];
            uL = (uL + 1) % S;
        }
        return elem;
    }

    //очищение очереди
    int clean(){
        uL = uR = -1;
        return 0;
    }

    //печать с удалением
    int printQ(){
        while (!this->isEmpty()){
            int current;
            current = this->pop();
            cout << current << " ";
        }
        cout << endl;
        return 0;
    }
};

//дек
class deque
{
private:
    int SIZE = N;
    int storage[N], begin = SIZE / 2 - 1, end = SIZE / 2;
public:
    void pushL(int elem)
    {


            if ((end - begin + 1 + SIZE) % SIZE == SIZE - 1)
                    cout << "Erorr, cant push" << endl;
             else{
                storage[begin] = elem;
                begin = (begin - 1 + SIZE) % SIZE;
        }
    }
    void pushR(int elem)
    {
        if ((end - begin + 1 + SIZE) % SIZE == SIZE - 1)
                cout << "Erorr, cant push" << endl;
        else
        {
            storage[end] = elem;
            end = (end + 1) % SIZE;
        }
    }
    int popL()
    {
        if (begin != end)
        {
            begin++;
            return storage[begin];
        }
        else printf("Error! Deque is empty.");
    }
    int popR()
    {
        if (begin != end)
        {

            end = (end - 1 + SIZE) % SIZE ;
            return storage[end];
        }
        else printf("Error! Deque is empty.");
    }
    int deqlenght()
    {
        return end - begin;
    }
    void deqclear()
    {
        begin = SIZE/2;
        end = SIZE/2;
    }
    void deqprint()
    {
        if ((end - begin) != 0)
            for (int i = begin + 1; i < end; i++)
                printf("%d ", storage[i]);
        else printf("Error! Deque is empty.");
    }
};
typedef basic_istream<int> istream;
//односвязный список
class list{

private :

    //информационное звено списка
    struct Node{
        int Data;
        Node *Next;
    };

    //голова списка
    Node *Head = NULL;

public:

   //создание N элементов списка и заполнение нулями
    int Create(int n)
    {
        for ( int i = 0; i < n; i++){
            Node *Current = new Node;
            if (Head == NULL){
                Head = Current;
                Current->Next = NULL;
                Current->Data = 0;
            }
            else{
                Current->Next = new Node;
                Current = Current->Next;
                Current->Next = NULL;

                Current->Data = 0;
            }
        }

        return 0;
    }

    //получить голову списка
    Node *GetHead(){
        return Head;
    }

    //вставить после n-ного элемента
    //можно использовать для инициализации списка в цикле, начиная с -1
    int Add(int n, int Data){
        int i = 0;//считчик текущего элемента

        //Если создаем первый элемент в списке,то переназначаем голову и создаем первую ноду
        Node *Current = Head;
        if (Current == NULL){
            Head = Current;
            Current->Next = NULL;
            Current->Data = Data;
            return 0;
        }

        //если элемента с таким номером не существует, нода будет добавлена в конец
        while ((i < n)&&(Current->Next != NULL)){
            i++;
            Current = Current->Next;

        }
        //пришли к n-ному элементу, либо к последнему
        Node *NewEl = new Node;
        NewEl->Next = Current->Next;
        NewEl->Data = Data;
        Current->Next = NewEl;
        return 0;

    }

    //заполнить поле Дата в текущей ноде
    int Fill(Node *Current, int Data){
        Current->Data = Data;
    }

    //очистка памяти листа
    int Clear(){
        Node *Current = Head;
        while (Head != NULL){
               Current = Head;
               Head = Head->Next;
               delete Current;
        }
    }
};
