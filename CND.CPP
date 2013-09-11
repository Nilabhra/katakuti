#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>

/*========================= CLASS GRAPHICS AND IT'S MEMBER FUNTION DEFINITIONS========================*/

class Graphics

    {
       /*============ PROTECTED DATA MEMBERS =============*/

        protected :

            void drawHomeScreen ();
            void drawLoadScreen ();
            void drawBlankBoard ();
            void drawGameBoard ();
            void turnPrompt ( int , int );
            void cross ( int , int );
            void dot ( int , int );
            void continueCheck ();
            void nameDisp ( int );
            void putMenuText ();
            void drawHowToPlay ();
            void drawInfoScreen ();

    };

void Graphics::drawGameBoard () // DRAW'S THE PLAY SCREEN

    {

        setbkcolor ( LIGHTGRAY );
        setcolor ( WHITE );
        setlinestyle ( SOLID_LINE , 0 , NORM_WIDTH );
        rectangle ( 169 , 89 , 469 , 389 );
        setfillstyle ( SOLID_FILL , LIGHTGRAY );
        bar ( 171 , 91 , 467 , 387 );
        bar ( 119 , 410 , 519 , 460 );
        rectangle ( 269 , 89 , 369 , 389 );
        rectangle ( 169 , 189 , 469 , 289 );
        setcolor ( BLUE );
        rectangle ( 173 , 93 , 265 , 185 );
        rectangle ( 273 , 93 , 365 , 185 );
        rectangle ( 373 , 93 , 465 , 185 );
        rectangle ( 173 , 193 , 265 , 285 );
        rectangle ( 273 , 193 , 365 , 285 );
        rectangle ( 373 , 193 , 465 , 285 );
        rectangle ( 173 , 293 , 265 , 385 );
        rectangle ( 273 , 293 , 365 , 385 );
        rectangle ( 373 , 293 , 465 , 385 );
        setcolor ( DARKGRAY );
        setlinestyle ( SOLID_LINE , 0 , NORM_WIDTH );
        line ( 499 , 189 , 600 , 189 );
        line ( 500 , 190 , 600 , 190 );
        line ( 600 , 189 , 600 , 239 );
        line ( 599 , 190 , 599 , 238 );
        line ( 40 , 189 , 141 , 189 );
        line ( 41 , 190 , 141 , 190 );
        line ( 141 , 189 , 141 , 239 );
        line ( 140 , 190 , 140 , 238 );
        setcolor ( WHITE );
        line ( 499 , 189 , 499 , 239 );
        line ( 500 , 190 , 500 , 238 );
        line ( 499 , 239 , 600 , 239 );
        line ( 500 , 238 , 599 , 238 );
        line ( 40 , 189 , 40 , 239 );
        line ( 41 , 190 , 41 , 238 );
        line ( 40 , 239 , 141 , 239 );
        line ( 41 , 238 , 140 , 238 );

    }

void Graphics::cross ( int mx , int my ) // DRAW'S CROSS IN SPECIFIED SQUARES ON USER INPUT

    {

        setfillstyle ( CLOSE_DOT_FILL , LIGHTBLUE );
        floodfill ( mx , my , BLUE );
        setcolor ( LIGHTBLUE );
        line (mx , my - 5 , mx + 25 , my - 25 );
        line ( mx + 5 , my , mx + 35 , my - 25 );
        line ( mx + 25 , my - 25 , mx + 35 , my - 25 );
        line ( mx , my - 5 , mx - 25 , my - 25 );
        line ( mx - 5 , my , mx - 35 , my - 25 );
        line ( mx - 25 , my - 25 , mx - 35 , my - 25 );
        line ( mx , my + 5 , mx + 25 , my + 25 );
        line ( mx + 5 , my , mx + 35 , my + 25 );
        line ( mx + 25 , my + 25 , mx + 35 , my + 25 );
        line ( mx , my + 5 , mx - 25 , my + 25 );
        line ( mx - 5 , my , mx - 35 , my + 25 );
        line ( mx - 25,my + 25,mx - 35, my + 25 );
        setfillstyle ( SOLID_FILL,RED );
        floodfill ( mx , my , LIGHTBLUE );

    }

void Graphics::dot ( int mx , int my ) // DRAW'S DOT IN SPECIFIED SQUARES ON USER/COMPUTER INPUT

    {

        setfillstyle ( CLOSE_DOT_FILL ,RED);
        floodfill ( mx , my , BLUE );
        setcolor ( RED ) ;
        circle ( mx , my , 30 );
        circle ( mx , my , 20 );
        setfillstyle (SOLID_FILL , LIGHTBLUE );
        floodfill ( mx , my-25 , RED );

    }

void Graphics::continueCheck () // DISPLAYS A PROMPT ASKING THE USER TO CONTINUE OR NOT

    {

        delay ( 800 );
        setfillstyle ( SOLID_FILL , DARKGRAY );
        bar ( 264 , 214 , 384 , 274 );
        setfillstyle ( SOLID_FILL , BLUE );
        setcolor ( WHITE );
        bar ( 259 , 209 , 379 , 269 );
        setlinestyle ( 0 , 0 , 1 );
        rectangle ( ( 319 ) - 58 , ( 239 ) - 28 , ( 319 ) + 58 , ( 239 ) + 28 );
        rectangle ( ( 319 ) - 56 , ( 239 ) - 26 , ( 319 ) + 56 , ( 239 ) + 26 );
        settextstyle ( TRIPLEX_FONT , HORIZ_DIR , 1 );
        outtextxy ( 260 , 215 , " Play again?" );
        outtextxy ( 295 , 240 , "(y/n)" );

    }

void Graphics::nameDisp( int game_mode ) // DISPLAYS THE NAME OF THE PLAYERS ON TOP OF SCORE-BOX

    {

        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 1 );
        setcolor ( DARKGRAY );

        if ( game_mode == 1 )

            {

                outtextxy ( 41 , 159 , "Player 1 :" );
                outtextxy ( 500 , 159 , "Player 2 :" );
                setcolor ( RED );
                outtextxy ( 40 , 160 , "Player 1 :" );
                setcolor ( LIGHTBLUE );
                outtextxy ( 499 , 160 , "Player 2 :" );

            }

        else if ( game_mode == 2 )

            {

                outtextxy ( 41 , 159 , "Player :" );
                outtextxy ( 500 , 159 , "Computer :" );
                setcolor ( RED );
                outtextxy ( 40 , 160 , "Player :" );
                setcolor ( LIGHTBLUE );
                outtextxy ( 499 , 160 , "Computer :" );

            }


    }

