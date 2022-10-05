#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
string hash(string input);

int main()
{
  string input = "";
  std::cout<<"Iveskite savo string: ";
  std::cin>>input;
  std::cout<<"Sugeneruotas hash: "<<hash(input);
}

string hash(string input)
{
  int bytesleft = input.length() % 4; //likusiu baitu skaiciu padalinus is 4
  int blockamount = (input.length() - bytesleft) / 4; //4 baitu blokai
  int blocknr;
  for (const auto &item : input)
  {
    calculation(item, blocknr);
  }
  //cout<<toHex.str()<<endl;
  std::stringstream ss;
  //ss<<std::hex<<int(sum);
  return ss.str();
}
unsigned int calculation(string block, int blocknr)
{

}