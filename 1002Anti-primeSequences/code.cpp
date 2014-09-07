#include <iostream>
#include <string>

using namespace std;

int n;
int m;
int d;
int input[1000];
int output[1000];
int currentMaxAttemptIndex[1000];
int inputMaxIndex;

bool isPrime(int number)
{
  if ( n % 2 == 0 ) return false;
  
  for (int i = 3; i <= n / 2; i = i + 1)
  {
    if ( n % i == 0) return false;
  }
  
  return true;
}

int subSum(int endIndex)
{
  int sum = 0;
  int startIndex = (endIndex - d + 1) > 0 ? : 0;
  for (int i = endIndex; i >= startIndex; i--)
    sum += input[i];
  return sum;
}

int getSmallestUnattemptedNumberForIndex(int currentIndex)
{
  if ( currentMaxAttemptIndex[currentIndex] >= inputMaxIndex )
	return -1;
	
  for (int i = currentMaxAttemptIndex[currentIndex] + 1; i <= inputMaxIndex; i++)
  {
    // If input[i] == -1, its used;
	// If not, its not used, can be returnd.
    if (input[i] != -1)
	{
	  int value = input[i];
	  input[i] = -1;
	  currentMaxAttemptIndex[currentIndex] = i;
	  return value;
	}
  }
  
  return -1;
}

void putSmallestNumber(int currentLast)
{
  // Find the smallest currentLast position
  int number = getSmallestUnattemptedNumberForIndex(currentLast);
  int index;
  
  cout << currentLast << "   ";
  
  if (number < 0)
  {
    // No more smallest
	// 1. pop the last & mark the number as not used
	index = output[currentLast-1] - n;
	input[index] = output[currentLast-1];
	// 2. Reset the current one's max atempt index
	currentMaxAttemptIndex[currentLast] = -1;
	// 3. Start from currentLast-1, get the next biggest
	putSmallestNumber(currentLast-1);
  }
  else
  {
    // Find a existing smallest, put it in the output current last position
	output[currentLast] = number;
	
    if ( isPrime( subSum(currentLast) ) ) 
	{
	  // pop currentLast
	  index = number - n;
	  input[index] = number;
	  // get the next smallest
	  putSmallestNumber(currentLast);
	}
    else
	{
	  putSmallestNumber(currentLast+1);
	}
  }
}

int main()
{
  int i;
  
  while(true)
  {
    // Take input
	for (i = 0; i < 1000; i++ )
	{
	  input[i] = -1;
	  output[i] = -1;
	  currentMaxAttemptIndex[i] = -1;
	}
    cin >> n >> m >> d;
    if ( n == 0 && m == 0 && d == 0) return 0;
	inputMaxIndex = m - n;
	for (i = 0; i < inputMaxIndex; i++)
	  input[i] = n + i;
	
	// Depth-First Insert
	putSmallestNumber(0);
  }

  return 0;
}
