#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <bitset>

using std::string;
using std::cout;
using std::endl;
string toBinary(int x);
string hash(string input);

int main()
{
  string input = "";
  cout<<"Iveskite savo string: ";
  std::getline(std::cin, input);
  cout<<"Sugeneruotas hash: "<<hash(input);
}

/*prideti 0 gale kad butu 256bitai
paskutiniai bitai parodo kiek simboliu buvo zinutej

*/
string toBinary(int x)
{
  std::bitset<8> bin_x(x);
  return bin_x.to_string();
}

string hash(string input)
{
  string s = "";
  string orgLenght = toBinary(input.length()); //reikia padaryti int to binary conversion
  cout<<input.length()<<endl;
  for (int i = 0; i < input.length(); i++)
    {
        s += toBinary(input[i]);
    } //convert to binary
  s += '1'; //pazymeti, nuo kur prasideda pridetiniai nuliai
  int pow = (s.length() + 64) / 256; // koks 256 laipsnis
  if(pow < 1) pow++;
  int apendZeros = (256 * pow) - s.length() - 64;

  s.append(apendZeros, '0'); 
  cout<<s;
  return "";
}

// formatInput(input)
// {
//   while(.length() < 223) //32bitai zinutes ilgui
//   {
    
//   }

// }
