#include <stdio.h>
#include <conio.h>
// It's a two player game
// We need two variables to store their names and run a loop to ask for the player to enter their move turn by turn
// We need another variable to store the turn to see which player is to enter the move

char name[2][30]; // doble dimensional array to store names of the player
int chance; // to store the chance
// to track which player is to enter the move
// We need a function to handle the navigation to boxes when the player presses arrow keys and hit the enter button to enter his move in the box
// We need another variable to track the current box the player is on at the movement
// An array to store the values entered by the player
int box; // to track the current box the player is on at the moment
char a[3][3]; // array to hold the actual values that player enter while playing
int navigate(char a[3][3], int box, int player, int key); // to handle key presses and update the current box the player is on
// and to enter the move in to the box when player presses enter
// Here in this function
// char a[3][3] is the array that holds the moves
// box is the box the player was on
// key is the key pressed
// Another variable is required to count the number of turns
// There are nine boxes in total however the number of turns maybe more than nine because if the player tries to enter his move into a box that's already taken
// then the chance passes over the other player
int turns; // to count the number of chances
// We need a function to put the move into the box chosen by the player and we need to make sure that we don't overwrite the value in a box
void putintobox(char a[3][3], char ch, int box);
// Here a[3][3] is used to represent the boxes
// ch is the character o or x
// and box is the box into which the value is to be entered
// How would we know what character to put into the box?
// This function is called by the navigate function mentioned above
// If the navigate function is called like this:
// box = navigate(a[3][3], 3, 0, ENTER)
// then it means that player1(here player1-0, player2 is represented by 2) needs to enter into box 3
// the putintobox funtion checks if the box is taken and enter the value in to the array that represents the boxes (a[3][3])
// calls another function showbox(char ch, int box) to show the character on screen in the specified box

//Function to show the tic tac toe frame
void showframe(int posx, int posy){
    int hr=196, vr=179; // These are ascii character which display the lines
    int crossbr=197; // Another ascii character
    int x=posx, y=posy;
    int i, j;

    gotoxy(35,4); cprintf("TIC TAC TOE");
    gotoxy(35,5); for(i=0;i<11;i++) cprintf("%c",223);

    for(i=0; i< 2; i++){
        for(j=1;j<=11; j++){
            gotoxy(x,y);
            printf("%c", hr);
            x++;      x++;               // remove p because it was causing errors
        }
        x = posx; y+=2;
    }
    x=posx+3; y = posy-1;
    for(i=0; i<2;i++){
        for(j=1;j<=5; j++){
            gotoxy(x,y);
            printf("%c", vr);
            y++;

        }
        x+=4; y=posy-1;
    }
    x=posx+3; y=posy;
    gotoxy(x,y);
    printf("%c", crossbr);

    x=posx+7; y=posy;
    gotoxy(x,y);
    printf("%c",crossbr);

    x=posx+3; y=posy+2;
    gotoxy(x,y);
    printf("%c", crossbr);

    x=posx+7; y=posy+2;
    gotoxy(x,y);
    printf("%c", crossbr);

}

//Function to show the character in the specified box
void showbox(char ch, int box){
    switch(box){
        case 1: gotoxy(_x+1,_y-1); printf("%c", ch); break; // 1st box
        case 2: gotoxy(_x+5,_y-1); printf("%c", ch); break; // 2nd box
        case 3: gotoxy(_x+9,_y-1); printf("%c", ch); break; // 3rd
        case 4: gotoxy(_x+1,_y+1); printf("%c", ch); break; // 4th
        case 5: gotoxy(_x+5,_y+1); printf("%c", ch); break; //5th
        case 6: gotoxy(_x+9,_y+1); printf("%c", ch); break;  //6th
        case 7: gotoxy(_x+1,_y+3); printf("%c", ch); break;  //7th
        case 8: gotoxy(_x+5,_y+3); printf("%c", ch); break;  //8th
        case 9: gotoxy(_x+9,_y+3); printf("%c", ch); break;  //9th
            
    }
}

