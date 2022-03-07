#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int info;
    Node* next;
};
class List:public Node
{

    Node *first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void Buat();
    void Tambahkan();
    void Hapus();
    void tampil();
    void cari();
};
void List::Buat()
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nInput Elemen:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }

    else
    {
        last->next=temp;
        last=temp;
    }
}
void List::Tambahkan()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nInput Elemen:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<"\nInput sebagai\n1:Urutan Pertama\n2:Urutan Terakhir\n3:Antara Awal dan Akhir";
    cout<<"\nInput Pilihan Anda:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nInput posisi yang ingin diInput:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nData tidak dapat diinput";
        break;

    }
}
void List::Hapus()
{
    Node *prev=NULL,*cur=first;
    int count=1,pos,ch;
    cout<<"\nHapus\n1:Urutan Pertama\n2:Urutan Terakhir\n3:Antara Awal dan Akhir";
    cout<<"\nInput Pilihan Anda:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\nElemen yang dihapus adalah "<<first->info;
            first=first->next;
        }
        else
            cout<<"\nTidak dapat dihapus";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\nElemen yang dihapus adalah: "<<cur->info;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\nTidak dapat dihapus";
        break;
    case 3:
        cout<<"\nInput posisi yang ingin dihapus:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\nElemen yang dihapus adalah: "<<cur->info;
            prev->next=cur->next;
        }
        else
            cout<<"\nTidak dapat dihapus";
        break;
    }
}
void List::tampil()
{
    Node *temp=first;
    if(temp==NULL)
    {
        cout<<"\nList kosong";
    }
    while(temp!=NULL)
    {
        cout<<temp->info;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void List::cari()
{
    int value,pos=0;
    bool flag=false;
    if(first==NULL)
    {
        cout<<"List kosong";
        return;
    }
    cout<<"Input nilai yang ingin dicari:";
    cin>>value;
    Node *temp;
    temp=first;
    while(temp!=NULL)
    {
        pos++;
        if(temp->info==value)
        {
            flag=true;
            cout<<"Element"<<value<<"terletak diposisi ke "<<pos;
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Elemen "<<value<<" tidak ditemukan di list";
    }
}
int main()
{
    List l;
    int ch;
    while(1)
    {
        cout<<"\n** MENU Single Link List (SLL) **";
        cout<<"\n1:Buat list\n2:Insertion Data\n3:Deletion Data\n4:Searching Data\n5:Tampilkan\n6:Exit\n";
        cout<<"\nInput pilihan anda:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.Buat();
            break;
        case 2:
            l.Tambahkan();
            break;
        case 3:
            l.Hapus();
            break;
        case 4:
            l.cari();
            break;
        case 5:
            l.tampil();
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}
