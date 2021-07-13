#include<stdio.h>
#define VALID 1
#define INVALID 0
int isColValid(int mat[9][9],int nor,int noc)
{
 int flag[10]={0};
 int row,col;
  for(col=0 ; col<noc; col++)
  {
      for(row=0 ;row< nor;row++)
      {
        if(flag [ mat[row][col] ]==col)
          flag [ mat[row][col] ] = flag [ mat[row][col] ] +1;
       else
         return INVALID;
      }
   }
   return VALID;
}
int isRowValid(int mat[9][9],int nor,int noc)
{
 int flag[10]={0};
 int row,col;
  for(row=0 ;row< nor;row++)
  {
      for(col=0 ; col<noc; col++)
      {
        if(flag [ mat[row][col] ]==row)
          flag [ mat[row][col] ] = flag [ mat[row][col] ] +1;
       else
         return INVALID;
      }
   }
   return VALID;
}
int isSubCheck(int mat[9][9],int srow,int scol)
{
    int row,col;
    int flag[10]={0};
    for(row= srow ; row<srow+3;row++)
     {
          for(col=scol ; col< scol+3;col++)
            {
                if(flag [ mat[row][col] ]==0)
                    flag [ mat[row][col] ] = flag [ mat[row][col] ] +1;
                else
                    return INVALID;
            }
     }
     return VALID;
}
int isSubValid(int mat[9][9],int nor,int noc)
{
  int row,col;
      for(row=0 ; row<nor;row=row+3)
                for(col= 0 ; col< noc; col=col+3)
                    if(isSubCheck(mat,row,col) ==INVALID)
                            return INVALID;
        return VALID;
}
int main()
{
  int mat[9][9]={
                            {2,3,8,5,4,7,9,6,1},
                            {6,7,4,9,3,1,8,2,5},
                            {5,1,9,8,6,2,3,4,7},
                            {9,2,6,7,5,3,4,1,8},
                            {7,4,1,2,9,8,6,5,3},
                            {8,5,3,6,1,4,2,7,9},
                            {3,9,7,1,2,6,5,8,4},
                            {4,8,2,3,7,5,1,9,6},
                            {1,6,5,4,8,9,7,3,2},
                            };
int nor=9,noc=9;

if(isRowValid(mat,nor,noc)==VALID)
{
        if(isColValid(mat,nor,noc)==VALID)
        {
              if(isSubValid(mat,nor,noc)==VALID)
                  printf("VALID");
              else
                    printf("InValid");
        }
        else
            printf("InValid");

}
else
    printf("InValid");
    return 0;
}
