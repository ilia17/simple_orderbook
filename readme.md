# Simple Orderbook in C++

This project provides a basic implementation of an orderbook using singly linked lists in C++. Each order is represented as a node, and the orderbook tracks two separate lists: bids and asks.

## Features

- **Bid and Ask Insertion:**  
  New bids are inserted in descending price order (highest to lowest), and asks are inserted in ascending price order (lowest to highest) to maintain price-time priority.
- **Orderbook Display:**  
  The `print_book` function prints the current state of both the bid and ask lists.
- **Order Level Deletion:**  
  Levels (all orders at a given price) can be removed from either side using `delete_level`.
- **Memory Management:**  
  The `free_list` function safely deletes all nodes to free resources.

## Example Usage

When running `main.cpp`, the following logic is executed:

```cpp
Node* bids = nullptr;
Node* asks = nullptr;

// Insert bids (out of price order)
bids = insert_bid(bids, 100.05, 200);
bids = insert_bid(bids, 100.10, 500);
bids = insert_bid(bids, 100.07, 300);

// Insert asks (out of price order)
asks = insert_ask(asks, 100.25, 150);
asks = insert_ask(asks, 100.20, 300);
asks = insert_ask(asks, 100.30, 400);

print_book(bids, asks);

// Remove a bid level
bids = delete_level(bids, 100.07);
print_book(bids, asks);
```

**Sample Output:**
```
--- Initial book ---
Bid: 100.10 Quantity: 500
Bid: 100.07 Quantity: 300
Bid: 100.05 Quantity: 200
Ask: 100.20 Quantity: 300
Ask: 100.25 Quantity: 150
Ask: 100.30 Quantity: 400

--- After deleting bid 100.07 ---
Bid: 100.10 Quantity: 500
Bid: 100.05 Quantity: 200
Ask: 100.20 Quantity: 300
Ask: 100.25 Quantity: 150
Ask: 100.30 Quantity: 400
```

## Getting Started

1. **Build the application:**
    ```
    g++ main.cpp orderbook.cpp -o orderbook
    ```
2. **Run the executable:**
    ```
    ./orderbook
    ```

## File Overview

- `main.cpp` &mdash; Example usage and simple test of the orderbook interface.
- `orderbook.cpp` / `orderbook.h` &mdash; Core functions for managing the orderbook.
- `node.h` &mdash; Definition of the order node data structure.

## Notes

- This implementation is designed for educational and demonstration purposes and does not include order matching or advanced error handling.
- Node insertion/deletion is O(n) and not suitable for high-performance or production environments.
- For real-world usage, consider data structures optimized for fast insertion/removal, like red-black trees (std::map, std::set), skip lists, or specialized in-memory orderbook representations.