/*
    Author:Dipayan Das
    Date:2-08-2018
    Description:This Process Will Kill  the process and all its child processes.
    Bhabatu Sarba Manglam 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

/*Constants*/
#define FirstDigit 48;

/*Function Definitions*/
void KillProcess();
void showOptions();
int getSingleInput();
void processChoices(int );
////////////////////////////////////////////////////
/*Link list Declearations*/
/*structure*/
struct node{
    int data;
    struct node *next;
};

/*LinkList function signetures*/
struct node * createLinkList();
struct node *createNode();
void insertAtBegeningLinkList(int data,struct node *head);
void insertAtEndLinkList(int data,struct node *head);
void freeTheLinkList(struct node *head);
void getElementAtBegening(struct node *head);
void getElementAtend(struct node *head);
void traverse(struct node *head);
void traverseAndKillProcess(struct node *head);
int findData(struct node *head,int data);
////////////////////////////////////////////////////

int killReturnValue;

/*Mian Function*/
int main(int argc,char *argv[]){
    
    int processId;
    int choice=-1;
    
    /*If argument was send by the Programmer*/
   
    if(argc==2){
        printf("\nKill Process with Process ID then backl");
         KillProcess(atoi(argv[1]));
        return 14891;
    }


        do{
            showOptions();
            choice=getSingleInput();
            processChoices(choice);            
            
        }while(0!=choice);
    return 0;

}

/////////////////////////////////////////////////////////////////////
void processChoices(int choice){

    int processId;
    char processIdString[10];
    char instruction[30]="pstree -p ";
    
    switch (choice){
        case 0:
                printf("Happy Doing Worlk with You,Mangalam Bhabatu.\n");
                break;
        case 1:
                printf("Enter Process ID:");
                processId=getSingleInput();
                if(processId<=0){
                    printf("Please enter properly");
                    break;
                }
                KillProcess(processId);
                if(killReturnValue<0){
                    printf("We had Error in Killing, may be process Does not exist,or might have entered wrong input for eg:char");
                }else{
                     printf("Process was terminated");
                }
                break;        
        case 2:
               
                printf("Enter ProcessID OR '0' To see All the Process.\n");
                //processId=getSingleInput();
                scanf("%s",processIdString);

                strcat(instruction, processIdString);
                //printf("%s",instruction);
                system(instruction);
                break;                
        default :
                printf("Please Enter Properly.");
                break;        
    }
}


/*Its taking single input integer*/
int getSingleInput(){
    /*int choice=-1;
    scanf("%d",&choice);
    return choice;*/


    ////
    char input[100];
    int data=-1;
    scanf("%s",input);
    if(0<atoi(input)){
        data=0<atoi(input);
    }

    return data;

}


/*Its Providing the OS Choices*/
void showOptions(){
    printf("\n===============ProgramChoices==================\n");
    printf("Enter 1 kill the Process\n");
    printf("Enter 2 show All running the Process\n");
    printf("Enter 0 Exit from the proccess\n");
    printf("===============================================\n");
}

/*THis section is the heart of the code whichh will kill process and all the child processes */
/*I am going to store the entire  ppid and pid in log file
  and read the file if ppid is given process Id Then I will store it in link list 
  and will kill it recursively 
 */
void KillProcess(int processId){
   int pid,ppid;
   int year;
   FILE * fp;
   struct node *head;
   head=createLinkList();
    char showAllProcessLIst[30]="ps -e -o ppid= -o pid=";
    killReturnValue=0;
    //printf("\nHello World From killing the process");
    //printf("pid: %d",processId);
    //printf("\n%d\n",SIGKILL);
    /*This is going to print the parent and child process id in log file */
    system("ps -e -o ppid= -o pid= >log");
     killReturnValue=killReturnValue+kill(processId,SIGKILL);
    /*This will read the file and will kill the process accordingly*/
   

   fp = fopen ("log", "r");
     
  /*inserting the child processes in a list*/
   while(0<=fscanf(fp, "%d %d", &ppid,&pid )){
       // fscanf(fp, "%d %d", &ppid,&pid )
        //printf("%d %d\n",ppid,pid);
        if(processId==ppid){
            insertAtBegeningLinkList(pid,head);
        }


   }
   fclose(fp);

   






///////File reading is done///////////////////////////////////////////
    /*This will kill*/
   
   traverseAndKillProcess(head);
   //kill(processId,SIGKILL);
   //kill(processId,SIGTERM);   
   //kill(processId,SIGTERM);   
   freeTheLinkList(head);
}

