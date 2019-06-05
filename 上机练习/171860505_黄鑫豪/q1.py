original_string = input()
i = 0
while i < len(original_string):
    count = 1
    j = i + 1
    while j < len(original_string) and original_string[i] == original_string[j]:
        j = j + 1
        count = count + 1
    if count != 1:
        print(count, end="")
    print(original_string[i], end=""),
    i = j
