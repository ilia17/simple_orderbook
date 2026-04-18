
#include <iostream>

struct Node {
    double price;
    int quantity;
    Node* next;
};

Node* insert_bid(Node* head, double price, int quantity) {
    //case 0: empty list
    if (head == nullptr){
        Node* new_node = new Node{price, quantity, nullptr};
        return new_node;

    }
    //case 1: new priceis higher than the head. new node becomes the new head.
    if (head->price < price){
        Node* new_node = new Node{price, quantity, head};
        return new_node;
    }   

    // case 2: new price fits somehere in the middle.
    Node* current = head;
    while (current->next != nullptr){
        if (current->next->price < price){
            Node* new_node = new Node{price, quantity, current->next};
            current->next = new_node;
            return head;
        }
        current = current->next;
    }

    // case 3: price is lower than all existing bids. new node becomes the new tail.
    Node* new_node = new Node{price, quantity, nullptr};
    current->next = new_node;
    return head;
}


Node* insert_ask(Node* head, double price, int quantity) {
    //case 0: empty list
    if (head == nullptr){
        Node* new_node = new Node{price, quantity, nullptr};
        return new_node;

    }
    //case 1: new priceis higher than the head. new node becomes the new head.
    if (head->price > price){
        Node* new_node = new Node{price, quantity, head};
        return new_node;
    }   

    // case 2: new price fits somehere in the middle.
    Node* current = head;
    while (current->next != nullptr){
        if (current->next->price > price){
            Node* new_node = new Node{price, quantity, current->next};
            current->next = new_node;
            return head;
        }
        current = current->next;
    }

    // case 3: price is lower than all existing bids. new node becomes the new tail.
    Node* new_node = new Node{price, quantity, nullptr};
    current->next = new_node;
    return head;
}


void print_book(Node* bids, Node* asks){
    //print the bids
    Node* current_bid = bids;
    while (current_bid != nullptr){
        std::cout << "Bid: " << current_bid->price << " Quantity: " << current_bid->quantity << std::endl;
        current_bid = current_bid->next;
    }

    //print the asks
    Node* current_ask = asks;
    while (current_ask != nullptr){
        std::cout << "Ask: " << current_ask->price << " Quantity: " << current_ask->quantity << std::endl;
        current_ask = current_ask->next;
    }
} 

Node* free_list(Node* head){
    Node* current = head;
    while (current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
    return nullptr;
}

Node* delete_level(Node* head, double price){
    Node* current = head;
    if (head->price == price){
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
        return head;
    }
    while (current != nullptr){
        if (current->next->price == price){
            Node* to_delete = current->next;
            current->next = current->next->next;
            delete to_delete;
            return head;
        }
        current = current->next;
    }
    return head;
}

int main() {
    Node* bids = nullptr;
    Node* asks = nullptr;

    // build the book
    bids = insert_bid(bids, 100.05, 200);
    bids = insert_bid(bids, 100.10, 500);
    bids = insert_bid(bids, 100.07, 300);

    asks = insert_ask(asks, 100.25, 150);
    asks = insert_ask(asks, 100.20, 300);
    asks = insert_ask(asks, 100.30, 400);

    std::cout << "--- Initial book ---\n";
    print_book(bids, asks);

    // delete a level
    bids = delete_level(bids, 100.07);
    std::cout << "\n--- After deleting bid 100.07 ---\n";
    print_book(bids, asks);

    // cleanup
    bids = free_list(bids);
    asks = free_list(asks);

    return 0;
}