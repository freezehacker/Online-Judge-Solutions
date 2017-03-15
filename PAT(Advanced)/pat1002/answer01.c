#include<stdio.h>  
#include<math.h>  
int main(){  
  freopen("in", "r", stdin);
  
  int i,n,m,Ni,cnt=0,mark[1008];  
  double ni,sum[1008];  
  for(i=0;i<1008;i++){  
    sum[i]=0;  
    mark[i]=0;  
  }   
  scanf("%d",&n);  
  for(i=0;i<n;i++){  
    scanf(" %d %lf",&Ni,&ni);  
    sum[Ni]=sum[Ni]+ni;  
    if(mark[Ni]==0){  
      mark[Ni]=1;  
      cnt++;  
    }    
  }   
  scanf("%d",&m);  
  for(i=0;i<m;i++){  
    scanf(" %d %lf",&Ni,&ni);  
    sum[Ni]=sum[Ni]+ni;  
    if(mark[Ni]==0){  
      mark[Ni]=1;  
      cnt++;  
    }  
  }   
  for(i=1000;i>=0;i--){  
    if(mark[i]==1&&fabs(sum[i])<0.00001){  
      cnt--;  
      mark[i]=0;  
    }  
  }  
  printf("%d",cnt);  
  for(i=1000;i>=0;i--){  
    if(mark[i]==1){  
      cnt--;  
      if(cnt==0)  
        printf(" %d %.1lf\n",i,sum[i]);  
      else  
        printf(" %d %.1lf",i,sum[i]);  
    }  
      
  }   
  return 0;  
}