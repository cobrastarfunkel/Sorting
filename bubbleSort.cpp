#include <stdlib.h>
#include <time.h>
#include <iostream>

void sortArr(int* nums, int size);
bool isSorted(int* nums,int size);

int main()
{

  srand(time(NULL));

  const int SIZE = 100;
  int nums[SIZE];
  for(int i = 0; i < SIZE; i++)
    nums[i] = rand() % SIZE+1;
  std::cout << "Pre Sort: ";
  for(int i = 0; i < SIZE; i++)
    std::cout << nums[i] << " ";
  sortArr(nums, SIZE);

  return 0;
}

void sortArr(int* nums, int size)
{
  int low, high;
  bool sorted = false;
  do
  {
    sorted = isSorted(nums, size);
    for(int i = 0; i < size; i++)
    {
      if(i != size-1 && nums[i] > nums[i+1])
      {
          low = nums[i+1];
          high = nums[i];
          nums[i] = low;
          nums[i+1] = high;
      }
    }

  } while (!sorted);
  std::cout << "\n" << "Sorted: ";
  for(int i = 0; i < size; i++)
    std::cout << nums[i] << " ";
}

bool isSorted(int* nums, int size)
{
  for(int i = 0; i < size; i++)
  {
    if(i != size-1 && nums[i] > nums[i+1])
      return false;
    else if(i != 0 && nums[i] < nums[i-1])
      return false;
  }
  return true;
}
