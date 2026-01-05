#include<stdio.h>
#include <stdbool.h>
#include<string.h>

typedef struct 
{
    char name[50];
    char surname[50];
    int studentId;
    int isDeleted ;
} Student;

void saveStudent(Student s, char fileName[50]) {
    FILE *fptr;
    fptr = fopen(fileName,"a");
    fprintf(fptr, "%d,%s,%s,%d\n",s.isDeleted, s.name, s.surname, s.studentId);
    fclose(fptr);
    printf("Student saved succesfully");
}

void listStudents(const char fileName[50]) {
    FILE *fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("No student records found.\n");
        return;
    }
    char line[150];
    printf("\n--- Active Students ---\n");
    while (fgets(line, sizeof(line), fptr)) {
        // Only print lines where first character = '0' (not deleted)
        if (line[0] == '0')
            printf("%s", line);
    }
    fclose(fptr);
}
void deleteStudentById(const char fileName[50], int targetId){
    FILE *src = fopen(fileName,"r");
    if (src == NULL) {
        printf("No student records found.\n");
        return;
    }
    FILE *temp = fopen("temp.txt", "w");

    char line[150];
    int count = 1;
    while (fgets(line, sizeof(line), src)) {
        if(count != targetId){
          fprintf(temp,"%s",line);  
        }else{
            line[0] = '1';
            fprintf(temp,"%s",line);  
        }   
        count++;
    }
    fclose(src);
    fclose(temp);;

    remove(fileName);
    rename("temp.txt", fileName);
}

int main(){
    int idCount = 1;
    const char fileName[50] = "StudentRecordSystem.txt"; 
    Student students[50];
    int choose = 1;
    char name[50];
    char surname[50];
    int number;
    int lastIndex = 0;

    while(choose != 0){
        printf("Welcome to Student Registration System\n");
        printf("Type the number corresponds to operation\n");
        printf("1-Create a student\n");
        printf("2-Delete a student\n");
        printf("3-List The students \n");
        printf("0-Exit\n");
        scanf("%d",&choose);
        if(choose == 1){
            Student s1;
            printf("Name: ");
            scanf("%49s", name);
            strcpy(s1.name,name);
            printf("Surname: ");
            scanf("%49s", surname);
            strcpy(s1.surname,surname);
            s1.studentId = idCount;
            students[s1.studentId] = s1;
            idCount++;
            s1.isDeleted = 0;
            saveStudent(s1,fileName);
        }else if( choose == 2){
            listStudents(fileName);
            int id = -1;
            printf("Enter the studentID");
            scanf("%d",&id );
            deleteStudentById(fileName,id);
            
        }else if(choose == 3){
            listStudents(fileName);
        }
    }
        return 0;
}

