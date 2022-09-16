#include <iostream>
#include <stdlib.h>
#include<stdio.h>

using namespace std;
class e_books;

typedef struct Sub_Chapters
{
    char   *DATA;
    FILE *FCh;
    struct Sub_Chapters *Next;
} sub_chapters;

typedef struct chapters
{
    string DATA_CH;
    sub_chapters *Poin_Sub_CH;
    struct chapters *last;
    struct chapters *next;
} chapters;


///********** Class books **********///

class Books
{
private :
    string Author;
    string Name_Of_Book;
    string Subject;
    string Language;
    int Number_Of_Page;
    int Book_Chapiters;
    int Release_Date;
    int Sub_Chapiterss;
public :
    ///************* Set data member : **************///

    void set_Name_of_Book(string);
    void set_subject(string);
    void set_language(string);
    void set_Name_author(string);
    void set_Release_Date(int);
    void set_number_of_page(int);
    void set_book_chapiters(int);
    void set_sub_chapiters(int);

    ///************* Get data member : **************///
    string get_name_author();
    string get_Name_of_Book();
    string get_subject();
    string get_language();
    int get_Release_Date();
    int get_number_of_page();
    int get_book_chapters();
    int get_sub_chapiters();

};
void Books::set_Name_author(string S)
{
 Author = S;
}

void Books::set_Name_of_Book(string S)
{
    Name_Of_Book = S;
}
void Books::set_subject(string S)
{
    Subject = S;
}
void Books::set_language(string S)
{
    Language = S;
}

void Books::set_number_of_page(int num)
{
    Number_Of_Page = num;
}
void Books::set_book_chapiters(int num)
{
    Book_Chapiters = num;
}
string Books::get_Name_of_Book()
{
    return Name_Of_Book;
}
string Books::get_subject()
{
    return Subject;
}
string Books::get_language()
{
    return Language;
}
void Books::set_Release_Date(int Date)
{
    if( Date > 2022 )
    {
        cout<<"Re-enter date please ^-^ :  ";
        cin>>Date;
    }
    Release_Date = Date;
}
void Books::set_sub_chapiters(int data)
{
    Sub_Chapiterss = data;
}

int Books::get_Release_Date()
{
    return Release_Date;
}
int  Books::get_number_of_page()
{
    return Number_Of_Page;
}
int Books::get_book_chapters()
{
    return Book_Chapiters;
}
int Books::get_sub_chapiters()
{
    return Sub_Chapiterss;
}
string Books::get_name_author()
{
return Author;
}
chapters *ch1 = ( chapters* ) malloc ( sizeof ( chapters ) );
chapters *ch2 = ( chapters* ) malloc ( sizeof ( chapters ) );

///********** Class e-books **********///

class e_books : public Books
{
private:
    int number_of_Readers;
    int likes;


    ///******** SET NAME OF SUB-CHAPTER ********///
    void Set_Name_Sub_Ch(Sub_Chapters *SCH,chapters *CH)
    {
        int counter = 1;
        Sub_Chapters *assist = SCH;
        while(assist != nullptr)
        {
            cout<<"\n  Please enter name of "<<counter<<" Sub-CHapters in ";
            printf(" %s",CH->DATA_CH);
            cout<<" CHapter : ";
            scanf(" %s",&assist->DATA);
            assist = assist->Next;
            counter++;
        }
    }
    ///******** SET NAME OF CHAPTER ********///

    void Set_Name_ch(chapters *ass)
    {
        cout<<"\n Please enter name of this CHapter : ";
        scanf(" %s",&ass->DATA_CH);
    }


    ///******** CREATE AND SET NAME OF CHAPTER ********///

    void Set_Sub_Ch(chapters *CH)
    {

        int Number_Sub_Ch ;
        cout<<"\n\t How many Sub-Chapters do you want in " ;
        printf("%s CHapter : ",CH->DATA_CH);
        cin>>Number_Sub_Ch;

        int counter;
        Sub_Chapters *S2 = ( Sub_Chapters* ) malloc ( sizeof ( Sub_Chapters ) );

        for ( counter = 0 ; counter < Number_Sub_Ch - 1 ; counter++ )
        {
            Sub_Chapters *S3 = ( Sub_Chapters* ) malloc ( sizeof( Sub_Chapters ) );
            S3 -> Next = nullptr ;

            if ( counter == 0 )
            {
                CH->Poin_Sub_CH = S3 ;
                S3->Next = S2 ;
                S2->Next = nullptr ;
            }
            else
            {
                S2->Next = S3;
                S2 = S3;
            }
        }
        Set_Name_Sub_Ch(CH->Poin_Sub_CH,CH);
    }

