#include<stdio.h>
int main()
{
char message[100], ch;
int i, key;
printf("enter a plain text  ");
gets(message);
printf("Enter key: ");
scanf("%d", &key);
for(i = 0; message[i] != '\0'; ++i){
ch = message[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch + key;
if(ch > 'z'){
ch=ch-'z'+'a'-1;
}
message[i] = ch;
}
else if(ch >='A'&& ch<='Z'){
ch = ch + key;
if(ch > 'Z'){
ch=ch-'Z'+'A'-1;
}
message[i] = ch;
}
}
printf("encrypted message is (cipher text)  %s ", message);
for(i = 0; message[i] != '\0'; ++i){
ch = message[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch - key;
if(ch < 'a'){
ch=ch+'z'-'a'+1;
}
message[i] = ch;
}
else if(ch>='A'&&ch<='Z'){
ch = ch - key;
if(ch < 'A'){
ch=ch+'Z'-'A'+1;
}
message[i]=ch;
}
}
printf("\ndecrypted message is (plain text)  %s", message);
return 0;
}
