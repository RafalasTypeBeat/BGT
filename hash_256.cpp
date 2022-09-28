#include <iostream>
#include <string>
#include <sstream>

using std::string;

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
  std::stringstream toHex;
  for (const auto &item : input)
  {
    toHex<<std::hex<<int(item);
  }
}