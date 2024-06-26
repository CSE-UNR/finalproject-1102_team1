//Alexus Rowe and Ervin Martinez//
//Professor: Erin Keith
//CS 135-1102
//Final Group Project
//7 May 2024


#include<stdio.h>



#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_FILE_NAME 50

int defaultMenu();
void displayCurrentImage(char file[], int rows, int *cols, int image[][MAX_COLS], FILE* initialImage);
void newImage(char file[], int row, int cols, int image[][cols], FILE* newPhoto);
int sizeOfArray(char file[],FILE* currentFile, int row, int* cols, int enteredImage[][MAX_COLS]);
void editImage(char file[], FILE* editImages, int image[][MAX_COLS], int rows, int columns);
void cropImage(int image[][MAX_COLS], int cropped[][MAX_COLS], int startRow, int startCol,int endRow, int endCol,int rows, int cols);
void dimImage(char file[], FILE* dimImagefp, int image[][MAX_COLS], int rows, int *cols);
void brightenImage(char file[], FILE* brightenImagefp, int image[][MAX_COLS], int rows, int *cols);
void saveImage(char file[],FILE* saveEditedImage, int row, int cols, int image[][cols]);
	

int main(){

	int image[MAX_ROWS][MAX_COLS], choice, rows, cols;
	char file[MAX_FILE_NAME+1];
	
	
	FILE* currentImage_fp;
	
	
	do{
		choice = defaultMenu();
		
		switch(choice){
		
			case 1:
				rows = sizeOfArray(file, currentImage_fp, rows, &cols, image);
				newImage(file, rows, cols, image, currentImage_fp);
			break;
			
			case 2:
				rows = sizeOfArray(file, currentImage_fp, rows, &cols, image);
				printf("\n");
				displayCurrentImage(file, rows, &cols, image, currentImage_fp);
			break;
			
			case 3:
				editImage(file, currentImage_fp, image, rows, cols);
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
	printf("Choose from one of the options above: ");
	scanf("%d", &menuChoice);
	
	return menuChoice;
}

void newImage(char file[],int row, int cols, int image[][MAX_COLS], FILE* newPhoto){
	
	
	printf("Enter a file you would like to load: ");
	scanf("%s", file);
	
	newPhoto = fopen(file, "r");
	
	if(newPhoto == NULL){
		printf("\n");
		printf("Unable to open file. Non-existent.\n");
		printf("\n");
		return;
	}
	else{
		
		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < cols; j++){
				fscanf(newPhoto, "%d", &image[i][j]);
			}
		}
		fclose(newPhoto);
		printf("\n");
		printf("Image successfully loaded!\n");
		printf("\n");

	}
	
}