void Graphics::drawBlankBoard () // DRAW'S A SCREEN USED AS BACKGROUND FOR DISPLAYING MENU AND SCORE

    {

        int x = getmaxx ();
        int y = getmaxy ();

        setcolor ( BLACK );
        setbkcolor ( BLACK );
        setfillstyle ( SOLID_FILL , BLACK );
        bar ( 1 , 1 , 638 , 478 );
        setcolor ( RED );
        setlinestyle ( SOLID_LINE , 0 , NORM_WIDTH );
        rectangle ( ( x / 2 ) - 200 , ( y / 2 ) - 200 , ( x / 2) + 200 , ( y / 2 ) + 200 );
        rectangle( ( x / 2 ) - 197 , ( y / 2 ) - 197 , ( x / 2 ) + 197 , ( y / 2 ) + 197 );
        setfillstyle ( INTERLEAVE_FILL , LIGHTBLUE );
        floodfill ( x / 2 , y / 2 , RED );

    }

void Graphics::putMenuText () // TO PUT THE MENU TEXT ON THE SCREEN

    {

        const char *menu_text[]=   {"MENU" ,
                                    "1 : Player vs Player" ,
                                    "2 : Player vs Computer" ,
                                    "3 : Scores" ,
                                    "4 : How to Play" ,
                                    "5 : INFO" ,
                                    "6 : QUIT"};  // POINTER ARRAY CONTAINING THE MENU TEXT

        int x = getmaxx ();
        int y = getmaxy ();
        int h = ( x / 2 ) - 160;
        int k = ( y / 2 ) - 100;

        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 4 );
        setcolor ( BLACK );
        outtextxy ( ( x / 2 ) - 57 , ( y / 2 ) - 183 , menu_text [ 0 ] );
        setcolor ( LIGHTGREEN );
        outtextxy ( ( x / 2 ) - 60 , ( y / 2 ) - 180 , menu_text [ 0 ] );
        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 3 );

        for( int i = 1 ; i <= 6 ; i ++,k+ = 28 )

            {

                delay ( 450 );
                setcolor ( BLACK );
                outtextxy( h + 3 , k - 2, menu_text [ i ] );

                if ( i == 6 )

                    {

                        setcolor ( RED );

                    }

                else

                    {

                        setcolor ( LIGHTGREEN );

                    }


                outtextxy ( h , k , menu_text [ i ] );

            }

        delete [] menu_text;

    }

void Graphics::drawHomeScreen () // DRAW'S THE HOME SCREEN

    {

        int x = getmaxx ();
        int y = getmaxy ();

        setbkcolor ( WHITE );
        setcolor ( MAGENTA );
        setlinestyle ( CENTER_LINE , 0 , NORM_WIDTH );
        line ( 270 , 20 , 150 , y - 20 );
        line ( 470 , 20 , 340 , y - 20 );
        line ( 50 , 155 , x - 43 , 155 );
        line ( 7 , 310 , x - 86 , 310 );
        setcolor ( RED );
        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 8 );
        outtextxy ( 26 , 38 , "cr" );
        setcolor ( LIGHTBLUE );
        settextstyle ( SANS_SERIF_FONT , HORIZ_DIR , 10 );
        outtextxy ( 106 , 0 , "o" );
        setfillstyle ( SOLID_FILL , LIGHTBLUE );
        floodfill ( 108 , 100 , LIGHTBLUE );
        setcolor ( RED );
        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 8 );
        outtextxy ( 160 , 38 , "ss" );
        settextstyle ( COMPLEX_FONT , HORIZ_DIR , 10 );
        setcolor ( CYAN );
        outtextxy ( 264 , 125 , "&" );
        setcolor ( RED );
        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 8 );
        outtextxy ( x - 250 , y - 170 , "d" );
        settextstyle ( SANS_SERIF_FONT , HORIZ_DIR , 10 );
        setcolor ( LIGHTBLUE );
        outtextxy ( x - 200 , y - 220 , "o" );
        floodfill ( x - 190 , y - 140 , LIGHTBLUE );
        setcolor ( RED );
        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 8 );
        outtextxy ( x - 145 , y - 170 , "ts" );
        setcolor ( LIGHTBLUE );
        settextstyle ( SANS_SERIF_FONT , HORIZ_DIR , 10 );
        outtextxy ( x - 150 , 0 , "x" );
        setfillstyle (SOLID_FILL , LIGHTBLUE );
        floodfill ( x - 141 , 79 , LIGHTBLUE );
        floodfill ( x - 141 , 120 , LIGHTBLUE );
        floodfill ( x - 110 , 79 , LIGHTBLUE );
        floodfill ( x - 110 , 120 , LIGHTBLUE );
        floodfill ( x - 126 , 100 , LIGHTBLUE );
        outtextxy ( 80 , y - 220 , "x" );
        floodfill ( 97 , 350 , LIGHTBLUE );
        floodfill ( 110 , 350 , LIGHTBLUE );
        floodfill ( 97 , 367 , LIGHTBLUE );
        floodfill ( 110 , 367 , LIGHTBLUE );
        floodfill ( 104 , 359 , LIGHTBLUE );
        settextstyle ( SIMPLEX_FONT , HORIZ_DIR , 3 );
        setcolor ( BLUE );
        delay ( 500 );
        outtextxy ( 50 , y - 55 , "Press any key to continue..." );
        getch ();

    }

