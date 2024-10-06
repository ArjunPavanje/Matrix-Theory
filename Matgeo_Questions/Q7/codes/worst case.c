#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(){
    char s1[499];
    char s2[499];
    int ar1[26]={0};
    int ar2[26]={0};
    scanf("%s %s",s1,s2);
    int i=0; int c=0;
    while(s1[i]!='\0'){
        int k;
        if((s1[i]-'A')>25){
            k=s1[i]-'a';
        }
        else{
            k=s1[i]-'A';
        }
        ar1[k]+=1;
        i++;
        c++;
    }
    int cs=0;
    i=0;
    while(s2[i]!='\0'){
        int k;
        if((s2[i]-'A')>25){
            k=s2[i]-'a';
        }
        else{
            k=s2[i]-'A';
        }
        ar2[k]+=1;
        i++;
        cs++;
    }
    int ans=1;
    for(int i=0;i<26;i++){
        if(ar1[i]!=ar2[i]){
            ans=0;
            break;
        }
    }
    if (ans==1){
        printf("yes");
        return 0;
    }
    int len=c-1;
    while(len>0){
        int l=0; int u=len-1;
        while(u<=(c-1)){
            char s4[len];
            char s3[len];
            int k2=0;
            int l1=0;int u1=len-1;
            for(int i=l;i<=u;i++){
                s3[k2]=s1[i];
                k2++;
                }
                printf("%s\n",s3);/*
            while(u1<=(cs-1)){
                int k1=0;
                for(int j=l1;j<=u1;j++){
                    s4[k1]=s2[j];
                    k1++;
                }
                int ar3[26]={0};
                int ar4[26]={0};
                int l=0;
                while(s3[l]!='\0'){
                    int k;
                    if((s3[l]-'A')>25){
                        k=s3[l]-'a';
                    }
                    else{
                        k=s3[l]-'A';
                    }
                    ar3[k]+=1;
                    l++;
                }
                l=0;
                while(s4[l]!='\0'){
                    int k;
                    if((s4[l]-'A')>25){
                        k=s4[l]-'a';
                    }
                    else{
                        k=s4[l]-'A';
                    }
                    ar4[k]+=1;
                    l++;
                }
                int ans1=1;
                for(int m=0;m<26;m++){
                    if(ar3[m]!=ar4[m]){
                        ans1=0;
                        break;
                    }
                }
                if(ans1==1){
                    printf("%s %s",s3,s4);
                    return 0;
                }
                ans=1;
                for(int k=0;k<len;k++){  
                    char c3=s3[k]; char c4=s4[k];
                    if(c3!=c4){
                        ans=0;
                        break;
                    }
                }
                if(ans==1){
                printf("%s %s",s3,s4);
                return 0;
                }
                l1++;u1++;s4[len-1]='\0';
            }*/
            l++;u++;s3[len-1]='\0';
       }
       len--;
    }
    printf("no");
    return 0;
}
