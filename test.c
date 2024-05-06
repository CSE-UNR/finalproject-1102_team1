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
//int rowSize(FILE* Image, int Rows, int Cols, int size[][Cols]);
int sizeOfArray(FILE* currentFile, int row, int* cols, int enteredImage[][MAX_COLS]);
void editImage(FILE* editImages, int image[][MAX_COLS], int rows, int columns);
void dimImage(FILE* dimImage, int image[][MAX_COLS], int row, int *cols);
void brightenImage(FILE* brightenImage, int image[][MAX_COLS], int row, int *cols);

void saveImage(FILE* saveEditedImage);

int main(){

	int image[MAX_ROWS][MAX_COLS], choice, rows, cols;
	int row=0;
	
	
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
				editImage(currentImage_fp, image, rows, cols);
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

void editImage(FILE* editImages, int image[][MAX_COLS], int rows, int cols) {
    int choice;
    char saveorno;
    char y,n;
    
    do {
   	 printf("\n");
   	 printf("**EDITING**\n");
   	 printf("1: Crop image\n");
   	 printf("2: Dim image\n");
   	 printf("3: Brighten image\n");
    	 printf("0: Return to main menu\n");
    	 printf("\n");
    	 printf("Choose from one of the options above: ");
    	 scanf("%d", &choice);
    
    
    		switch(choice) {
        		case 1:
           	//call to display image loop through to add numbers in the upper corner 
          	//call to cropfunction here 
          	//display image again
          		saveImage(editImages);
          	 // saveImage(FILEPOINTER, rows, columns);
          	 	//saveImage(
          		// }
          	 
            		break;
        	case 2:
		//Call to dim function here 
		//Display Image
         		dimImage(editImages,image,rows,&cols);
         		saveImage(editImages);
          		 
          	 
            		break;
        	case 3:
            	// Call to brighten function here
            	// saveImage(currentImage, rows, columns);
            	//Display Image
            		brightenImage(editImages,image,rows, &cols);
         		saveImage(editImages);
          	 
          	 case 0:
          	 	
          	 	break;
        	default:
           		printf("Invalid choice. Please enter a valid option.\n");
           		printf("Choose from one of the options above: ");
             		scanf("%d", &choice);
   	} 
    }while (choice != 0);
    
}


void dimImage(FILE* dimImage, int image[][MAX_COLS], int row, int *cols) {
	dimImage = fopen(CURRENT_IMAGE, "r");
	
	if(dimImage == NULL){
		printf("Unable to open file. Non-existent.\n");
	}		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < *cols; j++){
				image[i][j]--;
			}
		}
		fclose(dimImage);
		
	}


void brightenImage(FILE* brightenImage, int image[][MAX_COLS], int row, int *cols) {
	brightenImage = fopen(CURRENT_IMAGE, "r");
	
	if(brightenImage == NULL){
		printf("Unable to open file. Non-existent.\n");
	}		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < *cols; j++){
				image[i][j]++;
			}
		}
		fclose(brightenImage);
		
	}


void saveImage(FILE* saveEditedImage){
	
	char editImage[MAX_FILE_NAME+1], saveorno;
	printf("\n");
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c",&saveorno);
	
	if(saveorno != 'Y' && saveorno != 'y'){
		printf("\n");
		printf("Save not initiated\n");
	}
	else{
		printf("Where would you like to save this masterpiece?: ");
		scanf("%s", editImage);
	
		saveEditedImage = fopen(editImage, "w");
		
		if(saveEditedImage == NULL){
			printf("Unable to open file. Non-existent.\n");
		}
		else{
		//call for size of array to get size of row & cols
		// hardcoded for now
			int rows = 12;
			int col = 21;
			int editedImage[rows][col];
			
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < col; j++){
					fprintf(saveEditedImage, "%d", editedImage[i][j]);
				}
				fprintf(saveEditedImage,"\n");
			}
			fclose(saveEditedImage);
			printf("\n");
			printf("Successfully saved new image!\n");
			printf("\n");
		
		}
	}
}








	
