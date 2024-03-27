# strings 
* an array of characters terminated by null character by null character {'a','e','i','\0'}
* until the null character everything will be printed as one unit : printf("%s",arr)
* char str2[4]={'s','t','r'} // its an array of char as well as strings cuz partial ini
* char str3[]={"pesu"}//size is 5 (4 + /0)
* if(str1 == str2) printf("equal");else printf("not equal"); soln : not equal (cuz adress loac diff)
  
# string manipulation and string.h
* strlen gives the length of string withought counting the null character 
* sizeof gives the size including null character
* Functions
  * int strlen(char *str)
  * char strcpy(char *dest,const char * sorce)// string copy 
  * char strcat(char *dist,const char *source) // string concatination 
  * char* strchr( const char *str , char ch) //gives pointer to the first occurenece of ch in const str 
  * char* strrchr
  * strncpy(dest,src,n) // copies n characters of a string withought null char so we have to to //  dest[n]="/0"
  * 