#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Drug{
    char name[20];
    char type[20];
    int quantity;
    int expiry;
};

struct Hospital{
    char name[20];
    int ID;
    char location[20];
    int distance;
    struct Drug pharmacy[50];
};

void addHospital(struct Hospital hospitals[], int i){
    
    printf("Enter Hospital name: ");
    scanf("%s", &hospitals[i].name);
    while(getchar() != '\n');  
    printf("Enter ID: ");
    scanf(" %d", &hospitals[i].ID);
    while(getchar() != '\n');  
    printf("Enter location: ");
    scanf("%s", &hospitals[i].location);
    while(getchar() != '\n');  
    printf("Enter distance: ");
    scanf(" %d", &hospitals[i].distance);
    while(getchar() != '\n');  

}

void showData(struct Hospital hospitals[], int i){
    printf("Hospital is called %s\n", hospitals[i].name);
    printf("Hospital ID is %d\n", hospitals[i].ID);
    printf("Hospital location is %s\n", hospitals[i].location);
    printf("Hospital is %dKM away\n", hospitals[i].distance);
}

void writeToFile(struct Hospital hospitals[], int count) {
    FILE *file = fopen("hospitals.dat", "w");
    if (file != NULL) {
        fwrite(hospitals, sizeof(struct Hospital), count, file);
        fclose(file);
    }
}

int readFromFile(struct Hospital hospitals[]) {
    FILE *file = fopen("hospitals.dat", "r");
    int count = 0;
    if (file != NULL) {
        while(fread(&hospitals[count], sizeof(struct Hospital), 1, file)) {
            count++;
        }
        fclose(file);
    }
    return count;
}

int main()
{
    struct Hospital hospitals[100];
    int hIndex = readFromFile(hospitals);
    
    char choice;
    do{
        printf("Main Menu\n");
        printf("1. Add new hospital\n");
        printf("2. Dispaly Hospital data\n");
        printf("3. Quit\n");
        printf("Enter: ");
        scanf(" %c", &choice);

        switch(choice){
            case '1':
                addHospital(hospitals, hIndex);
                hIndex++;
                break;
            case '2':
                printf("Enter Hospital Index: ");
                int inde;
                scanf("%d", &inde);
                inde--;
                showData(hospitals, inde);
                break;

        }
    }
    while(choice != '3');

    writeToFile(hospitals, hIndex);
    
    
    return 0;
}

