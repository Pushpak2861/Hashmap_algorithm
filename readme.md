# Toy Hash Map in C

A simple implementation of a **hash map (hash table) with chaining** in C.  
Supports **string keys** and **integer values**, with **O(1) average insertion and lookup**.

---

## Features

- Hash map with **chaining** for collision resolution.  
- **String keys** (up to 100 characters).  
- Dynamic memory allocation for nodes.  
- Safe insertion using `strncpy` to avoid buffer overflow.  
- Lookup returns a pointer to the stored value.  
- Proper memory cleanup with `freeMap()`.

---

## Files

| File | Description |
|------|-------------|
| `common.h` | Header file defining `hashmap`, `node`, and `product` structs, and function prototypes. |
| `main.c` | Contains `hash()`, `initMap()`, `insert()`, `lookup()`, `freeMap()`, and a sample `main()` to test the hash map. |

---

## Usage

### 1️⃣ Compile

```bash
gcc main.c -o main
```

### 2️⃣ Run

```bash
./main
```

Expected output:

```
banana: 20
```

---

## Example Code

```c
hashmap myMap;
initMap(&myMap, 16);

insert("apple", 10, &myMap);
insert("banana", 20, &myMap);

int* val = lookup(&myMap, "banana");
if (val) printf("banana: %d\n", *val);

freeMap(&myMap);
```

---

## How it Works

1. **Hashing**  
   - Computes hash of a string key using:  
     ```c
     hash = 0;
     for each char c: hash = hash * 31 + c
     index = hash % capacity
     ```
2. **Collision Resolution**  
   - Uses **chaining**: each bucket is a linked list of nodes.  
   - New nodes are **inserted at the head** of the linked list.
3. **Memory Management**  
   - Buckets array is allocated using `calloc` → all pointers initialized to NULL.  
   - Each node is dynamically allocated.  
   - `freeMap()` cleans all nodes and the buckets array.

---

## Limitations

- Fixed maximum key length (100 characters).  
- No dynamic resizing of the hash table.  
- Only supports integer values.

---

## Possible Improvements

- Support for **arbitrary-length strings** using dynamic allocation.  
- **Dynamic resizing** of buckets when load factor > 0.75.  
- Support for **generic values** using `void*`.  
- Better hash functions (e.g., DJB2, FNV-1a).

---

## License

This project is **MIT licensed**.