/*Link list implementations starts*/


/*This will check weather data exist if exit then reurn positive esle return negetive*/
int findData(struct node *head,int data){
    int result=-1;
    struct node *temp=head->next;
   // printf("Hi from finding the data %d",data);
    while(temp){
        if(data==temp->data){
            return data;
        }
        temp=temp->next;
    }
    
    return result;
}


//get element at the end
void getElementAtend(struct node *head){
    if(NULL==head||NULL==head->next){
      //  printf("\nPlease create LinkList or insert data \n");
        return ;
    }
    if(NULL==head->next->next){
        //printf("\ndata at the end=%d\n",head->next->data);
        free(head->next);
        return ;
    }
    struct node *temp=head->next;
    while(temp->next->next){
        temp=temp->next;
    }
   // printf("\n data at the end=%d\n",temp->next->data);

    free(temp->next);
    temp->next=NULL;
}
//getdata from beginig
void getElementAtBegening(struct node *head){
    if(NULL==head&&NULL==head->next){
       // printf("\nPlease create LinkList or insert data \n");
        return ;
    }
    struct node *temp=head->next;
    int data;
    data =temp->data;
    head->next=temp->next;
    free(temp);
   // printf("\nElement at bgening:data%d\n",data);

}
//insert in the end
void insertAtEndLinkList(int data,struct node *head){
    if(NULL==head&&NULL==head->next){
        //printf("\nPlease create LinkList\n");
        return;
    }
    struct node *temp;
    temp=head;
    struct node *node=createNode();
    node->data=data;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=node;
    node->next=NULL;

    //head->next=node;
   // printf("\nData Inserted in end data=%d\n",temp->next->data);
}

//insert at begenning
void insertAtBegeningLinkList(int data,struct node *head){
    if(NULL==head){
       // printf("\nPlease create LinkList\n");
        return;
    }
    struct node *node=createNode();
    node->data=data;
    node->next=head->next;
    head->next=node;
   // printf("Data Inserted in begening\n");
}

//traverse the linklist
void traverse(struct node *head){
    if(NULL==head){
      // printf("\nLinkList is empty");
        return;
    }
    struct node *temp=head->next;
   // printf("\n");
    while(temp){
       // printf(" %d",temp->data );
        temp=temp->next;
    }
   // printf("\n");
}

//free entire list
void freeTheLinkList(struct node *head){
    struct node *temp1=head;
    struct node *temp2=temp1;
    while(temp1){
        temp2=temp2->next;
        free(temp1);
        temp1=temp2;
    }


}
//creating the node
struct node *createNode(){
    struct node * head;
    if(NULL==(head= (struct node *)malloc(sizeof(struct node *)))){
       // printf("There IS Some ERROR\n");
        return NULL;
    }

    head->next=NULL;
    if(head){
      // printf("LinkLst Created\n");
    }
    return head;
}
//creating LinkList
struct node * createLinkList(){
    struct node * head;
    if(NULL==(head= (struct node *)malloc(sizeof(struct node *)))){
       // printf("There IS Some ERROR\n");
        return NULL;
    }

    head->next=NULL;
    if(head){
       // printf("LinkLst Created\n");
    }
    return head;
}
void traverseAndKillProcess(struct node *head){
   //printf("Hello From traverse and kill");
     if(NULL==head){
        //printf("\nLinkList is empty");
        return;
    }
    struct node *temp=head->next;
   // printf("\n");
    while(temp){
        KillProcess(temp->data);
        temp=temp->next;
    }
   // printf("\n");
}


/*link list implementations ends*/