void Graphics::drawLoadScreen ()  // DRAW'S THE LOADING SCREEN

    {

        int y = getmaxy ();

        setlinestyle ( DEFAULT_FONT , HORIZ_DIR , 2 );
        setcolor ( LIGHTBLUE );
        setbkcolor ( BLACK );
        setfillstyle ( SOLID_FILL , BLACK );
        bar ( 1 , 1 , 638 , 478 );
        settextstyle (BOLD_FONT , HORIZ_DIR , 5 );
        outtextxy ( 180 , ( y / 2 ) - 70 , "LOADING..." );
        setcolor ( WHITE );
        rectangle ( 199 , 330 , 439 , 380 );
        rectangle ( 209 , 340 , 429 , 370 );
        line ( 199 , 330 , 209 , 340 );
        line ( 439 , 330 , 429 , 340 );
        line ( 199 , 380 , 209 , 370 );
        line ( 439 , 380 , 429 , 370 );
        setfillstyle ( SOLID_FILL , LIGHTGRAY );
        floodfill ( 201 , 333 , WHITE );
        floodfill ( 205 , 377 , WHITE );
        setfillstyle ( SOLID_FILL , DARKGRAY );
        floodfill ( 435 , 333 , WHITE );
        floodfill ( 437 , 373 , WHITE );

        int m;

        for ( m = 210 ; m < 429 ; ++m)

            {

                setcolor ( 2 );
                line ( m , 341 , m , 369 );
                delay ( 13 );

            }

        delay ( 500 );

    }

void Graphics::turnPrompt ( int game_mode , int turn_num ) // DISPLAYS THE NAME OF THE PLAYER WHOSE TURN IS NEXT

    {

        int player_num = turn_num%2;

        settextstyle ( TRIPLEX_FONT , HORIZ_DIR , 1 );

        if ( game_mode == 2 )

            {

                if( player_num == 0 )

                    {

                        setfillstyle ( SOLID_FILL , 7 );
                        bar ( 119 , 20 , 519 , 70 );
                        setcolor ( DARKGRAY );
                        outtextxy ( 231 , 29 , "Player's turn :" );
                        setcolor ( RED );
                        outtextxy ( 230 , 30 , "Player's turn :" );

                    }

                else

                    {

                        setfillstyle ( SOLID_FILL , 7 );
                        bar ( 119 , 20 , 519 , 70 );
                        setcolor ( 8 );
                        outtextxy ( 231 , 29 , "Computer's turn :" );
                        setcolor ( 9 );
                        outtextxy ( 230 , 30 , "Computer's turn :" );
                        delay ( 350 );

                    }

            }

        else if ( game_mode == 1 )

            {

                if ( player_num == 0 )

                {

                    setfillstyle ( SOLID_FILL , 7 );
                    bar ( 119 , 20 , 519 , 70 );
                    setcolor ( 8 );
                    outtextxy ( 231 , 29 , "Player 1's turn :" );
                    setcolor ( 4 );
                    outtextxy ( 230 , 30 , "Player 1's turn :" );

                }

                else

                {

                    setfillstyle ( SOLID_FILL , 7 );
                    bar ( 119 , 20 , 519 , 70 );
                    setcolor ( 8 );
                    outtextxy ( 231 , 29 , "Player 2's turn :" );
                    setcolor ( 9 );
                    outtextxy ( 230 , 30 , "Player 2's turn :" );

                }

            }

    }

void Graphics::drawHowToPlay () // DISPLAYS THE INSTRUCTION SCREEN

    {
        setbkcolor ( BLACK );
        setfillstyle ( SOLID_FILL , BLACK );
        bar ( 1 , 1 , 638 , 478 );
        setcolor ( WHITE );
        rectangle ( 244 , 50 , 394 , 200 );
        rectangle ( 294 , 50 , 344 , 200 );
        rectangle ( 244 , 100 , 394 , 150 );
        settextstyle( TRIPLEX_FONT , HORIZ_DIR , 1 );
        outtextxy ( 263 , 65 , "7" );
        outtextxy ( 313 , 65 , "8" );
        outtextxy ( 363 , 65 , "9" );
        outtextxy ( 263 , 115 , "4" );
        outtextxy ( 313 , 115 , "5" );
        outtextxy ( 363 , 115 , "6" );
        outtextxy ( 263 , 165 , "1" );
        outtextxy ( 313 , 165 , "2" );
        outtextxy ( 363 , 165 , "3" );

        char *instruction_text[] = {"Controls :",
                       "Use the number pad of the key board to put the crosses in the desired squares",
                       "Reffer to the diagram above.",
                       "Game Play :",
                       "It's just like the old Tic-Tac-Toe we all have played, only now you can play",
                       "it on your PC ! I hope you enjoy my game",
                       "Press any key to return"};

        setcolor ( GREEN );
        settextstyle( COMPLEX_FONT , HORIZ_DIR , 3 );
        outtextxy ( 10 , 220 , instruction_text [ 0 ] );
        line ( 7 , 250 , 120 , 250 );
        settextstyle ( SIMPLEX_FONT , HORIZ_DIR , 1 );
        setcolor ( BLACK );
        setcolor ( GREEN );
        outtextxy ( 10 , 255 , instruction_text [ 1 ] );
        outtextxy ( 10 , 274 , instruction_text [ 2 ] );
        settextstyle ( COMPLEX_FONT , HORIZ_DIR , 3 );
        outtextxy  ( 10 , 309 , instruction_text [ 3 ] );
        line ( 7 , 339 , 130 , 339 );
        settextstyle ( SIMPLEX_FONT , HORIZ_DIR , 1 );
        outtextxy ( 10 , 344 , instruction_text [ 4 ] );
        outtextxy ( 10 , 363 , instruction_text [ 5 ] );
        setcolor ( WHITE );
        outtextxy ( 220 , 400 , instruction_text [ 6 ] );

        delete [] instruction_text;

        getch ();

    }

void Graphics::drawInfoScreen () // DRAW'S THE INFORMATION SCREEN

    {

        setbkcolor ( BLACK );
        setfillstyle ( SOLID_FILL , BLACK );
        bar ( 0 , 0 , 639 , 479 );
        setcolorv ( GREEN );
        settextstyle ( COMPLEX_FONT , HORIZ_DIR , 3 );
        outtextxy ( 20 , 100 , "Master Programmer: Nilabhra Roy Chowdhury" );
        outtextxy ( 90 , 150 , "Contact: nilabhraroy@ymail.com" );
        settextstyle ( SIMPLEX_FONT , HORIZ_DIR , 2 );
        outtextxy ( 30 , 200 , "Graphics Designers : Sudipto Dutta & Priyojit Karmakar" );
        outtextxy ( 30 , 250 , "GUI developed by by Nilarghya Siddhanta & Kaustov Bhattacharya" );
        outtextxy ( 30 , 300 , "Artificial Intelligence developed by Nilabhra Roy Chowdhury" );
        settextstyle ( COMPLEX_FONT , HORIZ_DIR , 4 );
        setcolor ( YELLOW );
        outtextxy ( 100 , 360 , "Thank You for playing!" );
        settextstyle ( SIMPLEX_FONT , HORIZ_DIR , 1 );
        setcolor ( WHITE );
        outtextxy ( 220 , 420 , "Press any key to return..." );
        getch ();

    }

