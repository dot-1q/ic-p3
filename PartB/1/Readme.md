How To Compile & Run:

Compile:
```bash
g++ main.cpp Lang.cpp ../../PartA/FiniteContextModel.cpp ../../PartA/CircularBuffer.cpp -o lang
```
Run:
```bash
./lang [-k-] [-alpha-] [-reference text file path-] [-analysis text file path-]
```
- Example:
```bash 
./lang 5 0.3 ../../Texts/Ref_texts/French_latn_EP7.utf8 ../../Texts/Analysis_texts/Memorie_di_un_cacciatore.txt
```

Reference Texts Directory Path:

- "../../Texts/Ref_texts"

Analysis Texts Directory Path:

- "../../Texts/Analysis_texts/"

