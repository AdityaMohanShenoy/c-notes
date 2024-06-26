# QUESTIONS 
    1. DIFFERENCE BETWEEN FORMATED AND UNFORMATED INPUT OUTPUT FUNCTION 
        ans : format = They tell the program how to format or interpret the data being passed to or read from the scanf() and printf() functions.

    2. VARIABLE DECLARATION AND INITIALISATION 
        ans : declaration int a;    initialisation(value) int a = 2;

    3. DIFFERENCE BETWEEN SEMATIC AND LOGICAL ERROR
        ANS: ● A semantic error is a type of error that occurs when the code violates the rules or constraints of the language, leading to undefined behavior. Semantic errors are caused by incorrect usage of language constructs or incorrect assumptions about the behavior of the program
        ● A logical error occurs when the program runs without any syntax errors or warnings, but the output or behavior is not what was intended due to a mistake in the programmer’s
        logic or reasoning. Logical errors are sometimes called "bugs" in the program
    4. Rvlaue and Lvalue
        ANS : pesu notes pg 49 

# intresting points

       1. char ch='pqrs' output is s
       2. Assignment is considered as an expression in ‘C’
       3. n = scanf(“%d,%d”,&a,&b); //If user enters 20 30, a becomes 20, value of b is undefined
           and 1 is returned by the function
       4. // If I enter p<space>q, q will not be stored in y. Only space is stored. This can be avoided using
           fflush(stdin) function between two getchar function calls. This function clears the key board
           buffer.
           // fflush(stdin) –windows
       5. *TYPE IS A COMPILE TIME MECHANISM*
       6. If we want to only declare variables and not to define it i.e. we do not want to
           allocate memory, then the following declaration can be used.
           extern int a; // We will discuss this in Unit - 5
       7. sizeof is compile time uniary operator
       8. The limits.h header file has the maximum and min *value* a data type can store
       9.  ![INTEGER LITERAL](image-2.png)
           ![OUTPUT](image-3.png)
           * %d converts octal or hex to decimal *
           * %o gives the octal value *
           * %x gives the hexadecimal equivalent *
       10.A constant has only R-value. An initialized variable has both l and r value. An expression of the form a + b is only a R-value.
       11.*The only operator which gives a value back is the dereferencing operator*.
       12. *%p is format specifier for an adress location pointer * 
       13. the size of a pointer in 64 bit pc is always 8 bytes irrespestive of the type
       14. 
        
# C PROGRAM BEHIND THE SCENES [[gfg]](https://www.geeksforgeeks.org/compiling-a-c-program-behind-the-scenes/)
    1. pre processor = expands all micros(stdio.h,add(a,b)=a+b)=output file = filename.i
    
    2. compiling = conversts evrythong to assembly level language = output file = filename.s
    
    3. assembler = converts assembly level code to machine level code = output file = filename.o
    
    4. linker = links all the definition of the functions used in the main code (printf) ** adds some extra code ** = a.exe or -o filename.exe
# FORMAT STRING

    field_width  

    precision

    conversion_char

    flags

    %[flags][field_width][precision]conversion_char  -> [] - optional

# "char" datatype
    1. It can also store symbols such as '!', and digits such as '7'.
    
    2. Regarding memory allocation, a signed char lets you store numbers ranging from [-128 to 127], and uses at least 1 byte (or 8 bits) of memory.An unsigned char stores numbers ranging from [0 to 255].
   
 ```c
        #include <stdio.h>

        int main(void) 
        {

        char initial = 'D';

    }
``` 

# FORMAT SPECIFIERS

![format specifiers](image.png)

## to check max value of a data type in your system 
    INT_MAX
    INT_MIN
    UINT_MAX
    CHAR_MAX
    CHAR_MIN
    FLT_MAX
    FLT_MIN
    DBL_MAX
    DBL_MIN

