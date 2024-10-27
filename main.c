#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#define MAX 17
//----------------------------------------------------------------------
void gotoXY(int x, int y) //thủ tục di chuyển đến tọa độ x y
{
    COORD coord;  // Cấu trúc chứa tọa độ
    coord.X = x;  // Tọa độ x
    coord.Y = y;  // Tọa độ y
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  // Đặt vị trí con trỏ
}
void SetColor(int ForgC) // thủ tục đổi màu
{
    // Lấy handle của console output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Đặt thuộc tính màu cho văn bản
    SetConsoleTextAttribute(hConsole, ForgC);
}
void ShowCur(int cursorVisibility) // thủ tục giảm độ trễ
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    // Lấy thông tin về con trỏ hiện tại
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = cursorVisibility;  // Thay đổi trạng thái hiển thị
    SetConsoleCursorInfo(handle, &cursorInfo); // Áp dụng thay đổi
}
//----------------------------------------------------------------------
struct mang
{
    int x,y;
};
struct mangghidiem
{
    int diem;
    char xau[MAX];
};
struct mangktmap2
{
    int x,y;
};
struct mangktmap2 ktmap2[500];
struct mang toado[1000]= {0};
struct mangghidiem a[MAX];
int checkmap=0;
int slmap2=0;
int sl=3;
int x_qua=-1;
int y_qua=-1;
int score=0;
int tocdo=0;
int tangdiem;
int diemcong=0;
int chuyenqua=1;
int chuyendiem=0;
int mode=0;
void khoi_tao_ran()
{
    int x_khoi_tao=42;
    int y_khoi_tao=13;
    for(int i=0; i<sl; i++)
    {
        toado[i].x=x_khoi_tao--;
        toado[i].y=y_khoi_tao;
    }
}
void ve_ran()
{
    for(int i=0; i<sl; i++)
    {
        if(i==0)
        {
            gotoXY(toado[i].x,toado[i].y);
            printf("O");
        }
        else
        {
            gotoXY(toado[i].x,toado[i].y);
            printf("o");
        }
    }
}
void ve_tuong()
{
    SetColor(11);
//max 90*26
    // vẽ tường trên
    for(int i=1; i<=90; i++)
    {
        gotoXY(i,1);
        printf("#");
    }
    // vẽ tường dưới
    for(int i=1; i<=90; i++)
    {
        gotoXY(i,26);
        printf("#");
    }
    // vẽ tường trái
    for(int i=1; i<=26; i++)
    {
        gotoXY(1,i);
        printf("#");
    }
    // vẽ tường phải
    for(int i=1; i<=26; i++)
    {
        gotoXY(90,i);
        printf("#");
    }
}
void ve_tuong2()
{
    SetColor(11);
//max 90*26
    // vẽ tường trên
    for(int i=1; i<=90; i++)
    {
        gotoXY(i,1);
        printf("#");
    }
    // vẽ tường dưới
    for(int i=1; i<=90; i++)
    {
        gotoXY(i,26);
        printf("#");
    }
    // vẽ tường trái
    for(int i=1; i<=26; i++)
    {
        gotoXY(1,i);
        printf("#");
    }
    // vẽ tường phải
    for(int i=1; i<=26; i++)
    {
        gotoXY(90,i);
        printf("#");
    }
    for(int j=11; j<=12; j++)
        for(int i=40; i<=50; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=i;
            ktmap2[slmap2].y=j;
            gotoXY(i,j);
            printf("#");
        }
    for(int j=55; j<=56; j++)
        for(int i=12; i>=7; i--)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    for(int j=34; j<=35; j++)
        for(int i=12; i>=7; i--)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    for(int j=14; j<=15; j++)
        for(int i=31; i<=41; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=i;
            ktmap2[slmap2].y=j;
            gotoXY(i,j);
            printf("#");
        }
    for(int j=14; j<=15; j++)
        for(int i=50; i<=60; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=i;
            ktmap2[slmap2].y=j;
            gotoXY(i,j);
            printf("#");
        }
    for(int j=65; j<=66; j++)
        for(int i=10; i<=15; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    for(int j=25; j<=26; j++)
        for(int i=10; i<=15; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    for(int j=19; j<=20; j++)
        for(int i=40; i<=50; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=i;
            ktmap2[slmap2].y=j;
            gotoXY(i,j);
            printf("#");
        }
    for(int j=29; j<=30; j++)
        for(int i=1; i<=4; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    for(int j=29; j<=30; j++)
        for(int i=21; i<=26; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    for(int j=61; j<=62; j++)
        for(int i=1; i<=4; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    for(int j=61; j<=62; j++)
        for(int i=21; i<=26; i++)
        {
            slmap2++;
            ktmap2[slmap2].x=j;
            ktmap2[slmap2].y=i;
            gotoXY(j,i);
            printf("#");
        }
    //ve khoi vuong 4 ben
    for(int i=5; i<=10; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=86;
        ktmap2[slmap2].y=i;
        gotoXY(86,i);
        printf("#");
    }
    for(int i=5; i<=10; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=70;
        ktmap2[slmap2].y=i;
        gotoXY(70,i);
        printf("#");
    }
    for(int i=70; i<=86; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=10;
        gotoXY(i,10);
        printf("#");
    }
    for(int i=70; i<=76; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=5;
        gotoXY(i,5);
        printf("#");
    }
    for(int i=80; i<=86; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=5;
        gotoXY(i,5);
        printf("#");
    }
    for(int i=5; i<=10; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=5;
        ktmap2[slmap2].y=i;
        gotoXY(5,i);
        printf("#");
    }
    for(int i=5; i<=10; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=21;
        ktmap2[slmap2].y=i;
        gotoXY(21,i);
        printf("#");
    }
    for(int i=5; i<=21; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=10;
        gotoXY(i,10);
        printf("#");
    }
    for(int i=5; i<=11; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=5;
        gotoXY(i,5);
        printf("#");
    }
    for(int i=15; i<=21; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=5;
        gotoXY(i,5);
        printf("#");
    }
    for(int i=5; i<=11; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=22;
        gotoXY(i,22);
        printf("#");
    }
    for(int i=15; i<=21; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=22;
        gotoXY(i,22);
        printf("#");
    }
    for(int i=17; i<=22; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=5;
        ktmap2[slmap2].y=i;
        gotoXY(5,i);
        printf("#");
    }
    for(int i=5; i<=21; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=17;
        gotoXY(i,17);
        printf("#");
    }
    for(int i=17; i<=22; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=21;
        ktmap2[slmap2].y=i;
        gotoXY(21,i);
        printf("#");
    }
    for(int i=80; i<=86; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=22;
        gotoXY(i,22);
        printf("#");
    }
    for(int i=70; i<=76; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=22;
        gotoXY(i,22);
        printf("#");
    }
    for(int i=17; i<=22; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=86;
        ktmap2[slmap2].y=i;
        gotoXY(86,i);
        printf("#");
    }
    for(int i=70; i<=86; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=i;
        ktmap2[slmap2].y=17;
        gotoXY(i,17);
        printf("#");
    }
    for(int i=17; i<=22; i++)
    {
        slmap2++;
        ktmap2[slmap2].x=70;
        ktmap2[slmap2].y=i;
        gotoXY(70,i);
        printf("#");
    }
}
void di_chuyen_ran(int x,int y)
{
    for(int i=sl; i>0; i--)
    {
        toado[i].x=toado[i-1].x;
        toado[i].y=toado[i-1].y;
    }
    toado[0].x=x;
    toado[0].y=y;
}
bool kt_ran_de_qua()
{
    for(int i=0; i<sl; i++)
    {
        if(x_qua==toado[i].x&&y_qua==toado[i].y)
            return true;
    }
    return false;
}
bool kt_qua_de_map()
{
    for(int i=1; i<=slmap2; i++)
    {
        if(x_qua==ktmap2[i].x&&y_qua==ktmap2[i].y)
            return true;
    }
    return false;
}
void tao_qua2()
{
    int kt1=1,kt2=1;
    while(1)
    {
        x_qua=rand()%(89-2+1)+2;
        y_qua=rand()%(25-2+1)+2;
        for(int i=0; i<sl; i++)
            if(x_qua==toado[i].x&&y_qua==toado[i].y)
            {
                kt1=0;
                break;
            }
        for(int i=1; i<=slmap2; i++)
            if(x_qua==ktmap2[i].x&&y_qua==ktmap2[i].y)
            {
                kt2=0;
                break;
            }
        if(kt1+kt2==2)
            break;
        kt1=1,kt2=1;
    }
}
void tao_qua1()
{
    int kt1=1;
    while(1)
    {
        x_qua=rand()%(89-2+1)+2;
        y_qua=rand()%(25-2+1)+2;
        for(int i=0; i<sl; i++)
            if(x_qua==toado[i].x&&y_qua==toado[i].y)
            {
                kt1=0;
                break;
            }
        if(kt1==1)
            break;
        kt1=1;
    }
}
void ve_qua1()
{
    //SetColor(7);
    int p=rand()%(15-1+1)+1;
    while(p==11)
        p=rand()%(15-1+1)+1;
    SetColor(p);
    gotoXY(x_qua,y_qua);
    printf("Q");
}
void ve_qua2()
{
    //SetColor(7);
    int p=rand()%(15-1+1)+1;
    while(p==11)
        p=rand()%(15-1+1)+1;
    SetColor(p);
    gotoXY(x_qua,y_qua);
    printf("D");
}
bool kt_ran_an_qua()
{
    if(x_qua==toado[0].x&&y_qua==toado[0].y)
        return true;
    return false;
}
void xu_ly_ran_an_qua()
{
    if(kt_ran_an_qua())
    {
        sl++;//tăng số lượng đốt
        if(checkmap==2)
            tao_qua2();
        else
            tao_qua1();//tạo quả mới
            ve_qua1();
        //tăng điểm
        score+=tangdiem+diemcong;
         if(mode==3)
            tocdo-=2;
    }
}
void xu_ly_ran_an_qua2()
{
    if(kt_ran_an_qua())
    {
        chuyendiem++;
        chuyenqua++;// đủ số lượng sẽ chuyễn sang quả đặc biệt
        sl++;//tăng số lượng đốt
        if(checkmap==2)
            tao_qua2();
        else
            tao_qua1();//tạo quả mới
        if(chuyenqua%3==0)
            ve_qua2();
        else
            ve_qua1();
        //tăng điểm
        if(chuyendiem%3==0)
            score+=30+diemcong;
        else
        score+=tangdiem+diemcong;
    }
}
bool kt_ran_cham_than()
{
    for(int i=1; i<sl; i++)
        if(toado[0].x==toado[i].x&&toado[0].y==toado[i].y)
            return true;
    return false;
}
bool game_over()
{
    if(toado[0].x==1||toado[0].x==90||toado[0].y==1||toado[0].y==26)
        return true;
    for(int i=1; i<=slmap2; i++)
        if(toado[0].x==ktmap2[i].x&&toado[0].y==ktmap2[i].y)
            return true;
    return (kt_ran_cham_than());
}
void play()
{
    slmap2=0;
    sl=3;
    score=0;
    ShowCur(0); // ẩn độ trễ
    khoi_tao_ran();
    if(checkmap==2)
    {
        ve_tuong2();
        tao_qua2();
    }
    else
    {
        ve_tuong();
        tao_qua1();
    }
    ve_qua1();
    int x=toado[0].x;
    int y=toado[0].y;
    int check=2;
    //0 đi xuống
    //1 đi lên
    //2 đi qua phải
    //3 đi qua trái
    gotoXY(102,13);
    printf("SCORE=%d",score);
    while(1)
    {
        // xóa dữ liệu cũ
        gotoXY(toado[sl].x,toado[sl].y);
        printf(" ");
        // in
        ve_ran();
        // điều khiển-------------------------------------
        if(_kbhit()) //kiem tra nguoi dung nhap gi
        {
            char c=_getch();
            /*if(c==-32)
              {
                  c=_getch();
                  if(c==72||c=='w')
                      check=1;
                  else if(c==80||c=='s')
                      check=0;
                  else if(c==75||c=='a')
                      check=3;
                  else if(c==77||c=='d1')
                      check=2;
              }*/
            if((c==72||c=='w')&&(check!=0))  //check!=0 la khi dang di len thi k dc phep di xuong
                check=1;
            else if((c==80||c=='s')&&(check!=1))
                check=0;
            else if((c==75||c=='a')&&(check!=2))
                check=3;
            else if((c==77||c=='d')&&(check!=3))
                check=2;
        }
        // di chuyển-------------------------------------------
        if(check==0)
            y++;
        else if(check==1)
            y--;
        else if(check==2)
            x++;
        else if(check==3)
            x--;
        // biên
        if(game_over())
            break;
        // xử lý rắn
        if(mode==1||mode==3)
             xu_ly_ran_an_qua();
      else
        xu_ly_ran_an_qua2();
        gotoXY(102,13);
        printf("SCORE=%d",score);
        di_chuyen_ran(x,y);
        // tốc độ
        Sleep(tocdo);
    }
    tocdo=0;
    checkmap=0;
    mode=0;
    diemcong=0;
}
void clear_het()
{
    for(int i=1; i<=120; i++)
        for(int j=1; j<=30; j++)
        {
            gotoXY(i,j);
            printf(" ");
        }
}
int main()
{
    struct mangghidiem a[7]=
    {
        {1000,"noname"},
        {955,"SV PTIT"},
        {200,"880k/tin"},
        {100,"ISP MAI DINH"},
        {5,"ABCXYZ"}
    };
    while(1)
    {
        ShowCur(0);
        gotoXY(51,2);
        SetColor(1);
        printf("GAME MENU");
        gotoXY(50,6);
        SetColor(2);
        printf("1.NEW GAME");
        gotoXY(50,8);
        SetColor(4);
        printf("2.QUIT GAME");
        gotoXY(50,10);
        SetColor(7);
        printf("3.CREDIT");
        gotoXY(50,12);
        SetColor(5);
        printf("4.TOP RANKINGS");
        gotoXY(50,14);
        SetColor(12);
        printf("5.ABOUT");
        if(_kbhit()) //kiem tra nguoi dung nhap gi
        {
            char c=_getch();
            if(c=='1')
            {
                for(int i=50; i<=73; i++)
                    for(int j=2; j<=14; j++)
                    {
                        gotoXY(i,j);
                        printf(" ");
                    }
                      while(mode==0)
                {
                    gotoXY(51,2);
                    SetColor(1);
                    printf("CHOOSE MODE");
                    gotoXY(51,4);
                    SetColor(1);
                    printf("1.CLASSIC (Q)");
                    gotoXY(51,6);
                    SetColor(1);
                    printf("2.MODERN (Q,D)");
                    gotoXY(51,8);
                    SetColor(1);
                    printf("3.SPECIAL (Q,Each time it eats, it moves faster)");
                    if(_kbhit())
                    {
                        char t=_getch();
                        if(t=='1')
                        {
                           mode=1;
                        }
                        else if(t=='2')
                        {
                           mode=2;
                        }
                        else if(t=='3')
                        {
                            mode=3;
                        }
                    }
                }
              for(int i=50; i<=100; i++)
                    for(int j=2; j<=14; j++)
                    {
                        gotoXY(i,j);
                        printf(" ");
                    }
                while(tocdo==0)
                {
                    gotoXY(51,2);
                    SetColor(1);
                    printf("CHOOSE LEVEL");
                    gotoXY(51,4);
                    SetColor(1);
                    printf("1.EASY (+5 point for eating 'Q')");
                    gotoXY(51,6);
                    SetColor(1);
                    printf("2.NORMAL (+10 point for eating 'Q')");
                    gotoXY(51,8);
                    SetColor(1);
                    printf("3.HARD (+15 point for eating 'Q')");
                     gotoXY(51,10);
                    SetColor(1);
                    printf("4.SUPER HARD (+20 point for eating 'Q')");
                    if(_kbhit())
                    {
                        char c=_getch();
                        if(c=='1')
                        {
                            tangdiem=5;
                            tocdo=150;
                        }
                        else if(c=='2')
                        {
                            tangdiem=10;
                            tocdo=100;
                        }
                        else if(c=='3')
                        {
                            tangdiem=15;
                            tocdo=50;
                        }
                         else if(c=='4')
                        {
                            tangdiem=20;
                            tocdo=30;
                        }
                    }
                }
                for(int i=50; i<=100; i++)
                    for(int j=2; j<=14; j++)
                    {
                        gotoXY(i,j);
                        printf(" ");
                    }
                while(checkmap==0)
                {
                    gotoXY(51,2);
                    SetColor(1);
                    printf("CHOOSE MAP");
                    gotoXY(51,4);
                    SetColor(1);
                    printf("1.BASIC");
                    gotoXY(51,6);
                    SetColor(1);
                    printf("2.MAZE (+5 point for eating 'Q')");
                    if(_kbhit())
                    {
                        char t=_getch();
                        if(t=='1')
                        {
                            checkmap=1;
                        }
                        else if(t=='2')
                        {
                            checkmap=2;
                            diemcong=5;
                        }
                    }
                }
                 for(int i=50; i<=100; i++)
                    for(int j=2; j<=14; j++)
                    {
                        gotoXY(i,j);
                        printf(" ");
                    }
                srand(time(NULL));
                play();
                Sleep(200);
                if(score>a[4].diem)
                {
                    gotoXY(93,14);
                    printf("You're one of the top 5!!");
                    gotoXY(93,15);
                    printf("Please enter your name to ");
                    gotoXY(93,16);
                    printf("see your ranking.");
                    gotoXY(93,17);
                    printf("PLAYER:");
                    fgets(a[5].xau, MAX, stdin);
                    a[5].diem=score;
                     for(int i=4; i>=0; i--)
                {
                    if(a[i].diem<a[i+1].diem)
                    {
                        int tmp;
                        tmp=a[i].diem;
                        a[i].diem=a[i+1].diem;
                        a[i+1].diem=tmp;
                        char tmp1[MAX];
                        strcpy(tmp1,a[i].xau);
                        strcpy(a[i].xau,a[i+1].xau);
                        strcpy(a[i+1].xau,tmp1);
                    }
                }
                }
                clear_het();
            }
            else if(c=='2')
            {
                clear_het();
                gotoXY(51, 2);
                SetColor(1);
                printf("SEE YOU LATER!");
                Sleep(3000);
                return 0;
            }
            else if(c=='3')
            {
                clear_het();
                int k=0;
                while(k==0)
                {
                    gotoXY(50,2);
                    SetColor(15);
                    printf("CREDIT");
                    gotoXY(38,4);
                    SetColor(4);
                    printf("HOC VIEN HOANG GIA PI TI AI TI");
                    gotoXY(43,6);
                    SetColor(11);
                    printf("TRO CHOI GIUN SAN MOI");
                    gotoXY(40,10);
                    SetColor(2);
                    printf("DUONG HONG TRIET B24DCAT267");
                    SetColor(4);
                    gotoXY(49,13);
                    printf("3.RETURN");
                    if(_kbhit())
                    {
                        char c=_getch();
                        if(c=='3')
                            k++;
                    }
                }
                clear_het();
            }
            else if(c=='4')
            {
                clear_het();
                for(int i=4; i>=0; i--)
                {
                    if(a[i].diem<a[i+1].diem)
                    {
                        int tmp;
                        tmp=a[i].diem;
                        a[i].diem=a[i+1].diem;
                        a[i+1].diem=tmp;
                        char tmp1[MAX];
                        strcpy(tmp1,a[i].xau);
                        strcpy(a[i].xau,a[i+1].xau);
                        strcpy(a[i+1].xau,tmp1);
                    }
                }
                int k=0;
                while(k==0)
                {
                    gotoXY(54,2);
                    SetColor(5);
                    printf("TOP RANKINGS");
                    SetColor(3);
//                     FILE *file = freopen("output.txt", "w", stdout);
//    if (file == NULL) {
//        perror("freopen");
//        return 1;
//    }
//                    for(int i=0;i<5;i++)
//                         printf("%s %d\n ",a[i].xau,a[i].diem);
//
//                    fflush(stdout);
//    // Điều kiện kiểm tra hệ điều hành
// #ifdef _WIN32
//        freopen("CON", "w", stdout); // Trên Windows
//    #else
//        freopen("/dev/tty", "w", stdout); // Trên Unix-like OS
//    #endif
                    for(int i=0; i<5; i++)
                    {
                        gotoXY(50,5+i);
                        printf("%d.%s",i+1,a[i].xau);
                        gotoXY(70,5+i);
                        printf("%d",a[i].diem);
                    }
                    SetColor(4);
                    gotoXY(50,13);
                    printf("4.RETURN");
                    if(_kbhit())
                    {
                        char c=_getch();
                        if(c=='4')
                            k++;
                    }
                }
                clear_het();
        }
        else if(c=='5')
            {
                 clear_het();
                int k=0;
                while(k==0)
                {
                    SetColor(12);
                gotoXY(50,2);
                 printf("TUTORIAL");
                  SetColor(7);
                  gotoXY(1,4);
                  printf("-You can only move up, left, down, or right either with arrow keys or use the W A S D key.");
                  SetColor(7);
                  gotoXY(1,5);
                  printf("-There are only two rules you must follow when playing: do not hit a wall and do not bite your own tail.");
                  SetColor(7);
                  gotoXY(1,6);
                  printf("-Crashing into a wall or your tail will end the game immediately.");
                   SetColor(12);
                gotoXY(51,8);
                 printf("NOTE");
                   SetColor(7);
                  gotoXY(1,10);
                  printf("CLASSIC MODE:'Q' appears randomly on the screen. Each time the snake eats a 'Q' the player is score increases.");
                  SetColor(7);
                  gotoXY(1,11);
                  printf("MODERN MODE:After eating 'Q' twice,'D' will appear, and when the player eats 'D' their score will increase by 30 points");
                   SetColor(7);
                  gotoXY(1,12);
                  printf("SPECIAL MODE:Not only does your snake grow longer each time it eats, it moves faster than the classic game as well.");
                   SetColor(4);
                    gotoXY(49,14);
                    printf("5.RETURN");
                    if(_kbhit())
                    {
                        char c=_getch();
                        if(c=='5')
                            k++;
                    }
                }
                 clear_het();
            }
    }
    }
}
