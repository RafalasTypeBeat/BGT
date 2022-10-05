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
  int x, sum=0;
  std::stringstream toHex;
  for (const auto &item : input)
  {
    toHex<<std::hex<<int(item);
    cout<<toHex.str()<<endl;
    toHex>>x;
    cout<<x<<endl;
    sum=sum+(x^70);
    toHex.str("");
    cout<<toHex.str();
    x=0;
  }
  cout<<toHex.str();
  cout<<toHex.str()<<endl;
  cout<<sum<<endl;
  std::stringstream ss;
  ss<<std::hex<<int(sum);
  return ss.str();
}