//Function to insert the specifed character into the array
void putintobox(char arr[3][3], char ch, int box){
    switch(box){
        case 1: if(arr[0][0] != 'X' && arr[0][0] != 'O'){
            arr[0][0] = ch;
            showbox(ch, 1);
        }
        break;
        case 2: if(arr[0][1] != 'X' && arr[0][1] != 'O'){
            arr[0][1] =ch;
            showbox(ch,2);
        }
        break;
        case 3: if(arr[0][2] != 'X' && arr[0][2] != 'O'){
            arr[0][1] = ch;
            showbox(ch, 2);
        }
        break;
        case 4: if(arr[1][0] != 'X' && arr[1][0] != 'O'){
            arr[1][0] = ch;
            showbox(ch, 4);
        }
        break;
        case 5: if(arr[1][1] != 'X' && arr[1][1] != 'O'){
            arr[1][1] = ch;
            showbox(ch,5);
        }
        break;
        case 6: if(arr[1][2] != 'X' && arr[1][2] != 'O'){
            arr[1][2] = ch;
            showbox(ch,6);
        }
        break;
        case 7: if(arr[2][0] != 'X' && arr[2][0] != 'O'){
            arr[2][0] = ch;
            showbox(ch, 7);
        }
        break;
        case 8: if(arr[2][1] != 'X' && arr[2][1] != 'O'){
            arr[2][1] = ch;
            showbox(ch, 8);
        }
        break;
        case 9: if( arr[2][2] != 'X' && arr[2][2] != 'O'){
            arr[2][2] = ch;
            showbox(ch, 9);
        }
        break;
    }
}

//Function to show the curson on the box specified
//uses the position to check the coordinates
void gotobox(int box){
    switch(box){
        case 1: (_x+1,_y-1); break;
        case 2: (_x+5,_y-1); break;
        case 3: (_x+9,_y-1); break;
        case 4: (_x+1,_y+1); break;
        case 5: (_x+5,_y+1); break;
        case 6: (_x+9,_y+1); break;
        case 7: (_x+1,_y+3); break;
        case 8: (_x+5,_y+3); break;
        case 9: (_x+9,_y+3); break;
    }
}

//Function to handle the navigation
int navigate(char arr[3][3], int box, int player, int key){
    switch(key){
        case UPARROW: if( (box!=1) || (box != 2) || (box!=3) ){
            box-=3; if(box<1) box =1; gotobox(box);
        }
        break;
        case DOWNARROW: if( (box!=7) || (box != 8) || (box!=9) ){
            box+=3; if(box>9) box =9; gotobox(box);
        }
        break;
        case LEFTARROW: if( (box!=1) || (box != 4) || (box!=7) ){
            box--; if(box<1) box =1; gotobox(box);
        }
        break;
        case RIGHTARROW: if( (box!=3) || (box != 6) || (box!=9) ){
            box++; if(box>9) box =9; gotobox(box);
        }
        break;
        case ENTER: if( player == 0 ){
            putintobox(arr,'O', box);
        }
        else if(player == 1){
            putintobox(arr, 'X',box);
        }
        break;
    }
    return box;
}

int checkforwin(char arr[3][3]){
    int w = 0;
    /* 0,0  0,1  0,2
       1,0  1,1  1,2
       2,0  2,1  2,2 */
       //rows
       if((arr[0][0] == arr[0][1]) && (arr[0][1] == arr[0][2])) w =1;
       else if((arr[1][0] == arr[1][1]) && (arr[1][1] == arr[1][2])) w =1;
       else if((arr[2][0] == arr[2][1]) && (arr[2][1] == arr[2][2])) w =1;

       //coloums
       else if((arr[0][0] == arr[1][0]) && (arr[1][0] == arr[2][0])) w =1;
       else if((arr[0][1] == arr[1][1]) && (arr[1][1] == arr[2][1])) w =1;
       else if((arr[0][2] == arr[1][2]) && (arr[1][2] == arr[2][2])) w =1;

       //diagonals
       else if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])) w =1;
       else if((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0])) w =1;

       return w;
}

