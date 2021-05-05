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
   [Bubble sort]  Took:  87813196 µs   (87813 ms) (87s) to sort 100000 numbers
   [Bubble sort]  Took:  92229621 µs   (92230 ms) (92s) to sort 100000 numbers
   [Bubble sort]   Avg:  90021408 µs   (90021 ms) (90s) to sort 100000 numbers
```

<br />

## ⌨️ Example usage

First create sequence of _n_ random numbers

```sh
foo@bar:~$ python create_file_with_nums.py
```

Then edit main() in main.cpp

```cpp
int main() {
  auto data = IO::load_data("nums.txt");

  auto const tests = std::vector<std::tuple<std::string, std::vector<int> (*)(std::vector<int> const&), std::vector<int> const&, std::size_t const>> {
    {"Bubble sort", &SortingAlg::bubble_sort, data, 2u}
  };

  for (auto&& [name, func, data, run_qty] : tests) {
    test_sort_function(name, func, data, run_qty);
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
