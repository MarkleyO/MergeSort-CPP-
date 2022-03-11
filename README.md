# Merge Sort C++ Implementation

<p>My implementation of the Merge Sort algorithm in C++. Included is the CPP file, a make file, a file with test cases, and a bash script for easy testing. Given a list, the program will return the list sorted from smallest to largest.</p>

# Setup and Use

<p><b>Installation:</b></p>

<p>Clone the repo to desired location</p>

<p><b>Compiling / Running:</b></p>

<p>Make sure that the shell script is executable, using the following command in the project directory.</p>

<code>chmod u+x test.sh</code>

<p>Execute the script by running in the same location.</p>

<code>./test.sh</code>

<p>This scipt will first run the make file and compile the project, before directing the file 'testvalues' to the program as input. The sorted list will be printed as a list of comma separated values.</p>

<p>NOTE: <code>make clean</code> may be used in order to create a clean working environment as well.</p> 

<p><b>Testing:</b></p>

<p>A valid list is considered to be one that is comprised of an integer number, followed by a comma with no spaces (EX: 5,4,3,2,1). The end of a list is recognized by the end of a line. Entires in the 'testvalues' file may be changed, and as many as desired may be included. An empty line is not considered valid, but will not break the program.</p>

# Pseudocode


```
Mergesort (array, left, right)

        IF right > left :

            middle = left + (right - left) / 2

        Mergesort (array, left, middle)
        

        Mergesort (array, middle +1, right)
        

        Merge (array, left, middle, right)
        
```