# ŽA-256

![version][version-badge]  

**TLDR: SHA-256 clone**

This is VU ISI Blockchain course's first exercise - implementation of a popular and most commonly used hash algorithm SHA-256

## Wall of Fame

These are the main points where my algorithm shines:

- Input size does not matter.
- Output size is always 64 symbols.
- The hash function is deterministic
- Without any hints about specifics of the algorithm, it is very hard to determine what was the original input
- Function performs best with small inputs

## Wall of Shame

Nevertheless, my algorithm still lacks power and has some fatal security flaws:

- There are collisions, especially with very long texts and very small differences.
- The hash function is not efficient enough to carry heavy-sized inputs.

Long story short, there is always a room for improvement.

![Alt Text](https://media1.tenor.com/images/86f2936e3b4e83969d4096dc3a2635b2/tenor.gif?itemid=13763573)

## Analysis

These are the [Analysis requirements]( https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/1uzduotis-Hashavimas.md#komentarai-d%C4%97l-eksperimentinio-tyrimo-analiz%C4%97s-atlikimo)

If You decide to run tests by your own, results will be saved in `ZA-256\test-data\test-data-results.txt` file.

```
1.1:	547531e4420f0552e25155511545354e514525173145327e2312453e3555f0f3
		fe095da595cacb5e0dad5aba5ade5bfe5e5c018e1f591cbc5ab9e0c99b5c1b5e
		565555c5045505157c5757574505151016504527757c565050555675257d5256
		75776b107350425642211157565745357254522517373157575755350531751a
		56b5715215557a565565562106576525552bb756560b05761576b67655255252

1.2:	753512453575f55525125751512535e5651535555457545250545333555e5560
		3b56656b35737517053a51b256545113575617576457113b53ab41035a565455
		5d8da5dc5a5a5c5e85c95b5be5915aca5e5dfc59a5d5a5b5995a80af5b95badf

1.3:	5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
		5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
        5ca5c59d8095e5cbd5b5aa59cfeb05a95bcbe885dd5d5ac5b5c5ef5c05e5a15e
	
2:	Konstitucija užhash'inta per 4.563s.
```



## Additional analyses

Incoming...



## How to use it?

Just place class file in Your project's directory and write:

```c++
zygisau::ZA256::hash("HashMyPassword123");
```

## Installation

In order to run a program, follow these steps
- `git clone git@github.com:zygisau/ZA-256.git` <-- if You are using SSH

- `git clone https://github.com/zygisau/ZA-256.git` <-- else  

- `cd ZA-256`  

- Run CMakeLists.txt file with CMAKE.

  

There is also a possibility to run a few tests.

- Make sure You have *python 3*

- Run ZA-256/test-data/generate-test-data.py

  ```bash
  python3 generate-test-data.py
  ```
- Go back to project's Make/CMake files and run *test-hash* executable.

## Changelog

### [v0.1.1](https://github.com/zygisau/ZA-256/releases/tag/v0.1.1) - (2019-10-03)

**Created**

- Data generating python program and testing implementation in c++

**Changed**  

- Updated hash algorithm
- Updated README.md file by writing analyses

### [v0.1](https://github.com/zygisau/ZA-256/releases/tag/0.1) - (2019-09-25)  

**Added**  

 - Developed *static* class
 - Created README file

[version-badge]: https://img.shields.io/badge/version-0.1.1-yellow.svg

```

```