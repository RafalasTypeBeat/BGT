#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
string hash(string input);
unsigned int getblock(string block, int blocknr);

int main()
{
  string input = "";
  std::cout<<"Iveskite savo string: ";
  std::cin>>input;
  std::cout<<"Sugeneruotas hash: "<<hash(input);
}

string hash(string input)
{
  int x;
  const int bytesleft = input.length() % 4; //likusiu baitu skaiciu padalinus is 4
  const int blockamount = (input.length() - bytesleft) / 4; //4 baitu blokai
  cout<<blockamount<<endl<<bytesleft<<endl;
  for (int blocknr = 0; blocknr < blockamount; blocknr++)
  {
    x = getblock(input, blocknr);
  }
  return input;
}

unsigned int getblock(string block, int blocknr) //funkcija paima po 4 elementus, juos pavercia i ascii decimal vertes ir sudeda
{
  return	 block[(blocknr * 4)] +
      (block[(blocknr * 4) + 1]) +
			(block[(blocknr * 4) + 2]) +
			(block[(blocknr * 4) + 3]);
}