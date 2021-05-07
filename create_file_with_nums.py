import random, sys

NUMBER_OF_RANDOM_NUMBERS = 100

if len(sys.argv) > 1:
  try: 
    n = int(sys.argv[1])
    NUMBER_OF_RANDOM_NUMBERS = n
  except ValueError:
    pass

with open("nums.txt", "w") as f:
  for i in random.sample(range(-NUMBER_OF_RANDOM_NUMBERS, NUMBER_OF_RANDOM_NUMBERS), NUMBER_OF_RANDOM_NUMBERS):
    f.write(f"{i}\n")
  print("Done")
