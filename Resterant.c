#include <stdio.h>
#include <string.h>

const char items[5][20] = {"TEA", "COFFEE", "IDLI", "SET DOSA", "MASALA DOSA"};
int prices[5] = {15, 20, 25, 30, 40}; // Predefined prices

int findItemIndex(const char *selection)
{
    for (int i = 0; i < 5; i++)
    {
        if (strcasecmp(selection, items[i]) == 0)
        {
            return i;
        }
    }
    return -1; // Return -1 if not found
}

int main()
{
    char selections[5][20]; // User inputs for selections
    int numSelections, totalBill = 0;

    printf("WELCOME TO DSU FOOD COURT! \n HERE IS OUT MENU FOR TODAY:\n");
    for (int a = 0; a < 5; a++)
    {
        printf("%d. %s\n", (a + 1), items[a]);
    }
    printf("Enter the number of items you would like to order (up to 5): ");
    scanf("%d", &numSelections);

    // Consume the newline character left in the input buffer
    getchar();

    for (int i = 0; i < numSelections; i++)
    {
        printf("Enter selection %d: ", i + 1);
        scanf("%[^\n]", selections[i]);

        int index = findItemIndex(selections[i]);
        if (index != -1)
        {
            printf("Price for %s is Rs%d/-\n", selections[i], prices[index]);
            totalBill += prices[index];
        }
        else
        {
            printf("Selection %s not in the menu for today.\n", selections[i]);
        }

        // Consume the newline character left in the input buffer
        getchar();
    }
    totalBill += totalBill * 0.18;

                 if (totalBill == 0)
    {
        printf("None of the items you chose are in today's menu. \n");
    }
    else
    {
        printf("The total bill payable including GST is: Rs%d/-\n if you really enjoyed the food and our services, please rate us out of 5 below\n.", totalBill);
    }

    int rating;
    printf("Select a num out of 5\n");
    scanf("%d", &rating);
    if (rating == 0 || rating == 1)
    {
        printf("We are sorry for the inconvenience we have caused to you, we will surely take your review into consideration. Thank you for your feedback\n");
    }
    else if (rating == 2 || rating == 3)
    {
        printf("We are sorry for the inconvenience we have caused to you, we will surely take your review into consideration. Thank you for your feedback\n");
    }
    else if (rating == 4 || rating == 5)
    {
        printf("We are glad that you enjoyed our services, thank you for your feedback. Please visit us once again next time.");
    }

    return 0;
}