    Sub_Chapters *Search_Sub_Chapter(chapters *CH)
    {
        char *assist;
        cout<<"\n  Which Sub-CHapter you want : ";
        scanf("%s",&assist);

        Sub_Chapters *poin = (CH->Poin_Sub_CH);
        if( poin!= nullptr )
        {
            // printf("\n\n\t%s",poin->DATA);

            while( poin != nullptr )
            {

                if( poin->DATA == assist)
                {
                    return poin;
                    break;
                }
                break;
                poin = poin->Next;
            }
        }
        return poin;
    }

    ///************  Read & Write in book  *************///

    void Read_Write(Sub_Chapters *SCH)
    {
re:
        char ch;
        cout<<"\n  If do you want : Read press R , Write press W : ";
        cin>>ch;
        switch(ch)
        {
        case 'W'  :
            SCH->FCh = fopen(SCH->DATA,"a");
            cout<<"\n  If you want stop write on "<<SCH->DATA<<" CHapter press 0 "<<endl;
            do
            {
                cin.get(ch);
                if(ch!='0')
                    putc(ch,SCH->FCh );
            }
            while(ch != '0');
            fclose(SCH->FCh);
            break;

        case 'R'  :
            SCH->FCh = fopen(SCH->DATA,"r");
            while(ch = getc(SCH->FCh) !=  EOF )
            {
                cout<<ch;
            }

            fclose(SCH->FCh);
            break;
        default:
press :
            char answer;
            cout<<"Do you want to exit if yes press Y else press N";
            cin>>answer;
            if( answer == 'N' || answer == 'n' )
            {
                cout<<"\n      Please re-enter :"<<endl;
                goto re;
            }
            else if(answer == 'Y' || answer == 'y')
            {
                break;
            }
            else
            {
                cout<<"\n     Please : "<<endl;
                goto press;
            }
        }
    }
public:

    ///************* 1- Create chapter **************///
    int counter;

    void Create_Chapters();

    ///*************  2- Add chapter  **************///
    void Add_chapter();

    ///*************  3- Search CHapter & Sub-CHapter  *************///
    void Search_Chapter(string);

    ///*************  4- Delete Chapter  *************///
    void Delete_chapter(chapters*);

    ///*******************************///
    void management_Object()
    {
        int choose;
        do
        {
            system("CLS");
            cout<<"\n\n\t\t\t\t\t\t- Raba7 Book management -\n" <<endl;
            cout<<"\t\t\t    ----------------------------------------------------------------------\n\n"<<endl;
            cout<<"\t\t\t\t\t 1) Create chapter\n\n\t\t\t\t\t 2) Add chapter\n\n\t\t\t\t\t 3) Search CHapter & Sub-CHapter\n\n\t\t\t\t\t 4) Delete Chapter\n\n\t\t\t\t\t 5) Exit";
            cout<<"\n\n\t\t\t\t\t Enter your choice : ";
            cin>>choose;
            if(choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5) break;
            system("CLS");
        }
        while(1);
        string str;
        switch(choose)
        {
        case 1:
            set_book_chapiters(5);
            Create_Chapters();
            break;
        case 2:
            Add_chapter();
            break;
        case 3:
            cout<<" Please enter name of CHapter you want to get : "<<endl;
            cin>>str;
            Search_Chapter(str);
            break;

        case 4:
            cout<<" Please enter name of CHapter you want to delete : ";
            cin>>str;
            chapters *assist = ch1 ;
            if(ch1 != nullptr)
            {
                while(assist != nullptr )
                {
                    if( assist->DATA_CH == str ) break;
                    assist = assist->next;
                }
                if(assist != nullptr) Delete_chapter(assist);
                else cout<<"the CHapter does not exist"<<endl;
            }
            break;
        }
    }
};


///************* 1 **************///

void e_books::Create_Chapters()
{
    int Gbch = get_book_chapters() ;
    for( counter = 0 ; counter < (Gbch-2) ; counter++ )
    {
        chapters *ch3 = (chapters*) malloc( sizeof ( chapters ));
        ch3->last = nullptr;
        ch3->next = nullptr;

        if ( counter == 0 )
        {
            ch1->next = ch2 ;
            ch1->last = nullptr ;
            ch2->last = ch1 ;
            ch2->next = ch3 ;
            ch2 = ch3 ;
            ch2->next = nullptr;
        }
        else
        {
            ch2 -> next = ch3;
            ch3 -> last = ch2;
            ch3 -> next = NULL;
            ch2 = ch3;
        }
    }

    chapters *assist = ch1;
    while( assist != nullptr )
    {
        Set_Name_ch(assist);
        assist = assist->next;
    }
    assist = ch1;
    while( assist != nullptr )
    {
        Set_Sub_Ch(assist);
        assist = assist->next;
    }
}


