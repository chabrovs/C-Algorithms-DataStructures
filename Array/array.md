# Array


## Introduction


### Definition


**Array** is a linear data structure that is defined as a collection of elements with same data type.  **Arrays** exist both in single dimension (meaning that the array contains primitive values e.g., integers, chars, etc.) and multiple dimension (meaning that the array can contain another array as a value, more precisely a pointer to the first element in another array.).

### Create an array
```
data_type array_name[array_size]={elements separated by commas}

// or,

data_type array_name[array_size];
```

## Array in memory



### Array allocation in RAM.


In RAM **arrays** are allocated as a contiguous block of memory cells.
For example:
```
int arr = {1, 2, 3};
```

|Index    | Value | Address |
|-------- | ------| ------- |
|0        | 1     | 0x0001  |
|1        | 2     | 0x0002  |
|2        | 3     | 0x0003  |