using System.Data;

// ==================================
// === CHANGE HERE
// ==================================

int LinearSearch(IList<int> list, int target)
{
    if (list == null || list.Count == 0) return -1;

    for (int i = 0; i < list.Count; i++)
    {
        if (target == list[i]) return i;
    }

    return -1;
}

// ==================================
// === MAIN EXECUTION
// ==================================

int.TryParse(Console.ReadLine(), out int no);
int[] nums = Console.ReadLine().Split(" ").Select(e =>
{
    if (int.TryParse(e, out int num)) return num;
    return 0;
}).ToArray();

Console.WriteLine(LinearSearch(nums, no));