/*=========================== END OF CLASS GRAPHICS AND IT'S MEMBER FUNTION DEFINITIONS =============================*/


/*=============================== CLASS GAME AND IT'S MEMBER FUNTION DEFINITIONS ===================================*/

class Game : protected Graphics // INHERITING CLASS GRAPHICS UNDER PROTECTED SECURITY

    {

/*============= PRIVATE DATA MEMBERS ==============*/
        private:

            char player_choice;
            char *pl_1_Tscore ;
            char *pl_2_Tscore ;
            char *pl_Tscore_AI;
            char *comp_Tscore_AI;

            int score_p1;
            int score_p2;
            int score_AI_p;
            int score_AI_comp;
            int sq[9];

            int winCheck();

            void winDeclare ( int , int , int , int & , int & , int & , int & );
            void playGame ( int );
            void scoreUpdate ( int , int , int , int , int );
            void gameInteract ( int , int & );
            void putScoreText ();

/*============= PUBLIC DATA MEMBERS ==============*/
        public :

            Game (); // CONSTRUCTOR FOR GAME CLASS
            void Driver ();
        };

int Game::winCheck () // CHECKS IF ANY PLAYER HAS WON

    {

        if ( sq [ 0 ] + sq [ 1 ] + sq [ 2 ] == 3 || sq [ 0 ] + sq [ 1 ] + sq [ 2 ] == - 3 )
            return 1;
        if ( sq [ 3 ] + sq [ 4 ] + sq [ 5 ] == 3 || sq [ 3 ] + sq [ 4 ] + sq [ 5 ] == - 3 )
            return 2;
        if ( sq [ 6 ] + sq [ 7 ] + sq [ 8 ] == 3 || sq [ 6 ] + sq [ 7 ] + sq [ 8 ] == - 3 )
            return 3;
        if ( sq [ 0 ] + sq [ 3 ] + sq [ 6 ] == 3 || sq [ 0 ] + sq [ 3 ] + sq [ 6 ] == - 3 )
            return 4;
        if ( sq [ 1 ] + sq [ 4 ] + sq [ 7 ] == 3 || sq [ 1 ] + sq [ 4 ] + sq [ 7 ] == - 3 )
            return 5;
        if ( sq [ 2 ] + sq [ 5 ] + sq [ 8 ] == 3 || sq [ 2 ] + sq [ 5 ] + sq [ 8 ] == - 3 )
            return 6;
        if ( sq [ 0 ] + sq [ 4 ] + sq [ 8 ] == 3 || sq [ 0 ] + sq [ 4 ] + sq [ 8 ] == - 3 )
            return 7;
        if ( sq [ 2 ] + sq [ 4 ] + sq [ 6 ] == 3 || sq [ 2 ] + sq [ 4 ] + sq [ 6 ] == - 3 )
            return 8;
        else
            return 0;

    }

void Game::winDeclare ( int w , int player_num , int game_mode , int & a , int & b , int & c , int & d ) // DIPLAYS THE NAME OF THE WINNER AND DRAW'S THE WIN LINE

    {

    //To draw the line...
        setlinestyle ( DASHED_LINE , 0 , THICK_WIDTH );
        setcolor ( YELLOW );
        switch ( w )

            {

                case 1:
                    line ( 219 , 139 , 419 , 139 );
                    break;

                case 2:
                    line ( 219 , 239 , 419 , 239 );
                    break;

                case 3:
                    line ( 219 , 339 , 419 , 339 );
                    break;

                case 4:
                    line ( 219 , 139 , 219 , 339 );
                    break;

                case 5:
                    line ( 319 , 139 , 319 , 339 );
                    break;

                case 6:
                    line ( 419 , 139 , 419 , 339 );
                    break;

                case 7:
                    line ( 219 , 139 , 419 , 339 );
                    break;

                case 8:
                    line ( 219 , 339 , 419 , 139 );
                    break;


                }

       // Displaying the name of the winner....

        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 2 );

        if ( ( player_num - 1 ) % 2 == 0 )

            {

                setcolor ( RED );
                if ( game_mode == 2 )

                    {

                        c+ = 1;
                        score_AI_p+ = c;
                        outtextxy ( 230 , 420 , "Player wins!" );

                    }

                else

                    {

                        a+ = 1;
                        score_p1+ = a;
                        outtextxy ( 230 , 420 , "Player 1 wins!" );

                    }

            }

        else

            {
                setcolor ( LIGHTBLUE );
                if ( game_mode == 2 )
                    {
                        d+ = 1;
                        score_AI_comp+ = d;
                        outtextxy ( 230 , 420 , "Computer wins!" );
                    }
                else
                    {
                        b+ = 1;
                        score_p2+ = b;
                        outtextxy ( 230 , 420 , "Player 2 wins!" );
                    }
            }
    }

