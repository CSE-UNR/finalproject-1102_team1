//Alexus Rowe and Ervin Martinez//



#include<stdio.h>
#include<stdbool.h>

#define CURRENT_IMAGE "test_image.txt"
#define MAX_ROWS 500
#define MAX_COLS 500
#define MAX_FILE_NAME 50

int defaultMenu();
void displayCurrentImage(int realRows, int realCols,int image[][realCols], FILE* initialImage);
void newImage(int row, int cols, int image[][cols], FILE* newPhoto);
void editImage(int image[][MAX_COLS], int rows, int columns);
int rowSize(FILE* Image, int Rows, int Cols, int size[][Cols]);

int sizeOfArray(FILE* currentFile, int row, int* cols, int enteredImage[][MAX_COLS]);

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
				displayCurrentImage(rows, cols, image, currentImage_fp);
			break;
			
			case 3:
				rows = sizeOfArray(currentImage_fp, rows, &cols, image);
				printf("%d rows.\n", rows);
				printf("%d cols.\n", cols);
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
		//call for size of array to get size of row & cols
		// hardcoded for now
		
		row = 12;
		cols = 21;
		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < cols; j++){
				fscanf(newPhoto, "%d", &image[i][j]);
			}
		}
		fclose(newPhoto);
		printf("\n");
		printf("Successfully loaded new image!\n");
		printf("\n");

	}
	
}

int sizeOfArray(FILE* currentFile, int row, int* cols, int enteredImage[][MAX_COLS]){
	char temp[MAX_ROWS][MAX_COLS];
	row = 0; 
	int colsCount = 0;
	currentFile = fopen(CURRENT_IMAGE, "r");
	if(currentFile == NULL){
		printf("Unable to open file. Non-existent.\n");
	}
	else{
	

	
	
		while(fscanf(currentFile, "%d", &enteredImage[row][MAX_ROWS]) == 1){
			row++;
		}
		while(fscanf(currentFile, "%c", &temp[row][MAX_ROWS]) == 0){
			colsCount++;
	
		
		}
		fclose(currentFile);
		*cols = colsCount;
	
	return row;
	}
}
	




void displayCurrentImage(int realRows, int realCols,int image[][realCols], FILE* initialImage){
	
	
	//work in progress 
	char temp;
	int type;

	
	initialImage = fopen(CURRENT_IMAGE, "r");
	
	if(initialImage == NULL){
		printf("Unable to open file. Non-existent.\n");
	}
	else{
	 	realRows = 12;
		realCols = 21;
	
		//while(fscanf(initialImage, "%c", &temp) == 1){
	
			for(int i = 0; i < realRows; i++){
				for(int j = 0; j < realCols; j++){
					fscanf(initialImage, "%d", &image[i][j]);
				}
			}	
	
		//}
		fclose(initialImage);
		for(int i = 0; i < realRows; i++){
				for(int j = 0; j < realCols; j++){
					//type = image[i][j];
					if (image[i][j] = 0){
						printf(" ");
					}else if(image[i][j] = 1){
						printf(".");
					}else if(image[i][j] = 2){
						printf("o");
					}else if(image[i][j] = 3){
						printf("O");
					}else if(image[i][j] = 4){
						printf("0");
					}
				}
			printf("\n");
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
