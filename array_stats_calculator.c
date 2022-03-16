/*
Filename: 2211_assign3
Filetype: C File
Author: Michael Salton
Created on: 02/22/22
Description: display different stats and calculations based on a user inputted array
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//function to print array
void printArray(int array[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
}

//function to reverse array
int* reverse(int array[], int length){
    static int arrayCopy[20];
    for(int i = 0; i < length; i++){
        arrayCopy[i] = array[i];
    }
    for (int low = 0, high = length - 1; low < high; low++, high--){
        int temp = arrayCopy[low];
        arrayCopy[low] = arrayCopy[high];
        arrayCopy[high] = temp;
    }
    return arrayCopy;
}

//function to find the smallest element of an array
int smallest(int array[], int length){
    int smallest = array[0];
    for(int i = 0; i < length; i++){
        if(array[i] < smallest){
            smallest = array[i];
        }
    }
    return smallest;
}

//function to calculate the sum of all elements in an array
int sum(int array[], int length){
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += array[i];
    }
    return sum;
}

//function to swap first and last element of array
void swapped(int array[], int length){
    int temp = array[0];
    array[0] = array[length-1];
    array[length-1] = temp;
}

//function to sort the array in asceding order
void sorted(int array[], int length){
    int temp;
    for(int i = 0 ; i < length - 1; i++){
        for(int j = i + 1; j < length; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(){
    int i=0, length;

    printf("How many integers do you want to enter: ");
    scanf("%d", &length);

    int array[length];

    while(i != length){
        char temp = ' ';
        i=0;
        printf("Please enter your %d integers seperated by spaces: ", length);
        do{
            scanf("%d%c", &array[i], &temp);
            i++;
        } while(temp != '\n');
    }

    printf("\nPart 1:\n");
    printf("    Your array is: ");
    printArray(array, length);
    printf("\n    Your array has %d elements\n", length);
    printf("    The size of the array is %d bytes\n", sizeof(array));

    printf("\nPart 2:\n");
    printf("    Your array in reverse is: ");
    reverse(array, length);
    printArray(array, length);
    reverse(array, length);
    printf("\n");

    printf("\nPart 3:\n");
    printf("    The smallest vlaue in your array is: %d\n", smallest(array, length));

    printf("\nPart 4:\n");
    printf("    The sum of all values in your array is: %d\n", sum(array, length));

    printf("\nPart 5:\n");
    printf("    Your array with first and last element switched is: ");
    swapped(array, length);
    printArray(array, length);
    swapped(array, length);
    printf("\n");

    printf("\nPart 6:\n");
    printf("    Your array in sorted order is: "); 
    sorted(array, length);
    printArray(array, length);

    return 0;
}

/* PART TWO

1. 
    1. "echo *"
        Echo passes the strings thatr are passed to it as arguments, ls * lists all directories in 
        the current directory aswell as all files and directories within those directories. 
        Therefore echo * lists the directories and files in the current working directory as strings.
    2. "rm -i" to be prompted before removing a file or directory. "rm -f" to not be prompted before
        removing a file or directory. If both are used simutaneously whichever one is written second will 
        take precedence.
    3. mv changes the name of the file, you write the old name and the new name and it changed the file 
        to the new name. rename is used for bulk changing names, you can change thousands of files at once.
    4. ELF stands for executable and linkable format. It's a standard file format for executable files.
        In this context it means the binary is little-endian
    5. du shows how much disk space is used for the given file and takes into consideration all blocks 
        not just data blocks. ls shows the file size but the total space in the directory is 
        again shown with all space used not just the data blocks.

2.
    1. mkdir -p grandparent/parent/child
    2. "mkdir hello\ world" or "mkdir 'hello world'"
       "rmdir hello\ world" or "rmdir 'hello world'"
    3. "mkdir -m500 newDir"
    4. "cd -"
    5. 
    
3.
    1.
    2. "chwon --reference=file1 file2"
    3. only stat comman is enough to list all details
    4. "chmod 755 directory"
    5. the default one is a and the permissions that are set by the umask are not affacted
*/

