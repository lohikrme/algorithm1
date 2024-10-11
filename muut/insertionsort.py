def insertion_sort(numbers: list):
    for i in range(1, len(numbers)):
        currentNumber = numbers[i]
        for j in range(i - 1, -1, -1):
            if numbers[j] > currentNumber:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
            else:
                break
        print(numbers)
    return numbers


list = [3, 9, 7, 2, 1, 15, 6, 3]
print(list)
print(insertion_sort(list))
