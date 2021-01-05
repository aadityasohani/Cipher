#include<iostream>
#include<conio.h>
#include<cstdio>
#include<string>
#include<cstdlib>

using namespace std;

void encode(string s)
{
    int a;
    string key;
    string encrypt;
    cout<<"Enter your key\n";
    cin>>key;
    int l = key.length();
    for(int i=s.length()-1;i>=0;i--)
    {
        if(isupper(s[i]))
        {
            encrypt+=s[i]+2;
        }
        else if(islower(s[i]))
        {
            encrypt+=s[i]-2;
        }
        else{ encrypt+=s[i];}

        int b;
        for(int j=0;j<l;j++)
        {
            b=rand()%10+60;
            encrypt+=b;
        }
    }
    cout<<encrypt<<endl;
    encrypt="";
}


void decode(string s)
{
    string key,decrypt="";
    cout<<"Enter your key\n";
    cin>>key;
    int l = key.length();
    for(int i=s.length()-1-l;i>=0;i-=l+1)
    {
        if(s[i]>65 && s[i]<94) decrypt+=s[i]-2;
        else if(s[i]>93&&s[i]<123) decrypt+=s[i]+2;
        else decrypt+=s[i];
    }
    cout<<decrypt<<endl;
    decrypt="";
}

int main()
{
    system("color E0");
    string username,password,message="";
    cout<<"ENTER YOUR USER-NAME\n"<<endl;
    cout<<"USERNAME :\t";
    cin>>username;
    char c,want;
    int ch;


    if(username == "@Aaditya")
    {
        cout<<"\nENTER YOUR PASSWORD\nPASSWORD :\t";
        while(c!=' '&& c!=13)
        {
           c = _getch();
           if(c!=' ' && c!=13)
           password+=c;
           cout<<"*";
        }


        if(password=="MU2018")
        {
            do{
                system("cls");
                cout<<"\n\t\t________________________ACCESS GRANTED_____________________________"<<endl;
                cout<<"\t\t_______________________ENTER YOUR MESSAGE___________________________"<<endl<<endl;
                c='a';
                while(c!=13)
                {
                    c = _getch();
                    if(c!=13)
                    message+=c;
                    printf("%c",c);
                }
                printf("\n");
                cout<<endl<<"ENTER YOUR CHOISE\n(1) ENCODE\n(2) DECODE\n"<<endl;
                cin>>ch;
                cout<<endl;
                if(ch==1)
                {
                     encode(message);
                     cout<<endl;
                     message="";
                }
                else {decode(message);
                cout<<endl;
                message="";
             }
             system("pause");
                cout<<"DO YOU WANT TO CONTINUE OR END(n)\n";
                cin>>want;
             }while(want!='n');
        }
        else cout<<"\nWrong password"<<endl;
    }


    else cout<<"Wrong user-name"<<endl;


    return 0;
}
