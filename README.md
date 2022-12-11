## 256 bit hash generatorius

# Programos paleidimas
- git clone https://github.com/RafalasTypeBeat/BGT.git
- Atsidaryti projektą VS code aplinkoje
- Konsolėje parašyti komandą make
- Konsolėje paleisti sukompiliuotą main.exe tipo programą su komanda ./main
- Priima failo, kurio duomenis norima hash'inti, adresą kaip command line argument

# Maišos funkcijos pseudo kodas
<pre>
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
- 5. Efektyvumas:
- <br/>![image](https://user-images.githubusercontent.com/92015185/206902565-4e92bbc5-0da7-4238-8b7f-fd29777c1a37.png)
