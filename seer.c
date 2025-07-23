#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define NUM_QUESTIONS 3

// Struct to represent a question
typedef struct {
    char text[300];
    char options[4][100];
    char traits[4][20];
} Question;

// Struct to hold trait scores
typedef struct {
    int extrovert;
    int introvert;
    int thinker;
    int creative;
} Traits;

// Function prototypes
char ask_question(Question q);
void update_scores(Traits *t, const char *trait);
void print_result(const char *name, Traits t);
void save_result(const char *name, Traits t, const char choices[]);

int main() {
    char name[MAX_NAME_LEN];
    char choices[NUM_QUESTIONS];
    Traits t = {0, 0, 0, 0};

    Question questions[NUM_QUESTIONS] = {
        {
            "Choose a number:",
            {"3", "7", "9", "11"},
            {"extrovert", "thinker", "creative", "introvert"}
        },
        {
            "Pick a place:",
            {"Beach", "Forest", "City", "Mountains"},
            {"extrovert", "introvert", "creative", "thinker"}
        },
        {
            "Pick one:",
            {"Fight a horse-sized duck", "Fight 100 duck-sized horses", "Be invisible in school", "Wake up with duck voice"},
            {"creative", "thinker", "introvert", "extrovert"}
        }
    };

    printf("Welcome to the CLI Personality Analyzer!\n\n");
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        choices[i] = ask_question(questions[i]);
        int idx = choices[i] - 'a';
        update_scores(&t, questions[i].traits[idx]);
    }

    print_result(name, t);
    save_result(name, t, choices);

    return 0;
}

char ask_question(Question q) {
    char answer;
    while (1) {
        printf("\n%s\n", q.text);
        for (int i = 0; i < 4; i++) {
            printf("  %c - %s\n", 'a' + i, q.options[i]);
        }
        printf("Enter your choice: ");
        scanf(" %c", &answer);

        if (answer >= 'a' && answer <= 'd') {
            return answer;
        } else {
            printf("Invalid input. Please choose a, b, c, or d.\n");
        }
    }
}

void update_scores(Traits *t, const char *trait) {
    if (strcmp(trait, "extrovert") == 0) t->extrovert++;
    else if (strcmp(trait, "introvert") == 0) t->introvert++;
    else if (strcmp(trait, "thinker") == 0) t->thinker++;
    else if (strcmp(trait, "creative") == 0) t->creative++;
}

void print_result(const char *name, Traits t) {
    printf("\n\nAnalyzing your personality, %s...\n", name);

    if (t.extrovert >= 2) printf("You are an Extrovert! Energetic and outgoing.\n");
    else if (t.introvert >= 2) printf("You are an Introvert! Reflective and thoughtful.\n");
    else if (t.thinker >= 2) printf("You are a Thinker! Logical and curious.\n");
    else if (t.creative >= 2) printf("You are Creative! Imaginative and expressive.\n");
    else printf("You are a balanced individual with diverse traits.\n");
}

void save_result(const char *name, Traits t, const char choices[]) {
    FILE *file = fopen("results.txt", "a");
    if (!file) {
        perror("Could not open results.txt");
        return;
    }

    time_t now = time(NULL);
    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Choices: %c %c %c\n", choices[0], choices[1], choices[2]);
    fprintf(file, "Result: ");

    if (t.extrovert >= 2) fprintf(file, "Extrovert\n");
    else if (t.introvert >= 2) fprintf(file, "Introvert\n");
    else if (t.thinker >= 2) fprintf(file, "Thinker\n");
    else if (t.creative >= 2) fprintf(file, "Creative\n");
    else fprintf(file, "Balanced\n");

    fprintf(file, "Timestamp: %s\n\n", ctime(&now));
    fclose(file);
}
