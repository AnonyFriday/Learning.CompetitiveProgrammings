def get_sum(n: int = 0) -> int:
    s = 0
    for i in range(n):
        s += i
    return s

print(get_sum(10)) # 45

def get_longest_string(sentence: str = "") -> list[str]:
    """
    Return a list of workds from the given sentence, sorted by length.
    """
    words = sentence.split(' ')
    if len(words) == 1:
        return words
    else:
        max_length = 0
        result: list[str] = []
        for word in words:
            if len(word) > max_length:
                result.clear()
                max_length = len(word)
                result.append(word)
                print(result)
            elif len(word) == max_length:
                result.append(word)
        return result

print(get_longest_string("Todau is Tuesday"))

print(get_longest_string())