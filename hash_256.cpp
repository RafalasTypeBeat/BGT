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

const unsigned int hashes[8] = 
        {
          0x6a09e667,
          0xbb67ae85,
          0x3c6ef372,
          0xa54ff53a,
          0x510e527f,
          0x9b05688c,
          0x1f83d9ab,
          0x5be0cd19
        };

const unsigned int sha256_k[64] = 
        {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
        };

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


  for (int i = 0; i < 8; i++)
  {
    buffer.assign(s, index, 32);
    data.push_back(buffer);
    index += 32;
    cout<<data[i]<<" "<<index<<endl;
  }     //padalina string i 32 bitu blokus
  
  for (int i = 0; i < pow; i++)
  {
    generateBlocks(data);
  }
  
  cout<<endl<<index;
  return "";
}

void rightrotate(string &s, int d)    // 01100001011000100110001110000000 ULONGAS
{
    reverse(s.begin(), s.end() - d);  // ULONGAS -> NOLUGAS  01100001011000100110001110000000 -> 00001101011000100110001110000000  ULONGAS -> OLUNGAS
    reverse(s.end() - d, s.end());    // NOLUGAS -> NOLUSAG  00001101011000100110001110000000 -> 00001100000000111000110010001101  OLUNGAS -> OLUNSAG
    reverse(s.begin(), s.end());      // NOLUSAG -> GASULON  00001100000000111000110010001101 -> 10110001001100011100000000110000  OLUNSAG -> GASNULO
}

string sigma0(string s)
{
  vector<string>::iterator itr;
  rightrotate(s, 7);
  rightrotate(s, 18);
}

string sigma1(string s)
{
  rightrotate(s, 17);
  rightrotate(s, 19);
}

void generateBlocks(vector<string> s)
{
  vector<string> hash = s;
  string calc = "";
  for (int i = 8; i < 32; i++)
  {
    calc = sigma0(hash[i-2]);
  }
  
}

// formatInput(input)
// {
//   while(.length() < 223) //32bitai zinutes ilgui
//   {
    
//   }

// }
