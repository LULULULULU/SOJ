#include <iostream>
#include <string>

using namespace std;

int checkSTwo(string input)
{
  int n = (input[0] - '0') * 10 + (input[1] - '0');
  if ( (n >= 11 && n <= 19) || (n >= 21 && n <= 26 ) )
  {
    return 2;
  }
  return 1;
}

int main()
{
  string input;
  int Sn;
  int Sn_1;
  int newSn;

  while(true)
  {
    input = "";
    cin >> input;
    if (input == "0")
      return 0;

    Sn_1 = 1;
    Sn = checkSTwo(input);
    newSn = Sn;

    for (int i = 1, j = 2; j < input.length(); ++i, ++j)
    {
      int An = input[i] - '0';
      int B = input[j] - '0';

      if ( An == 1 )
      {
        if (B == 0)
        {
          Sn = Sn_1;
        }
        else
        {
          newSn = Sn_1 + Sn;
          Sn_1 = Sn;
          Sn = newSn;
        }
      }
      else if ( An == 2 )
      {
        if ( B < 1 || B >= 7 )
        {
          Sn = Sn_1;
        }
        else
        {
          newSn = Sn_1 + Sn;
          Sn_1 = Sn;
          Sn = newSn;
        }
      }
      else
      {
        Sn_1 = Sn;
      }
    }

    cout << Sn << endl;
  }

  return 0;
}
