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
foo@bar:~$ g++ -std=c++20 main.cpp io.cpp sorting_alg.cpp timer.cpp
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

## ✔️ Run Tests

```sh
foo@bar:~$ cmake -S . -B build
```

```sh
foo@bar:~$ cmake --build build
```

```sh
foo@bar:~$ cd build && ctest
```

<br />

## 🚪 Example output

An example of one test series for each of the algorithms

```sh
   [Bubble sort]  Took:  77330038 µs   (77330 ms) (77s) to sort 100000 numbers
[Insertion sort]  Took:  21608994 µs   (21609 ms) (21s) to sort 100000 numbers
      [STD sort]  Took:     33999 µs      (34 ms)  (0s) to sort 100000 numbers
[Selection sort]  Took:  18224001 µs   (18224 ms) (18s) to sort 100000 numbers
    [Merge sort]  Took:    355993 µs     (356 ms)  (0s) to sort 100000 numbers
     [Quicksort]  Took:     27998 µs      (28 ms)  (0s) to sort 100000 numbers
```

Example of four test series for each of the algorithms

```sh
   [Bubble sort]  Took:  76896164 µs   (76896 ms) (76s) to sort 100000 numbers
   [Bubble sort]  Took:  76639047 µs   (76639 ms) (76s) to sort 100000 numbers
   [Bubble sort]  Took:  76618005 µs   (76618 ms) (76s) to sort 100000 numbers
   [Bubble sort]   Avg:  76717739 µs   (76718 ms) (76s) to sort 100000 numbers

[Insertion sort]  Took:  21812000 µs   (21812 ms) (21s) to sort 100000 numbers
[Insertion sort]  Took:  21678001 µs   (21678 ms) (21s) to sort 100000 numbers
[Insertion sort]  Took:  21663003 µs   (21663 ms) (21s) to sort 100000 numbers
[Insertion sort]   Avg:  21717668 µs   (21718 ms) (21s) to sort 100000 numbers

      [STD sort]  Took:     33999 µs      (34 ms)  (0s) to sort 100000 numbers
      [STD sort]  Took:     34001 µs      (34 ms)  (0s) to sort 100000 numbers
      [STD sort]  Took:     33999 µs      (34 ms)  (0s) to sort 100000 numbers
      [STD sort]   Avg:     34000 µs      (34 ms)  (0s) to sort 100000 numbers

[Selection sort]  Took:  17824003 µs   (17824 ms) (17s) to sort 100000 numbers
[Selection sort]  Took:  17797987 µs   (17798 ms) (17s) to sort 100000 numbers
[Selection sort]  Took:  17806985 µs   (17807 ms) (17s) to sort 100000 numbers
[Selection sort]   Avg:  17809658 µs   (17810 ms) (17s) to sort 100000 numbers

    [Merge sort]  Took:    357000 µs     (357 ms)  (0s) to sort 100000 numbers
    [Merge sort]  Took:    358005 µs     (358 ms)  (0s) to sort 100000 numbers
    [Merge sort]  Took:    361993 µs     (362 ms)  (0s) to sort 100000 numbers
    [Merge sort]   Avg:    358999 µs     (359 ms)  (0s) to sort 100000 numbers

     [Quicksort]  Took:     29997 µs      (30 ms)  (0s) to sort 100000 numbers
     [Quicksort]  Took:     28997 µs      (29 ms)  (0s) to sort 100000 numbers
     [Quicksort]  Took:     30000 µs      (30 ms)  (0s) to sort 100000 numbers
     [Quicksort]   Avg:     29665 µs      (30 ms)  (0s) to sort 100000 numbers
```

<br />

## ⌨️ Example usage

First create sequence of _n_ random numbers

```sh
foo@bar:~$ python create_file_with_nums.py n
```

Then edit main() in main.cpp

```cpp
int main() {
  auto data = IO::load_data("nums.txt");

  auto const tests = std::vector<std::tuple<
                                            std::string,
                                            std::vector<int> (*)(std::vector<int> const&),
                                            std::vector<int> const&,
                                            std::size_t const,
                                            bool>> {
    {"Bubble sort",     &SortingAlg::bubble_sort,     data, 1u, false},
    {"Insertion sort",  &SortingAlg::insertion_sort,  data, 1u, false},
    {"STD sort",        &SortingAlg::std_sort,        data, 1u, false},
    {"Selection sort",  &SortingAlg::selection_sort,  data, 1u, false},
    {"Merge sort",      &SortingAlg::merge_sort,      data, 1u, false},
    {"Quicksort",       &SortingAlg::quicksort,       data, 1u, false}
  };

  for (auto&& [name, func, data, run_qty, save_res_to_file] : tests) {
    test_sort_function(name, func, data, run_qty, save_res_to_file);
  }

  return 0;
}
```

<br />

## 💁🏻 Contributing

Have fun as much as you want. I will consider all of the PR's

<br />

## 📜 License

[MIT](https://choosealicense.com/licenses/mit/)
