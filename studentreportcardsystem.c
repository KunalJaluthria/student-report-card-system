#include <stdio.h>

#include <conio.h>

#include <windows.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

bool check(int);

struct record {
    char name[100];
    int c;
    char section;
    int rollno;
    int eng;
    int math;
    int cs;
    int physics;
    int chem;
    int percent;
    char grade;
}s1;

void create(char filename[]) {
    FILE * student;
    int per;
    student = fopen(filename, "a+");
	
    printf("\n\nENTER THE NAME OF THE STUDENT: ");
	scanf("%s", &s1.name);
	printf("\n\nENTER THE CLASS: ");
    scanf("%d", &s1.c);
    printf("\n\nENTER THE SECTION: ");
    scanf(" %c", &s1.section);
    printf("\n\nENTER THE ROLL NO. OF THE STUDENT: ");
    scanf("%d", & s1.rollno);
    
    do {
        printf("\n\nENTER THE MARKS IN ENGLISH OUT OF 100           : ");
        scanf("%d", & s1.eng);
        if (check(s1.eng) == false) {
            printf("ERROR\n");
        }
    } while (check(s1.eng) == false);
    do {
        printf("\nENTER THE MARKS IN MATHEMATICS OUT OF 100       : ");
        scanf("%d", & s1.math);
        if (check(s1.math) == false) {
            printf("ERROR\n");
        }
    } while (check(s1.math) == false);
    do {
        printf("\nENTER THE MARKS IN COMPUTER SCIENCE OUT OF 100  : ");
        scanf("%d", & s1.cs);
        if (check(s1.cs) == false) {
            printf("ERROR\n");
        }
    } while (check(s1.cs) == false);
    do {
        printf("\nENTER THE MARKS IN PHYSICS OUT OF 100           : ");
        scanf("%d", & s1.physics);
        if (check(s1.physics) == false) {
            printf("ERROR\n");
        }
    } while (check(s1.physics) == false);
    do {
        printf("\nENTER THE MARKS IN CHEMISTRY OUT OF 100         : ");
        scanf("%d", & s1.chem);
        if (check(s1.chem) == false) {
            printf("ERROR\n");
        }
    } while (check(s1.chem) == false);
    per = (s1.eng + s1.math + s1.cs + s1.physics + s1.chem) / 5;
    s1.percent = per;
    printf("\n\nTOTAL PERCENTAGE OF STUDENT                     : %d\n\n", per);
    

    if (per > 90) {
        printf("THE GRADE IS O\n");
        s1.grade = 'O';
    } else if (per > 80) {
        printf("THE GRADE IS A\n");
        s1.grade = 'A';
    } else if (per > 70) {
        printf("THE GRADE IS B\n");
        s1.grade = 'B';
    } else if (per > 60) {
        printf("THE GRADE IS C\n");
        s1.grade = 'C';
    } else if (per > 50) {
        printf("THE GRADE IS D\n");
        s1.grade = 'D';
    } else if (per > 40) {
        printf("THE GRADE IS E\n");
        s1.grade = 'E';
    } else {
        printf("RESULT: FAIL\n");
        s1.grade = 'F';
    }

    fwrite( & s1, sizeof(s1), 1, student);

    fclose(student);

}



bool check(int x) 
{
    if (x >= 0 && x <= 100)
        return true;
    else
        return false;
}

