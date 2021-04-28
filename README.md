# 💯 Incredibly Precise Sorter

**Incredibly Precise Sorter** is a console program which allows You to:

- sort a sequence of numbers loaded from a _TXT_ file
- save sorted sequence in a new _TXT_ file
- measure the sorting time for individual algorithm

<br />

#### 📐 Available algorithms

- Bubble Sort
- Insertion Sort

<br />

## 💻 Compile and Run

```sh
foo@bar:~$ g++ main.cpp sorter.cpp timer.cpp
```

Windows

```sh
foo@bar:~$ a.exe
```

Linux

```sh
foo@bar:~$ ./a.out
```

<br />

## 🚪 Example output

```sh
   [Bubble Sort]  Duration:    863583 microseconds (863.583000 milliseconds)
[Insertion Sort]  Duration:    469014 microseconds (469.014000 milliseconds)
```

<br />

## ⌨️ Example usage

First create sequence of _n_ random numbers

```sh
foo@bar:~$ python create_file_with_nums.py
```

<br />

```cpp
#include <iostream>
#include "sorter.h"

int main() {
  Sorter s;
  s.load_numbers("nums.txt");

  s.run_bubble_sort();
  s.run_insertion_sort();

  return 0;
}
```

<br />

## 💁🏻 Contributing

Have fun as much as you want. I will consider all of the PR's

<br />

## 📜 License

[MIT](https://choosealicense.com/licenses/mit/)
