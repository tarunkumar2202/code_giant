/************************************************************************************/
// HEARFILE USED IN THE PROGRAM 
/************************************************************************************/

#include<stdio.h>    //for printf(),scanf()
#include<conio.h>    //for getch()
#include<stdlib.h>   //for exit()
#include<string.h>   //for strcpy()
#include<time.h>     //for printing date and time
//#include<dos.h>      //for sleep()

/************************************************************************************/
/* STRUCTURE additem USED TO TAKE ITEM ID,NAME,PRICE */
/************************************************************************************/

struct additem
{
 int item_id;
 char item_name[50];
 float price;
}ad;

/*************************************************************************************/
/* STRUCTURE 2 USED TO HAVE THE BILL ID,CUSTOMER NAME,ITEM NAME,QUANTITY,PRICE*/
/*************************************************************************************/

struct bill
{
 int bill_id;
 char cust_name[50];
 char item_name[15][15];
 float quant[10];
 float total;
 float price[10];
 char date[15];
 int n;
}bi;

FILE *fp,*bifp,*bifp1;

void intro();                 //fuction for showing personal details
int add_item();               //function used for adding item
int generate_bill();          //function to generate bill
int delete_bill();            //function to delete bill 
int display_bill();           //function to display bill
void menu();                  //function to show the items
int q=0;

int main()
{
 char user[10]="TARUN";
 int password=2202;
 printf("\nENTER THE USERNAME:");
 scanf("%s",user);
 printf("\nENTER THE PASSWORD:");
 scanf("%d",&password);
 if(stricmp(user,"TARUN")==0&&password==2202)
 {
  printf("\nLOGIN SUCCESSFULLY....");
  printf("\nENTER TO CONTINUE..");
  getch();
  int i=1;
  system("cls");
  intro();
  system("cls");
  printf("\n\n\n\n\n\n\t\t\t\t\t\t* * * * * * * * * * * * * * * * *");
  printf("\n\t\t\t\t\t\t* * * * * * * * * * * * * * * * *");
  printf("\n\n\t\t\t\t\t\t        ** LUSCIOUS **");
  printf("\n\t\t\t\t\t\t           =========  ");
  printf("\n\t\t\t\t\t\t          ** BAKERY **");
  printf("\n\t\t\t\t\t\t             ======  ");
  printf("\n\t\t\t\t\t\t         ** BILLING **");
  printf("\n\t\t\t\t\t\t            =======  ");
  printf("\n\t\t\t\t\t\t          ** SYSTEM **");
  printf("\n\t\t\t\t\t\t             ======  ");
  printf("\n\n\t\t\t\t\t\t* * * * * * * * * * * * * * * * *");
  printf("\n\t\t\t\t\t\t* * * * * * * * * * * * * * * * *");
  printf("\n\n\n\n\t\t\tPRESS 1 TO ENTER AND 0 TO EXIT.....");
  scanf("%d",&i);
  if(i==0)
  {
    printf("\n\n\t\t\t\t THANKYOU!!!");
    exit(0);
  }
  else
  {
   int f=1,choice;
   XYZ:
   system("cls");	
   printf("\n\n\n\n\t\t\t\t\t *********************************************");
   printf("\n\t\t\t\t\t SWEET LUSCIOUS BAKERY,LUCKNOW BILLING SYSTEM");
   printf("\n\t\t\t\t\t *********************************************");
   printf("\n\n========================================================================================================================");
   printf("\n\n\t[1]. ADD A PRODUCT");
   printf("\n\n\t[2]. GENERATE A BILL");
   printf("\n\n\t[3]. DISPLAY A BILL");
   printf("\n\n\t[4]. DELETE A BILL");
   printf("\n\n\t[5]. EXIT");
   printf("\n\n========================================================================================================================");
   printf("\n\nPRESS CORRESPONDING KEYS TO PERFORM OPERATION (1-5) :- ");
   ABC:
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:q=add_item();
           if(q==0)
           {
            printf("\n\n\n\t\t\t\t THANK YOU!!!");
            exit(0);
           } 
           else
            goto XYZ;
           break;
    case 2:q=generate_bill();
           if(q==0)
           {
	    	  printf("\n\n\n\t\t\t\t THANK YOU!!!");
              exit(0);
           }
           else
             goto XYZ;
           break;
    case 3:q=display_bill();
           if(q==0)
           {
             printf("\n\n\n\t\t\t\t THANK YOU!!!");
             exit(0);
		   }
           else
		   goto XYZ;
		   break;
    case 4:q=delete_bill();
           if(q==0)
           {
             printf("\n\n\t\t\t\t THANK YOU!!!");
             exit(0);
           }
           else
		     goto XYZ;
           break;
    case 5:printf("\n\n\t\t\t\t THANK YOU!!!");
           exit(0);
    default:printf("\n\nYOU ENTERED A WRONG VALUE.PLEASE TRY AGAIN : ");
    goto ABC;
   }
  }
 }
 else
  printf("\nWRONG USERNAME OR PASSWORD.. ABORT!!!");
 getch();
}