void modify(char filename[]) {
    FILE * fp1, * fp2;
    struct record s1, s2;
    char arr[100];
    int rollno;
	
    printf("\n\n  ENTER THE NAME YOU WANT TO UPDATE: ");
    scanf("%s", & arr);

    printf("\n\n  ENTER THE ROLL NO. OF THE STUDENT: ");
    scanf("%d", & rollno);

    fp1 = fopen(filename, "r+");
    fp2 = fopen("copy.txt", "a+");

    if (fp1 == NULL) {
        fprintf(stderr, "File cannot be opened");
        exit(1);
    }

	while (fread( & s1, sizeof(s1), 1, fp1) == 1) {
    if ((strcmp(s1.name, arr) == 0 & s1.rollno == rollno)) {
        printf("\n\nENTER THE NAME OF THE STUDENT: ");
        //gets(c);
        scanf("%s", & s2.name);
        printf("\n\nENTER THE CLASS: ");
    	scanf("%d", &s2.c);
    	printf("\n\nENTER THE SECTION: ");
    	scanf(" %c", &s2.section);
        printf("\n\nENTER THE ROLL NO. OF THE STUDENT: ");
        scanf("%d", & s2.rollno);
    	
        do {
            printf("\n\nENTER THE MARKS IN ENGLISH OUT OF 100           : ");
            scanf("%d", & s2.eng);
            
            if (check(s2.eng) == false) {
                printf("ERROR\n");
            }
        } while (check(s2.eng) == false);
        do {
            printf("\nENTER THE MARKS IN MATHEMATICS OUT OF 100       : ");
            scanf("%d", & s2.math);
            if (check(s2.math) == false) {
                printf("ERROR\n");
            }
        } while (check(s2.math) == false);
        do {
            printf("\nENTER THE MARKS IN COMPUTER SCIENCE OUT OF 100  : ");
            scanf("%d", & s2.cs);
            if (check(s2.cs) == false) {
                printf("ERROR\n");
            }
        } while (check(s2.cs) == false);
        do {
            printf("\nENTER THE MARKS IN PHYSICS OUT OF 100           : ");
            scanf("%d", & s2.physics);
            if (check(s2.physics) == false) {
                printf("ERROR\n");
            }
        } while (check(s2.physics) == false);
        do {
            printf("\nENTER THE MARKS IN CHEMISTRY OUT OF 100         : ");
            scanf("%d", & s2.chem);
            if (check(s2.chem) == false) {
                printf("ERROR\n");
            }
        } while (check(s2.chem) == false);
        int per = (s2.eng + s2.math + s2.cs + s2.physics + s2.chem) / 5;
        s2.percent = per;
        printf("\n\nTOTAL PERCENTAGE OF STUDENT                     : %d\n\n", per);
        
    if (per > 90) {
        printf("THE GRADE IS O\n");
        s2.grade = 'O';
    } else if (per > 80) {
        printf("THE GRADE IS A\n");
        s2.grade = 'A';
    } else if (per > 70) {
        printf("THE GRADE IS B\n");
        s2.grade = 'B';
    } else if (per > 60) {
        printf("THE GRADE IS C\n");
        s2.grade = 'C';
    } else if (per > 50) {
        printf("THE GRADE IS D\n");
        s2.grade = 'D';
    } else if (per > 40) {
        printf("THE GRADE IS E\n");
        s2.grade = 'E';
    } else {
        printf("RESULT: FAIL\n");
        s2.grade = 'F';
    }

        fwrite( & s2, sizeof(s2), 1, fp2);

        printf("\n\n  RECORD MODIFIED SUCCESSFULLY");
    }
    else
    	{
    		fwrite( & s1, sizeof(s1), 1, fp2);
		}
}
    fclose(fp1);
    fclose(fp2);
    
    remove(filename);
    rename("copy.txt", filename);

}

void search(char filename[]) 
{
    FILE * fp1;
    struct record s1, s2;
    char arr[100];
    int rollno;
    int Choice;
    
    printf("\n\n\n1. SEARCH RECORD OF A STUDENT\n");
    printf("\n2. SEARCH RECORD OF A CLASS");
    
    printf("\n\n\nENTER YOUR CHOICE: ");
    scanf("%d", & Choice);
	
	switch(Choice)
	{
		case 1: 
			system("cls");
			printf("\n\t\t\t\t\tSEARCH RECORD OF A STUDENT");
			printf("\n\n  ENTER THE NAME YOU WANT TO SEARCH: ");
		    scanf("%s", & arr);
		
		    printf("\n\n  ENTER THE ROLL NO. OF THE STUDENT: ");
		    scanf("%d", & rollno);
		
		    fp1 = fopen(filename, "rb");
		
		    if (fp1 == NULL) {
		        fprintf(stderr, "File cannot be opened");
		        exit(1);
		    }
		    
		    bool dataFound = false;
		
		    while (fread( & s1, sizeof(s1), 1, fp1)) {
		        if (strcmp(s1.name, arr) == 0 & s1.rollno == rollno)
		        {
		            printstudent(s1);
					dataFound = true;
		        }            
		    }
		    fclose(fp1);
		
			if(!dataFound) 
			{
				printf("\n\n  DATA NOT FOUND");
			}
			break;
			
		case 2:
			system("cls");
			int c;
			char section;
			printf("\n\t\t\t\t\tSEARCH RECORD OF A CLASS");
			printf("\n\n  ENTER THE CLASS: ");
		    scanf("%d", &c);
		    printf("\n  ENTER THE SECTION: ");
		    scanf(" %c", &section);
		    
		    fp1 = fopen(filename, "rb");
		
		    if (fp1 == NULL) {
		        fprintf(stderr, "File cannot be opened");
		        exit(1);
		    }
		    
		    bool dataF = false;
		
		    while (fread( & s1, sizeof(s1), 1, fp1)) {
		        if ( s1.c == c & s1.section == section)
		        {
		            printstudent(s1);
		            printf("\n\n--------------------------------------------------------------------\n--------------------------------------------------------------------");
					dataF = true;
		        }            
		    }
		    fclose(fp1);
		
			if(!dataF) 
			{
				printf("\n\n  DATA NOT FOUND");
			}
			break;

		default:
            printf("\n\t\tINVALID CHOICE");
	}
    
}

