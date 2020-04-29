/*
 *   Checker for Soccer League
 *   r. anido
 *   ACM2005
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 15
#define MAX_MATCHES 1000
#define MAX_CLUBS MAX_MATCHES
#define TRUE 1
#define FALSE 0

typedef struct aClub {
  char name[MAX_STR+1];
  int points, diff, seen;
} aClub;

int nclubs;
aClub clubs[MAX_CLUBS]; 
FILE *compet_out;

void error(char *msg)
{
  fprintf(stderr, "ERROR: %s\n", msg);
  exit(1);
}

int cmp(const void *a, const void *b) {
  if (((aClub*)a)->points==((aClub*)b)->points)
	 return ((aClub*)b)->diff-((aClub*)a)->diff;
  else
	 return ((aClub*)b)->points-((aClub*)a)->points;
}

void swap(aClub a, aClub b)
{
  aClub tmp;

  tmp = a;
  a = b;
  b = tmp;
}

void insert(char *s)
{
  strcpy(&clubs[nclubs++].name[0], s);
}

int lookup(char *s)
{
  int i;
  
  for (i=0;i<nclubs;i++)
	 if (strcmp(clubs[i].name,s)==0)
		break;
  if (i==nclubs)
	 insert(s);
  return i;
}

int lookup1(char *s)
{
  int i;
  
  for (i=0;i<nclubs;i++)
	 if (strcmp(clubs[i].name,s)==0)
		break;
  return i;
}

int main(int argc, char * argv[])
{
  int i, j, n, x, y, c1, c2, test;
  char name1[MAX_STR+1], name2[MAX_STR+1];
  int points;
  char line[3*MAX_STR], name[3*MAX_STR];

  if (argc != 3) {
    printf("usage:\n%s problem_input_file compet_out_file\n", argv[0]);
    exit(-1);
  }
  freopen(argv[1], "rt", stdin);
  compet_out = fopen(argv[2],"rt");
  test=0;

  while (scanf("%d", &n) == 1 && n!=0) {
	 //		fprintf(stderr,"test case %d... ", ++test);
	 memset(clubs,0,n*sizeof(aClub));
	 nclubs=0;
	 for (i=0; i<n; i++) {
		scanf("%s %d x %d %s", name1, &x, &y, name2);
		c1=lookup(name1);
		c2=lookup(name2);
		if (x>y)
		  clubs[c1].points += 3;
		else if (x<y)
		  clubs[c2].points += 3;
		else {
		  clubs[c1].points++;
		  clubs[c2].points++;
		}
		clubs[c1].diff += x-y;
		clubs[c2].diff += y-x;
	 }
    qsort(clubs, nclubs, sizeof(aClub), cmp);
	 // check result
	 j = 0;
	 for (i=0; i<nclubs; i++)
		clubs[i].seen = FALSE;
	 for (i=0; i<nclubs; i++) {
		if (fgets(line, sizeof(line), compet_out) == NULL)
		  error("expected more lines");
		//printf("read line [%s]\n",line);
		if (sscanf(line, "%d %s\n",&points,name) != 2)
		  error("club is missing");
		if (n<0)
		  error("negative number of points");
		if (strlen(name)>MAX_STR)
		  error("club name too big");
		c1 = lookup1(name);
		if (c1 >= nclubs)
		  error("non-existent club name");
		if (clubs[c1].seen==TRUE)
		  error("club appears twice in table");
		clubs[c1].seen=TRUE;
		if (points != clubs[j].points)
		  error("wrong number of points");
		if (clubs[c1].points != clubs[j].points)
		  error("club appears out of place, number or points");
		if (clubs[c1].diff != clubs[j].diff)
		  error("club appears out of place, goal difference");
		// clubs c1 and j have the same standing
		if (c1 != j)
		  swap(clubs[c1],clubs[j]);
		j++;
	 }
	 if (fgets(line, sizeof(line), compet_out) == NULL)
		error("blank line in input file? should no happen!");
  }
  if (fgets(line, sizeof(line), compet_out) != NULL)
	 error("extra lines in output file");
  fprintf(stderr,"Output is OK\n");
  return 0;
}
