#include <stdio.h>
#include <stdlib.h>

int mat[100][100];
int ejder[100][100];
int n;
int exitExists = 0 ;
int crossroad[100];
int cpointer=0;
int path[500];
int ppointer=0;
int flag = 0;

int crossIsFull()
{
     if (cpointer > 199 )
     {
         return 1;
     }
     else{
        return 0;
     }
}

int crossIsEmpty()
{

    if (cpointer == 0)
    {
        return 1;
    }
    else{
        return 0;
    }

}

void crossPush(int i)
{
   if (!crossIsFull())
   {
       crossroad[cpointer] = i;
        cpointer ++;
   }

}

int crossPop()
{
    int i;
    if (!crossIsEmpty())
    {
        cpointer--;
         i = crossroad[cpointer];
         return i;
    }
}

int pathIsFull()
{
    if (ppointer > 499)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int pathIsEmpty()
{
    if (ppointer == 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}
 void pathPush(int i)
 {
     if(!pathIsFull())
     {
         path[ppointer]= i;
         ppointer++;
     }
 }

 int pathPop()
 {
     int i;
     if(!pathIsEmpty())
     {
         ppointer--;
         i = path[ppointer];
         return i;
     }

 }


void readMatrix()  //reading matrix
{
    int i,j;  // auxiliary variables
   FILE *reader;
   reader = fopen("data.txt","r");
   char *temp[100], *token;  // auxiliary variables
    i=0;

        while(fscanf(reader,"%s",temp)==1)
          {
           token = strtok(temp,",");
           j=0;
             while(token!=NULL)
               {
                mat[i][j]= atoi(token);
                token = strtok(NULL,",");
                j++;
                }
           i++;
         }
    n=j;
}

void printMatrix()  //printing matrix
 {
     int i,j;   // auxiliary variables
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             printf("%d ",mat[i][j]);

         }
         printf("\n");
     }

 }

 int checkExitWithDFS(int i, int j)
 {

     if ((i==n-2) && (j==n-2))
     {
         exitExists = 1;
     }
     else
        {
        if(i<n && j<n)
           {
                  mat[i][j] = 2;

              if (mat[i][j+1]!=0 && mat[i][j+1]!=2)
                   checkExitWithDFS(i,j+1);
              if (mat[i+1][j]!=0 && mat[i+1][j]!=2)
                  checkExitWithDFS(i+1,j);
              if  (mat[i][j-1]!=0 && mat[i][j-1]!=2)
                  checkExitWithDFS(i,j-1);
              if (mat[i-1][j]!=0 && mat[i-1][j]!=2)
                  checkExitWithDFS(i-1,j);}

           }
        }

  void findPath(int i, int j)
 {
     int l,m;
     int itemp;
     int jtemp;

       while (i<n-1 && j< n-1 && !flag)
       {
            // mat[i][j]=-1;
              pathPush(i);
              pathPush(j);
          if (mat[i][j+1] + mat[i+1][j] + mat[i][j-1] + mat[i-1][j]  >= 0)
          {
              crossPush(i);
              crossPush(j);

             //printf("cross push \n ");
          }

          if (mat[i][j+1] ==1)
          {

              mat[i][j]=-1;
              j++;
          }
          else if ( mat[i+1][j] ==1)
          {
              mat[i][j]=-1;
              i++;
          }
          else if (mat[i][j-1] ==1)
          {
               mat[i][j]=-1;
               j--;
          }
          else if (mat[i-1][j] ==1)
          {
               mat[i][j]=-1;
               i--;
          }
          else if ((i==n-2)&& (j == n-2))
          {
              flag =1;
          }
          else if (!crossIsEmpty())
          {
              //printf("crossa girdi \n");
               jtemp = crossPop();
              itemp = crossPop();

              while( i!= itemp && j!= jtemp)
              {

                   mat[i][j]=0;
                  j = pathPop();
                  i = pathPop();

                  //printf("pop yapti \n");
              }

          }
          else
            {
            flag = 1;
            printf("flag 2 \n ");
          }

         /* if (mat[i][j+1] + mat[i+1][j] + mat[i][j-1] + mat[i-1][j]  >= 0)
          {
             // crossPush(i);
              //crossPush(j);
              mat[i][j]=1;
            //  printf("cross push \n ");
          }*/
       }

       for( l=0;l<n; l++)
       {
           for( m=0;m<n; m++)
           {
               ejder[l][m] =mat[l][m];
           }
       }

 }

 void printMaze()
 {
     int i,j;
     for( i=0;i<n; i++)
       {
           for( j=0;j<n; j++)
           {
               if (i%2 ==0)
               {
                   if (j%2==0)
                   {
                       if(ejder[i][j]==-1)
                       {
                           printf(" ");
                       }

                else
                      {
                           printf("+");
                      }

                   }
                   else
                   {
                        if(ejder[i][j]==-1)
                       {
                           printf(" ");
                       }

                       else if (mat[i][j]==0)
                       {
                           printf("-");
                       }
                       else
                       {
                           printf(" ");
                       }
                   }
               }
               else
               {
                   if (j%2 ==0)
                   {
                       if(ejder[i][j]==-1)
                       {
                           printf(" ");
                       }
                       else
                       {
                            printf("|");
                       }
                   }

                   else if(ejder[i][j]==-1)
                       {
                           printf("I");
                       }
                    else if(mat[i][j]==0)
                       {
                           printf("|");
                       }
                       else
                       {
                          printf(" ");
                       }
               }
           }
           printf("\n");
       }

 }

int main()
{
    readMatrix();
    printMatrix();
    checkExitWithDFS(1,1);
    if (exitExists == 1)
    {
        printf("\n exit Exists \n");
        printMatrix();
        printf("\n \n");

        readMatrix();
        findPath(1,1);
        printMatrix();
        printf("\n \n");
        readMatrix();
        printMaze();
    }
    printf("\n \n");

    printf("Hello world!\n");
    return 0;
}