void intro()
{
 printf("\n\n\n\n\n\t\t\t\t\t\tBAKERY BILLING SYSTEM");
 printf("\n\t\t\t\t\t\t=====================");
 printf("\n\n************************************************************************************************************************");
 printf("\n\nDEVELOPED BY....");
 printf("\nTARUN KUMAR");
 printf("\n\nREGISTRATION NUMBER : 11701624");
 printf("\nSECTION             : K17CF");
 printf("\nROLL NUMBER         : RK17CFA21");
 printf("\n\nCOLLEGE : LOVELY PROFESSIONAL UNIVERSITY");
 printf("\n            PHAGWARA, PUNJAB");
 printf("\n");
 printf("\n\n************************************************************************************************************************");
 printf("\nENTER TO CONTINUE...");
 getch();
}

void menu()
{
	system("cls");
	printf("\n\n\t\t\t\t******************************************");
	printf("\n\t\t\t\tTHE MENU OF SWEET LUSICIOUS BAKERY,LUCKNOW");
	printf("\n\t\t\t\t******************************************\n");
	fp=fopen("product8.txt","r");
	printf("\n\t\t\tITEM ID\t\t\ITEM NAME\t\tITEM PRICE\n");
	while(!feof(fp))
	{
	  fread(&ad,sizeof(ad),1,fp);
	  printf("\n\t\t\t%d.",ad.item_id);
	  printf("\t\t%s",ad.item_name);
      printf("\t\t%.2f",ad.price); 
    }
	fclose(fp);
	printf("\n\n");
}

int add_item()
{
 system("cls");	
 int f=1,id=0,p[10],i=0;
 while(f==1)
 {
  fp=fopen("product8.txt","r");
  while((fread(&ad,sizeof(ad),1,fp))==1)     //use to increment the product id
  {
   id=ad.item_id;
  }
  fclose(fp);
  printf("\nENTER PRODUCT NAME : ");
  scanf("%s",ad.item_name);
  printf("\nENTER PRODUCT PRICE: ");
  scanf("%f",&ad.price);
  id++;
  p[i]=id;
  i++;
  ad.item_id=id;
  fp=fopen("product8.txt","a");
  fwrite(&ad,sizeof(ad),1,fp);
  fclose(fp);
  printf("\n\n\n\nYOUR PRODUCT WITH ID %d IS ADDED SUCCESSFULLY....",ad.item_id);
  printf("\n\nPRESS 1 TO ADD NEW PRODUCT OR PRESS 0 TO EXIT...");
  scanf("%d",&f);
  if(f!=1)
  {
   break;
  }
 }
 i=0;
 fp=fopen("product8.txt","r");
 while((fread(&ad,sizeof(ad),1,fp))==1)
 {
  if(p[i]==ad.item_id)
  {
   printf("\nPRODUCT ID    : %d",ad.item_id);
   printf("\nPRODUCT NAME  : %s",ad.item_name);
   printf("\nPRODUCT PRICE : %.2f",ad.price);
   printf("\n\n");
   i++;
  }
 }
 fclose(fp);
 printf("PRESS 1 TO GO TO MENU PAGE AND 0 TO EXIT :");
 scanf("%d",&q);
 return q;
}

