#include<stdio.h>
int main()
{
int a[10],b[10],k=0,c[20],temp,i,j,n,m;
printf("enter the size of first array");
scanf("%d",&n);
printf("enter the elements of first array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\n the elements are");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n enter the size of second array");
scanf("%d",&m);
printf("\n enter the elements of second array");
for(i=0;i<m;i++)
{
scanf("%d",&b[i]);
}
printf("\n the elements are");
for(i=0;i<m;i++)
{
printf("%d\t",b[i]);
}
//sorting array a[] selection sort
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\n sorted first array is");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
//sorting array a[] selection sort
for(i=0;i<m-1;i++)
{
for(j=i+1;j<m;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}
printf("\n sorted second array is");
for(i=0;i<m;i++)
{
printf("%d\t",b[i]);
}
//merging arrays
i=0;
j=0;
k=0;
while(i<n && j<m)
{
if(a[i]<=b[j])
{
c[k++]=a[i++];
}
else
c[k++]=b[j++];
}
while(i<n)
{
c[k++]=a[i++];
}
while(j<m)
{
c[k++]=b[j++];
}
printf("\nthe merged array is");
for(i=0;i<n+m;i++)
{
printf("%d\t",c[i]);
}
return 0;
}



