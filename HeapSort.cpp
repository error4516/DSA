#include<iostream>
using namespace std;
class Heap
{
    int a[50],b[50],n;
public:
    Heap()
    {
        n=-1;
    }
    void insheap(int);
    int delheap();
    void display();
    void heapsort();
};

void Heap::insheap(int item)
{
    int i,j;
    n++;
    i=n;
    while(i>0)
    {
        j=(i-1)/2;
        if(item<=a[j])
        {
            a[i]=item;
            return;
        }
        a[i]=a[j];
        i=j;
    }
    a[0]=item;
}

int Heap::delheap()
{
    int left,right,last,i,item;
    item=a[0];
    last=a[n];
    n--;
    i=0;
    left=1;
    right=2;
    while(right<=n)
    {
        if(last>=a[left] && last >=a[right])
        {
            a[i]=last;
            return item;
        }
        if(a[right]<=a[left])
        {
            a[i]=a[left];
            i=left;
        }
        else
        {
            a[i]=a[right];
            i=right;
        }
        left=(2*i)+1;
        right=left+1;
    }
    if(left==n)
    {
        if(last<a[left])
        {
            a[i]=a[left];
            i=left;
        }
    }
    a[i]=last;
    return item;
}

void Heap::display()
{
    cout<<"\n Elements in heaps are:\n";
    for(int i=0;i<=n;i++)
    {
        cout<<" "<<a[i];
    }
}

void Heap::heapsort()
{
    int ch,temp,j=0;
    do
    {
        cout<<"\n enter item to insert:";
        cin>>item;
        insheap(item);

        cout<<"\n do you want to insert again ? press 1 for Yes and 0 for NO";
        cin>>ch;
    }while(ch!=0);

    cout<<"\n before sorting\n";
    for(int i=0;i<=n;i++)
    {
        cout<<" "<<a[i];
    }
    
    while(n!=-1)
    {
        b[j]=delheap();
        j++;
    }
    
    cout<<"\n after sorting\n";
    for(int i=j-1;i>=0;i--)
    {
        cout<<" "<<b[i];
    }
}

int main()
{
    Heap h=Heap();
    h.heapsort();
    return 0;
}
