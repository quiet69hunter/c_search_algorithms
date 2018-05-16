/*
The linear and binary search comparison program
Herasymchuk Roman		11.05.2018
*/
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int countLin, countBin; //transitions
void BubbleSort(int Arr[], int n)
{
    int i, j, kl;
    for(i=0; i<n-1; i++){
        for(j=1; j<n; j++){
           if (Arr[j]<Arr[j-1]){
            kl = Arr[j];
            Arr[j] = Arr[j-1];
            Arr[j-1] = kl;
           }
        }
    }
}

int SzukajLiniwo(int x,int Arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        countLin++;
        if(Arr[i]==x){
            return i;
        }
    }
    //cout<<"Elemen "<<x<<" not find"<<endl;
    return -1;
}

int SzukajBin(int x, int Arr[], int n)
{
    int l=0, i;
    while(l<=n){
        countBin++;
        i = (l+n-1)/2;
        if (Arr[i]<x) {
            l = i+1;
        }
        else if(Arr[i]>x) {
                n = i-1;
            }
        else
            return i;
    }

    return -1;
}

int main()
{
    int n, i;
    cout << "Enter the size of the table -->";
    cin>>n;
    int *tab = new int[n];
    for(i=0; i<n; i++){
        tab[i]=rand()%100+1;
    }
    for(i=0; i<n; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    BubbleSort(tab,n);
    for(i=0; i<n; i++){
        cout<<tab[i]<<" ";
    }
    int xi;

    cout<<'\n'<<"What number are you looking for?  ";
    cin>>xi;

    int lin = SzukajLiniwo(xi, tab, n);
    cout<<'\n'<<"Results of linear search "<<endl;
    if (lin!=-1){
        cout<<"Indeks of element = "<<lin<<'\n'<<"transitions = "<<countLin<<endl;}
    else
            cout<<"Element "<<xi<<" not find after "<<countLin<<" transitions"<<endl;

    int bin = SzukajBin(xi, tab, n);
    cout<<'\n'<<"Results of binary search"<<endl;
    if (lin!=-1){
        cout<<"Indeks of element = "<<bin<<'\n'<<"transitions = "<<countBin<<endl;}
    else
            cout<<"Elemen "<<xi<<" not find after "<<countBin<<" transitions"<<endl;
    return 0;
}
