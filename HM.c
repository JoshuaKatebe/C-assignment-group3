#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Drug{
    char name[20];
    char type[20];
    int quantity;
    char expiry[20];
};

struct Hospital{
    char name[50];
    int ID;
    char location[20];
    int distance;
    struct Drug drug[50];
};

void addDrug(struct Drug drug[], int j);
//void addDrug(struct Drug drug[], int *numDrugs);

void addHospital(struct Hospital hospitals[], int j){
    
    printf("Enter Hospital name: ");
    scanf("%s", &hospitals[j].name);
    while(getchar() != '\n');  
    printf("Enter ID: ");
    scanf(" %d", &hospitals[j].ID);
    while(getchar() != '\n');  
    printf("Enter location: ");
    scanf("%s", &hospitals[j].location);
    while(getchar() != '\n');  
    printf("Enter distance: ");
    scanf(" %d", &hospitals[j].distance);
    while(getchar() != '\n');
    /*
    printf("Enter the number of drug: ");
    int numDrugs;
    scanf(" %d", &numDrugs);
    for(int j = 0; j < numDrugs; j++){
        addDrug(hospitals[j].drug, j);
    }*/
}

void editHospital(struct Hospital hospitals[], int j){
    
    printf("Enter Hospital name: ");
    scanf("%s", &hospitals[j].name);
    while(getchar() != '\n');  
    printf("Enter ID: ");
    scanf(" %d", &hospitals[j].ID);
    while(getchar() != '\n');  
    printf("Enter location: ");
    scanf("%s", &hospitals[j].location);
    while(getchar() != '\n');  
    printf("Enter distance: ");
    scanf(" %d", &hospitals[j].distance);
    while(getchar() != '\n');
    
}

/*void addDrug(struct Drug drug[], int j){
    int drugQ;
    printf("Enter Drug name: ");
    scanf("%s", &drug[j].name);
    while(getchar() != '\n'); 
    printf("Enter Drug Type: ");
    scanf("%s", &drug[j].type);
    while(getchar() != '\n'); 
    printf("Enter Drug quantity: ");
    scanf(" %d", &drugQ);
    drug[j].quantity = drug[j].quantity + drugQ;
    while(getchar() != '\n'); 
    printf("Enter expiry date: ");
    scanf("%s", &drug[j].expiry);
    while(getchar() != '\n'); 
}*/

void addDrug(struct Drug drug[], int i) {
    char drugName[20];
    char drugType[20];
    char drugExpiry[20];
    int drugQuantity;

    printf("Enter Drug name: ");
    scanf("%s", drugName);
    while (getchar() != '\n');
    printf("Enter Drug Type: ");
    scanf("%s", drugType);
    while (getchar() != '\n');
    printf("Enter expiry date: ");
    scanf("%s", drugExpiry);
    while (getchar() != '\n');
    printf("Enter Drug quantity: ");
    scanf(" %d", &drugQuantity);

    int j;
    for (j = 0; j < i; j++) {
        if (strcmp(drug[j].name, drugName) == 0 &&
            strcmp(drug[j].type, drugType) == 0 &&
            strcmp(drug[j].expiry, drugExpiry) == 0) {
            
            drug[j].quantity += drugQuantity;
            break;
        }
    }

    if (j == i) {
        
        strcpy(drug[i].name, drugName);
        strcpy(drug[i].type, drugType);
        drug[i].quantity = drugQuantity;
        strcpy(drug[i].expiry, drugExpiry);
        (i)++; 
    }
}


void deliverDrug(struct Hospital hospitals[], int j){

    printf("Enter the number of drugs to be delivered: ");
    int numDrugs;
    scanf(" %d", &numDrugs);
    for(int j = 0; j < numDrugs; j++){
        addDrug(hospitals[j].drug, j);
    }
    printf("Delivering drugs to %s located in %s\n", hospitals[j].name, hospitals[j].location);
    printf("Estimated time of arrival in %d seconds please wait\n", hospitals[j].distance);
    sleep(hospitals[j].distance);
    printf("Delivery complete\n");

}

