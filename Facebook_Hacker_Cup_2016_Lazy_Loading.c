/*
LAZY LOADING

Wilson works for a moving company. His primary duty is to load household items into a moving truck. Wilson has a bag that he uses to move these items. He puts a bunch of items in the bag, moves them to the truck, and then drops the items off.
Wilson has a bit of a reputation as a lazy worker. Julie is Wilson's supervisor, and she's keen to make sure that he doesn't slack off. She wants Wilson to carry at least 50 pounds of items in his bag every time he goes to the truck.
Luckily for Wilson, his bag is opaque. When he carries a bagful of items, Julie can tell how many items are in the bag (based on the height of the stack in the bag), and she can tell the weight of the top item. She can't, however, tell how much the other items in the bag weigh. She assumes that every item in the bag weighs at least as much as this top item, because surely Wilson, as lazy as he is, would at least not be so dense as to put heavier items on top of lighter ones. Alas, Julie is woefully ignorant of the extent of Wilson's lack of dedication to his duty, and this assumption is frequently incorrect.
Today there are N items to be moved, and Wilson, paid by the hour as he is, wants to maximize the number of trips he makes to move all of them to the truck. What is the maximum number of trips Wilson can make without getting berated by Julie?
Note that Julie is not aware of what items are to be moved today, and she is not keeping track of what Wilson has already moved when she examines each bag of items. She simply assumes that each bagful contains a total weight of at least k * w where k is the number of items in the bag, and w is the weight of the top item.
Input
Input begins with an integer T, the number of days Wilson "works" at his job. For each day, there is first a line containing the integer N. Then there are N lines, the ith of which contains a single integer, the weight of the ith item, Wi.
Output
For the ith day, print a line containing "Case #i: " followed by the maximum number of trips Wilson can take that day.
Constraints
1 ≤ T ≤ 500 
1 ≤ N ≤ 100 
1 ≤ Wi ≤ 100 
On every day, it is guaranteed that the total weight of all of the items is at least 50 pounds.
Example input:
5
4
30
30
1
1
3
20
20
20
11
1
2
3
4
5
6
7
8
9
10
11
6
9
19
29
39
49
59
10
32
56
76
8
44
60
47
85
71
91
Example output
Case #1: 2
Case #2: 1
Case #3: 2
Case #4: 3
Case #5: 8
Explanation of Sample
In the first case, Wilson can make two trips by stacking a 30-pound item on top of a 1-pound item, making the bag appear to contain 60 pounds.
In the second case, Wilson needs to put all the items in the bag at once and can only make one trip.
In the third case, one possible solution is to put the items with odd weight in the bag for the first trip, and then the items with even weight in the bag for the second trip, making sure to put the heaviest item on top.
*/


#include <stdio.h>
void merging(int a[],int b[],int low, int mid, int high)
{
   int l1, l2, i;
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
   {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   while(l1 <= mid)    
      b[i++] = a[l1++];
   while(l2 <= high)   
      b[i++] = a[l2++];
   for(i = low; i <= high; i++)
      a[i] = b[i];
}
void sort(int a[],int b[],int low, int high)
{
   int mid;
   if(low < high)
   {
      mid = (low + high) / 2;
      sort(a,b,low, mid);
      sort(a,b,mid+1, high);
      merging(a,b,low, mid, high);
   }
   else
      return;
}
int checksort(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;++i)
    {
        j=i;
        t=a[i];
        while(j>0)
        {
            if(a[j-1]<t)
                break;
            else
                return 0;
        }
    }
    return 1;
}
int main()
{
    int t,k=0;
    scanf("%d",&t);
    while(k!=t)
    {
        int n;
        scanf("%d",&n);
        int a[n+1],b[n+1];
        int i,j,c=0,flag=0;
        for(i=0;i<n;++i)
            scanf("%d",&a[i]);
        if(checksort(a,n)==0)
            sort(a,b,0,n-1);
        for(i=0;i<n;++i)
        {
            if(a[i]>=50)
                flag++;
        }
        i=0;int s;
        for(j=n-1;j>=0&&i<j;--j)
        {
            if(a[j]>=50)
                c++;
            else
            {
                s=2;
                for(;i<j;)
                {
                    if((s*a[j])>=50)
                    {
                        c++;i++;break;
                    }
                    else
                    {
                        s++;i++;
                    }
                }
            }
        }
        if(flag!=0 && flag==n)
            c=flag;
        printf("Case #%d: %d\n",k+1,c);
        k++;
    }
    return 0;
}

