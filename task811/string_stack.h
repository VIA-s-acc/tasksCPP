#include <cstring>

class stack_string {
public:
    
    bool find(const char* str);
    stack_string();
    stack_string(const char* str);
    stack_string(const stack_string& other);
    ~stack_string();


    void push(const char* str);
    const char* pop();
    const char* peek() const;
    
    stack_string operator+(const char* str) const;
    stack_string& operator=(const stack_string& other);
    stack_string& operator+=(stack_string& other);
    stack_string operator+(stack_string& other) const;
    void operator-(const char* & res);
    
    void print() const;
    operator char* () const;
    int length() const;
private:

    struct Node {
        const char* data;
        Node* next;
        Node(const char* str, Node* ptr = nullptr) :data(str), next(ptr) {
        }
        };
    Node* top;
    char* pop_data;
    int size;
};