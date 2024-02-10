# chess
A chess graphical game with a basic engine, written in `C++`.

## Setup
- `gcc, g++`

_At the moment, the graphical part of the project is broken. It will be re-written later as there are comptability issues between `OSX` and `Linux` distributions. The required setup will be updated when the graphical part will be up again._

## How to run
### Engine part
```console
cd engine_src/ && make
```
then you can run the `engine` executable. It takes a [FEN](https://en.wikipedia.org/wiki/Forsyth–Edwards_Notation) text file as an argument. If no file is passed, it will defaults to the basic chess starting position.

```console
./engine path_to_fen
```
It will print the current position followed by the castling rights following this noting convention
```
K: king side, white
Q: queen side, white
k: king side, black
q: queen side, black
```
and then the player turn `white` or `black`.
In the future, an evaluation of the position will be displayed followed by two moves suggested by the engine.

### Graphical part
_Do not run for now, broken_


## Credits
[malomo42](https://github.com/malomo42) for some SFML help.
