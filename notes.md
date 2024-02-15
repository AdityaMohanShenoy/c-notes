# QUESTIONS 
    1. DIFFERENCE BETWEEN FORMATED AND UNFORMATED INPUT OUTPUT FUNCTION 
    2. VARIABLE DECLARATION AND INITIALISATION 
        ans : declaration int a;    initialisation(value) int a = 2;
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

# 

    %e - float printed in exponential form 
    %g - strips trailing zeroes
    %u - unsigned int

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

# OPERATORS AND EXPRESSIONS
OPERATOR - symbol used for calculations or evaluations. They have rank, precedence and associativity.


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
     