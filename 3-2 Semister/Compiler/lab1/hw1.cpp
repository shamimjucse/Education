#include<bits/stdc++.h>
using namespace std;
string s,s2;
set<string>numerical,keyword,math,logical,other,identifier;
string key[26]={"short","int","long","double","float","static","signed","unsigned","void","char","const","auto","if","else","for","goto","break","case","continue","do","return","sizeof","struct","switch","typedef","while"};
int main()
{
    freopen("lab1.txt","r",stdin);
    int i,j,k,fg;
    cout << "INPUT ::" << endl << endl;
    while(getline(cin,s))
    {
        cout << s << endl;
        s+=" ",s2="";
        for(i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
            {
                if(s2=="")continue;
                if(s2[0]>='0'&&s2[0]<='9')
                {
                    numerical.insert(s2);
                    s2="";
                    continue;
                }
                fg = 0;
                for(j=0; j<26; j++)
                {
                    if(key[j]==s2)
                    {
                        keyword.insert(s2);
                        fg = 1;
                        break;
                    }
                }
                if(fg)
                {
                    s2="";
                    continue;
                }
                if(s2=="+" || s2=="-"  || s2=="*"  || s2=="/"  || s2=="%"  || s2=="=")
                {
                    math.insert(s2);
                    s2="";
                    continue;
                }
                if(s2==">" || s2=="<"  || s2==">="  || s2=="<="  || s2=="==")
                {
                    logical.insert(s2);
                    s2="";
                    continue;
                }
                if(s2=="," || s2==";"  || s2==":"  || s2=="{"  || s2=="}"  || s2=="("  || s2==")"  || s2=="["  || s2=="]"  || s2=="#" || s2=="$"  || s2=="@")
                {
                    other.insert(s2);
                    s2="";
                    continue;
                }
                identifier.insert(s2);
                s2="";
            }
            else
            {
                s2+=s[i];
            }
        }
    }
    cout << "\nOUTPUT ::\n" << endl;
    cout<<"Keywords :";for(auto ss : keyword)cout<<" "<<ss;cout<<endl;
    cout<<"Identifiers :";for(auto ss : identifier)cout<<" "<<ss;cout<<endl;
    cout<<"Math Operators :";for(auto ss : math)cout<<" "<<ss;cout<<endl;
    cout<<"Logical Operators :";for(auto ss : logical)cout<<" "<<ss;cout<<endl;
    cout<<"Numerical Values :";for(auto ss : numerical)cout<<" "<<ss;cout<<endl;
    cout << "Others :";for(auto ss : other)cout<<" "<<ss;cout<<endl;
    return 0;
}
