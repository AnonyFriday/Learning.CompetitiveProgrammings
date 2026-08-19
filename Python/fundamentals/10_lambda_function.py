# Anonymous Function
l1: tuple[int] = (1,2,3,4)
squares = list(map(lambda x: x * x, l1))
print(squares)

# Get the longest word
def get_longest_word(sentences=''):
    words = tuple(sentences.split(' '))
    max_len = len(max(words, key=len))
    return list(filter(lambda x : len(x) == max_len, words))

print(get_longest_word("Python is very awesome"))