int boxesleft(char a[3][3]){
    int i,j,boxesleft=9;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if((a[i][j] == 'X') || (a[i][j] == 'O')){
                boxesleft--;
            }
        }
    }
    return boxesleft;
}

int main(){
    char arr[3][3];
    char player[3][30],O_OR_X[2],ch;
    int x,y,turns,chance,enter,box,win,quit,winner;
    int movesfinished = 0;

    O_OR_X[0] = 'O'; O_OR_X[1]="X";
    do{
        textbackground(7); textcolor(0);
        clrscr();

        _x = 35; _y = 12;
        x = _x; y =_y;
        showframe(x,y);
        showbox('O', 1);
        showbox('X', 2);
        showbox('O', 3);
        showbox('X', 4);
        showbox('O', 5);
        showbox('X', 6);
        showbox('O', 7);
        showbox('X', 8);
        showbox('O', 9);

        gotoxy(2,18);
        printf("Welcome to Tic Tac Toe");
        printf("\n Rules are simple. Navigate with arrow keys [%c %c %c %c] and hit enter.", 30, 31, 17, 16);
        printf("\n If you try to overwrite a box, then your chance will be passed on.")
        fillrandom(arr);

        printf("\nPlayer 1, enter your name:"); gets(player[0]);
        printf("\nPlayer 2, enter your name:"); gets(player[1]);
        printf("\n%s, you take O", name[0]);
        printf("\n%s, you take X", name[1]);
        printf("Let's begin (press any key)"); getch();

        turns = 0;
        chance = 0;
        enter = 0;
        box = 1;
        win = 0;
        quit = 0;
        winner = 0;

        clrscr();
        showframe(x,y);

        while((!win)){
            gotoxy(2,20);
            printf("%s(%c), its your chance.", player[chance], O_OR_X[chance]);
            while(!enter && !quit){
                if(khbit())
                ch = getch();
                switch(ch){
                    case UPARROW: box = navigate(a[3][3], box, player, UPARROW);
                    case DOWNARROW: box = navigate(a[3][3], box, player, UPARROW);
                    case UPARROW: box = navigate(a[3][3], box, player, UPARROW);
                    case UPARROW: box = navigate(a[3][3], box, player, UPARROW);
                    case QUIT : quit = 1; break;
            }
        }

        }
    }

        
        if(quit) break;
        if(chance === 0){
            putintobox(arr,box,'O');
            box = 1;
        }
        else if(chance == 1){
            putintobox(arr,box,'X');
            box = 1;
        }
        if((win = checkforwin(arr))==1){
            winner = chance;
            if(chance == 1){
                chance = 0;
            }
            else chance = 1;
        }
        enter = 0;
        turns++;
        if(!boxesleft(arr)){
            movesfinished = 1;
        }
        if(!win) && (turns == 9) && (movesfinished){
            break;
        }
        
    }
    if(win){
        gotoxy(22,22);
        textbackground(4);
        textcolor(15);
        if(winner == 0){
            cprintf("Congrats! %s won the game!", player[0]);

        }
        else{
            cprintf("Congrats! %s won the game!", player[1]);
        }
    }
    else if(quit){
        gotoxy(10,22);
        textbackground(4);
        textcolor(15);
        cprintf("That was fun! See you later.\n Press any key to exit. . .\n\n");
        getch();
        return 1;
    }
    else if((!win) && (turns==9) && (movesfinished)){
        gotoxy(22,22);
        printf("Y'all are losers. \n It's a draw.\n");
    }
    printf("Do you want to play again?? (Y/N):\n");
    ch = getch();
    while(ch=='Y'||ch=='y');
    return 0;
}