void Game::playGame ( int game_mode ) // CALLS THE NECESSARY FUNCTION TO PLAY THE GAME
    {
        const int TOTAL_TURNS = 9;
        int turn_number , n;

        int temp_score_p1 = 0;
        int temp_score_p2 = 0;
        int temp_score_AI_p = 0;
        int temp_score_AI_comp = 0;

        cleardevice();

        for ( ; ; )
            {

                for ( int i = 0; i < 9; ++i)
                    {
                        sq [ i ] = 0;
                    }

                drawGameBoard ();
                nameDisp ( game_mode );
                for ( turn_number = 0; turn_number <= TOTAL_TURNS; turn_number++ )
                    {
                        n = winCheck ();

                        if ( n != 0 )
                            {
                                winDeclare ( n , turn_number , game_mode , temp_score_p1 , temp_score_p2 , temp_score_AI_p , temp_score_AI_comp );
                                scoreUpdate ( game_mode , temp_score_p1 , temp_score_p2 , temp_score_AI_p , temp_score_AI_comp );
                                break;
                            }

                        scoreUpdate ( game_mode , temp_score_p1 , temp_score_p2 , temp_score_AI_p , temp_score_AI_comp );

                        if ( turn_number == 9 )
                            {
                                settextstyle ( 1 , 0 , 2 );
                                setcolor ( 14 );
                                outtextxy ( 270 , 420 , "DRAW!" );
                                break;
                            }
                        else
                            {
                                turnPrompt (game_mode , turn_number );
                                gameInteract ( game_mode , turn_number );
                            }
                    }
                for ( ; ; )
                    {
                        continueCheck ();
                        player_choice = getch ();
                        if ( player_choice == 'y' || player_choice == 'n' || player_choice == 'Y' || player_choice == 'N' )
                            break;
                    }
            if ( player_choice == 'n' || player_choice == 'N' )
                {
                    return;
                }
            }
    }

void Game::scoreUpdate ( int game_mode , int a , int b , int c , int d ) // UPDATES THE SCORE ON THE SCREEN
    {
        setfillstyle ( SOLID_FILL , LIGHTGRAY );
        bar ( 45 , 195 , 135 , 233 );
        bar ( 505 , 195 , 595 , 233 );

        if ( game_mode == 1 )
            {
                itoa ( a ,pl_1_Tscore , 10 );
                itoa (b , pl_2_Tscore , 10 );
                setcolor ( GREEN );
                settextstyle ( DEFAULT_FONT , HORIZ_DIR , 2 );
                outtextxy ( 515 , 205 , pl_2_Tscore );
                outtextxy ( 55 , 205 , pl_1_Tscore );
            }
        else
            {
                if ( game_mode == 2 )
                {
                    itoa ( c , pl_Tscore_AI , 10 );
                    itoa ( d , comp_Tscore_AI , 10 );
                    setcolor ( GREEN );
                    settextstyle ( DEFAULT_FONT , HORIZ_DIR , 2 );
                    outtextxy ( 515 , 205 , comp_Tscore_AI );
                    outtextxy ( 55 , 205 , pl_Tscore_AI );
                }
            }
    }

