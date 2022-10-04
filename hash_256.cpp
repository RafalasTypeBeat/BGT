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
  int x;
  std::stringstream toHex;
  for (const auto &item : input)
  {
    toHex<<std::hex<<int(item);
  }
  cout<<toHex.str()<<endl;
  toHex>>x;
  x=x^70;
  cout<<x<<endl;
  std::stringstream ss;
  ss<<std::hex<<int(x);
  return ss.str();
}