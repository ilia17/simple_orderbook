# Simple Orderbook in C++

This project implements a simple orderbook using singly linked lists in C++. Orders are represented as nodes, and the orderbook maintains two lists: bids and asks.

## Features

- **Bid and ask insertion**: Orders are inserted into the appropriate list, maintaining price priority (highest-to-lowest for bids, lowest-to-highest for asks).
- **Orderbook visualization**: The `print_book` function outputs the current state of both sides of the orderbook.

## Example

Here's what happens when running `main.cpp`:

```cpp
Node* bids = nullptr;
Node* asks = nullptr;

// Insert bids out of order
bids = insert_bid(bids, 100.05, 200);
bids = insert_bid(bids, 100.10, 500);
bids = insert_bid(bids, 100.07, 300);

// Insert asks out of order
asks = insert_ask(asks, 100.25, 150);
asks = insert_ask(asks, 100.20, 300);
asks = insert_ask(asks, 100.30, 400);

print_book(bids, asks);
```

**Sample Output:**
```
Bid: 100.10 Quantity: 500
Bid: 100.07 Quantity: 300
Bid: 100.05 Quantity: 200
Ask: 100.20 Quantity: 300
Ask: 100.25 Quantity: 150
Ask: 100.30 Quantity: 400
```

## Getting Started

1. **Build the application:**
    ```
    g++ main.cpp -o orderbook
    ```
2. **Run it:**
    ```
    ./orderbook
    ```

## File Descriptions

- `main.cpp` &mdash; Main logic and implementation of the linked-list based orderbook.

## Notes

- This implementation does not handle deletions or order matching.
- For a more advanced or production-ready orderbook, consider data structures that allow fast inserts/removals, such as balanced trees or heaps.

---