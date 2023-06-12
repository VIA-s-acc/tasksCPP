#include "string_stack.h"
#include <iostream>
//конструкторы
stack_string::stack_string() : top(nullptr), size(0) {}

stack_string::stack_string(const char* str) : top(nullptr), size(0) {
    push(str);
}

stack_string::stack_string(const stack_string& other) : top(nullptr), size(0) {
    *this = other;
}

//деструкторы
stack_string::~stack_string() {
Node* temp;
while (top != nullptr) {
    temp = top;
    top = top->next;
    delete(temp);
    }
}
//положить элемент в стэк
void stack_string::push(const char* str) {
    if(top!=nullptr){
    Node* temp = top;
    top = new Node(str);
    top->next = temp;
    }
    else{
    top = new Node(str);}
    size++;
}
//выкинуть элемент со стека и вернуть его
const char* stack_string::pop() {
    if (top == nullptr) {
    return nullptr;
    }
    const char* str = top->data;
    Node *temp = top;
    top = top->next;
    size--;
    delete temp;
    return str;
}
//find


bool stack_string::find(const char* str) {
    Node* currentNode = top;
    while (currentNode != nullptr) {
        if (strcmp(currentNode->data, str) == 0) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}


//вернуть элемент с вершины стэка

const char* stack_string::peek() const {
    if (top == nullptr) {
        return nullptr;
    }
    return top->data;
}

//оператор присваивания
stack_string& stack_string::operator=(const stack_string& other) {
    if (this != &other) {
    while (top != nullptr) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    Node* currentNode = other.top;
    Node* lastNode = nullptr;
    while (currentNode != nullptr) {
        if (lastNode == nullptr) {
            top = new Node(currentNode->data);
            lastNode = top;
        } 
        else {
            lastNode->next = new Node(currentNode->data);
            lastNode = lastNode->next;
        }
        size++;
        currentNode = currentNode->next;
    }
}
return *this;
}

//оператор стэк+строка
stack_string stack_string::operator+(const char* str) const
{
    stack_string result = *this;
    result.push(str);
    return result;
}
//оператор стэк+=стэк
stack_string& stack_string::operator+=(stack_string& other) 
{
    while (other != nullptr) {
        push(other.top->data);
    }    
return *this;
}
//оператор стэк+стэк
stack_string stack_string::operator+(stack_string& other) const {
    stack_string result = *this;
    result += other;
    return result;
}
//оператор стэк-строка | удаляет элемент с вершины стэка и записывает в char* data
void stack_string::operator-(const char* & data) {
    data = pop();
}

//вывести стэк

void stack_string::print() const {
    Node* currentNode = top;
    while (currentNode != nullptr) {
        std::cout<<(currentNode->data) << " -> ";
        currentNode = currentNode->next;
    }
    std::cout<<nullptr<<std::endl;
}

//приведение типов
stack_string::operator char* () const {
    if (top == nullptr) {
        return nullptr;
    }
    int totalLength = size - 1; // 
    Node* currentNode = top;
    while (currentNode != nullptr) {
        totalLength += strlen(currentNode->data);
        currentNode = currentNode->next;
    }
    char* result = new char[totalLength + 1];
    result[0] = '\0';
    currentNode = top;
    while (currentNode != nullptr) {
        strcat(result, currentNode->data);
        if (currentNode->next != nullptr) {
            strcat(result, "\n");
        }
        currentNode = currentNode->next;
    }
return result;
}

//вернуть длину стэка
int stack_string::length() const {
    return size;
}

