#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <bitset>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;
string toBinary(int x);
string hash(string input);

int main()
{
  string input = "";
  cout<<"Iveskite savo string: ";
  std::getline(std::cin, input);
  cout<<"Sugeneruotas hash: "<< endl << hash(input);
}

/*prideti 0 gale kad butu 256bitai
paskutiniai bitai parodo kiek simboliu buvo zinutej

*/
string toBinary(int x)
{
  //cout << x <<endl;
  std::bitset<8> bin_x(x);
  //cout<<bin_x<< endl;
  return bin_x.to_string();
}

string hash(string input)
{
  string s = "";
  std::bitset<32> orgLenght(input.length());
  //cout<<input.length()<<endl;
  for (int i = 0; i < input.length(); i++)
    {
        s += toBinary(input[i]);
    } //convert to binary
  s += '1'; //pazymeti, nuo kur prasideda pridetiniai nuliai
  int pow = (s.length() + 32) / 256; // koks 256 laipsnis
  if(pow < 1) pow++;
  int apendZeros = (256 * pow) - s.length() - 32; //32bitai saugoti string ilgiui
  s.append(apendZeros, '0'); //padaro 224 bitu ilgio
  s += orgLenght.to_string();

  cout<<s<<endl;
  
  int size = pow * 8;

  vector<string> data;

  int index = 0;
  string buffer;

  for (int i = 1; i <= pow * 8; i++)
  {
    buffer.assign(s, index, 32);
    data.push_back(buffer);
    index += 32;
    cout<<data[i - 1]<<" "<<index<<endl;
  }   //padalina string i 32 bitu blokus

  cout<<endl<<index;
  return "";
}

// formatInput(input)
// {
//   while(.length() < 223) //32bitai zinutes ilgui
//   {
    
//   }

// }
