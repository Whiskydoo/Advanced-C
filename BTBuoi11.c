#include <stdio.h>

int S1[]={3,8,1,4,6};
int S2[]={23,65,12,76};

//Gộp mảng

void mergeArr(int sizeOfS1, int sizeOfS2)
{
    for(int i = sizeOfS1; i<(sizeOfS1+sizeOfS2); i++)
    {
        *(S1+i) = *(S2+i-sizeOfS1);
    }
}

//In Mảng

void printArr(int N)
{
    for(int i = 0; i<N; i++)
    {
        printf("%d\t",*(S1+i));
    }
}

//Hàm hoán đổi giá trị

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm dịch của thuật toán sắp xép HeapSort từ NHỎ ĐẾN LỚN

void STLShift(int l, int r)
{
	int i, j, x;
	i = l;
	j = 2 * i + 1;
	x = *(S1+i);
	while (j <= r)
	{
		if ((j < r) && (*(S1+j) < *(S1+j + 1)))
			j++;
		if (x >= *(S1+j))
			break;
		else
		{
			*(S1+i) = *(S1+j);
			*(S1+j) = x;
			i = j;
			j = 2 * i + 1;
			x = *(S1+i);
		}
	}
}

//Hàm tạo heap của thuật toán HeapSort NHỎ ĐẾN LỚN

void STLCreatHeap(int N)
{
	int I = (N-1)/2;
	while (I >= 0)
	{
		STLShift(I, N - 1);
		I--;
	}
}

//Thuật toán HeapSort sắp xếp từ NHỎ ĐẾN LỚN

void STLHeapSort(int N)
{
	int r = N - 1;
	STLCreatHeap(N);
	while (r > 0)
	{
		Swap((S1), (S1+r));
		r--;
		if(r>0)
			STLShift(0, r);
	}

}

// Hàm dịch của thuật toán sắp xép HeapSort từ LỚN ĐÊN NHỎ

void LTSShift(int l, int r)
{
	int i, j, x;
	i = l;
	j = 2 * i + 1;
	x = *(S1+i);
	while (j <= r)
	{
		if ((j < r) && (*(S1+j) > *(S1+j + 1)))
			j++;
		if (x <= *(S1+j))
			break;
		else
		{
			*(S1+i) = *(S1+j);
			*(S1+j) = x;
			i = j;
			j = 2 * i + 1;
			x = *(S1+i);
		}
	}
}

//Hàm tạo heap của thuật toán HeapSort TỪ LỚN ĐẾN NHỎ

void LTSCreatHeap(int N)
{
	int I = (N-1)/2;
	while (I >= 0)
	{
		LTSShift(I, N - 1);
		I--;
	}
}

//Thuật toán HeapSort sắp xếp từ LỚN ĐẾN NHỎ

void LTSHeapSort(int N)
{
	int r = N - 1;
	LTSCreatHeap(N);
	while (r > 0)
	{
		Swap((S1), (S1+r));
		r--;
		if(r>0)
			LTSShift(0, r);
	}

}

void main(){
    int sizeOfS1, sizeOfS2, newSize;
    sizeOfS1 = sizeof(S1)/sizeof(int);
    sizeOfS2 = sizeof(S2)/sizeof(int);
    printf("Mang S1: ");
    for(int i = 0; i < sizeOfS1; i++)
    {
        printf("%d\t", *(S1+i));
    }
    printf("\nMang S2: ");
    for(int i = 0; i < sizeOfS2; i++)
    {
        printf("%d\t", *(S2+i));
    }
    newSize = sizeOfS1 + sizeOfS2;
    mergeArr(sizeOfS1,sizeOfS2);
    printf("\nMang sau khi gop: ");
    printArr(newSize);
    //Dùng thuật toán xếp HeapSort để sắp xếp mảng từ NHỎ ĐẾN LỚN
    STLHeapSort(newSize);
    printf("\nTu nho den lon: ");
    printArr(newSize);
    //Dùng thuật toán xếp HeapSort để sắp xếp mảng từ LỚN ĐẾN NHỎ
    LTSHeapSort(newSize);
    printf("\nTu nho den lon: ");
    printArr(newSize);

}