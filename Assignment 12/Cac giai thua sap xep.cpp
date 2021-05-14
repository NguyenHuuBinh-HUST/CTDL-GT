#include <iostream>
using namespace std;

void SELECTION_SORT(int A[], int n)
{
	int Min;
	for (int i = 0; i < n - 1; i++)
	{
		Min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[Min])
				Min = j;
		if (Min != i)
		{
			int temp = A[Min];
			A[Min] = A[i];
			A[i] = temp;
		}
	}
}
void InsertionSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = A[i];
		int j = i - 1;
		while ((temp < A[j]) && (j >= 0))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
	}
}

void bubbleSort(int A[], int N)
{
	int i = 0;
	bool sorted = false;
	while (!sorted && i < N - 1)
	{
		sorted = true;
		for (int k = N - 2; k >= i; k--)
			if (A[k] > A[k + 1])
			{
				swap(A[k], A[k + 1]);
				sorted = false;
			}
		i++;
	}
}
int Partition(int A[], int first, int last)
{
	if (first >= last)
		return 0;
	int c = A[first];
	int i = first + 1, j = last;
	while (i <= j)
	{
		while (A[i] <= c && i <= j)
			i++;
		while (A[j] > c && i <= j)
			j--;
		if (i < j)
			swap(A[i], A[j]);
	}
	swap(A[first], A[j]);
	return j;
}
void QuickSort(int A[], int first, int last)
{
	int j;
	if (first < last)
	{
		j = Partition(A, first, last);
		QuickSort(A, first, j - 1);
		QuickSort(A, j + 1, last);
	}
}
void MergeArrays(int A[], int m, int n, int p)
{
    int i = m, j = n + 1;
    while (i < j && j <= p)
    {
        if (A[i] <= A[j])
            i++;
        else
        { //chen Aj vao vi tri i
            int x = A[j];
            for (int k = j - 1; k >= i; k--)
            {
                A[k + 1] = A[k];
                A[i] = x;
                i++;
                j++;
            }
        }
    }
}
void Merge(int A[], int first, int last)
{
    if (first >= last)
        return;
    int m = (first + last) / 2;
    Merge(A, first, m);
    Merge(A, m + 1, last);
    MergeArrays(A, first, m, last);
}
void MergeSort(int A[], int N)
{
    if (N < 2)
        return;
    Merge(A, 0, N - 1);
}

// Vun dong mot cay con co nut root la i
// n la kich thuoc cua dong
void heapify(int arr[], int n, int i)
{
	int largest = i; // khoi tao largest nhu la root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// Neu nut con trai lon hon so voi root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Neu nut con phai lon hon so voi root
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Neu root khong phai la lon nhat
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// De quy lai ham heapify
		heapify(arr, n, largest);
	}
}

// Ham vun dong
void heapSort(int arr[], int n)
{
	// Tao mot dong (Sap xep lai mang)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Trích xuất từng một phần tử một từ heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Di chuyen root ve cuoi cung
		swap(arr[0], arr[i]);

		// goi ham heapify
		heapify(arr, i, 0);
	}
}

void ShowArray(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
    ShowArray(arr, n);
	// SELECTION_SORT(arr, n);
	// InsertionSort(arr, n);
	 bubbleSort(arr,n);
	// QuickSort(arr,0, n-1);
	// heapSort(arr, n);
	// MergeSort(arr, n);
	cout << "Sorted array is \n";
	ShowArray(arr, n);
	return 0;
}