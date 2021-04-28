with open("nums.txt", "a") as f:
  for i in range(9999, 0, -1):
    print(f"{i}\n");
    f.write(f"{i}\n")