int sizeOfArray(char file[], FILE* currentFile, int row, int* cols, int enteredImage[][MAX_COLS]){
	
	char temp[MAX_COLS];
	int Cols =0, rows = 0;
	int index;
	
	currentFile = fopen(file, "r");
	if(currentFile == NULL){
		return 0;
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
	




void displayCurrentImage(char file[], int rows, int *cols, int image[][MAX_COLS], FILE* initialImage){
	
	char temp;
	int type;

	
	initialImage = fopen(file, "r");
	
	if(initialImage == NULL){
		printf("\n");
		printf("Unable to open file. Non-existent.\n");
		printf("\n");
		return;
	}
	else{
	 	for(int i= 0; i < rows; i++){
			for(int j = 0; j < *cols; j++){
				
				do{
					fscanf(initialImage, "%c", &temp);
				
				}while(temp == '\n' || temp == ' ');
				
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
		printf("\n");
	
		
	}
}

void editImage(char file[], FILE* editImages, int image[][MAX_COLS], int rows, int cols) {
    
    
    	editImages = fopen(file, "r");
    	
    	if(editImages == NULL){
    		printf("\n");
		printf("Unable to edit image. Non-existent.\n");
		printf("\n");
		return;
	}
	else{
    
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
   				displayCurrentImage(file, rows, &cols, image, editImages);
              			int croppedImage[MAX_ROWS][MAX_COLS];
				int startCol,endCol,startRow,endRow;

    				printf("The image you want to crop is %d x %d.\n", rows, cols-1);
    				printf("The row and column values start in the upper lefthand corner.\n\n");

    				printf("Which column do you want to be the new left side? ");
    				scanf("%d", &startCol);
				while(startCol<1 || startCol>= cols){
   		 			printf("Invalid column value. Choose a value between 1 and %d: ", cols-1);
		 			scanf("%d", &startCol);
    				}
    				printf("Which column do you want to be the new right side? ");
    				scanf("%d", &endCol);
    				while(endCol<startCol || endCol>= cols){
    					printf("Invalid column value. Choose a value between %d and %d: ",startCol, cols-1);
    					scanf("%d", &endCol);
    				}

    				printf("Which row do you want to be the new top? ");
    				scanf("%d", &startRow);
				while(startRow<1 || startRow>= rows){
   		 			printf("Invalid row value. Choose a value between 1 and %d: ", rows-1);
		 			scanf("%d", &startRow);
    				}

    				printf("Which row do you want to be the new bottom? ");
    				scanf("%d", &endRow);
   				while(endRow<startRow || endRow>= rows){
    					printf("Invalid row value. Choose a value between %d and %d: ", startRow, rows-1);
    					scanf("%d", &endRow);
    				}
   

   
    				cols = endCol - startCol + 1;
    				rows=endRow-startRow+1;
          		
         			cropImage(image, croppedImage,startRow, startCol,endRow, endCol,rows, cols);
         			saveImage(file, editImages, rows, cols, image);
            		break;
        	case 2:
			rows = sizeOfArray(file, editImages, rows, &cols, image);
         		dimImage(file, editImages,image,rows,&cols);
         		saveImage(file, editImages, rows, cols, image);
          		 
          	 
            		break;
        	case 3:
            		
            		rows = sizeOfArray(file, editImages, rows, &cols, image);
            		brightenImage(file, editImages,image,rows, &cols);
         		saveImage(file, editImages, rows, cols, image);
	
          	 case 0:
          	 	
          	 	break;
        	default:
           		printf("Invalid choice. Please enter a valid option.\n");
           		printf("Choose from one of the options above: ");
             		scanf("%d", &choice);
   		} 
   	
   	
   	}
   
    fclose(editImages);
}

void cropImage(int image[][MAX_COLS],int croppedImage[][MAX_COLS], int startRow, int startCol,int endRow, int endCol, int rows, int cols) {
   
    
    

    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            croppedImage[i - startRow][j - startCol] = image[i][j];
        }
    }

   for(int i = startRow; i <= endRow; i++){
        for(int j = startCol; j <= endCol; j++){
           int newtype = image[i][j];
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
  
    
   
}

void dimImage(char file[], FILE* dimImagefp, int image[][MAX_COLS], int rows, int *cols) {
    int newtype;
    char newtemp;
    dimImagefp = fopen(file, "r");
    
    if(dimImagefp == NULL){
        printf("Unable to open file. Non-existent.\n");
        return;
    }   
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
            do {
                fscanf(dimImagefp, "%c", &newtemp);
            } while(newtemp == '\n' || newtemp == ' ');
            image[i][j] = newtemp - '0';
        }
    }

   
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
        if (image[i][j]==0){
        image[i][j]==0;}
        else{
            image[i][j]--;
        }
        }
    }

    
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

    fclose(dimImagefp); 
}



void brightenImage(char file[], FILE* brightenImagefp, int image[][MAX_COLS], int rows, int *cols) {
    int type2;
    char temp3;
    brightenImagefp = fopen(file, "r");
    
    if(brightenImagefp == NULL){
        printf("Unable to open file. Non-existent.\n");
        return;
    }   

    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
            do {
                fscanf(brightenImagefp, "%c", &temp3);
            } while(temp3 == '\n' || temp3 == ' ');
            image[i][j] = temp3 - '0';
        }
    }

    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < *cols; j++){
        if (image[i][j]==4){
        image[i][j]==4;}
        else{
            image[i][j]++;
        }
        }
    }

   
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

    fclose(brightenImagefp); 
}




void saveImage(char file[], FILE* saveEditedImage, int row, int cols, int image[][MAX_COLS]){
	
	char editImage[MAX_FILE_NAME+1], saveorno;
	printf("\n");
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c",&saveorno);
	
	if(saveorno != 'Y' && saveorno != 'y'){
		printf("\n");
		printf("Save not initiated.\n"); printf("\n");
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








	
