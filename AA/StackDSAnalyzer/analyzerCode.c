#include <stdio.h>
#include <string.h>

#define MAX_LINE 256
int is_integer(char ch)
{
  return ch == '0' ||  ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5', ch == '6' || ch == '7' || ch == '8' || ch == '9';
}

int findNumber(char after, char* str)
{

  int start, end;
  start = (int) (strchr(str, after) - str);
  end = start;
  while(is_integer(str[end]))
    end++;
  
  char *numString = strncpy(str. syt + start, end - 1 - start);
  return  (int) numString;
}

int main() {
  FILE *file;
  // int is_stack = 0;
  int push_count = 0,  pop_count = 0, forFunc = 0, loopedFor = 1;
  // inIf = 0;

  // Open a file in read mode
  file = fopen("..\\easyStackFile.c", "r");

  if (file == NULL)
  {
    printf("File content not found.");
    return -1;
  }
  
  // Store the content of the file
  char line[MAX_LINE];

  // Read the content and print it
  while(fgets(line, MAX_LINE, file)) {
    if(strstr(line, "for"))
    {
        forFunc += 1;
        if(strstr(line, "<"))
        {
            int startFrom = findNumber('=', line);
            int endBefore = findNumber('<', line);
            loopedFor =  endBefore - startFrom + 1;
            if(loopedFor < 0)
              loopedFor = 0;
        }
    }
    if(strstr(line, "}"))
    {
      forFunc --;
      if(forFunc == 0)
        loopedFor = 1;
    }
    else
    {
          if (strstr(line, "push"))
          {
            push_count += loopedFor;
          }
      
          if (strstr(line, "pop"))
          {
            pop_count += loopedFor;
          }
    }
  //   if(strstr(line, "if"))
  //   {
  //       inIf += 1;
  //   }
  //   if(strstr(line, "}"))
  //   {
  //   }
  //   printf("%s", fileContent);
  }

  // Close the file
  printf("PopCount = %d\nPushCount = %d",  pop_count, push_count);

  fclose(file);

  return 0;
}

