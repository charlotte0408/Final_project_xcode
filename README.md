# QT_CORE Implementation 

* This is the Core implementation process of my project. 

## Learning process for QT_Core part 
* Before I developed the algorithm in C++, I played the game several times in order to encounter all the possible cases that I need to consider for my algorithm, including ways to determine win and loss. 
* Then I planned out the whole **structure** for my program 
    * A **class** Matrix with **2D vector** as its underlying structure 
    * Have **member functions** to move(left, right, up, and down), determine win and lose, and generate numbers on random blocks. 
* When implementing:
    * Start from the **LEFT and RIGHT** function
        * **Confused** at first, because when thinking deep about the algorithm there are actually a lot of cases to consider and check. 
        > Look online: https://www.codeproject.com/Articles/1173541/A-Walkthrough-to-Implement-Game. 
        * From this, I learned to split the left function into two parts: add and move. Because considered separately, each of them can be implemented easily. 
    * Got the first attempt, and it seemed to work 
    * However, when I tested the algorithm, it was not the case. :-(
    * **Debugging** steps: continue commenting out unchecked codes from top to the bottom to check which steps cause errors. Also, I learned to print out every step 
    * Three **issues** were found:
        * I kept change the index(terminating) value inside the for loop, which is not a standard way to use the “for” loop. => use while loop inside
        * In the second step: moving, I used lots of nested loops to determine which block should I move my cell to, which confused me a lot and therefore caused errors. => use function instead to reduce the number of nested loops. 
        * Actually, the fatal issue is that I define every row in the matrix as a new variable line, but forgot to update after the actual values were changed due to the move steps.
    * Try the **UP and DOWN** function 
        * First thought to implement from scratch, but it’s hard to manipulate a 2d vector across rows 
        > Look online: https://www.leaseweb.com/labs/2014/03/text-mode-2048-game-c-algorithm-explained/ 
        * The above online enabled me to **think out of box** that the UP and DOWN functions could be implemented by first do rotations on the original matrixes and then use LEFT and RIGHT functions to perform the moves. 
    * Generate **“random”** numbers on “random” positions
        * First learn about the randomness rule about 2048 that 90% is 2 and 10% is 4
        > https://gaming.stackexchange.com/questions/170665/what-is-the-probability-of-4
        * Then learn about how to generate actually random numbers instead of the pseudo ones. 
        > http://www.math.uaa.alaska.edu/~afkjm/csce211/fall2018/handouts/RandomFunctions.pdf