void showDrugData(struct Drug drug[], int j){
    printf("Drug is called %s\n", drug[j].name);
    printf("Drug type is %s\n", drug[j].type);
    printf("Quantity is %d\n", drug[j].quantity);
    printf("Expiry year is %s\n", drug[j].expiry);
}

void showData(struct Hospital hospitals[], int j){
    printf("Hospital is called %s\n", hospitals[j].name);
    printf("Hospital ID is %d\n", hospitals[j].ID);
    printf("Hospital location is %s\n", hospitals[j].location);
    printf("Hospital is %dKM away\n", hospitals[j].distance);
    
}

void showAllData(struct Hospital hospitals[], int j, int k){
    
    for(int j = 0; j < k; j++){
        printf("Hospital is called %s\n", hospitals[j].name);
        printf("Hospital ID is %d\n", hospitals[j].ID);
        printf("Hospital location is %s\n", hospitals[j].location);
        printf("Hospital is %dKM away\n", hospitals[j].distance);
        printf("\n");
        j++;
    }
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
    struct Drug drug[50];
    struct Hospital hospitals[100];
    int hIndex = readFromFile(hospitals);
    int dIndex = readFromFile(hospitals);

    
    char choice;
    char Mh;
    do{
        printf("Main Menu\n");
        printf("1. Manage Hospitals\n");
        printf("2. Manage orders\n");
        printf("3. Make delivery\n");
        printf("4. View statistics\n");
        printf("5. Quit\n");
        printf("Enter: ");
        scanf(" %c", &choice);

        switch(choice){
            case '1':
                
                do{
                    printf("1. Add new Hospital\n");
                    printf("2. Edit Hospital\n");
                    printf("3. Show Hospital data\n");
                    printf("4. Show all Hospitals\n");
                    printf("5. View Hospital inventory\n");
                    printf("6. Hospital statistics\n");
                    printf("7. Back\n");
                    printf("Enter: ");
                    scanf(" %c", &Mh);
                    switch(Mh){
                        case '1':
                            addHospital(hospitals, hIndex);
                            hIndex++;
                            break;
                        
                        case '2':
                            printf("Enter hospital ID: ");
                            int id;
                            scanf("%d", &id);
                            id = id - 101;
                            editHospital(hospitals, id);
                            break;

                        case '3':
                    
                            printf("Enter Hospital ID: ");
                            int inde;
                            scanf("%d", &inde);
                            inde -= 101;
                            showData(hospitals, inde);
                            break;

                        case '4':
                            printf("How many Hospital would you like to view: ");
                            printf("\n");
                            int numh;
                            scanf("%d", &numh);
                            showAllData(hospitals, 0, numh);
                            break;

                        case '5':
                            printf("Enter Hospital ID for displaying drug: ");
                            scanf("%d", &inde);
                            inde = inde - 101;
                            showDrugData(hospitals[inde].drug, inde); 
                            break;
        
                    }
                }while(Mh != '7');
                break;
                    
            case '2':
                printf("Enter Hospital Index: ");
                int inde;
                scanf("%d", &inde);
                inde--;
                showData(hospitals, inde);
                break;
            case '3':
                /*printf("Enter Hospital Index for adding drug: ");
                scanf("%d", &inde);
                inde--;
                addDrug(hospitals[inde].drug, inde); 
                break;*/
                printf("Enter Hospital ID for delivery: ");
                int hId;
                scanf("%d", &hId);
                hId = hId - 101;
                deliverDrug(hospitals, hId);
                break;
            case '4':
                printf("Enter Hospital Index for displaying drug: ");
                scanf("%d", &inde);
                inde--;
                showDrugData(hospitals[inde].drug, inde); 
                break;
        }
    }
    while(choice != '5');
    writeToFile(hospitals, hIndex);
    return 0;
}

