#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define HELP_MSG    " Usage: wc+ [OPTION]... [FILE]...\n Syntax: wc+ [ -c | -m | -w | -l] [file .]\n" \
                    " Print newline, word, and byte counts for FILE. A word is a non-zero-length sequence of\n" \
                    "characters delimited by white space.\n\n The options below may be used to " \
                    "select which counts are printed, always in\n" \
                    "the following order: newline, word, character, byte, maximum line length.\n" \
                    "  -c, --bytes            print the byte counts\n" \
                    "  -m, --chars            print the character counts\n" \
                    "  -w, --words            print the word counts\n" \
                    "  -l, --lines            print the newline counts\n" \
                    "  --h, --help            display this help and exit\n\n" \
                    "If no option is specified the default is [-l -w -c] (count lines, words, and bytes).\n"

struct Tuple {
    bool enable;
    long int count;
};

struct FileCounter {
    struct Tuple bytes, words, lines;
};

long int fileSize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    return ftell(file);
}

void calculateFile(FILE *file, struct FileCounter *fileCounter) {

    if (fileCounter->bytes.enable && !fileCounter->words.enable && !fileCounter->lines.enable) {
        fileCounter->bytes.count = fileSize(file);
        return;
    }

    char buffer, prevChar = '\0';
    bool word = false, newWord = false;

    while ((buffer = fgetc(file)) != EOF) {
        fileCounter->bytes.count++;

        if ((buffer == ' ' || buffer == '\t') && (prevChar != ' ' && prevChar != '\t' && prevChar != '\0'))
            newWord = true, word = true;
        else if (buffer == '\n') {
            fileCounter->lines.count++;
            if (prevChar != '\n' && prevChar != '\0')
                newWord = true, word = true;
        } else if (newWord) {
            fileCounter->words.count++;
            newWord = false;
        }
        prevChar = buffer;
    }
    if (word) // Add last word
        fileCounter->words.count++;
    #ifdef _WIN32
        fileCounter->bytes.count += fileCounter->lines.count; // '\n' = two byte in Windows
    #endif

}

void printResult(const struct FileCounter *fileCounter, char *fileName) {

    printf("  ");
    if (fileCounter->lines.enable)
        printf("%ld ", fileCounter->lines.count);
    if (fileCounter->words.enable)
        printf("%ld ", fileCounter->words.count);
    if (fileCounter->bytes.enable)
        printf("%ld ", fileCounter->bytes.count);

    printf("%s\n", fileName);
}

int main(int argc, char *argv[]) {

    if (strcmp(argv[argc - 1], "--h") == 0 || strcmp(argv[argc - 1], "--help") == 0) {
        printf("%s",HELP_MSG);
        return 0;
    }

    if (argc <= 1 || (argc > 1 && argv[argc - 1][0] == '-')) {
        printf("wc+: filename not found\nTry \'wc+ --help\' for more information.\n");
        return 0;
    }

    struct FileCounter fileCounter = {{false, 0}, {false, 0}, {false, 0}};

    if (argc == 2)
        fileCounter.bytes.enable = true, fileCounter.words.enable = true, fileCounter.lines.enable = true;
    else {
        for (int i = 1; i < argc - 1; i++) {
            if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--bytes") == 0 ||
                strcmp(argv[i], "--chars") == 0)
                fileCounter.bytes.enable = true;
            else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0)
                fileCounter.words.enable = true;
            else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0)
                fileCounter.lines.enable = true;
            else if (strcmp(argv[i], "--h") == 0 || strcmp(argv[i], "--help") == 0) {
                printf("%s",HELP_MSG);
                return 0;
            }
            else {
                printf("wc+: unknown option %s\nTry \'wc+ --help\' for more information.\n", argv[i]);
                return 0;
            }
        }
    }

    FILE *file = fopen(argv[argc - 1], "r");

    if (file == 0) {
        printf("wc+: %s: No such file\n", argv[argc - 1]);
        return 0;
    }

    calculateFile(file, &fileCounter);

    printResult(&fileCounter, argv[argc - 1]);

    fclose(file);

    return 0;
}
