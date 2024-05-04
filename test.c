//Alexus Rowe and Ervin Martinez//



#include<stdio.h>

#define CURRENT_IMAGE "image.txt"
#define MAX_ROWS 500
#define MAX_COLS 500

int defaultMenu();
void displayCurrentImage(int image[][MAX_COLS], FILE* initialImage, int realRows, int realCols);
void editImage(int image[][MAX_COLS], int rows, int columns);

int main(){

	int image[MAX_ROWS][MAX_COLS], choice, rows, cols;
	
	FILE* currentImage_fp;
	
	
	do{
		choice = defaultMenu();
		
		switch(choice){
		
			case 1:
			
			break;
			
			case 2:
				displayCurrentImage(image, currentImage_fp, rows, cols);
			break;
			
			case 3:
			
			break;
			
			case 0:
				printf("Goodbye!\n");
			break;
			
			default:
				printf("\n");
				printf("Invalid option. Try again!\n \n");
			break;
		}
		
	}while(choice != 0);


	return 0;
}

int defaultMenu(){
	
	int menuChoice;
	
	printf("********Photo Menu********\n|");
	printf("1. Load New Image       |\n|");
	printf("2. Display Current Image|\n|");
	printf("3. Edit Current Image   |\n|");
	printf("0. Exit                 |\n");
	printf("**************************\n");
	printf("\n");
	printf("What would you like?: ");
	scanf("%d", &menuChoice);
	
	return menuChoice;
}

void displayCurrentImage(int image[][MAX_COLS], FILE* initialImage, int realRows, int realCols){
	
	
	//work in progress 
	char temp;
	
	initialImage = fopen(CURRENT_IMAGE, "r");
	
	if(initialImage == NULL){
		printf("Unable to open file.\n");
	}
	else{
		for(realRows = 0; realRows <= MAX_ROWS; realRows++){
			for(realCols = 0; realCols <= MAX_COLS; realCols++){
				while(fscanf(initialImage, "%c", &temp) == 1){
					fscanf(initialImage, "%d", &image[realRows][realCols]);
					fclose(initialImage);
					printf("%d", image[realRows][realCols]);
				
				}
			
			}
		}
		
	}

}

void editImage(int image[][MAX_COLS], int rows, int columns) {
    int choice;
    char saveorno;
    char y,n;

    printf("**EDITING**\n");
    printf("1: Crop image\n");
    printf("2: Dim image\n");
    printf("3: Brighten image\n");
    printf("0: Return to main menu\n");
    printf("Choose from one of the options above: ");
    scanf("%d", &choice);
    
    do {
    		switch(choice) {
        	case 1:
           	//call to display image loop through to add numbers in the upper corner 
          	//call to cropfunction here 
          	//display image again 
         	printf("Would you like to save the file? (y/n) ");scanf(" %c",&saveorno);
          	if(saveorno==y){
          	 // saveImage(FILEPOINTER, rows, columns);
          	 }
            	break;
        	case 2:
		//Call to dim function here 
		//Display Image
         	printf("Would you like to save the file? (y/n) ");scanf(" %c",&saveorno);
          	if(saveorno==y){
          	 // saveImage(filepointer, rows, columns);
          	 }
            break;
        	case 3:
            	// Call to brighten function here
            	// saveImage(currentImage, rows, columns);
            	//Display Image
         	printf("Would you like to save the file? (y/n) ");scanf(" %c",&saveorno);
          	if(saveorno==y){
          	 // saveImage(filepointer, rows, columns);
          	 }
        	default:
            printf("Invalid choice. Please enter a valid option.\n");
    } 
    }while (choice != 0);
    
 }	
