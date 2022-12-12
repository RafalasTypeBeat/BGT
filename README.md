## 256 bit hash generatorius

# Programos paleidimas
- git clone https://github.com/RafalasTypeBeat/BGT.git
- Atsidaryti projektą VS code aplinkoje
- Konsolėje parašyti komandą make
- Konsolėje paleisti sukompiliuotą main.exe tipo programą su komanda ./main
- Priima failo, kurio duomenis norima hash'inti, adresą kaip command line argument

# Maišos funkcijos pseudo kodas
<pre>
vector<string> s; // 32 bitu blokai, paddinti, kad ilgis butu 256 kartotinis
int index = 0;

string hashed[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
string H1 = hashes[0], H2 = hashes[1], H3 = hashes[2], H4 = hashes[3], H5 = hashes[4], H6 = hashes[5], H7 = hashes[6], H8 = hashes[7], T1 = "", T2 = "";

string calc;

FOR int i = 0; i < pow; i ++: //pow is amount of 256bit blocks
  vector<string> values;
  FOR int k = 0; k < 8; k ++:
    values.assign(s, index, 32);
    index += 32
  FOR int i = 8; i < 32; i ++:
    calc = (rightrotate(values[i - 1][17] xor rightrotate(values[i - 1][19]) xor values[i - 3] xor (values[i - 7][7] xor values[i - 7][18]) xor values[i - 8];
    values.push_back(calc)
  string a = H1, b = H2, c = H3, d = H4, e = H5, f = H6, g = H7, h = H8;
  FOR int i = 0; i < 32; i ++:
    T1 = h xor ((rightrotate(e, 6) xor rightrotate(e, 11)) xor rightrotate(e, 25)) xor ((e ∧ f ) xor (e ∧ g)) xor sha256_k[i] xor values[i];
    T2 = (rightrotate(a, 2) xor rightrotate(a, 13)) xor rightrotate(a, 22)) XOR ((a ∧ b ) xor (a ∧ c) xor (b ∧ c));
    h = g;
    g = f;
    f = e;
    e = d + T1;
    d = c;
    c = b;
    b = a;
    a = T1 + T2;
  H1 = H1 xor a;
  H2 = H2 xor b;
  H3 = H3 xor c;
  H4 = H4 xor d;
  H5 = H5 xor e;
  H6 = H6 xor f;
  H7 = H7 xor g;
  H8 = H8 xor h;
string rez = toHex(H1) + toHex(H2) + toHex(H3) + toHex(H4) + toHex(H5) + toHex(H6) + toHex(H7) + toHex(H8);
</pre>

# Eksperimentinė analizė:
1. Du failai sudaryti tik iš vieno, tačiau skirtingo, simbolio:
- 1Symbol1.txt, Hash - 9090eae421562a88a9a1c11a21aa8933ef352bf7ab3a15877c4c344cb7bc9164
- 1Symbol2.txt, Hash - 3158850fd65e42db86208268e3e1d474b9c75d6b92e6caf0d10dd9a65f824929
2. Du failai sudaryti iš daugiau nei 1000 atsitiktinai sugeneruotų simbolių:
- 1000Symbols1.txt, Hash - 7590e2a552797451403f29f6634763adf423921a9deac6beb2952e73316782b7
- 1000Symbols2.txt, Hash - a0e21d86838ad185e1e709967f5fbda576630fe26fa2a70a5fa59c31592b9323
3. Du failai sudaryti iš daugiau nei 1000 simbolių, bet skiriasi vienu nuo kito tik vienu simboliu:
- 1000Symbols3.txt, Hash - 28e3dbb60ec353fb28b64ad197ac63f1d72cc433b7712d7e1550490383407949
- 1000Symbols4.txt, Hash - 273244f3306490cb4b87c0229b527bd51c3077e13c1444baf15619980d534999
4. Tuščias failas:
- empty.txt, Hash - fab1761db33bff7ea9d0f8abf6b7a43153a2ae90145aa90bf0c3ed8c31528d34
5. Efektyvumas:
<br/>![image](https://user-images.githubusercontent.com/92015185/206902565-4e92bbc5-0da7-4238-8b7f-fd29777c1a37.png)
6. 100 000 atsitiktinių simbolių eilučių porų:
- 25 000 porų po 10 simbolių. Kolizijų skaičius - 0.
- 25 000 porų po 100 simbolių. Kolizijų skaičius - 0.
- 25 000 porų po 500 simbolių. Kolizijų skaičius - 0.
- 25 000 porų po 1000 simbolių. Kolizijų skaičius - 0.
7. 100 000 atsitiktinių simbolių eilučių porų, kuriuos skiria tik vienas simbolis. Įvertinamas gautų hash'ų procentinis skirtingumas:
- Bitų lygmenyje:
  - Minimali skirtingumo reikšmė: **0%**
  - Maksimali skirtingumo reikšmė: **45%**
  - Vidurinė skirtingumo reikšmė: **33%**
- Hexo lygmenyje:
  - Minimali skirtingumo reikšmė: **0%**
  - Maksimali skirtingumo reikšmė: **100%**
  - Vidurinė skirtingumo reikšmė: **94%**
# Išvados:
  - Algoritmas yra pakankamai greitas, tačiau yra kur tobulinti spartumą
  - Atstatyti output į input neįmanoma
  - Funkcija yra deterministinė
  - Minimalūs input pakeitimai absoliučiai pakeičia output