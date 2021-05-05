import random

NUMBER_OF_RANDOM_NUMBERS = 100_000

with open("nums.txt", "w") as f:
  for i in random.sample(range(-NUMBER_OF_RANDOM_NUMBERS, NUMBER_OF_RANDOM_NUMBERS), NUMBER_OF_RANDOM_NUMBERS):
    f.write(f"{i}\n")
  print("Done")
