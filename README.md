# Lem-in
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Overview](#Overview)
### General Info
***
Pathfinding for ants in rooms with multiples links
## Technologies
***
A list of technologies used within the project:
* [Djkstra algorithm](https://fr.wikipedia.org/wiki/Algorithme_de_Dijkstra)
* [Langage C]
* [Linked lists]
## Installation
***
A little intro about the installation. 
```
$ git clone git@github.com:EpitechPromo2027/B-CPE-200-BDX-2-1-lemin-killian.trouve.git
$ cd B-CPE-200-BDX-2-1-lemin-killian.trouve
$ make
$ ./lem_in

```
## Overview
***
```
∼/B-CPE-200> cat input
34
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 0
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```
```
∼/B-CPE-200> cat anthill
3
##start
0 1 0
##end
1 13 0 #bedroom
2 5 0
# The next room is the kitchen
3 9 0
0-2
2-3
3-1
```
```
∼/B-CPE-200> ./lem_in < anthill
#number_of_ants
3
#rooms
##start
0 1 0
##end
1 13 0
2 5 0
3 9 0
#tunnels
0-2
2-3
3-1
#moves
P1-2
P1-3 P2-2
P1-1 P2-3 P3-2
P2-1 P3-3
P3-1
```
```
∼/B-CPE-200> ./lem_in < anthill
#number_of_ants
3
#rooms
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
#tunnels
0-2
0-3
2-1
3-1
2-3
#moves
P1-2 P2-3
P1-1 P2-1 P3-2
P3-1
```