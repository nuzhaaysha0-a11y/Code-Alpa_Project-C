
#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    struct student s;
    FILE *fp, *temp;
    int ch, roll, found;

    while(1)
    {
        printf("\n\n--- STUDENT RECORD MANAGEMENT ---");
        printf("\n1. Add Record");
        printf("\n2. Delete Record");
        printf("\n3. Update Record");
        printf("\n4. Search Record");
        printf("\n5. Display Records");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                fp = fopen("student.dat", "ab");

                printf("Enter Roll Number: ");
                scanf("%d", &s.roll);

                printf("Enter Name: ");
                scanf(" %29[^\n]", s.name);

                printf("Enter Marks: ");
                scanf("%f", &s.marks);

                fwrite(&s, sizeof(s), 1, fp);
                fclose(fp);

                printf("Record Added Successfully!");
                break;

            case 2:
                fp = fopen("student.dat", "rb");
                temp = fopen("temp.dat", "wb");

                printf("Enter Roll Number to Delete: ");
                scanf("%d", &roll);

                found = 0;

                while(fread(&s, sizeof(s), 1, fp))
                {
                    if(s.roll == roll)
                        found = 1;
                    else
                        fwrite(&s, sizeof(s), 1, temp);
                }

                fclose(fp);
                fclose(temp);

                remove("student.dat");
                rename("temp.dat", "student.dat");

                if(found)
                    printf("Record Deleted Successfully!");
                else
                    printf("Record Not Found!");
                break;

            case 3:
                fp = fopen("student.dat", "rb+");

                printf("Enter Roll Number to Update: ");
                scanf("%d", &roll);

                found = 0;

                while(fread(&s, sizeof(s), 1, fp))
                {
                    if(s.roll == roll)
                    {
                        printf("Enter New Name: ");
                        scanf(" %29[^\n]", s.name);

                        printf("Enter New Marks: ");
                        scanf("%f", &s.marks);

                        fseek(fp, -sizeof(s), SEEK_CUR);
                        fwrite(&s, sizeof(s), 1, fp);

                        found = 1;
                        break;
                    }
                }

                fclose(fp);

                if(found)
                    printf("Record Updated Successfully!");
                else
                    printf("Record Not Found!");
                break;

            case 4:
                fp = fopen("student.dat", "rb");

                printf("Enter Roll Number to Search: ");
                scanf("%d", &roll);

                found = 0;

                while(fread(&s, sizeof(s), 1, fp))
                {
                    if(s.roll == roll)
                    {
                        printf("\nRoll Number: %d", s.roll);
                        printf("\nName: %s", s.name);
                        printf("\nMarks: %.2f", s.marks);
                        found = 1;
                        break;
                    }
                }

                fclose(fp);

                if(!found)
                    printf("Record Not Found!");
                break;

            case 5:
                fp = fopen("student.dat", "rb");

                printf("\n--- STUDENT RECORDS ---\n");

                while(fread(&s, sizeof(s), 1, fp))
                {
                    printf("\nRoll Number: %d", s.roll);
                    printf("\nName: %s", s.name);
                    printf("\nMarks: %.2f\n", s.marks);
                }

                fclose(fp);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!");
        }
    }

    return 0;
}
