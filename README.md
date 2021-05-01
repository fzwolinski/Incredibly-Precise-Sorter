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
   [Bubble Sort]  Took:  77063238 µs   (77063.238 ms) (77s) to sort 100000 numbers
[Insertion Sort]  Took:  22203005 µs   (22203.005 ms) (22s) to sort 100000 numbers
      [STD Sort]  Took:     30999 µs      (30.999 ms)  (0s) to sort 100000 numbers
[Selection Sort]  Took:  18047006 µs   (18047.006 ms) (18s) to sort 100000 numbers
    [Merge Sort]  Took:    352000 µs     (352.000 ms)  (0s) to sort 100000 numbers
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

  return 0;
}
```

<br />

## 💁🏻 Contributing

Have fun as much as you want. I will consider all of the PR's

<br />

## 📜 License

[MIT](https://choosealicense.com/licenses/mit/)