void Game::gameInteract ( int game_mode , int & turn_num ) // INTERACTS BETWEEN THE PLAYER AND THE USER
    {
        int player_num = turn_num % 2 ;

        if ( game_mode == 1 )
            {
                const int P1_USED = 1 ;
                const int P2_USED = -1 ;
                const int UNUSED = 0 ;
                player_choice = getch ();

                switch ( player_choice )
                    {
                        case '7':
                            if ( sq [ 0 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            sq [ 0 ] = P1_USED;
                                            cross ( 219 , 139 );
                                        }
                                    else
                                        {
                                            sq [ 0 ] = P2_USED;
                                            dot ( 219 , 139 );
                                        }
                                }
                            else
                                --turn_num;
                            break;

                        case '8':
                            if ( sq [ 1 ]== UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 319 , 139 );
                                            sq [ 1 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 319 , 139 );
                                            sq [ 1 ] = P2_USED;
                                        }
                                }
                            else
                                --turn_num;
                            break;

                        case '9':
                            if ( sq [ 2 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 419 , 139 );
                                            sq [ 2 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 419 , 139 );
                                            sq [ 2 ] = P2_USED;
                                        }
                                }
                            else
                                --turn_num;
                            break;

                        case '4':
                            if ( sq [ 3 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 219 , 239 );
                                            sq [ 3 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 219 , 239 );
                                            sq [ 3 ] = P2_USED;
                                        }
                                }
                                else
                                    --turn_num;
                                break;

                        case '5':
                            if( sq [ 4 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 319 , 239 );
                                            sq [ 4 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 319 , 239 );
                                            sq [ 4 ] = P2_USED;
                                        }
                                }
                            else
                                --turn_num;
                                break;

                        case '6':
                            if( sq [ 5 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 419 , 239 );
                                            sq [ 5 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 419 , 239 );
                                            sq [ 5 ] = P2_USED;
                                        }
                                }
                            else
                                --turn_num;
                            break;

                        case '1':
                            if ( sq [ 6 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 219 , 339 );
                                            sq [ 6 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 219 , 339 );
                                            sq [ 6 ] = P2_USED;
                                        }
                                }
                                else
                                    --turn_num;
                                break;

                        case '2':
                            if ( sq [ 7 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 319 , 339 );
                                            sq [ 7 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 319 , 339 );
                                            sq [ 7 ] = P2_USED;
                                        }
                                }
                            else
                                --turn_num;
                            break;

                        case '3':
                            if( sq [ 8 ] == UNUSED )
                                {
                                    if ( player_num == 0 )
                                        {
                                            cross ( 419 , 339 );
                                            sq [ 8 ] = P1_USED;
                                        }
                                    else
                                        {
                                            dot ( 419 , 339 );
                                            sq [ 8 ] = P2_USED;
                                        }
                                }
                            else
                                --turn_num;
                            break;

                        default :
                            --turn_num;
                        break;
                    }
            }

        if ( game_mode == 2)
            {
                const int PL_USED = 1;
                const int COMP_USED = -1;
                const int UNUSED = 0;
                const int PL_CRITICAL = 2;
                const int COMP_CRITICAL = -2;

                int i;

                if( player_num == 0 )
                    {
                        player_choice = getch ();
                        switch ( player_choice )
                            {
                                case '7':
                                    if ( sq [ 0 ] == UNUSED )
                                        {
                                            sq [ 0 ] = PL_USED;
                                            cross ( 219 , 139 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '8':
                                    if ( sq [ 1 ] == UNUSED )
                                        {
                                            sq [ 1 ] = PL_USED;
                                            cross ( 319 , 139 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '9':
                                    if ( sq [ 2 ] == UNUSED )
                                        {
                                            sq [ 2 ] = PL_USED;
                                            cross ( 419 , 139 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '4':
                                    if ( sq [ 3 ] == UNUSED )
                                        {
                                            sq [ 3 ] = PL_USED;
                                            cross ( 219 , 239 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '5':
                                    if ( sq [ 4 ] == UNUSED )
                                        {
                                            sq [ 4 ] = PL_USED;
                                            cross ( 319 , 239 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '6':
                                    if ( sq [ 5 ] == UNUSED )
                                        {
                                            sq [ 5 ] = PL_USED;
                                            cross ( 419 , 239 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '1':
                                    if ( sq [ 6 ] == UNUSED )
                                        {
                                            sq [ 6 ] = PL_USED;
                                            cross ( 219 , 339 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '2':
                                    if ( sq [ 7 ] == UNUSED )
                                        {
                                            sq [ 7 ] = PL_USED;
                                            cross ( 319 , 339 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                                case '3':
                                    if( sq [ 8 ] == UNUSED )
                                        {
                                            sq [ 8 ] = PL_USED;
                                            cross ( 419 , 339 );
                                        }
                                    else
                                        --turn_num;
                                    break;

                            default :
                                --turn_num;
                                break;
                            }

                        return;
                    }
                else
                    {
                        for(i=0; i<=6; i+=3)
                            {
                                int temp = sq[i+0]+sq[i+1]+sq[i+2];

                                if(temp == COMP_CRITICAL)
                                    {
                                        for (int j = 0;  j < 3; j++)
                                            {
                                                if ( sq [ i + j ] == UNUSED )
                                                    {
                                                        dot ( ( 219 + ( j * 100 ) ) , ( 139 + ( i / 3 ) * 100 ) );
                                                        sq [ i + j ] = COMP_USED;
                                                        return;
                                                    }
                                            }
                                    }//end of if
                            }
                        for ( i = 0; i < 3; i++)
                            {
                                int temp = sq [ i + 0 ] + s q [ i +3 ] + sq [ i + 6];

                                if ( temp == COMP_CRITICAL )
                                    {
                                        for (int j = 0;  j <= 6; j+=3)
                                            {
                                                if ( sq [ i + j ] == UNUSED )
                                                    {
                                                        dot ( ( 219 + ( i * 100 ) ) , ( 139 + ( j / 3 ) *100 ) );
                                                        sq [ i + j ] = COMP_USED;
                                                        return;
                                                    }
                                            }
                                    }//end of if
                            }

                        if ( sq [ 0 ] + sq [ 4 ] + sq [ 8 ] == COMP_CRITICAL )
                            {
                                if( sq [ 0 ] == UNUSED )
                                    {
                                        dot ( 219 , 139 );
                                        sq [ 0 ] = COMP_USED;
                                        return;
                                    }
                                else if(sq[4]==UNUSED)
                                    {
                                        dot ( 319 , 239 );
                                        sq [ 4 ] = COMP_USED;
                                        return;
                                    }
                                else if ( sq [ 8 ] == UNUSED )
                                    {
                                        dot ( 419 , 339 );
                                        sq [ 8 ] = COMP_USED;
                                        return;
                                    }
                            }

                        if( sq [ 6 ] + sq [ 4 ] + sq [ 2 ]   == COMP_CRITICAL )
                            {
                                for ( i = 6 ; i >= 2; i- = 2 )
                                    {
                                        if ( sq [ 6 ] == UNUSED )
                                            {
                                                dot ( 219 , 339 );
                                                sq [ 6 ] = COMP_USED;
                                                return;
                                            }
                                        else if( sq [ 4 ] == UNUSED )
                                            {
                                                dot ( 319 , 239 );
                                                sq [ 4 ] = COMP_USED;
                                                return;
                                            }
                                        else if ( sq [ 2 ] == UNUSED )
                                            {
                                                dot ( 419 , 139 );
                                                sq [ 2 ] = COMP_USED;
                                                return;
                                            }
                                    }
                            }
                        for ( i = 0; i <= 6; i+ = 3 )
                            {
                                int temp = sq [ i + 0 ]+ sq [ i + 1 ] + sq[ i + 2 ];

                                if ( temp == PL_CRITICAL )
                                    {
                                        for ( int j = 0;  j < 3; j++ )
                                            {
                                                if ( sq [ i + j ] == UNUSED )
                                                    {
                                                        dot( ( 219 + ( j * 100 ) ) , ( 139 + ( i / 3 ) * 100 ) );
                                                        sq [ i + j ] = COMP_USED;
                                                        return;
                                                    }
                                            }
                                    }//end of if
                            }
                        for( i = 0; i < 3; i++ )
                            {
                                int temp = sq [ i + 0 ] + sq [ i + 3 ] + sq [ i + 6 ];

                                if ( temp == PL_CRITICAL )
                                    {
                                        for ( int j = 0;  j <= 6; j+ = 3 )
                                            {
                                                if ( sq [ i + j ]  == UNUSED)
                                                    {
                                                        dot( ( 219 + ( i * 100) ) ,( 139+ ( j / 3 ) * 100 ) );
                                                        sq [ i + j ] = COMP_USED;
                                                        return;
                                                    }
                                            }
                                    }//end of if
                            }

                        if ( sq [ 0 ] + sq [ 4 ] + sq [ 8 ]  == PL_CRITICAL )
                            {
                                if ( sq [ 0 ] == UNUSED)
                                    {
                                        dot ( 219 , 139 );
                                        sq [ 0 ] = COMP_USED;
                                        return;
                                    }
                                else if ( sq[ 4 ] == UNUSED )
                                    {
                                        dot ( 319 , 239 );
                                        sq [ 4 ] = COMP_USED;
                                        return;
                                    }
                                else if ( sq [ 8 ] == UNUSED)
                                    {
                                        dot ( 419 , 339 );
                                        sq [ 8 ] = COMP_USED;
                                        return;
                                    }
                            }

                        if ( sq [ 6 ] + sq [ 4 ] + sq [ 2 ]  == PL_CRITICAL )
                            {
                                for ( i = 6 ; i >= 2; i- = 2 )
                                    {
                                        if ( sq [ 6 ] == UNUSED )
                                            {
                                                dot ( 219 , 339 );
                                                sq [ 6 ] = COMP_USED;
                                                return;
                                            }
                                        else if ( sq [ 4 ] == UNUSED )
                                            {
                                                dot ( 319 , 239 );
                                                sq [ 4 ] = COMP_USED;
                                                return;
                                            }
                                        else if ( sq [ 2 ] == UNUSED )
                                            {
                                                dot ( 419 , 139 );
                                                sq [ 2 ] = COMP_USED;
                                                return;
                                            }
                                    }
                            }
                        if ( sq [ 0 ] + sq [ 1 ] + sq [ 2 ] + sq [ 3 ] + sq [ 5 ] + sq [ 6 ] + sq [ 7 ] + sq [ 8 ] == PL_USED && sq [ 4 ] == UNUSED )
                            {
                                dot ( 319 , 239 );
                                sq [ 4 ] = COMP_USED;
                                return;
                            }

                        if( ( sq [ 0 ] == UNUSED && sq [ 1 ] == UNUSED && sq [ 2 ] == UNUSED && sq [ 3 ] == UNUSED && sq[ 5 ] == UNUSED && sq [ 6 ] == UNUSED && sq[ 7 ] == UNUSED && sq[ 8 ] == UNUSED) && sq[ 4 ] == PL_USED )
                    {
                        randomize();
                        int temp = random ( 4 );

                        switch ( temp )
                            {
                                case 0 :
                                    dot( 219 , 139 );
                                    sq [ 0 ] = COMP_USED;
                                    break;

                                case 1 :
                                    dot ( 419 , 139 );
                                    sq [ 2 ] = COMP_USED;
                                    break;

                                case 2 :
                                    dot ( 219 , 339 );
                                    sq [ 6 ] = COMP_USED;
                                    break;

                                case 3 :
                                    dot( 419 , 339 );
                                    sq [ 8 ] = COMP_USED;
                                    break;

                                default :
                                    break;
                            }
                        return;
                    }

                    if (sq [4] == COMP_USED)
                        {
                            randomize();

                            if ( sq [ 1 ] == UNUSED && sq [ 3 ] == UNUSED && sq [ 5 ] == UNUSED && sq [ 7 ] == UNUSED )
                                {
                                    int temp;
                                    temp = random ( 4 );

                                    switch ( temp )
                                        {
                                            case 0 :
                                                dot ( 319 , 139 );
                                                sq [ 1 ] = COMP_USED;
                                                return;

                                            case 1 :
                                                dot ( 419 , 239 );
                                                sq [ 5 ] = COMP_USED;
                                                return;

                                            case 2 :
                                                dot ( 319 , 339 );
                                                sq [ 7 ] = COMP_USED;
                                                return;

                                            case 3 :
                                                dot ( 219 , 239 );
                                                sq [ 3 ] = COMP_USED;
                                                return;


                                            default :
                                                break;
                                        }
                                }
                            else if( sq [ 1 ] == UNUSED && sq [ 7 ] == UNUSED )
                                {
                                    int temp;
                                    temp = random ( 2 );

                                    if( temp == 0 )
                                        {
                                            dot ( 319 , 139 );
                                            sq [ 1 ] = COMP_USED;
                                            return;
                                        }
                                    else
                                        {
                                            dot ( 319 , 339 );
                                            sq [ 7 ] = COMP_USED;
                                            return;
                                        }
                                }
                            else if( sq [ 5 ] == UNUSED && sq [ 3 ] == UNUSED )
                                {
                                    int temp;
                                    temp = random ( 2 );

                                    if ( temp == 0 )
                                        {
                                            dot ( 219 , 239 );
                                            sq [ 3 ] = COMP_USED;
                                            return;
                                        }
                                    else
                                        {
                                            dot ( 419 , 239 );
                                            sq [ 5 ] = COMP_USED;
                                            return;
                                        }
                                }
                            else if ( sq [ 1 ] == UNUSED || sq [ 3 ] == UNUSED || sq [ 5 ] == UNUSED || sq [ 7 ] == UNUSED )
                                {
                                    for(;;)
                                        {
                                            int temp;
                                            temp = random (4);

                                            switch (temp)
                                                {
                                                case 0 :
                                                    if ( sq [ 1 ] == UNUSED )
                                                        {
                                                            dot( 319 , 139 );
                                                            sq [ 1 ] = COMP_USED;
                                                            return;
                                                        }
                                                    break;

                                                case 1 :
                                                    if ( sq [ 5 ] == UNUSED )
                                                        {
                                                            dot( 419 , 239 );
                                                            sq [ 5 ] = COMP_USED;
                                                            return;
                                                        }
                                                    break;

                                                case 2 :
                                                    if ( sq [ 7 ] == UNUSED )
                                                        {
                                                            dot ( 319 , 339 );
                                                            sq [ 7 ] = COMP_USED;
                                                            return;
                                                        }
                                                    break;

                                                case 3 :
                                                    if ( sq [ 3 ] == UNUSED )
                                                        {
                                                            dot ( 219 , 239 );
                                                            sq [ 3 ] = COMP_USED;
                                                            return;
                                                        }
                                                    break;

                                                default :
                                                    break;
                                                }
                                            }
                                }
                        }
                    else if ( sq [ 4 ] == PL_USED )
                    {
                        int temp;
                        temp = random ( 2 );

                        if ( temp == 0 )
                            {
                                if( sq [ 0 ] == UNUSED )
                                    {
                                        dot ( 219 , 139 );
                                        sq [ 0 ] = COMP_USED;
                                        return;
                                    }
                                else if ( sq [ 6 ] == UNUSED )
                                    {
                                        dot ( 219 , 339 );
                                        sq [ 6 ] = COMP_USED;
                                        return;
                                    }
                            }
                        else
                            {
                                if ( sq [ 2 ] == UNUSED )
                                    {
                                        dot ( 419 , 139 );
                                        sq [ 2 ] = COMP_USED;
                                        return;
                                    }
                                else if ( sq [ 8 ] == UNUSED )
                                    {
                                        dot ( 419 , 339 );
                                        sq [ 8 ] = COMP_USED;
                                        return;
                                    }
                            }
                        if ( sq [ 1 ] == UNUSED && sq [ 7 ] == UNUSED )
                            {
                                int temp;
                                temp = random ( 2 );

                                if ( temp == 0 )
                                    {
                                        dot ( 319 , 139 );
                                        sq [ 1 ] = COMP_USED;
                                        return;
                                    }
                                else
                                    {
                                        dot ( 319 , 339 );
                                        sq [ 7 ] = COMP_USED;
                                        return;
                                    }
                            }
                        else if ( sq [ 5 ] == UNUSED && sq [ 3 ] == UNUSED )
                            {
                                int temp;
                                temp = random ( 2 );

                                if ( temp == 0 )
                                    {
                                        dot ( 219 , 239 );
                                        sq [ 3 ] = COMP_USED;
                                        return;
                                    }
                                else
                                    {
                                        dot ( 419 , 239 );
                                        sq [ 5 ] = COMP_USED;
                                        return;
                                    }
                            }
                    }
                }
        }
}

void Game::putScoreText () // PUTS THE SCORE TEXT ON THE SCREEN
    {
        const char *score_text [] = {"SCORES",
                                   "Player vs Player",
                                   "Player 1 :",
                                   "Player 2 :",
                                   "Player vs Computer",
                                   "Player :",
                                   "Computer :",
                                   "Press any key to return ..."};  // POINTER CHARACTER ARRAY CONTAINING THE SCORE TEST

        int x = getmaxx();
        int y = getmaxy();
        int h;
        int k;

        itoa ( score_p1 , pl_1_Tscore , 10 );
        itoa ( score_p2 , pl_2_Tscore , 10 );
        itoa ( score_AI_p , pl_Tscore_AI , 10 );
        itoa ( score_AI_comp , comp_Tscore_AI , 10 );

        settextstyle ( TRIPLEX_FONT , HORIZ_DIR , 5 );
        setcolor ( BLACK ) ;
        outtextxy ( ( x / 2 ) - 67 , ( y / 2 ) - 183 , score_text [ 0 ] );
        setcolor ( LIGHTGREEN );
        outtextxy ( ( x / 2 ) - 70 , ( y / 2 ) - 180 , score_text [ 0 ] );

        h = ( x / 2 ) - 150;
        k = ( y / 2 ) - 100;

        delay ( 500 );
        settextstyle ( TRIPLEX_FONT , HORIZ_DIR , 3 );
        setcolor ( BLACK );
        outtextxy ( h + 3 , k - 2 , score_text [ 1 ] );
        setcolor ( LIGHTGREEN );
        outtextxy ( h , k, score_text [ 1 ] );
        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 3 );

        k+ = 38;

        delay ( 300 );
        setcolor ( BLACK );
        outtextxy ( h + 3 , k - 2 , score_text [ 2 ] );
        outtextxy ( h + 3 + 150 , k - 2 , pl_1_Tscore );
        setcolor ( LIGHTGREEN );
        outtextxy ( h , k , score_text [ 2 ] );
        outtextxy ( h + 150 , k - 2 , pl_1_Tscore );

        k+ = 28;

        delay ( 300 );
        setcolor ( BLACK );
        outtextxy ( h + 3 , k - 2 , score_text [ 3 ] );
        outtextxy ( h + 3 + 150 , k - 2 , pl_2_Tscore );
        setcolor ( LIGHTGREEN );
        outtextxy ( h  ,k  , score_text [ 3 ] );
        outtextxy ( h + 150 , k - 2 , pl_2_Tscore );

        k += 38;

        settextstyle ( TRIPLEX_FONT , HORIZ_DIR , 3 );
        delay ( 300 );
        setcolor ( BLACK );
        outtextxy ( h + 3 , k - 2 , score_text [ 4 ] );
        setcolor ( LIGHTGREEN );
        outtextxy ( h , k , score_text [ 4 ] );

        k+ = 38;

        settextstyle ( TRIPLEX_SCR_FONT , HORIZ_DIR , 3 );
        delay ( 300 );
        setcolor ( BLACK );
        outtextxy ( h + 3 , k - 2 , score_text [ 5 ] );
        outtextxy ( h + 3 + 150 , k - 2 , pl_Tscore_AI );
        setcolor ( LIGHTGREEN );
        outtextxy ( h , k , score_text [ 5 ] );
        outtextxy ( h + 150 , k - 2 , pl_Tscore_AI );

        k+ = 28;

        delay ( 300 );
        setcolor ( BLACK );
        outtextxy ( h + 3 , k - 2 , score_text [ 6 ]  );
        outtextxy ( h + 3 + 150 , k - 2 , comp_Tscore_AI );
        setcolor ( LIGHTGREEN );
        outtextxy ( h , k  , score_text [ 6 ] );
        outtextxy ( h + 150 , k - 2 , comp_Tscore_AI );
        setcolor ( WHITE );

        k+ = 58;

        delay ( 200 );
        outtextxy ( h + 5 , k , score_text [ 7 ] );
        delay ( 100 );
        getch ();

        delete [] score_text;
    }

Game::Game () // GAME CONSTRUCTOR DEFINITION
    {
        score_p1 = 0;
        score_p2 = 0;
        score_AI_p = 0;
        score_AI_comp = 0;

        pl_1_Tscore = new char;
        pl_2_Tscore = new char;
        pl_Tscore_AI = new char;
        comp_Tscore_AI = new char;
    }

void Game::Driver() // FUNCTION WHICH CALLS THE OTHER MEMBER FUNTIONS
    {
        int graphics_driver = DETECT;
        int graphics_mode;

        initgraph( &graphics_driver , &graphics_mode , "C:\\TC\\BGI" );

        drawHomeScreen ();
        drawLoadScreen ();

        for ( ;; )
            {


                drawBlankBoard ();
                putMenuText ();

                char ch;

                for( ; ; )
                    {
                        ch = getch ();
                        if ( ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' )
                            {
                                break;
                            }
                    }
                switch ( ch )
                    {
                    case '1' :
                        playGame ( 1 );
                        break;

                    case '2' :
                        playGame( 2 );
                        break;

                    case '3' :
                        drawBlankBoard ();
                        putScoreText ();
                        break;

                    case '4' :
                        drawHowToPlay ();
                        break;

                    case '5' :
                        drawInfoScreen ();
                        break;

                    case '6' :
                        break;

                    }
                if (ch=='6')
                    break;
            }

        closegraph (); // CLOSING THE GRAPHICS SCREEN
        restorecrtmode (); //
    }

/*================================ END OF CLASS GAME AND ITS MEMBER FUNTION DEFINITIONS ====================================*/

/*================= THE MAIN FUNTION ================*/

void main()
    {
        Game cross_and_dots;

        cross_and_dots.Driver ();
    }

/*================= END OF MAIN ====================*/
