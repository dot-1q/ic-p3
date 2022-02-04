How To Compile & Run:

Compile:
```bash
g++ main.cpp Findlang.cpp ../../PartA/FiniteContextModel.cpp ../../PartA/CircularBuffer.cpp ../1/Lang.cpp -o findlang
```
Run:
```bash
./findlang [-k-] [-alpha-] [-analysis text file path-]
```

- Example:
```bash 
./findlang 5 0.3 ../../Texts/Analysis_texts/Os_Maias.txt
```

Analysis Texts Directory Path:

- "../../Texts/Analysis_texts/"