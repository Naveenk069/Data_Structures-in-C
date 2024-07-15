#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
	};
struct node *head ='\0';
struct node *temp ='\0';
struct node *curr ='\0';
int n=0;

void insert_front()
{
	if(head == '\0')
	{
		head = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data : ");
		scanf("%d", &head->data);
		head->link = '\0';
		n++;
	}
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data : ");
		scanf("%d", &temp->data);
		temp->link = head;
		head = temp;
		n++;
	}
}

void insert_back()
{
	if(head == '\0')
	{
		head = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data : ");
		scanf("%d", &head->data);
		head->link ='\0';
		n++;
	}
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data : ");
		scanf("%d", &temp -> data);
		temp->link = '\0';
		curr = head;
		while(curr->link != '\0')
			curr = curr->link;
		curr->link = temp;
		n++;
	}
}

void insert_pos(int pos)
{
    temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter Data : ");
	scanf("%d", & temp->data);
	temp->link ='\0';
	curr = head;
	for(int i = 1; i < (pos-1); i++)
	{
		curr = curr->link;   
	}
	temp->link = curr->link;
	curr->link = temp;
	n++;
}

void del_front()
{
	if (head == '\0')
		printf("No nodes to delete\n");
	else
	{
		head = head->link;
		n--;
	}
}

void del_back()
{	
	if(head->link == '\0')
	{	
		head = '\0';
		n--;
	}
	else
	{
		curr=head;
		while(curr->link->link != '\0')
			curr = curr->link;
		curr->link = '\0';
		n--;
	}
}

void del_value()
{   
	int val=0;
    printf("Enter the value : ");
    scanf("%d", &val);
    if (head->data == val)
        del_front();
    else {
        curr = head;
        while ((curr->link->data != val) && (curr->link->link != '\0'))
            curr=curr->link;
        if (curr->link->data != val && curr->link->link == '\0')
            printf("Value not found\n");
        else
        {
            curr->link = curr->link->link;
            n--;
        }
    }
}

void display()
{
	if (head == '\0')
		printf("No nodes to display\n");
	else
	{
		curr = head;
		while(curr !='\0')
		{
			printf("%d\n", curr->data);
			curr = curr->link;
		}
	}
}	 	    

int main()
{
	int opt,pos=0;
	while(1)
	{
		printf("\nLinked list menu\
				\n1.Insert at front\
				\n2.Insert at back\
				\n3.Insert at position\
				\n4.Delete at front\
				\n5.Delete at back\
				\n6.Delete value\
				\n7.Display\
				\n8.Exit\n");
		printf("Enter the option : ");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_back();
				break;
			case 3:
			    printf("Enter a Position : ");
			    scanf("%d", &pos);
			    if(pos == n+1)
			        insert_back();
			    else if(pos == 1)
			        insert_front();
			    else if (pos<1 || pos>n+1)
			        printf("Enter valid Position\n");
			    else
			        insert_pos(pos);
			    break;
			case 4:
				if(head == '\0')
					printf("No nodes to delete\n");
				else
					del_front();
				break;	   
			case 5:
				if(head == '\0')
					printf("No nodes to delete\n");
				else
					del_back();
				break;
			case 6:
				if(head == '\0')
					printf("No nodes to delete\n");
				else
					del_value();
				break;
			case 7:
				if(head == '\0')
					printf("No nodes to display\n");
				else
					display();
				break;
			case 8:
				return 0;
		}
	}
	
}
