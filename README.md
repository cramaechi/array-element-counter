# Integer counter
A program that reads in integers from the user and prints out a two-column list<br />
specifying the distinct integers and the occurrences of each integer.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/integer-counter.git
   ```
    or [download as ZIP](https://github.com/cramaechi/integer-counter/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd integer-counter
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./integer_counter
```

Sample Output:
```
Enter up to 50 numbers: 4 5 5 3 4 3 2 5 5 2 9 5 9 5 2 5 0 1 3 1 0 4 5 -2 3 5 2 5 -1                                   
                                                                                                                      
 Integer   Count                                                                                                      
 9         2                                                                                                          
 5        10                                                                                                          
 4         3                                                                                                          
 3         4                                                                                                          
 2         4                                                                                                          
 1         2                                                                                                          
 0         2                                                                                                          
-1         1                                                                                                          
-2         1  
```
