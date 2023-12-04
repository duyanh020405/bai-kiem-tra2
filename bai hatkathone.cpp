#include <stdio.h> 
#include <string.h>
struct contactList {
	int contact_id;
	char name[50];
	char phone[12];
	char address[50];
	int statust;
};
typedef struct contactList ct;
void name_sort(ct temp[],int index){
    for (int i=0; i<index-1; i++) {
		for (int j=0; j<index-i-1; j++) {
			if (temp[j].name > temp[j+1].name) {
				ct t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
	}
}
void input (ct *temp){
	printf("nhap so id:");
	scanf("%d",&temp->contact_id);
	printf("nhap ten :");
	getchar();
	gets(temp->name);
	printf("nhap so dien thoai :");
	gets(temp->phone);
	printf("nhap dia chi :");
	gets(temp->address);
	printf("nhap status :");
	scanf("%d",&temp->statust);}
void output(ct *temp){
	printf("id :%d , ten :%s , sdt :%s , dia chi :%s , status : %d \n",temp->contact_id,temp->name,temp->phone,temp->address,temp->statust);	
}	
	int main(){
    ct temp[100];
    int n,i,count;
    int choice;
    int index;
printf(" so nguoi can luu trong contactList : 2\n");
    for(i=0;i<2;i++){
    input(&temp[i]);
    index=2;}
do {
printf("\n*****************MENU*******************\n");
printf("1.in ra toan bo danh sach cua contactList trong cung 1 hang\n");
printf("2.thuc hien chuc nang them moi contact vao vi tri cuoi cung cua contact\n");
printf("3.chinh sua thong tin cua contact muon tim (neu khong co thi se in ra khong tim thay)\n");
printf("4.thuc hien chuc nang xoa, nhap contact de tim , neu khong co thi se in ra khong tim thay\n ");
printf("5.thuc hien chuc nang sap xep\n");
printf("6.thuc hien chuc nang tim kiem (tim qua contact)\n");
printf("7.thuc hien chuc nang tim kiem (tim qua statut)\n");
printf("nhap lua chon cua ban\n");
scanf("%d",&choice)	;
  switch(choice){
        case 1 : 
	     for (i=0;i<index;i++){
        output(&temp[i]);}
                break;
        case 2 :
        	int add_Idcontact;
        	printf("nhap so lan them vao :");
        	scanf("%d",&add_Idcontact);
        	for (i=0;i<add_Idcontact;i++){
        	input(&temp[index]);
        	index++;
			}
		break;
        case 3 :
        	 count=0;
            	int find_id;
                printf("nhap vao contact_id can cap nhat:");
                scanf("%d",&find_id);
                for (i=0;i<index;i++) {
                    if (temp[i].contact_id == find_id)
                        {input(&temp[i]);
						count =1;
						}
    			}
    			if(count=0){
    				printf("khong tim thay\n");
				}
                break;
        case 4 :
        	count=0;
        	int delete_id;
                printf("nhap vao id can xoa:");
                scanf("%d",&delete_id);
                for (i=0;i<index;i++) {
                    if (temp[i].contact_id == delete_id)
                    for (int j=i;j<index-1;j++)
                    temp[i] = temp [i+1];
                    count=1;
                }
                if(count=0){
    				printf("khong tim thay\n");
				}
                break;
		case 5 :
		   name_sort(temp,index);
                break; 
        case 6 :
        	int find_contactId ;
        	printf("nhap contact_Id can tim :");
        	scanf("%d",&find_contactId);
			for (i=0;i<index;i++){
				if(temp[i].contact_id == find_contactId)
				output(&temp[i]);
			}
			break;
		case 7 :
			int find_statust ;
        	printf("nhap contact_statust can tim :");
        	scanf("%d",&find_statust);
			for (i=0;i<index;i++){
				if(temp[i].statust == find_statust)
				output(&temp[i]);
			}
			break;
}
}while("ff");
}
	
	
	
