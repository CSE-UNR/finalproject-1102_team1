//Alexus Rowe and Ervin Martinez//



#include<stdio.h>
#include<stdbool.h>

#define CURRENT_IMAGE "test_image.txt"
#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_FILE_NAME 50

int defaultMenu();
void displayCurrentImage(int rows, int *cols, int image[][MAX_COLS], FILE* initialImage);
void newImage(int row, int cols, int image[][cols], FILE* newPhoto);
int sizeOfArray(FILE* currentFile, int row, int* cols, int enteredImage[][MAX_COLS]);
void editImage(FILE* editImages, int image[][MAX_COLS], int rows, int columns);
void cropImage(FILE* cropImagefp,int image[][MAX_COLS], int rows, int *cols);
void dimImage(FILE* dimImagefp, int image[][MAX_COLS], int rows, int *cols);
void brightenImage(FILE* brightenImagefp, int image[][MAX_COLS], int rows, int *cols);
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
				displayCurrentImage(rows, &cols, image, currentImage_fp);
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

void newImage(int row, int cols, int image[][MAX_COLS], FILE* newPhoto){
	
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
				if(temp[index] != ' ' && temp[index] != '\n'){
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
	




void displayCurrentImage(int rows, int *cols, int image[][MAX_COLS], FILE* initialImage){
	
	char temp;
	int type;

	
	initialImage = fopen(CURRENT_IMAGE, "r");
	
	if(initialImage == NULL){
		printf("Unable to open file. Non-existent.\n");
	}
	else{
	 	for(int i= 0; i < rows; i++){
			for(int j = 0; j < *cols; j++){
				
				do{
					fscanf(initialImage, "%c", &temp);
				
				}while(temp == '\n' && temp == ' ');
				
				image[i][j] = temp - '0';
				
			}
		}
		
		fclose(initialImage);
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < *cols; j++){
				
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
           	
          		rows = sizeOfArray(editImages, rows, &cols, image);
         		cropImage(editImages,image,rows,&cols);
         		saveImage(editImages, rows, cols, image);
          		
          	 
            		break;
        	case 2:
		//Call to dim function here 
		//Display Image
			rows = sizeOfArray(editImages, rows, &cols, image);
         		dimImage(editImages,image,rows,&cols);
         		saveImage(editImages, rows, cols, image);
          		 
          	 
            		break;
        	case 3:
            	// Call to brighten function here
            	// saveImage(currentImage, rows, columns);
            	//Display Image
            		
            		rows = sizeOfArray(editImages, rows, &cols, image);
            		brightenImage(editImages,image,rows, &cols);
         		saveImage(editImages, rows, cols, image);
	
          	 case 0:
          	 	
          	 	break;
        	default:
           		printf("Invalid choice. Please enter a valid option.\n");
           		printf("Choose from one of the options above: ");
             		scanf("%d", &choice);
   	} 
   
    
}



void cropImage(FILE *cropImagefp, int image[][MAX_COLS], int rows, int *cols) {
    int startRow, endRow, startCol, endCol;

    cropImagefp = fopen(CURRENT_IMAGE, "r");
    if (cropImagefp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("The image you want to crop is %d x %d.\n", rows, *cols);
    printf("The row and column values start in the upper lefthand corner.\n\n");

    printf("Which column do you want to be the new left side? ");
    scanf("%d", &startCol);

    printf("Which column do you want to be the new right side? ");
    scanf("%d", &endCol);

    printf("Which row do you want to be the new top? ");
    scanf("%d", &startRow);

    printf("Which row do you want to be the new bottom? ");
    scanf("%d", &endRow);

    // Adjust the number of columns based on the cropping operation
    *cols = endCol - startCol + 1;

    // Create a new array to store the cropped image
    int croppedImage[MAX_ROWS][MAX_COLS];
    // Copy the cropped portion of the image to the new array
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            croppedImage[i - startRow][j - startCol] = image[i][j];
        }
    }

    // Copy the cropped image back to the original array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < *cols; j++) {
            image[i][j] = croppedImage[i][j];
        }
    }
    
    char temp; 
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
            do {
                fscanf(cropImagefp, "%c", &temp);
            } while(temp == '\n' && temp == ' ');
            image[i][j] = temp - '0';
        }
        
         fclose(cropImagefp);

    // Print the cropped image
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < *cols; j++) {
            int type = image[i][j];
            if (type == 0) {
                printf(" ");
            } else if (type == 1) {
                printf(".");
            } else if (type == 2) {
                printf("o");
            } else if (type == 3) {
                printf("O");
            } else if (type == 4) {
                printf("0");
            }
        }
        printf("\n");
    }
}
 
}


void dimImage(FILE* dimImagefp, int image[][MAX_COLS], int rows, int *cols) {
    int newtype;
    char newtemp;
    dimImagefp = fopen(CURRENT_IMAGE, "r");
    
    if(dimImagefp == NULL){
        printf("Unable to open file. Non-existent.\n");
        return;
    }   

    // Read the image data from the file and store it in the image array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
            do {
                fscanf(dimImagefp, "%c", &newtemp);
            } while(newtemp == '\n' && newtemp == ' ');
            image[i][j] = newtemp - '0';
        }
    }

    // Decrement the values in the image array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
        if (image[i][j]==0){
        image[i][j]==0;}
        else{
            image[i][j]--;
        }
        }
    }

    // Print the modified image
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
            newtype = image[i][j];
            if (newtype == 0){
                printf(" ");
            } else if(newtype == 1){
                printf(".");
            } else if(newtype == 2){
                printf("o");
            } else if(newtype == 3){
                printf("O");
            } else if(newtype == 4){
                printf("0");
            }
        }
        printf("\n");
    }

    fclose(dimImagefp); // Close the file after usage
}



void brightenImage(FILE* brightenImagefp, int image[][MAX_COLS], int rows, int *cols) {
    int type2;
    char temp3;
    brightenImagefp = fopen(CURRENT_IMAGE, "r");
    
    if(brightenImagefp == NULL){
        printf("Unable to open file. Non-existent.\n");
        return;
    }   

    // Read the image data from the file and store it in the image array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
            do {
                fscanf(brightenImagefp, "%c", &temp3);
            } while(temp3 == '\n' && temp3 == ' ');
            image[i][j] = temp3 - '0';
        }
    }

    // Decrement the values in the image array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
        if (image[i][j]==4){
        image[i][j]==4;}
        else{
            image[i][j]++;
        }
        }
    }

    // Print the modified image
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
            type2 = image[i][j];
            if (type2 == 0){
                printf(" ");
            } else if(type2 == 1){
                printf(".");
            } else if(type2 == 2){
                printf("o");
            } else if(type2 == 3){
                printf("O");
            } else if(type2 == 4){
                printf("0");
            }
        }
        printf("\n");
    }

    fclose(brightenImagefp); // Close the file after usage
}




void saveImage(FILE* saveEditedImage, int row, int cols, int image[][MAX_COLS]){
	
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








	
