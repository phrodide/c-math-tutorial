#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Level0(FILE *fp, int count);
void Level0_1(FILE *fp, int count);

// Start with void and don't pull argc/argv yet from the command line.
int main(void)
{
    FILE *md_file = fopen("result.md", "w");
    if (md_file == NULL)
        return 1;
    srand(time(0));
    fprintf(md_file, "# Multiplication\n\n");
    Level0(md_file, 25);
    fclose(md_file);
}

// Multiplication problems. Randomly done.
void Level0(FILE *fp, int count)
{
    for (int i = 0; i < count; i++)
    {
        int first = (rand() % 12) + 1;
        int second = (rand() % 12) + 1;

        // New line. 5 problems per line.
        if ((i % 5) == 0 && i != 0)
        {
            fprintf(fp, "\n&nbsp;\n\n&nbsp;\n");
        }

        fprintf(fp, "$\\begin{array}{r}\n%3d \\\\\n\\times %3d \\\\\n\\hline\n\\end{array}$ &nbsp; &nbsp;\n", first, second);
    }
}

void Level0_1(FILE *fp, int count)
{
}