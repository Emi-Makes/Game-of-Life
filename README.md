# Conway's Game of Life

It's in the name. Entirely self-taught project made
over roughly a week of study and practice.

There are some flaws with this project that I recognized
while making it. Displaying the board to the screen is
woefully unoptimized, creating unique starting positions
is tedious, and I'm pretty sure my implementation of the
game logic wouldn't be considered "cellular automata", 
as the individual cells are not technically acting autonomously.

## Personal Notes/Tasks

- [ ] Read starting pos from file
- [x] Implement game logic
  - [x] Read each cell
    - [x] Count and store adjacent live cells
      - [x] Implement grid as torus
    - [x] Check against criteria; Edit cell if necessary
    - [x] Write edited cell to new board
  - [x] Overwrite old board with new board; Loop
- [x] Grid size and interval as cmd arguments
- [ ] "Age" variable
  - [ ] Cell age increases by 1 each generation
  - [ ] Cell "size" increases with age (-+x#)
    
  0 1 2 3 4 5 6 7 8
0 - - - - - - - - -
1 - - - - - - - - - 
2 - - - - - - - - - 
3 - - - - - - - - - 
4 - - - - # - - - - 
5 - - - - - - - - - 
6 - - - - - - - - - 
7 - - - - - - - - - 
8 - - - - - - - - -  

Adjacent cells

__Up:__
\[r-1][c]

__Down:__
\[r+1][c]

__Left:__
\[r][c-1]

__Right:__
\[r][c+1]

__Up-Left:__
\[r-1][c-1]

__Up-Right:__
\[r-1][c+1]

__Down-Left:__
\[r+1][c-1]

__Down-Right:__
\[r+1][c+1]