void printstudent (struct record s1)
{
	printf("\n\n\n  STUDENT NAME: %s", s1.name);
	printf("\n  CLASS AND SECTION: %d-%c", s1.c, s1.section);
    printf("\n  ROLL NO. OF THE STUDENT: %d", s1.rollno);
    printf("\n  MARKS IN ENGLISH: %d", s1.eng);
    printf("\n  MARKS IN MATHEMATICS: %d", s1.math);
    printf("\n  MARKS IN COMPUTER SCIENCE: %d", s1.cs);
    printf("\n  MARKS IN PHYSICS: %d", s1.physics);
    printf("\n  MARKS IN CHEMISTRY: %d", s1.chem);
    printf("\n  TOTAL PERCENTAGE OF THE STUDENT: %d", s1.percent);
    printf("\n  GRADE OF THE STUDENT: %c", s1.grade);
}

void delete(char filename[]) 
{
    FILE * fp1, * fp2;
    struct record s1;
    char arr[100];
    int rollno;

    printf("\n\n  ENTER THE NAME YOU WANT TO DELETE: ");
    scanf("%s", & arr);

    printf("\n\n  ENTER THE ROLL NO. OF THE STUDENT: ");
    scanf("%d", & rollno);

    fp1 = fopen(filename , "r");
    fp2 = fopen("copy.txt", "a+");

    if (fp1 == NULL) {
        fprintf(stderr, "File cannot be opened");
        exit(1);
    }
    
    bool dataFound = false;
    
    while (fread( & s1, sizeof(s1), 1, fp1)) {
        if (strcmp(s1.name, arr) != 0 | s1.rollno != rollno) {
            fwrite( & s1, sizeof(s1), 1, fp2);    
            dataFound = true;
        }
        
    }
    fclose(fp1);
    fclose(fp2);
    
    if(!dataFound) 
	{
		printf("\n\n  DATA NOT FOUND");
	}
	else
		printf("\n\n  RECORD DELETED SUCCESSFULLY");

    remove(filename);
    rename("copy.txt", filename);

	
}

int main() 
{
    int Choice;
    int a, b, c, d, e, f;
    char a1, m;
    char filename[] = "RecordNew.txt";
    do {
        system("cls");
        system("color 3");
        printf("\n\t\t\t\t\t\t   WELCOME\n");
        printf("\n\t\t\t\t\t\t     TO\n");
        printf("\n\t\t\t\t\t  STUDENT REPORT CARD SYSTEM\n\n");
        printf("  ENTRY MENU\n");
        printf("\n  1. DISPLAY ALL STUDENTS RESULT\n");
        printf("\n  2. SEARCH STUDENT RESULT\n");
        printf("\n  3. CREATE STUDENT RESULT\n");
        printf("\n  4. MODIFY STUDENT RESULT\n");
        printf("\n  5. DELETE STUDENT RESULT\n");
        printf("\n  6. EXIT\n");

        printf("\n  ENTER YOUR CHOICE: ");
        scanf("%d", & Choice);

        switch (Choice) {
        case 1:
            system("cls");
            FILE * student;
            printf("\n\t\t\t\t\tDISPLAY ALL STUDENT RESULT\n\n");
            student = fopen(filename, "rb");
            while (fread( & s1, sizeof(s1), 1, student) > 0) {
                printf("\n\n  STUDENT NAME: %s", s1.name);
                printf("\n  CLASS AND SECTION: %d-%c", s1.c ,s1.section);
                printf("\n  ROLL NO. OF THE STUDENT: %d", s1.rollno);
                printf("\n  MARKS IN ENGLISH: %d", s1.eng);
                printf("\n  MARKS IN MATHEMATICS: %d", s1.math);
                printf("\n  MARKS IN COMPUTER SCIENCE: %d", s1.cs);
                printf("\n  MARKS IN PHYSICS: %d", s1.physics);
                printf("\n  MARKS IN CHEMISTRY: %d", s1.chem);
                printf("\n  TOTAL PERCENTAGE OF THE STUDENT: %d", s1.percent);
                printf("\n  GRADE OF THE STUDENT: %c\n", s1.grade);
                printf("\n--------------------------------------------------------------------\n--------------------------------------------------------------------");
            }
            fclose(student);
            break;

        case 2:
            system("cls");
            printf("\n\t\t\t\t\tSEARCH STUDENT RESULT");
            search(filename);
            break;

        case 3:
            system("cls");
            printf("\n\t\t\t\t\tCREATE STUDENT RESULT");
            create(filename);
            break;

        case 4:
            system("cls");
            printf("\n\t\t\t\t\tMODIFY STUDENT RESULT");
            modify(filename);
            break;

        case 5:
            system("cls");
            printf("\n\t\t\t\t\tDELETE STUDENT RESULT");
            delete(filename);
            break;

        case 6:
            system("cls");
            printf("\n\n\t\t\t\t\t\tTHANK YOU\n");
            printf("\n\t\t\t\t\tWISH TO SEE YOU NEXT TIME");
            getch();
            exit(0);

        default:
            printf("\n\t\tINVALID CHOICE");
        }
        printf("\n\nDO YOU WISH TO RUN PROGRAM AGAIN(Y/N): ");
        scanf(" %c", & a1);
    } while (a1 == 'Y' | a1 == 'y');
    return 0;
}