#include <iostream>
#include <algorithm>
using namespace std;

int can_be_cooked(int p, int r[], int l, int minutes){
    int pcount=0, temp=1, tempminutes=0;
    for(int i=0;i<l;i++){
        temp=1;
        tempminutes=0;
        while(tempminutes<minutes){
            tempminutes += r[i]*temp;
            temp++;
            if(tempminutes<=minutes)
                pcount++;
        }
    }
    //cout<<pcount<<endl;
    return pcount;
}

int main() {
    
    int p, l, r[50];
    cin>>p>>l;
    for(int i=0;i<l;i++){
        cin>>r[i];
    }
    
    sort(r, r+l);
    
    /*for(int i=0;i<l;i++){
        cout<<r[i]<<" ";
    }*/
    
    int end=0, tempcount=0, j;
    j=1;
    while(tempcount<=p){
        end += r[l-1]*j;
        j++;
        tempcount++;
    }
    
    //cout<<endl<<end<<" "<<tempcount;
    
    int s=1, mid, flag=0;
    int pcount = can_be_cooked(p, r, l, end);
    
    while(s<end){
        mid = (s+end)/2;
        
        //cout<<pcount<<endl;
        //cout<<"mid = "<<mid<<endl;
        //cout<<"s = "<<s<<" and e = "<<end<<endl;
        pcount=can_be_cooked(p, r, l, mid);
        if(pcount>=p){
            /*if(flag){
                break;
            }*/
            end = mid;
        }
        else{
            s = mid+1;
            //flag=1;
        }
    }
    
    cout<<end;
    
    return 0;
}
