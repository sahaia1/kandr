import sys

if __name__ == '__main__':
    binary_string = sys.argv[1]
    i = 0
    num = 0
    while (i < len(sys.argv[1])):
        digit = binary_string[-1]
        binary_string = binary_string[:-1]
        if (digit == "1"):
            num = num + pow(2, i)
        i = i + 1
    print num


