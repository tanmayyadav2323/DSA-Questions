class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;

        while (k--)
            pq.push(arr[l++]);

        for (int i = l; i <= r; i++)
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};

class Solution
{
public:
    int partition(int l, int r, int arr[])
    {
        int pivot = arr[l];
        int j = l - 1;

        for (int i = l; i <= r; i++)
        {
            if (arr[i] <= pivot)
            {
                j++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[j], arr[l]);
        return j;
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {

        int index = partition(l, r, arr);

        if (index - l == k - 1)
            return arr[index];

        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r, k - index + l - 1);
    }