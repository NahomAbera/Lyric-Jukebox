#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <windows.h>

int main(){
    int trackNum;
    char track[50];
    char lyric[1000];
    
    printf("\n\nWelcome to Nahom's Lyric Jukebox!\nPlease select a track from the list below:");

    // The following do...while loop will allow the application to run until the user puts in 0 to quit.
    do{
        printf("\n\n\n   artist \t\t Song \t\t\t Album\n");
        printf("-------------------------------------------------------------------\n");
        printf("1: JAY-Z, Kanye West \t - Ni**as in Paris \t - Watch the Throne\n");
        printf("2: Eminem \t\t - Without Me \t\t - The Eminem Show\n");
        printf("3: Drake \t\t - God's Plan \t\t - Scorpion\n");
        printf("4: The Weekend(Abel) \t - Save Your Tears \t - After Hours\n");
        printf("5: Pop Smoke \t\t - Dior \t\t - Meet the Woo 2\n");
        printf("6: Coldplay \t\t - Viva la Vida \t - Viva la Vida 2\n");
        printf("7: Micheal Jakcson \t - Beat it \t\t - Thriller by Michael Jackson\n");
        printf("\n0: Quit\n\n:> ");
        scanf("%d", &trackNum);
        printf("\n\n");


        if (trackNum == 1 || trackNum == 2 || trackNum == 3 || trackNum == 4 || trackNum == 5 || trackNum == 6 || trackNum == 7){
            // The followinf switch case statment will use the user input stored in trackNum to copy the file name to the track varibale.
            switch (trackNum){
                case 1: 
                    strcpy (track,"LyricsFolder/Ni!!as_in_Paris.txt"); 
                    break;
                case 2: 
                    strcpy (track, "LyricsFolder/Without_Me.txt"); 
                    break;
                case 3: 
                    strcpy (track, "LyricsFolder/God's_Plan.txt"); 
                    break;
                case 4: 
                    strcpy (track, "LyricsFolder/Save_Your_Tears.txt"); 
                    break;
                case 5: 
                    strcpy(track, "LyricsFolder/Dior.txt"); 
                    break;
                case 6: 
                    strcpy(track, "LyricsFolder/Viva_la_Vida.txt"); 
                    break;
                case 7: 
                    strcpy (track,"LyricsFolder/Beat_it.txt"); 
                    break;
                default: break;
            }

            FILE* fp;

            fp = fopen(track, "r");

            // This if statment will check is fp is not NULL which means the file has been successfully opened.
            if (fp != NULL){
                while (fgets(lyric, sizeof(lyric), fp) != NULL){
                printf("%s", lyric);
                }
            }
            // Give error message if fp == NULL.
            else printf("Error while opening file\n");

            // Sleep for three seconds between displaying the lyrics to the user and prompting the user again to choose a track.
            sleep(3);

            fclose(fp);
        }else if(trackNum != 0) {printf("Wrong Input");} // This else if statment is used to inform the user that they made an invalid input. 
    }while (trackNum != 0);
    return 0;

}