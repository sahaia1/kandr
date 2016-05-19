import sys

char_map = { "10" : "A",
             "11" : "B",
             "12" : "C",
             "13" : "D",
             "14" : "E",
             "15" : "F"
             }

if __name__ == '__main__':
    num = int(sys.argv[1])
    j = num
    r = ""
    while (j > 0):
        reminder = j % 16
        if (reminder >= 10):
            r = char_map[str(reminder)] + r
        else:
            r = str(reminder) + r
        j = j / 16
    print "0x" + r
