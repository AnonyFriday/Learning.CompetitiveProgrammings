using System.Data;

// ==================================
// === CHANGE HERE
// ==================================

/*
    We have 4 for loop per edge
*/
int[] PrintSprial(int[][] arr)
{
    List<int> result = new();

    if (arr == null) return result.ToArray();

    int rows = arr.Length;
    int cols = arr[0].Length;

    int sRow = 0;
    int eRow = rows - 1;
    int sCol = 0;
    int eCol = cols - 1;

    while (sRow <= eRow && sCol <= eCol)
    {
        // top + the case sRow == eRow
        for (int i = sCol; i <= eCol; i++)
        {
            result.Add(arr[sRow][i]);
        }

        // right + the case of sCol == eCol
        for (int i = sRow + 1; i <= eRow; i++)
        {
            result.Add(arr[i][eCol]);
        }

        // bottom
        // - avoid duplicate
        for (int i = eCol - 1; i >= sCol; i--)
        {
            if (sRow == eRow) break;
            result.Add(arr[eRow][i]);
        }

        // left
        // - avoid duplicate
        for (int i = eRow - 1; i >= sRow + 1; i--)
        {
            if (sCol == eCol) break;
            result.Add(arr[i][sCol]);
        }

        sRow++;
        eRow--;
        sCol++;
        eCol--;
    }

    return result.ToArray();
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/

int[][] arr = new int[5][];

for (int i = 0; i < 5; i++)
{
    int[] nums = Console.ReadLine()
                    .Split(" ")
                    .Select(int.Parse)
                    .ToArray();

    arr[i] = nums;
}

DurationTesting(() =>
{
    var result = PrintSprial(arr);

    Output(result);
});
// DurationTesting(() => AlgorithmName(nums, true));

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
    Output 2D Arrays
*/
void Output<T>(T[][] arr)
{
    foreach (T[] row in arr)
    {
        foreach (T el in row)
        {
            Console.Write(el + " ");
        }
        Console.WriteLine();
    }
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