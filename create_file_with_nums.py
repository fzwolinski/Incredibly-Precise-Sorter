with open("nums.txt", "a") as f:
  for i in range(99999):
    print(f"{i}\t{99999-i} left")
    f.write(f"{i}\n")