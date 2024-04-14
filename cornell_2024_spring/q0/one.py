input()

# it gets worse
print(
    sum(
        map(
            lambda word: int(word.lower().startswith("c")),
            input().split(),
        )
    )
)
"""
print(
    sum(
        map(
            lambda word: 1 if word.lower().startswith("c") else 0,
            input().split(),
        )
    )
)

"""
