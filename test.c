//Alexus Rowe and Ervin Martinez//



#include<stdio.h>

#define CURRENT_IMAGE "test_image.txt"
#define MAX_ROWS 500
#define MAX_COLS 500
#define MAX_FILE_NAME 50

int defaultMenu();
void displayCurrentImage(int image[][MAX_COLS], FILE* initialImage, int realRows, int realCols);
void newImage(int row, int cols, int image[][cols], FILE* newPhoto);
void editImage(int image[][MAX_COLS], int rows, int columns);


int main(){

	int image[MAX_ROWS][MAX_COLS], choice, rows, cols;
	
	FILE* currentImage_fp;
	
	
	do{
		choice = defaultMenu();
		
		switch(choice){
		
			case 1:
				newImage(rows, cols, image, currentImage_fp);
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

void newImage(int row, int cols, int image[][cols], FILE* newPhoto){
	
	char file[MAX_FILE_NAME+1];
	printf("Enter a file you would like to load: ");
	scanf("%s", file);
	
	newPhoto = fopen(file, "r");
	
	if(newPhoto == NULL){
		printf("Unable to open file. Non-existent.\n");
	}
	else{



	}


}
	

void displayCurrentImage(int image[][MAX_COLS], FILE* initialImage, int realRows, int realCols){
	
	
	//work in progress 
	char temp;
	int i;
	
	initialImage = fopen(CURRENT_IMAGE, "r");
	
	if(initialImage == NULL){
		printf("Unable to open file. Non-existent.\n");
	}
	else{
		
		
		for(int i = 0; i <= realRows; realRows++){
			for(int j = 0; j <= realCols; j++){
					fscanf(initialImage, "%d", &image[realRows][realCols]);
					fclose(initialImage);
					if (image[realRows][realCols] = 0){
						printf(" ");
					}else if(image[realRows][realCols] = 1){
						printf(".");
					}else if(image[realRows][realCols] = 2){
						printf("o");
					}else if(image[realRows][realCols] = 3){
						printf("O");
					}else if(image[realRows][realCols] = 4){
						printf("0");
					}
				//}
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
