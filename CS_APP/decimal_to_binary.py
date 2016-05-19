import sys

if __name__ == '__main__':
    num = int(sys.argv[1])
    j = num
    r = ""
    while (j > 0):
        reminder = j % 2
        r = str(reminder) + r
        j = j / 2
    if ( num == 0):
        r = "0"

    print r