# input output funcitons

    printf function signature:  
    int printf(const char *format,arg1.arg2......) -> returns number of characters printed.   
    On failure returns negative number.


   # READING INPUT
   ## scanf function signature;  
    int scanf(const char *format,arg1,arg2.......)   
    -> returns number of arguments read by scanf sucessfully   
    ->   Returns 0 is no item was assigned. Returns a negative number if unsucessful.

    by default values are separated using space,tab space, new line, white spaces.

    to separate using comma:
    scanf("%[format specifier],%[format specifier],.....")

    similarily you can use any other separator such as '-' etc

## SYNTAX OF SCANF                                        
```c
    int main();
    {
        int a;
        scanf("%d",&a)
    }
```
## SYNTAX OF PRINTF
```C
    int main();
    {
        int a;
        printf("%d",a)
    }
```


## sizeof 
sizeof(variable/datatype)   
-> retuns long unsigned integer  
                           ->**siizeof is not a function but a typecasting operator**

    2.0 - double not float

    for float - 2.0f


# UNFORMATTED INPUT OUTPUT

unformatted input takes one char unformatted output prints one char

 ## input
    ex: getchar() -> returns integer value of character. On failure returns EOF

    getc() - getc(FILE *fp); -> returns int value of character 

    **not in standard library (included in conio.h)** :

    getch() -> doesnt wait for user to press enter key, no keyboard buffer, doesnt display character.

    getche() - doesnt wait for user to press enter key, no keyboard buffer but displays character.

 ## output
    ex: putchar() -> returns ASCII value of character

        putch() - not in standard library (included in conio.h) 

        putc() - int putc(char, FILE *fp);

# ESCAPE SEQUENCES

    \b - takes cursor one space back erasing previous character   
    \r - takes cursor to the beginning of the line
    \"...."\ - for double quotes in output

# literals

# OPERATORS AND EXPRESSIONS
OPERATOR - symbol used for calculations or evaluations. They have rank, precedence and associativity.
    ![good example]](image-4.png)

  ## based on operation:
    -arithmetic
    -relational
    -logical
    -bitwise
    -address(&)
    -dereferencing(*)

  ## based on number of operands:
    -unary
    - binary
    -ternary

  ## INCREMENT(++)[cannot be used on variables]:

    int b = a++ - post increment -> current value of a assigned to b then incremented

    int c = ++a - pre increment -> value of a is incremented then assigned to c


### POSTINCREMENT - 
    int a = 2 b=3 
    c = a++ **the value stored in c is 2 and the value of a   changes to 3** [c=2,a=3]

    d = b++ **the value stored in d is 3 and the value of b changes to 4**[d=3,b=4]

## PREINCREMENT

      c=++a **the value of a will be updated and the new value will be given to c**[c=a=3]


### side effects of increment 
```c
        int main();
        {
        int a = 10; 
        printf(a++ + a++);/*we dont know if the old a is taken or new one*/
        }
```
# LOGICAL OPERATIONS 

## logical and (&&)
  1. it is sequence type
  2. short circuit evaluation 
   
   ```c
   int main(){
    int d = 0;
    int e = ++d && d;
    printf("E=%d",e);
    printf("D=%d",d);}
 ```

## relational operators 
    5>4>3
    (5>4)=1
    1>3 false
    so result is 0 

## BITWISE OPERATOR

1. we should us %u (it takes all the bits as unsigned integer)

```c
    int main()
    {
        int a =2 , b=3;
        printf("%u&%u=%u/n",a,b,a&b);

    }
 ```

## ternary operaotor
1. only one ternary operator {?}
   
        (exp1)?exp(2);exp(3)  
        
        
     ** if exp 1 is true exp2 is evaluated else exp 3 is evaluated **
     

# control structutres 
    1. conditioanl - if, if else, nested if, switch 
    2. unconditional - goto , return 
    3. loop - for ,while,do while
   

# pls reserch 
to remove keyboard buffer #include <stdioe_ext.h>
fpurge(stdin)