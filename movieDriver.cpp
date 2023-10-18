#include <iostream>
#include <queue>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "semaphore.cpp"

using namespace std;

const int MAX_MOVIE_NAME_LENGTH = 100;   //maximum movie name length
const int MAX_FILE_NAME = 50;   //maximum filename lenght
const int MAX_MOVIES = 1000;    //maximum number of movies
const int MAX_THREADS = 1000;
const int BUFFER_SIZE = 200;

int buf_size=BUFFER_SIZE;

std::queue<char*> list;
char aMovie[MAX_MOVIE_NAME_LENGTH];

Semaphore fullSlots(0);
Semaphore emptySlots(buf_size);
Semaphore syncMovies(1);
//Semaphore protectAMovie(1);

char* getMovie(char* fileName)
{
  char *lineBuffer;
  int lineLength = 0;
  char linesOfFile[MAX_MOVIES][MAX_MOVIE_NAME_LENGTH];
  FILE *myFile;
  int numberLines = 0;
  int lineToReturn;
  
  //open file
  
  //seed the thread-safe random number generator
  unsigned int seed = time(NULL);

  //open the file sent as the parameter and read the file into the 
  //2D array structure

  //select a random line between 0 and numberLines
  //copy the contents from that line in the 2D array and return it.


  //HINT - you don't need to protect this function with semaphores.
  //You can do that in the calling function
  
  return "A random movie\n";
}

void MovieProducer (char * fileName){

    char movie[MAX_MOVIE_NAME_LENGTH];

    //use semaphores to protext your queue (and any other shared memory)

    //get a movie from the getMovie function
    //place it in the queue

    //print the output expected in the sample run
    
}

void MovieConsumer (){
 
  //use semaphores to protect the queue
  //collect the movie produced and print the expected output
  
}

void printHelp(char* arg)
{
  printf ("Usage: %s -p number of producers -c number of consumers -f movie filename\n", arg);
  exit(1);
}
int main(int argc, char* argv[]) {
   
  int opt;
  int j = 0;
  char movieFileName[MAX_FILE_NAME];

  int numProducers=0;
  int numConsumers=0;

  //take care of command line arguments first
  if (argc !=7)
  {
      
        printHelp(argv[0]);
  }
  else
  {
    cout.flush();
    while ((opt = getopt(argc, argv, "p:c:f:")) != -1) {
      switch (opt) {
        case 'p':
          numProducers = atoi(optarg);
          break;
        case 'c':
          numConsumers = atoi(optarg);
          break;
        case 'f':
          sprintf(movieFileName, "%s", optarg);
          break;
        default:
          printHelp(argv[0]);
      }
    }
    cout << "In main with - " << movieFileName << ", " << numProducers << " producers, " << numConsumers
      << " consumers\n";

    //got arguments, now do the work
    
    //create and execute arrays of threads for both producers and consumers

    //don't call them sequentially, but interleave producers and consumers
    
    //HINT - since the producers are reading from a file (the same file), you 
    //can sleep for one second after calling each producer

    //also to make sure to always close files and deallocate any allocated data.
  } 
  return 0;
}
