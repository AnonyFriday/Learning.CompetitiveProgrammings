// ==================================
// === CHANGE HERE
// ==================================

bool CheckPalindrome(string input)
{
    if (input == null || input.Count() == 0) return false;

    int i = 0;
    int j = input.Count() - 1;

    while (i < j)
    {
        if (input[i] != input[j]) return false;
        i++;
        j--;
    }

    return true;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
string line;
List<string> inputs = new();
while ((line = Console.ReadLine()) != null)
{
    inputs.Add(line);
}

DurationTesting(() =>
{
    foreach (string input in inputs)
    {
        bool isBoolean = CheckPalindrome(input);
        Console.WriteLine(isBoolean);
    }
});

// ==================================
// === Utilities
// ==================================

/*
    Swapping elements
*/
void Swap<T>(ref T a, ref T b)
{
    T temp = a;
    a = b;
    b = temp;
}

/*
    Output Arrays
*/
void Output<T>(T[] arr)
{
    foreach (T el in arr)
    {
        Console.Write($"{el} ");
    }
    Console.WriteLine();
}

/*
    Testing duration time to run the algorithm in milliseconds
*/
void DurationTesting(Action action)
{
    var startTime = DateTime.Now;

    action();

    var endTime = DateTime.Now;
    var duration = endTime - startTime;
    Console.WriteLine($"Duration: {duration.TotalMilliseconds} ms");
}