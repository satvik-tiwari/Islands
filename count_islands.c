#include<stdio.h>
#define m 6
#define n 6

void destroy(int *,int,int);
void destroy2(int *,int,int);

int main()
{
  int i,j,c=0;
  int a[m][n];
  
  printf("Enter 1's and 0's in the matrix:\n");
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
  }
  printf("Original Matrix:\n");
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    printf("%d ",a[i][j]);
    printf("\n");
  }

  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      if(a[i][j]==0)
      {
        a[i][j]=9;
        destroy(&a[0][0],i,j);
        if(!(i>m-1) && !(j<0))
        {
          if(a[i+1][j-1]==0)
          {
            a[i+1][j-1]=9;
            destroy(&a[0][0],i+1,j-1);
          }
        }
        c++;
      }
    }
  }
  
  printf("Number of islands: %d\n",c);
  return(0);
}

void destroy(int *A,int I,int J)
{
 
   if(!(J+1>n-1))                  //row in forward direction
   {
      if(*(A+n*I+(++J))==0)
      {
       *(A+n*I+J)=9;
       destroy2(A,I,J); 
      }
      else
      J--;
   }

   if(!(I+1>m-1))
   {
      if(*(A+n*(++I)+J)==0)        //column in downward direction
      {
       *(A+n*I+J)=9;
       destroy2(A,I,J);
      }
      else
      I--;
   }

  if(!(J-1<0))
  {
    if(*(A+n*I+(--J))==0)          //row in backward direction
    {
      *(A+n*I+J)=9;
      destroy2(A,I,J);
    }
    else
    J++;
  }

  if(!(I-1<0))
  {
    if(*(A+n*(--I)+J)==0)         //column in upward direction
    {
      *(A+n*I+J)=9;
      destroy2(A,I,J);
    }
    else
    I++;
  }

  if(!(I+1>m-1) && !(J+1>n-1))            
  {                                //diagonal in south east direction
    if(*(A+n*(++I)+(++J))==0)
    {
    *(A+n*I+J)=9;
    destroy2(A,I,J);
    }
    else
    {
      I--;
      J--;
    }
  }

  if(!(I+1>m-1) && !(J-1<0))
  {                                //diagonal in south west direction
    if(*(A+n*(++I)+(--J))==0)
    {
      *(A+n*I+J)=9;
      destroy2(A,I,J);
    }
    else
    {
      I--;
      J++;
    }
  }

  if(!(I-1<0) && !(J+1>n-1))
  {                                //diagonal in north east direction
    if(*(A+n*(--I)+(++J))==0)
    {
      *(A+n*I+J)=9;
      destroy2(A,I,J);
    }
    else
    {
      I++;
      J--;
    }
  }

}


void destroy2(int *p,int II,int JJ)
{
  
  if(!(JJ+1>n-1))
  {
    if(*(p+II*n+(JJ+1))==0)
    {
      *(p+II*n+(JJ+1))=9;
      destroy(p,II,JJ+1);
    }
  }

  if(!(JJ-1<0))
  {
    if(*(p+II*n+(JJ-1))==0)
    {
      *(p+II*n+(JJ-1))=9;
      destroy(p,II,JJ-1);
    }
  }

  if(!(II+1>m-1))
  {
    if(*(p+(II+1)*n+JJ)==0)
    {
      *(p+(II+1)*n+JJ)=9;
      destroy(p,II+1,JJ);
    }
  }

  if(!(II-1<0))
  {
    if(*(p+(II-1)*n+JJ)==0)
    {
      *(p+(II-1)*n+JJ)=9;
      destroy(p,II-1,JJ);
    }
  }

  if(!(II+1>m-1) && !(JJ+1>n-1))
  {
    if(*(p+(II+1)*n+(JJ+1))==0)
    {
      *(p+(II+1)*n+(JJ+1))=9;
      destroy(p,II+1,JJ+1);
    }
  }

  if(!(II+1>m-1) && !(JJ-1<0))
  {
    if(*(p+(II+1)*n+(JJ-1))==0)
    {
      *(p+(II+1)*n+(JJ-1))=9;
      destroy(p,II+1,JJ-1);
    }
  }

  if(!(II-1<0) && !(JJ+1>n-1))
  {
    if(*(p+(II-1)*n+(JJ+1))==0)
    {
      *(p+(II-1)*n+(JJ+1))=9;
      destroy(p,II-1,JJ+1);
    }
  }
}
