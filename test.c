//Alexus Rowe and Ervin Martinez//



#include<stdio.h>
#include<stdbool.h>

#define CURRENT_IMAGE "image.txt"
#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_FILE_NAME 50

int defaultMenu();
void displayCurrentImage(int realRows, int realCols,int image[][realCols], FILE* initialImage);
void newImage(int row, int cols, int image[][cols], FILE* newPhoto);
int sizeOfArray(FILE* currentFile, int row, int* cols, int enteredImage[][MAX_COLS]);
void editImage(FILE* editImages, int image[][MAX_COLS], int rows, int columns);
void dimImage(FILE* dimImage, int image[][MAX_COLS], int row, int *cols);
void brightenImage(FILE* brightenImage, int image[][MAX_COLS], int row, int cols);
void saveImage(FILE* saveEditedImage, int row, int cols, int image[][cols]);
	

int main(){

	int image[MAX_ROWS][MAX_COLS], choice, rows, cols;
	
	
	FILE* currentImage_fp;
	
	
	do{
		choice = defaultMenu();
		
		switch(choice){
		
			case 1:
				rows = sizeOfArray(currentImage_fp, rows, &cols, image);
				newImage(rows, cols, image, currentImage_fp);
			break;
			
			case 2:
				rows = sizeOfArray(currentImage_fp, rows, &cols, image);
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
	
	char temp[MAX_COLS];
	int Cols = 0, rows = 0;;
	int index;
	
	currentFile = fopen(CURRENT_IMAGE, "r");
	if(currentFile == NULL){
		printf("Unable to open file. Non-existent.\n");
	}
	else{
		while(fgets(temp, sizeof(temp), currentFile)){
			rows++;
			index = 0;
			Cols = 0;
			
			while(temp[index] != '\0'){
				if(temp[index] != ' ' || temp[index] != '\n'){
					Cols++;
				}
				index++;
			}
		}
		fclose(currentFile);
		*cols = Cols;
		return rows;
	}
}
	




void displayCurrentImage(int realRows, int realCols,int image[][realCols], FILE* initialImage){
	
	char temp;
	int type;

	
	initialImage = fopen(CURRENT_IMAGE, "r");
	
	if(initialImage == NULL){
		printf("Unable to open file. Non-existent.\n");
	}
	else{
	 	for(int i= 0; i < realRows; i++){
			for(int j = 0; j < realCols; j++){
				
				do{
					fscanf(initialImage, "%c", &temp);
				
				}while(temp == '\n' && temp == ' ');
				
				image[i][j] = temp - '0';
				
			}
		}
		
		fclose(initialImage);
		for(int i = 0; i < realRows; i++){
				for(int j = 0; j < realCols; j++){
				
					type = image[i][j];
					
					if (type == 0){
						printf(" ");
					}else if(type == 1){
						printf(".");
					}else if(type == 2){
						printf("o");
					}else if(type == 3){
						printf("O");
					}else if(type == 4){
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
          		//saveImage(editImages);
          	 // saveImage(FILEPOINTER, rows, columns);
          	 	//saveImage(
          		// }
          	 
            		break;
        	case 2:
		//Call to dim function here 
		//Display Image
         		dimImage(editImages,image,rows,&cols);
         		displayCurrentImage(rows, cols, image, editImages);
         		saveImage(editImages, rows, cols, image);
          		 
          	 
            		break;
        	case 3:
            	// Call to brighten function here
            	// saveImage(currentImage, rows, columns);
            	//Display Image
            		
            		rows = sizeOfArray(editImages, rows, &cols, image);
            		brightenImage(editImages,image,rows, cols);
            		//displayCurrentImage(rows, cols, image, editImages);
         		saveImage(editImages, rows, cols, image);
	
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


void brightenImage(FILE* brightenImage, int image[][MAX_COLS], int row, int cols) {
	brightenImage = fopen(CURRENT_IMAGE, "r");
	
	if(brightenImage == NULL){
		printf("Unable to open file. Non-existent.\n");
	}		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < cols; j++){
				image[i][j]++;
			}
			printf("\n");
		}
		fclose(brightenImage);
		
		
	}


void saveImage(FILE* saveEditedImage, int row, int cols, int image[][cols]){
	
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
		
			for(int i = 0; i < row; i++){
				for(int j = 0; j < cols; j++){
					fprintf(saveEditedImage, "%d", image[i][j]);
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








	
