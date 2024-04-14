bools = [False] * 9

x = map(int, input().split())


def main():
    for i in x:
        if bools[i - 1]:
            print("NO")
            return
        bools[i - 1] = True

    print("YES")


main()
