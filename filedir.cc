//caroline Snyder 4/13/20 recreated LS project

#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>


using namespace std;

int main(){
  string fileTypeValue[8] = {"Unknown File Type","Regular File","Directory File","Character Device",
      "Blcok Device","Buffer File","Socket File","Symbolic Link"};
  DIR *dir;
  struct dirent *files;
  long size;
  char *buffer;

  //pre req for grabbing the current directory
  size = pathconf(".",_PC_PATH_MAX);
  buffer = (char *)malloc((size_t)size);
  //grabs the working directory
  getcwd(buffer, (size_t)size);

  //opens the dir if t doesnt work prints to error and crashes out
   if((dir = opendir(buffer)) == NULL)
    perror("opendir() error");
   else{
    while ((files = readdir(dir)) != NULL){ //while there is stuff in dir keep going
    cout << "file name: " << files->d_name << "  file type: " ;
    int cast = files->d_type; //cast type to int to name it
    cast--;
    cout << fileTypeValue[cast] << endl;

   }
 }

 closedir(dir);


}
