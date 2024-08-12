#include <stdio.h>
#define MAX_LINE 256

int main() {
  FILE *file;
  char line[MAX_LINE];
  int is_stack = 0;
  int push_count = 0,  pop_count = 0, forFunc = 0, inIf = 0;

  // Open a file in read mode
  file = fopen("..\\sampleStackFile.c", "r");

  if (file == NULL)
  {
    printf("File content not found.");
    return -1;
  }
  
  // Store the content of the file
  char fileContent[100000];

  // Read the content and print it
  while(fgets(fileContent, MAX_LINE, file)) {
    if(strstr(line, "for"))
    {
        forFunc += 1;
        char *start, *end;
        if(strstr(line, "<"))
        {
            start = strstr(line, "<");
            end = strstr(line, "<");
            while(is_integer(end))
            {
                end++;
            }
            int loopedFor =  (int) (start, end);

        }
    }
    if(strstr(line, "if"))
    {
        inIf += 1;
    }
    if(strstr(line, "}"))
    {
    }
    printf("%s", fileContent);
  }

  // Close the file
  fclose(file);

  return 0;
}
