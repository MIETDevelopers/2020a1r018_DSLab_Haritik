 //taken this code and help to understand it from Samragyi 
#include<stdio.h>
#include<stdlib.h>              // for memory allocation and exit()
#include<conio.h>               // for getch()
// Input elements in the array
void input_elements(int *list, int n){
    int i;                                            
    for(i=0; i<n; i++){
    printf("Enter Element at list[%d] : ", i);
    scanf ("%d", (list+i));
    }
}
// Inserting new element (Insertion)
int insert_element(int *list, int size, int insertat, int element){
     int i;
     if(size>insertat){
        list = realloc(list, ((size+1)*sizeof(int)));
        if(list == NULL){
         printf("Memory cannot be allocated");
        }else{
            for(i = size; i>=insertat; i--){
              *(list+i) = *(list+i-1);
            }
             *(list+insertat) = element;
             size++;
        }
     }
     return size; 
}
// Liner search
int Lsearch(int *list, int size, int element){
    int i, index= -1;
    for(i=0; i<size; i++){
        if(*(list+i)== element){
            index = i;
            break;
        }
    }    
    return index; 
}
// Deletion
int FindandDelete(int *list, int size, int element){
    int i, index;
    // Using Linear search function to check if the element is present 
    index = Lsearch(list, size, element); 
    if(index == -1){
        return -1;
    }
    else{
        // deleting the element
        for(i = index; i<size; i++){
            *(list+i) = *(list+i+1);
        }
        size = size-1;
        return size;
    }
}
// Printing the list
void output_elements(int *list, int n){
    int i;
    for(i = 0; i<n; i++)
        printf("%d \n" , *(list+i));
}
int main()
{
    int *list, size, item, position, index, del_element, del, option, searchFor;
     printf("\t \t \t LIST \n");
     printf("How many elements do you want to enter? \n");
     scanf("%d", &size);
     list = (int *)malloc(size*sizeof(int));
     if(list == NULL)
     printf("Memory cannot be allocated!");
     else{
        input_elements(list, size);
        printf("Entered elements are... \n");
        output_elements(list, size);
        do{
        printf("\n \t OPERATIONS \n");
        printf("1. Insertion \n");
        printf("2. Deletion \n");
        printf("3. Linear Seach \n");
        printf("4. Exit \n \n ");
        printf("Enter your choice : ");
        scanf("%d", &option);
        switch(option){
            case 1: printf("Insertion \n");
                    printf("\n Enter the element you want to insert : ");
                    scanf("%d", &item);
                    printf("Enter the position where you want to insert the element : ");
                    scanf("%d", &position);
                    index = position - 1;
                    size = insert_element(list, size, index, item);
                    printf("Updated List ... \n");
                    output_elements(list, size);
                    break;
            case 2: printf("Deletion \n");
                    printf("\n Enter the element you want to delete : ");
                    scanf("%d", &del_element);
                    del = FindandDelete(list,size, del_element);
                    if(del == -1 || size == 0){
                        // (size == 0) is used to check if the list is empty
                        printf("Element not found or the list is empty\n");
                    }else{
                        size = del;
                         printf("Element deleted!! \n");    
                         printf("Updated List... \n");
                         output_elements(list, size);
                    }
                    break;
            case 3: printf("Linear Search \n");
                    printf("Enter the element you want to search : ");
                    scanf("%d", & searchFor);
                    index = Lsearch(list, size, searchFor);
                    if( index == -1 || size== 0){
                        printf("Element not found !! \n");
                    }else
                     printf("Element found at index : %d", index);
                    break;
            case 4: exit(0);
            default: printf("Please enter the correct choice !! \n");
                     break;
        }
        printf("\n Press any key to continue \n");
        getch();
    }while(1);
    }
    free(list);
    return 0;
}

