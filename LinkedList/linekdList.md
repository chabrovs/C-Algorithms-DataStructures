# LinkedList


## Introduction


### Definition
A **Linked list** is a data structure that consists of N nodes. Each node contains at least two attributes (variables): 1. __Data__ - stores the actual domain data; 2: __Pointer__ - stores the memory address of next node, if the current node is the last one the pointer of the current node points to the `NULL`. Also, there is a __HEAD__ pointer that always points to the first node in the sequence of linked nodes.

   

## Types of LinkedLists



### Singly linked list

```
HEAD -> NODE[VALUE, NEXT] -> NODE[VALUE, NEXT] -> NULL
```


### Doubly linked list

```
HEAD <-> NODE[PREV, VALUE, NEXT] <-> NODE[PREV, VALUE, NEXT] -> NULL
```


### Circular linked list

```
HEAD -> NODE[VALUE, NEXT] -> NODE[VALUE, NEXT]
         ^                                 |
         |                                 |
         -----------------------------------
```