//#include <iostream>
//using namespace std;
//template <typename T>
// hey
//class Node
//{
//    T data;         
//    Node* next;
//public:
//    Node(T val)      
//    {
//        data = val;
//        next = nullptr;
//    }
//    template <typename U>  
//    friend class LinkedList;
//};
//template <typename T>
//class LinkedList
//{
//    Node<T>* head;   
//public:
//    LinkedList()
//    {
//        head = nullptr;
//    }
//    ~LinkedList()
//    {
//        if (head == nullptr)
//            return; 
//
//        Node<T>* temp = head;
//        do
//        {
//            Node<T>* nextNode = temp->next;  
//            delete temp;                     
//            temp = nextNode;                 
//        } while (temp != head);
//
//        head = nullptr; 
//    }
//    LinkedList(const LinkedList& other)
//    {
//        if (other.head == nullptr)
//        {
//            head = nullptr; 
//            return;
//        }
//        Node<T>* temp = other.head;
//        head = new Node<T>(temp->data); 
//        Node<T>* current = head;        
//        temp = temp->next;
//        while (temp != other.head)
//        {
//            Node<T>* newNode = new Node<T>(temp->data); // Create a new node with the copied data
//            current->next = newNode;                    
//            current = newNode;                      
//            temp = temp->next;
//        }
//        current->next = head;
//    }
//
//    void insertAtHead(T val)  
//    {
//        Node<T>* n = new Node<T>(val);
//        if (head == NULL)
//        {
//            n->next = n;
//            head = n;
//            return;
//        }
//        Node<T>* temp = head;
//        while (temp->next != head)
//        {
//            temp = temp->next;  
//        }
//        temp->next = n;
//        n->next = head;
//        head = n;
//    }
//    void insertAtTail(T val)  
//    {
//        if (head == NULL)
//        {
//            insertAtHead(val);
//            return;
//        }
//        Node<T>* temp = head;
//        Node<T>* n = new Node<T>(val);  
//        while (temp->next != head)
//        {
//            temp = temp->next;  
//        }
//        temp->next = n;
//        n->next = head;
//    }
//    void display()
//    {
//        if (head == nullptr)
//        {
//            cout << "List is empty" << endl;
//            return;
//        }
//        Node<T>* temp = head;
//        do
//        {
//            cout << temp->data << " "; 
//            temp = temp->next;
//        } while (temp != head);
//        cout << endl;
//    }
//    bool deleteAtHead()
//    {
//        if (head == nullptr)
//            return false;
//        Node<T>* temp = head;
//        while (temp->next != head)
//        {
//            temp = temp->next;
//        }
//        Node<T>* toDelete = head;
//        if (head == head->next)
//        {
//            head = nullptr;  
//        }
//        else
//        {
//            head = head->next;
//            temp->next = head;
//        }
//        delete toDelete;
//        return true;
//    }
//    bool deleteAtTail()
//    {
//        if (head == nullptr)
//        {
//            return false;
//        }
//        Node<T>* temp = head;
//        while (temp->next->next != head)
//        {
//            temp = temp->next;
//        }
//        Node<T>* toDelete = temp->next;
//        temp->next = head;
//        delete toDelete;
//        return true;
//    }
//    bool insertAfter(T value, T key)
//    {
//        if (head == nullptr)
//            return false;  
//        Node<T>* temp = head;
//        do
//        {
//            if (temp->data == key) 
//            {
//                Node<T>* newNode = new Node<T>(value);
//                newNode->next = temp->next;  
//                temp->next = newNode;  
//                return true;
//            }
//            temp = temp->next;
//        } while (temp != head);  
//
//        return false;
//    }
//    bool insertBefore(T value, T key)
//    {
//        if (head == nullptr)
//            return false;  
//        Node<T>* temp = head;
//        Node<T>* prev = nullptr;
//        if (head->data == key)
//        {
//            Node<T>* newNode = new Node<T>(value);
//            while (temp->next != head)  
//            {
//                temp = temp->next;
//            }
//            newNode->next = head;  
//            temp->next = newNode;  
//            head = newNode;         
//            return true;
//        }
//        do
//        {
//            prev = temp;            
//            temp = temp->next;      
//            if (temp->data == key)  
//            {
//                Node<T>* newNode = new Node<T>(value);
//                newNode->next = temp;    
//                prev->next = newNode;    
//                return true;
//            }
//        } while (temp != head);  
//
//        return false; 
//    }
//    bool deleteBefore(T key)
//    {
//        if (head == nullptr || head->next == head)
//            return false; 
//        Node<T>* temp = head;
//        Node<T>* prev = nullptr;
//        Node<T>* beforePrev = nullptr;
//        if (head->data == key)
//        {
//            while (temp->next != head)
//            {
//                beforePrev = prev;
//                prev = temp;
//                temp = temp->next;
//            }
//            if (prev == head) 
//                return false;
//            prev->next = head;
//            delete beforePrev;
//            return true;
//        }
//
//        do
//        {
//            beforePrev = prev;
//            prev = temp;
//            temp = temp->next;
//            if (temp->data == key)
//            {
//                if (beforePrev == nullptr) 
//                    return false;
//
//                beforePrev->next = temp; 
//                delete prev;
//                return true;
//            }
//        } while (temp != head);
//
//        return false;
//    }
//
//    bool deleteAfter(T key)
//    {
//        if (head == nullptr || head->next == head)
//            return false; 
//        Node<T>* temp = head;
//
//        do
//        {
//            if (temp->data == key)
//            {
//                Node<T>* toDelete = temp->next;
//                if (toDelete == head) 
//                {
//                    return deleteAtHead(); 
//                }
//                temp->next = toDelete->next; 
//                delete toDelete;
//                return true;
//            }
//            temp = temp->next;
//        } while (temp != head);
//
//        return false; 
//    }
//    int getLength()
//    {
//        if (head == nullptr)
//            return 0;  
//        int count = 0;
//        Node<T>* temp = head;
//        do
//        {
//            count++;   
//            temp = temp->next;
//        } while (temp != head);
//
//        return count;
//    }
//    Node<T>* search(T x)
//    {
//        if (head == nullptr)
//            return nullptr;  
//        Node<T>* temp = head;
//        do
//        {
//            if (temp->data == x)
//            {
//                return temp;  
//            }
//            temp = temp->next;
//        } while (temp != head);
//
//        return nullptr; 
//    }
//};
//
//int main()
//{
//    LinkedList<int> obj; 
//    obj.insertAtTail(20);
//    obj.insertAtTail(15);
//    obj.insertAtTail(45);
//    obj.display();
//    obj.insertAtHead(5);
//    obj.display();
//    obj.deleteAtTail();
//    obj.display();
//    obj.insertBefore(89, 5);
//    obj.display();
//    /*LinkedList<string> strList;
//    strList.insertAtTail("Hello");
//    strList.insertAtTail("World");
//    strList.display();
//    strList.insertAtHead("First");
//    strList.display();
//    strList.deleteAtTail();
//    strList.display();*/
//
//}
