import random

NUMBER_OF_RANDOM_NUMBERS = 10000

with open("nums.txt", "w") as f:
  for i in random.sample(range(1, NUMBER_OF_RANDOM_NUMBERS+1), NUMBER_OF_RANDOM_NUMBERS):
    f.write(f"{i}\n")
  print("Done")