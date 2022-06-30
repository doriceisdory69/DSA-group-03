#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

	//declare the variables.........................................................01
int CSS114, CSS124, CSS122, CSS118,i;
float avgCSS114 ,avgCSS124 ,avgCSS122 ,avgCSS118 ;
int score114[80],score124[80],score122[80],score118[80];


//variable initionalization..........................................................02
float sumCSS114 ,sumCSS124 ,sumCSS122,sumCSS118 ,score[350];
int y=0;

FILE *inFile;
char student[35][80];
char best114[35],regNo[35],worst114[35];
char best124[35],regNo124[35],worst124[35];
char best122[35],regNo122[35],worst122[35];
char best118[35],regNo118[35],worst118[35];

// opening the students file containing students details.............................03
inFile = fopen("data.txt", "r");
if (inFile == NULL)
{
    printf("\nFailed to open file \n");
    exit(1);
}
printf("DETAILS OF STUDENTS\n");

// spaces for courses scores...............................................................04
printf("\n\n\n"); 
printf("regNO        CSS114   CSS124   CSS122  CSS118----------------------------------------\n\n");

//Tracing the details of student from the student file......................................05
while (fscanf(inFile, "%s %d %d %d %d",&regNo, &CSS114, &CSS124, &CSS122, &CSS118) != EOF){
	printf("%s\t%d\t%d\t%d\t%d\n",regNo,CSS114,CSS124,CSS122,CSS118);
	
//copy registration number into respective student array....................................06
	strcpy(student[y],regNo);
	score114[y] = CSS114;
	score124[y] = CSS124;
	score122[y] = CSS122;
	score118[y] = CSS118;

    sumCSS114 += CSS114;
    sumCSS124 += CSS124;
    sumCSS122 += CSS122;
    sumCSS118 += CSS118;
    y++;
}

int max114 = score114[0];
int min114 = score114[0];
int max124 = score124[0];
int min124 = score124[0];
int max122 = score122[0];
int min122 = score122[0];
int max118 = score118[0];
int min118 = score118[0];

// computing the maximum and the minimum score......................................07 
for(i=0;i<y;i++){
		if(score114[i]>max114){
		max114 = score114[i];
		strcpy(best114,student[i]);
	}
	if(score114[i]<min114){
		min114 = score114[i];
		strcpy(worst114,student[i]);
	}
}
// testing the maximum and the minimum score using loop............................08
for(i=0;i<y;i++){
if(score122[i] > max122){
	max122 = score122[i];
}	
if(score118[i]>max118){
max118=score118[i];				
	}
if(score118[i]<min118){
min118=score118[i];				
	}
	
	if(score124[i]>max124){
max124=score124[i];				
	}
if(score124[i]<min124){
min124=score124[i];				
	}
}

for(i=0;i<y;i++){

	if(score122[i]<min122){
		min122 = score122[i];
	}

}
for(i=0;i<y;i++){
		if(max114==score114[i]){
		strcpy(best114,student[i]);
	}
	if(max122==score122[i]){
		strcpy(best122,student[i]);
	}
	if(min122==score122[i]){
	strcpy(worst122,student[i]);	
	}
	if(max118==score118[i]){
		strcpy(best118,student[i]);
	}
	if(min118==score118[i]){
	strcpy(worst118,student[i]);
	}
		if(max124==score124[i]){
		strcpy(best124,student[i]);
	}
	if(min124==score124[i]){
	strcpy(worst124,student[i]);
	}
		}
		
//average coursewise..................................................................09
avgCSS114 = sumCSS114 / y;
avgCSS124 = sumCSS124 / y;
avgCSS122 = sumCSS122/y;
avgCSS118 = sumCSS118 /y;

printf("\n\n");
printf("Details coursewise..\n");

//to dispalay the results...............................................................10
printf("\nCSS114.\nAverage score : %.2f\nBest student  : %s\nBest score    :%d\nWorst student : %s\nWorst marks   :%d\n",avgCSS114,best114,max114,worst114,min114);
printf("\nCSS124.\nAverage score : %.2f\nBest student  : %s\nBest score    :%d\nWorst student : %s\nWorst marks   :%d\n",avgCSS124,best124,max124,worst124,min124);
printf("\nCSS122.\nAverage score : %.2f\nBest student  : %s\nBest score    :%d\nWorst student : %s\nWorst marks   :%d\n",avgCSS122,best122,max122,worst122,min122);
printf("\nCSS118.\nAverage score : %.2f\nBest student  : %s\nBest score    :%d\nWorst student : %s\nWorst marks   :%d\n",avgCSS118,best118,max118,worst118,min118);

fclose(inFile);
return 0;
}

