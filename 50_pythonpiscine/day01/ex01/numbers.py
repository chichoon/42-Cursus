def numbers_func():
    with open("numbers.txt", "r") as f:
        line = f.read().strip("\n")
        numbers = line.split(",")
        for num in numbers:
            print(str(num))


if __name__ == "__main__":
    numbers_func()
