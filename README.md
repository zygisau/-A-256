# ŽA-256

![version][version-badge]  

Welcome to my implementation of a popular and most commonly used hash algorithm SHA-256.

## Wall of Fame

These are the main points where my algorithm shines:

- Input size does not matter.
- Output size is always 64 symbols.
- The hash function is deterministic
- The hash function is efficient enough to carry heavy-sized inputs.
- Without any hints about specifics of the algorithm, it is very hard to determine what was the original input

## Wall of Shame

Nevertheless, my algorithm still lacks power and has some fatal security flaws:

- Small changes in the input change only the small part of the hash, thus it is possible to eventually determine some patterns.
- Essentially, the first flaw makes a little bigger possibility for a collision

Long story short, there is always a room for improvement

## How to use it?

Just place it in Your project's directory and write:

```c++
zygisau::ZA256::hash("HashMyPassword123")
```

## Installation

## Programos paleidimas  
Paleisti programą galima keliais būdais.  
- `git clone git@github.com:zygisau/ZA-256.git` <-- jei naudojate SSH key  
- `git clone https://github.com/zygisau/ZA-256.git` <-- kitu atveju  
- `cd ZA-256`  
- Jei naudojate CMAKE, naudoti reikia CMakeLists.txt failą.


## Changelog

### [v0.1](https://github.com/zygisau/ZA-256/releases/tag/v0.1) - (2019-09-25)  
**Pridėta**  

 - Sukurta *static* klasė, turinti hash funkciją.
 - Paruoštas README failas

[version-badge]: https://img.shields.io/badge/version-0.1-yellow.svg