///************* 2 **************///

void e_books::Add_chapter()
{
    chapters *assist = ( chapters* ) malloc( sizeof( chapters ) );
    chapters *pointer = ch1 ;
    ch1->last = nullptr ;
    ch1->next = ch2 ;
    ch2->next = nullptr ;
    counter = 0 ;
    while( pointer->next != nullptr )
    {
        pointer = pointer->next;
        counter++;
    }
    if(pointer != nullptr)
    {
        pointer -> next = assist;
        assist  -> next = NULL ;
        Set_Name_ch(assist);
        Set_Sub_Ch(assist);
    }
}


///************* 3 **************///

void e_books::Search_Chapter(string Search)
{
    chapters *assist = ch1;

    while(assist != nullptr)
    {
        if( (assist->DATA_CH) == Search )
        {
            Sub_Chapters *sch = Search_Sub_Chapter(assist);

            if( sch !=nullptr )
            {
                Read_Write(sch);
            }

            else
            {
                cout<<"\n  This Sub-CHapter does not exist"<<endl;
            }
            break;
        }
        assist = assist->next;
    }
    if(assist == nullptr)
    {
        cout<<"\n  This CHapter does not exist"<<endl;
    }
}


///************* 4 **************///

void e_books::Delete_chapter(chapters *Del)
{

    chapters *assist= Del;
    Del -> last -> next = Del -> next;
    free(assist);
}

typedef struct Object
{
    e_books Book ;
    struct Object *next;
} Object;

int main ()
{
Pbegin :
    char choose;
    do
    {
      cout<<"\n\n\t\t\t\t\t\t- Raba7 Book management -\n" <<endl;
      cout<<"\t\t\t    ----------------------------------------------------------------------\n\n"<<endl;
      cout<<"\t\t\t\t\t 1) Add book\n\n\t\t\t\t\t 2) Search book\n\n\t\t\t\t\t 3) Exit  ";
      cout<<"\n\n\t\t\t\t\t Enter your choice : ";
      cin>>choose;
      if( choose ==  '1' || choose == '2'|| choose == '3' ) break;
      system("CLS");
    }
    while(1);

    Object *firstbook = (Object*) malloc(sizeof(Object));
    char ch;
    int num;
    string ASSstr;
    switch(choose)
    {
    case '1' :
                system("CLS");
        cout<<"\n\n\n\t\t\tName of Author : ";
        cin>>ASSstr;
        firstbook->Book.set_Name_author(ASSstr);
        cout<<"\n\n\t\t\tName of Book : ";
        cin>>ASSstr;
        firstbook->Book.set_Name_of_Book(ASSstr);

        cout<<"\n\n\t\t\tSubject : ";
        cin>>ASSstr;
        firstbook->Book.set_subject(ASSstr);

        cout<<"\n\n\t\t\tLanguage : ";
        cin>>ASSstr;
        firstbook->Book.set_language(ASSstr);

        cout<<"\n\n\t\t\tNumber of Page : ";
        cin>>num;
        firstbook->Book.set_number_of_page(num);
        cout<<"\n\n\t\t\tNumber of Chapters : ";
        cin>>num;
        firstbook->Book.set_book_chapiters(num);
        cout<<"\n\n\t\t\tNumber of Sub-Chapters : ";
        cin>>num;
        firstbook->Book.set_sub_chapiters(num);
        cout<<"\n\n\t\t\tRelease date : ";
        cin>>num;
        firstbook->Book.set_Release_Date(num);
        firstbook->Book.management_Object();
        break;
    case '2' :

         string str;
         cout<<"\n\t\t Please enter name of book you want to get : ";
         cin>>str;
          firstbook->Book.set_Name_of_Book(str);
        Object *poin = firstbook;

        while( poin != nullptr )
           {
                   if( poin->Book.get_Name_of_Book() == str )
                   {
                       poin->Book.management_Object();
                   }
                    poin = poin -> next;
           }
    }

    cout<<"\n\n\t\t\t\t\t\t\t-> Are sure (Y/N) : ";
    cin>>ch;
    if ( ch == 'Y' || ch == 'y' )
    {
        cout<<" \t\t\t\t\t\t\t-> Bye *-*";
    }
    else
    {
        system("CLS");
        goto Pbegin;
    }
    return 0;
}

















