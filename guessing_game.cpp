#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;
string check_word(string word);
string input(int x)
    {
        string str; 
        int flag=0;
        cin>>str;
        str=check_word(str);
        if(str=="exit")
            {
                cout<<"\n\t->THANK YOU FOR PLAYING SHYAM'S GUESSING GAME";
                exit(0);
            }
        if(x==0 && (str!="p" && str!="exit"))
            flag=1;
        while(flag==1)
            {
                 if(x==0 && (str!="p" && str!="exit"))
                    {
                          cout<<"\n\t->INVALID ENTRY. PLEASE ENTER ONLY 'P' OR 'EXIT : ";
                          cin>>str;
                          str=check_word(str);
                    }
                else
                    flag=0;
            }
        return str;
    }
string check_word(string word)
    {
        for(int i=0;word[i]!='\0';i++)
            {
                if(isupper(word[i])==1)
                    {
                        word[i]=tolower(word[i]);
                    }
            }
        return word;
    }

int check_closeness(string guess,string word)
    {
        int count=0,threshold=(0.75)*(word.length());
        for(int i=0;i<word.length();i++)
            {
                if(word[i]==guess[i])
                    count++;
            }
        if((count>=threshold) && count<word.length())
            cout<<"\t->"<<guess<<" IS VERY CLOSE.";
        return 0;
    }
void points(int tries,int no_of_tries, int hint_counter)
    {
        static int total_points =0;
        int points=100;
        if(tries==no_of_tries)
            points=0;
        else
            points-=10*(tries + hint_counter);
        total_points+=points;
        cout<<"\n\t->YOUR POINTS : "<<total_points;
    }
string game(string word, int no_of_tries)
    {
        string enter_game;
        cout<<"\n\t->YOUR WORD IS OF LENGTH "<<word.length()<<".\n\t->YOU HAVE "<<no_of_tries<<" TRIES TO GUESS THE WORD.\n\t->ENTER 'HINT' INSTEAD OF A GUESS TO REVEAL A LETTER OF THE WORD \n\t->YOU GET 100 POINTS FOR EACH CORRECT GUESS\n\t->YOU LOSE 10 POINTS EACH FOR EVERY WRONG GUESS AND EVERY HINT\n\t->BEGIN GUESSING!!! \n";
        int tries=0,hint_counter=0,no_of_hints_allowed=word.length()/2;
        word=check_word(word);
        string guess="";
        while(tries<no_of_tries)
            {
                cout<<"\n\n\t->MAKE GUESS "<<tries+1<<" : ";
                guess=input(1);
                if(guess=="hint")
                    {
                        if(hint_counter>=no_of_hints_allowed)
                            cout<<"\n\t->SORRY!YOU'VE EXHAUSTED YOUR HINTS";
                        else if(!hint_counter)
                            cout<<"\n\t->FIRST LETTER OF THE WORD IS "<<word[0];
                        else if(hint_counter==1)
                            cout<<"\n\t->LAST LETTER OF THE WORD IS "<<word[word.length()-1];
                        else if(hint_counter==2)
                            cout<<"\n\t->SECOND LETTER OF THE WORD IS "<<word[1];
                        else if(hint_counter==3)
                            cout<<"\n\t->SECOND LAST LETTER OF THE WORD IS "<<word[word.length()-2];
                        else if(hint_counter==4)
                            cout<<"\n\t->THIRD LETTER OF THE WORD IS "<<word[2];
                        hint_counter++;
                        continue;
                    }
                if(guess.length()!=word.length())
                    {
                        cout<<"\n\t->!!!NOTE: WORD IS OF LENGTH "<<word.length()<<" !!!";
                    }
                else
                    check_closeness(guess,word);
                if(guess==word)
                    {
                        cout<<"\t->SUCCESS. YOU HAVE GUESSED THE WORD!";
                        points(tries,no_of_tries,hint_counter);
                        break;
                    }
                else if(tries<no_of_tries-1)
                    {
                        cout<<"\t->WRONG ATTEMPT. TRY AGAIN!";
                    }
                if(guess!="hint")
                    tries++;
            }
        if(tries==no_of_tries)
            {
                cout<<"\n\t->HARD LUCK. YOUR TRIES ARE OVER.\n\t->THE WORD WAS '"<<word<<"'";
                points(tries,no_of_tries,hint_counter);
            }
        cout<<"\n\n\t->ENTER 'P' TO PLAY AGAIN\n\t->ENTER 'EXIT' TO EXIT GAME : ";
        enter_game=input(0);
        return enter_game;
    }

int main()
    {
        srand((unsigned int)time(NULL));
        cout<<"\n\t->WELCOME TO SHYAM'S GUESSING GAME!!!\n\t->YOU CAN ADD/REMOVE WORDS AND CHANGE YOUR NUMBER OF TRIES BY MODIFYING CODE\n\t->ENTER 'P' TO START PLAYING\n\t->ENTER 'EXIT' AT ANY INSTANT IN THE GAME TO EXIT GAME : ";
        string words[15]={"Shyam","Sriram","Brindha","Gowtham","Benlee","Vikram","Abhirup","Shivaram","Siddharth","Ishita","Kushal","Sudiksha","Shraddha","Ananya","Aditya"};
        int rdm=0;
        string enter_game;
        enter_game=input(0);
        while(enter_game=="p")
        {
            srand((unsigned int)time(NULL));
            rdm=rand()%15;
            enter_game=game(words[rdm],3);
        }
        return 0;
    }
