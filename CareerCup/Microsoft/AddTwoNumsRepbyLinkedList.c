#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
	int data;
	struct node* next;
};

struct node* newNode(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void Push(struct node** head, int data)
{
	struct node* temp = newNode(data);
	temp->next = *head;
	*head = temp;
}

void ConvertNumtoList(int num, struct node** head)
{
	int sign = 1;
	if(num == 0)
	{
		Push(head, num);
		return;
	}

	if(num < 0)
	{
		sign = -1;
		num *= sign;	
	}

	while(num > 0)
	{
		int val = (num % 10);
		Push(head, val);
		num /= 10;
	}
	if(sign < 0)
		(*head)->data = (*head)->data * sign;
}

void PrintList(struct node* head, char arr[])
{
	if(head == NULL)
		return;
	printf("\n%s is = ", arr);
	struct node* current = head;
	while(current != NULL)
	{
		printf(" %d ", current->data);
		current = current->next;
	}
	ListLen(head, arr);
}

int ListLen(struct node* head, char arr[])
{
	int count = 0;
	struct node* current = head;
	printf("\nLength of %s = ", arr);
	while(current != NULL)
	{
		count++;
		current = current->next;
	}
	printf("%d", count);
	return count;
}

void DeleteList(struct node** head)
{
	struct node* temp = *head;
	while(*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	*head = NULL;
}

struct node* addListofSameSize(struct node* lst1, struct node* lst2, int* carry)
{
	if(lst1 == NULL)
		return NULL;

	int sum;

	struct node* result = malloc(sizeof(struct node));

	result->next = addListofSameSize(lst1->next, lst2->next, carry);

	sum = lst1->data + lst2->data + *carry;
	*carry = sum / 10;
	result->data = sum%10;

	return result;
}

void swap(struct node** a, struct node** b)
{
	struct node* temp = *a;
	*a = *b;
	*b = temp;
}

void AddCarrytoRemaining(struct node* head1, struct node* cur, struct node** result, int* carry)
{
	int sum;
	if(head1 != cur)
	{
		AddCarrytoRemaining(head1->next, cur, result, carry);
		sum = head1->data + *carry;
		*carry = sum / 10;
		sum = sum % 10;
		Push(result, sum);
	}
}

void AddLists(struct node* lst1, struct node* lst2, struct node** result)
{
	struct node* cur = NULL;
	if(lst1 == NULL)
	{
		*result = lst2;
		return;
	}
	if(lst2 == NULL)
	{
		*result = lst1;
		return;
	}

	int len1 = ListLen(lst1, "list1");
	int len2 = ListLen(lst2, "list2");
	int i = 0;
	int carry = 0;

	if(len1 == len2)
	{
		*result = addListofSameSize(lst1, lst2, &carry);
	}
	else
	{
		if(len1 < len2)
		{
			swap(&lst1, &lst2);
		}

		int diff = abs(len1 - len2);
		for(cur = lst1; diff--; cur = cur->next);
		*result = addListofSameSize(cur, lst2, &carry);
		AddCarrytoRemaining(lst1, cur, result, &carry);
	}
	if(carry > 0)
		Push(result, carry);
}

void main()
{
	int num1, num2;
	printf("Please enter num1 = ");
	scanf("%d", &num1);
	printf("\nPlease enter num2 = ");
	scanf("%d", &num2);

	struct node* lst1 = NULL;
	ConvertNumtoList(num1, &lst1);

	struct node* lst2 = NULL;
	ConvertNumtoList(num2, &lst2);

	struct node* result = NULL;
	AddLists(lst1, lst2, &result);
	PrintList(result, "Result list ");
	
	DeleteList(&result);
	DeleteList(&lst1);
	DeleteList(&lst2);
	
}
