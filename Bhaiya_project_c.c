#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

struct task{
    int id;
    char description[200];
    bool completed;
};

void AddTask(struct task tasks[], int *count){
     if(*count < 100){tasks[*count].id = *count + 1;
    printf("enter task: ");
        fgets(tasks[*count].description, sizeof(tasks[*count].description), stdin);

        tasks[*count].completed = 0;

        (*count)++;}else{
            printf("Task list is full!");
        }
}

void ViewTasks(struct task tasks[], int count){
    for(int i = 0; i < count; i++){
        printf("ID: %d\n", tasks[i].id);
        printf("Task: %s", tasks[i].description);
        printf("Status: %d\n", tasks[i].completed);
    }
}

void MarkTaskDone(struct task tasks[], int count){
    int id;
    bool found = false;

    printf("enter the Task ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++){
    if(id == tasks[i].id){
        tasks[i].completed = 1;
        found = true;
        printf("Task Mark as Completed\n");
        break;
    }
    
    }
    if(found == false){
        printf("Task Not Found\n");
    }
}

int main(){
  
    int choice=0;
    struct task tasks[100];
    int count = 0;
    
   
do{
    printf("------To-Do Place For Everything------\n");
    printf("What task would you like to perform?\n");
    printf("1. Add a New Task\n");
    printf("2. Delete a Task\n");
    printf("3. Load Completed Task\n");
    printf("4. Load Pending Task\n");
    printf("5. View All Task\n");
    printf("6. Mark Task as Done\n");
    printf("7. Exit\n");


    printf("\nEnter in your choice: ");
    scanf("%d", &choice);

    getchar();

    if(choice == 1){

        AddTask(tasks, &count);
        
        
    }

    if(choice == 5){

        ViewTasks(tasks, count);


    }

    if(choice == 6){

        MarkTaskDone(tasks, count);
    }

    }
    while(choice != 7);

    
        return 0;
    }