int display_bill()
{
 system("cls");	
 int p=0;
 int item_id,f=0,i=0,bill_id=0;
 float total;
 printf("\nPLEASE ENTER YOUR BILL-ID :");
 scanf("%d",&bill_id);
 bifp=fopen("bill6.txt","r");
 while((fread(&bi,sizeof(bi),1,bifp))==1)
 {
  if(bill_id==bi.bill_id)
  {
   f=1;
   printf("\nSEARCHING.....");
   //sleep(5);
   printf("\n\n\t\t\t\t\t ******************************");
   printf("\n\t\t\t\t\t SWEET LUSCIOUS BAKERY, LUCKNOW");
   printf("\n\t\t\t\t\t ******************************");
   printf("\n\t\t\t\t\t    GSTIN NO: 03AAKFN8045SLBL");
   printf("\n\t\t\t\t\t\t     INVOICE");
   printf("\n\n\------------------------------------------------------------------------------------------------------------------------");
   printf("\nCUSTOMER NAME : %s",bi.cust_name);
   printf("\t\t\t\tBILL ID  : %d",bi.bill_id);
   printf("\t\t\t\tDATE   : %s",bi.date);
   printf("\n------------------------------------------------------------------------------------------------------------------------");
   printf("\n\nSrNo.");
   printf("\tITEM NAME");
   printf("\tPRICE");
   printf("\t\tQUANTITY");
   printf("\t\tTOTAL");
   total=0;
   for(i=0;i<=bi.n;i++)
   {
    printf("\n%d.",i+1);
    printf("\t%s",bi.item_name[i]);
    printf("\t\t%.2f",bi.price[i]);
    printf("\t\t%.2f",bi.quant[i]);
    printf("\t\t\t%.2f",bi.price[i]*bi.quant[i]);
    total=total+(bi.price[i]*bi.quant[i]);
   }
   printf("\n------------------------------------------------------------------------------------------------------------------------"); 
   printf("\nTOTAL: %.2f Rupees",total);
   printf("\n------------------------------------------------------------------------------------------------------------------------");
   printf("\n\nTHANKS FOR THE VISIT...COME BACK SOON!!");
   printf("\nHAVE A NICE DAY!!");
   break;
  }
 }
 if(f==0)
   printf("\n\nSORRY, YOUR BILL-ID DOES NOT MATCH");
 fclose(bifp);
 printf("\n\nPRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT :");
 scanf("%d",&q);
 return q;
}

int delete_bill()
{
 system("cls");	
 int item_id,f=0,i=0,bill_id=0;
 printf("\nPLEASE ENTER YOUR BILL-ID :");
 scanf("%d",&bill_id);
 if(f==0)
 {
  bifp=fopen("bill6.txt","w");
  bifp1=fopen("bill7.txt","r");
  while((fread(&bi,sizeof(bi),1,bifp1))==1)
  {
   if(bi.bill_id!=bill_id)
   {
    fwrite(&bi,sizeof(bi),1,bifp);
   }
  }
  fclose(bifp1);
  fclose(bifp);
  printf("\n\nYOUR BILL HAS BEEN DELETED SUCCESSFULLY.");
 }
 else
  printf("\n\nSORRY, YOUR BILL-ID DOES NOT MATCH.");
 printf("\n\nPRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT :- ");
 scanf("%d",&q);
 return q;
}

