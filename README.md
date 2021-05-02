# 💯 Incredibly Precise Sorter

**Incredibly Precise Sorter** is a console program which allows You to:

- sort a sequence of numbers loaded from a _TXT_ file
- save sorted sequence in a new _TXT_ file
- measure the sorting time for individual algorithm

<br />

#### 📐 Available algorithms

- Bubble Sort
- Insertion Sort
- IntroSort (using sort() from STD)
- Selection Sort
- Merge Sort
- Quicksort

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
   [Bubble Sort]  Took:  77817989 µs   (77817.989 ms) (77s) to sort 100000 numbers
[Insertion Sort]  Took:  24974911 µs   (24974.911 ms) (24s) to sort 100000 numbers
      [STD Sort]  Took:     33990 µs      (33.990 ms)  (0s) to sort 100000 numbers
[Selection Sort]  Took:  20961005 µs   (20961.005 ms) (20s) to sort 100000 numbers
    [Merge Sort]  Took:    364995 µs     (364.995 ms)  (0s) to sort 100000 numbers
     [Quicksort]  Took:     25993 µs      (25.993 ms)  (0s) to sort 100000 numbers
```

<br />

## ⌨️ Example usage

First create sequence of _n_ random numbers

```sh
foo@bar:~$ python create_file_with_nums.py
```

Then edit main.cpp

```cpp
#include <iostream>
#include "sorter.h"

int main() {
  Sorter s;
  s.load_numbers("nums.txt");

  s.run_bubble_sort();
  s.run_insertion_sort();
  s.run_std_sort();
  s.run_selection_sort();
  s.run_merge_sort();
  s.run_quicksort();

  return 0;
}
```

<br />

## 💁🏻 Contributing

Have fun as much as you want. I will consider all of the PR's

<br />

## 📜 License

[MIT](https://choosealicense.com/licenses/mit/)
