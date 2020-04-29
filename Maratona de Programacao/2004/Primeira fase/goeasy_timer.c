/**************************************
 *  Dummy solution for checking the   *
 *  time for the problem              *
 *  GoEasy                            *
 *  ICPC South American Regional 2004 *
 *                                    *
 *  R. Anido                          *
 **************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTRAIN        50        /* maximum number of train itineraries */
#define MAXBUS          50        /* maximum number of bus itineraries */
#define MAXZONE         30        /* maximum number of zones */
#define MAXSTATION      100       /* maximum number of stations */
#define TRUE      1
#define FALSE     0
#define TRAIN     1
#define BUS       2

int zone[MAXSTATION];
int z, s, t, b, start, finish;
int test;

void error(char *s)
{
  fprintf(stderr, "Error in test %d: %s\n", test, s);
  exit(-1);
}

int process(int start, int finish)
{
  int i, j;
  int k, cost;

  cost = 0;
  for (i=0; i<s+b; i++) {
    for (k=0; k<80; k++) {
      for (j=0; j<s+b; j++) {
	cost = k + j*i;
      }
    }
  }
  return cost;
}

int read_map(void)
{
  int i, j, k, l, dummy;
  
  test++;
  memset(zone, 0, sizeof(zone));
  if (scanf("%d %d", &z, &s) != 2) // number of zones, number of stations
	error("no zone/station?");
  if (z==0)
    return(0);
  if (z > MAXZONE || z < 0) {
    error("zone id too large");
  }
  if (s > MAXSTATION || s < 0) {
    error("too many stations");
  }
  for (i=0; i<z; i++) {
    scanf("%d", &k);
    for (j=0; j<k; j++) {
      scanf("%d", &l);
      if (l < 1 || l > s) {
	error("wrong station number");
      }
      l--;
      if (zone[l]) {
	error("station in two zones?");
      }
      zone[l] = i;
    }
  }
  scanf("%d %d", &t, &b);
  if (t < 1 || t > MAXTRAIN)
	error("too many train itineraries");
  if (b < 1 || b > MAXBUS)
	error("too many bus itineraries");
  for (i=0; i<t; i++) {
    scanf("%d %d", &k, &dummy);
    for (j=0; j<k-1; j++) {
      scanf("%d", &dummy);
    }
  }
  for (i=0; i<b; i++) {
    scanf("%d %d", &k, &dummy);
    for (j=0; j<k-1; j++) {
      scanf("%d", &dummy);
    }
  }
  scanf("%d %d", &start, &finish); // start station, end station
  return(1);
}

int main(void)
{

  test = 0;
  while (read_map()) {
    printf("bogus: %d\n", process(start, finish));
  }
  return 0;
}