int generate_bill()
{
 system("cls");	
 time_t now;
 struct tm *d;
 time(&now);
 d=localtime(&now);
 strftime(bi.date,11,"%d/%m/%Y",d);
 int item_id,f=1,i=0,n=0,bill_id=0,k=1,j=0,p;
 float total=0,quant=0;
 bifp=fopen("bill6.txt","a");
 fclose(bifp);
 while(f==1)
 {
  int flag=0;
  if(j==0)
  {
   bifp=fopen("bill6.txt","r");
   while((fread(&bi,sizeof(bi),1,bifp))==1)
   {
     bill_id=bi.bill_id;
   }
   bill_id++;
   bi.bill_id=bill_id;
   fclose(bifp);
   j++;
  }
  menu();
  printf("\n\tNOTE :- JUST ENTER PRODUCT ID OF BUYING PRODUCTS TO CALCULATE BILL");
  printf("\n\nPRODUCT ID :");
  scanf("%d",&item_id);
  fp=fopen("product8.txt","r");
  while((fread(&ad,sizeof(ad),1,fp))==1)
  {
    if(item_id==ad.item_id)
    {
     printf("\n\nPRODUCT NAME : %s",ad.item_name);
     strcpy(bi.item_name[i],ad.item_name);
     printf("\nPRODUCT PRICE  : %f",ad.price);
     bi.price[i]=ad.price;
     printf("\n");
     flag=1;
    }
   } 
   if(flag==0)
     printf("\n\n\tYOUR PRODUCT ID IS NOT FOUND.");
   else
   {
    printf("\n\nQUANTITY OF PRODUCT :");
    scanf("%f",&quant);
    bi.quant[i]=quant;
    total=total+quant*ad.price;
    bi.total=total;
    flag=0;
    bi.n=i;
    n=i;
    i++;
   }
   fclose(fp);
   printf("\n\n\nPRESS 1 TO ADD MORE PRODUCT OTHERWISE PRESS 0 TO GO TO BILL PAGE : ");
   scanf("%d",&f);
  }
  printf("\n\tPUT DOWN CUSTOMER INFORMATION .....");
  printf("\n\nCUSTOMER NAME :");
  scanf("%s",&bi.cust_name);
  printf("\n\nPRESS 1 TO GENERATE A BILL AND PRESS 0 TO GO TO MAIN MENU : ");
  scanf("%d",&p);
  if(p!=1)
    return p;
  else
  {
   i=0;
   system("cls");
   bifp=fopen("bill6.txt","a");
   fwrite(&bi,sizeof(bi),1,bifp);
   fclose(bifp);
   printf("\n\n\t\t\t\t\t  ************************");
   printf("\n\t\t\t\t\t  LUSCIOUS BAKERY, LUCKNOW");
   printf("\n\t\t\t\t\t  ************************");
   printf("\n\t\t\t\t\t  GSTIN NO: 03AAKFN8045SLBL");
   printf("\n\t\t\t\t\t\t   INVOICE"); 
   printf("\n\n------------------------------------------------------------------------------------------------------------------------");
   printf("\nCUSTOMER NAME: %s",bi.cust_name);
   printf("\t\t\t\tBILL ID : %d",bi.bill_id);
   printf("\t\t\t\tDATE  : %s",bi.date);
   printf("\n------------------------------------------------------------------------------------------------------------------------");
   printf("\n\nSrNo.");
   printf("\tITEM NAME");
   printf("\t\tPRICE");
   printf("\t\t\tQUANTITY");
   printf("\t\tTOTAL");
   total=0;
   for(i=0;i<=n;i++)
   { 
    printf("\n\n%d.",i+1);
    printf("\t%s",bi.item_name[i]);
    printf("\t\t\t%.2f",bi.price[i]);
    printf("\t\t\t%.2f",bi.quant[i]);
    printf("\t\t\t%.2f",bi.price[i]*bi.quant[i]);
    total=total+(bi.price[i]*bi.quant[i]);
   }
   printf("\n-----------------------------------------------------------------------------------------------------------------------");
   printf("\nTOTAL IS %.2f Rs",total);
   printf("\n------------------------------------------------------------------------------------------------------------------------");   
   printf("\n\nTHANKS FOR THE VISIT...COME BACK SOON!!");
   printf("\nHAVE A NICE DAY!!");
   printf("\n\nPRESS 1 TO GO TO MAIN MENU AND 0 TO EXIT:");
   scanf("%d",&q);
   return q;
  }
 }
 /************************************ END *******************************************/
