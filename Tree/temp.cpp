#include <bits/stdc++.h>
using namespace std;

int main() {
    // string SoftToys[] = {"Giant-Teddy-Bear", "Giraffe", "Cat", "Mega-Bear", "Dog", "Lion", "Billy-Bear", "Besty-Bear",
    //                     "Monkey", "Bobby-Bear", "Bunny-Rabbit", "Benjamin-Bear", "Kung-Fu-Panda", "Brown-Bear", "Pink-Bear",
    //                     "Baby-Elephant", "Blue-Fish", "Hippo", "Cute-Pig","Pikachu", "Doremon", "Tortoise", "Cater-Pillar", "Candy-Doll"};

    string SoftToys[] = {"GIANT-TEDDY-BEAR", "GIRAFFE", "CAT", "MEGA-BEAR", "DOG", "LION", "BILLY-BEAR", "BESTY-BEAR",
                        "MONKEY", "BOBBY-BEAR", "BUNNY-RABBIT", "BENJAMIN-BEAR", "KUNG-FU-PANDA", "BROWN-BEAR", "PINK-BEAR",
                        "BABY-ELEPHANT", "BLUE-FISH", "HIPPO", "CUTE-PIG","PIKACHU", "DOREMON", "TORTOISE", "CATER-PILLAR", "CANDY-DOLL"};

    int n= 24;
    string toDelete;
    cin>>toDelete;

    int j=0, i=0;
    for( i=0;i<n;i++)
    {
        if(SoftToys[i]!=toDelete)
        {
            SoftToys[j]=SoftToys[i];
            j++;
        }
    }

    if(i==j)
    {
        cout<<"ITEM UNAVAILABLE";
    }
    else
    {
        for(int i=1 ; i<=23; i++)
        {
            cout<<i<<"."<<SoftToys[i-1]<<" ";
        }
    }
    
}