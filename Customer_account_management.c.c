#include<stdio.h>
#include<string.h>

#define MAX_CUSTOMERS 100

struct PaymentDate {
    int month;
    int day;
    int year;
};

struct Customer {
    char name[50];
    char street[50];
    char city[50];
    char contact[15];
    int account_number;
    char account_type[10];
    float old_balance;
    float current_payment;
    float new_balance;
    struct PaymentDate payment_date;
};

void update_balance(struct Customer *customer) {
    customer->new_balance = customer->old_balance - customer->current_payment;
}

void update_status(struct Customer *customer, char *status) {
    if (customer->current_payment > 0 && customer->current_payment < 0.1 * customer->old_balance) {
        strcpy(status, "OVERDUE");
    } else if (customer->old_balance > 0 && customer->current_payment == 0) {
        strcpy(status, "DELINQUENT");
    } else {
        strcpy(status, "CURRENT ACCOUNT");
    }
}

void display_customer(struct Customer *customer, char *status) {
    printf("Name: %s\n", customer->name);
    printf("Street: %s\n", customer->street);
    printf("City: %s\n", customer->city);
    printf("Contact: %s\n", customer->contact);
    printf("Account Number: %d\n", customer->account_number);
    printf("Account Type: %s\n", customer->account_type);
    printf("Old Balance: %.2f\n", customer->old_balance);
    printf("Current Payment: %.2f\n", customer->current_payment);
    printf("New Balance: %.2f\n", customer->new_balance);
    printf("Payment Date: %02d/%02d/%04d\n", customer->payment_date.month, customer->payment_date.day, customer->payment_date.year);
    printf("Status: %s\n", status);
}

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int num_customers;
    char status[20];

    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);

    for (int i = 0; i < num_customers; i++) {
        printf("Enter details for customer %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Street: ");
        scanf("%s", customers[i].street);
        printf("City: ");
        scanf("%s", customers[i].city);
        printf("Contact: ");
        scanf("%s", customers[i].contact);
        printf("Account Number: ");
        scanf("%d", &customers[i].account_number);
        printf("Account Type: ");
        scanf("%s", customers[i].account_type);
        printf("Old Balance: ");
        scanf("%f", &customers[i].old_balance);
        printf("Current Payment: ");
        scanf("%f", &customers[i].current_payment);
        printf("Payment Date (mm dd yyyy): ");
        scanf("%d %d %d", &customers[i].payment_date.month, &customers[i].payment_date.day, &customers[i].payment_date.year);

        update_balance(&customers[i]);
        update_status(&customers[i], status);
        display_customer(&customers[i], status);
        printf("\n"); // Add a newline for better readability between customers
    }

    return 0;
}


