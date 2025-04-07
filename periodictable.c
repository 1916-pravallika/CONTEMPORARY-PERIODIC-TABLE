#include <stdio.h>
void searchelement();
void add();
void display();
struct Element
{
    int enumber;
    char esymbol[3];
    char ename[20];
    float emass;
};
int main()
{
    int choice;
    const char *filename = "element.txt"
    while (1)
    {
       printf("1. Search element\n2. Add element\n3. Display periodic table\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        if (choice == 1)
            searchelement();
        else if (choice == 2)
            add();
        else if (choice == 3)
            display(filename);
        else if (choice > 3)
            printf("Enter correct choice\n");
    }
  return 0;
}
void add()
{
    struct Element e;
   printf("Enter atomic number:");
    scanf("%d", &e.enumber);
    printf("Enter name of the element:");
    scanf("%s", e.ename);
    printf("Enter symbol:");
    scanf("%s", e.esymbol);
    printf("Enter atomic weight:");
    scanf("%f", &e.emass);
    FILE *file = fopen("element.txt", "a"); 
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
 fprintf(file, "%d %s %s %.3f\n", e.enumber, e.esymbol, e.ename, e.emass);
    fclose(file);
    printf("\nElement added successfully\n");
}
void searchelement()
{
    struct Element e;
    int k = 0;
    char name[20];
    FILE *file = fopen("element.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter the element to search: ");
    scanf("%s", name);

    while (fscanf(file, "%d %2s %19s %f", &e.enumber, e.esymbol, e.ename, &e.emass) == 4)
    {
        if (strcmp(name, e.ename) == 0)
        {
            k = 1;
            printf("Search Successful\n");
            break;
        }
    }
    if (k != 1)
        printf("Search Unsuccessful\n");

    fclose(file);
}

void display(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    struct Element element;
    printf("Periodic Table\n");
    printf("--------------------------------------------------\n");
    printf("| %-3s | %-2s | %-20s | %-10s |\n", "No.", "Sym", "Name", "Mass");
    printf("--------------------------------------------------\n");

    while (fscanf(file, "%d %2s %19s %f", &element.enumber, element.esymbol, element.ename, &element.emass) == 4)
    {
        printf("| %-3d | %-2s | %-20s | %-10.3f |\n", element.enumber, element.esymbol, element.ename, element.emass);
    }
    printf("--------------------------------------------------\n");
    fclose(file);
}
