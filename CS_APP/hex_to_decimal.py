import sys

char_map = { "A" : 10,
             "B" : 11,
             "C" : 12,
             "D" : 13,
             "E" : 14,
             "F" : 15
             }

if __name__ == '__main__':
    num = sys.argv[1]
    if (num.startswith('0x') or num.startswith('0X')):
        num = num[2:]
    length = len(num)
    i = 0
    decimal = 0
    while (i < length):
        digit = num[-1]
        num = num[:-1]
        if digit in char_map.keys():
            decimal = decimal + pow(16, i) * char_map[digit]
        else:
            decimal = decimal + pow(16, i) * int(digit)
        i = i + 1

    print decimal


