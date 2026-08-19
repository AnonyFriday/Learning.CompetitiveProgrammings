// ==================================
// === CHANGE HERE
// ==================================

/*
    Problem:
    - I have 4 friends
    - I'm the last person choosing maximum portion, my friends choose the min
    - Find the (i, j) so that I'm the final person choosing the maximum portion

    Bruce Force:
    - Make a cut at every i, j
        + Compute 4 partions: A1, A2, A3, A4
    - Then track the max for each A

    Result is the the max mango and the coordinate i and j to get the max mango
    e.g. 10, {12, 20}

    Time Complexity: O(N^2 * N^2)
*/
using System.Diagnostics;
using System.Numerics;
using System.Reflection.Metadata;

int MangoTreeBruceForce(int[][] arr, int n, int m)
{
    if (arr == null) return 0;
    if (n != m || n <= 0 || m <= 0) return 0;

    int max = int.MinValue;
    int rows = n - 1;
    int cols = n - 1;

    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= cols; j++)
        {
            // top left
            int sum1 = ComputeSum(arr, 0, i, 0, j);

            // bottom left
            int sum2 = ComputeSum(arr, i + 1, rows, 0, j);

            // top right
            int sum3 = ComputeSum(arr, 0, i, j + 1, cols);

            // bottom right
            int sum4 = ComputeSum(arr, i + 1, rows, j + 1, cols);

            // compute 4 portion, and find the min
            int minSum = Math.Min(
                Math.Min(sum1, sum2),
                Math.Min(sum3, sum4));

            // choose the max amongst min
            max = Math.Max(max, minSum);
        }
    }

    return max;
}

int ComputeSum(int[][] arr, int rowS, int rowE, int colS, int colE)
{
    int sum = 0;
    for (int a = rowS; a <= rowE; a++)
    {
        for (int b = colS; b <= colE; b++)
        {
            sum += arr[a][b];
        }
    }

    return sum;
}

int MangoTreePrefixSum(int[][] arr, int n, int m)
{
    if (arr == null) return 0;
    if (n != m || n <= 0 || m <= 0) return 0;

    int max = int.MinValue;
    int rows = n - 1;
    int cols = m - 1;

    // prefix sum matrix 1s base
    // using jagged array + 0s padding to avoid condition
    int[][] prefix = new int[rows + 1 + 1][];

    for (int i = 0; i <= rows + 1; i++)
    {
        prefix[i] = new int[cols + 1 + 1];
    }

    for (int i = 1; i <= rows + 1; i++)
    {
        for (int j = 1; j <= cols + 1; j++)
        {
            prefix[i][j] = arr[i - 1][j - 1]
                            + prefix[i - 1][j]
                            + prefix[i][j - 1]
                            - prefix[i - 1][j - 1];
        }
    }

    // Calculate the max sum of amongest minsum
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= cols; j++)
        {
            // top left
            int sum1 = ComputeSumPrefix(prefix, 0, i, 0, j);

            // bottom left
            int sum2 = ComputeSumPrefix(prefix, i + 1, rows, 0, j);

            // top right
            int sum3 = ComputeSumPrefix(prefix, 0, i, j + 1, cols);

            // bottom right
            int sum4 = ComputeSumPrefix(prefix, i + 1, rows, j + 1, cols);

            // compute 4 portion, and find the min
            int minSum = Math.Min(
                Math.Min(sum1, sum2),
                Math.Min(sum3, sum4));

            // choose the max amongst min
            max = Math.Max(max, minSum);
        }
    }

    return max;
}

int ComputeSumPrefix(int[][] prefix, int r1, int r2, int c1, int c2)
{
    // prefix sum 
    // 1D: sum(i, j) = prefix[j] - prefix[i - 1] = right - left (not 0s base)
    // 1D: sum(i, j)

    int total = prefix[r2 + 1][c2 + 1];
    int top = prefix[r1 - 1 + 1][c2 + 1];
    int left = prefix[r2 + 1][c1 - 1 + 1];
    int cross = prefix[r1 - 1 + 1][c1 - 1 + 1];

    int sum = total - top - left + cross;
    return sum;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
int[][] arr = new int[4][];

for (int i = 0; i < 4; i++)
{
    int[] nums = Console.ReadLine()
                    .Split(" ")
                    .Select(int.Parse)
                    .ToArray();

    arr[i] = nums;
}

DurationTesting(() =>
{
    int n = arr[0].Length;
    int m = arr[0].Length;
    var result1 = MangoTreeBruceForce(arr, n, m);
    var result2 = MangoTreePrefixSum(arr, n, m);
    Console.WriteLine(result1);
    Console.WriteLine(result2);
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