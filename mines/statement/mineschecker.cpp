#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cctype>

#define MAXH 600
#define MAXW 600

void ERR(const char *s, ...) {
    printf("Error: ");
    va_list ap;
    va_start(ap, s);
    vprintf(s, ap);
    va_end(ap);
    printf("\n");
    exit(0);
}

bool empty(const char *s) {
    while (isspace(*s))
        ++s;
    return (*s == 0);
}

int h, w;
int a1[MAXH][MAXW], a2[MAXH][MAXW];
char s[MAXW+100];

char count(int i, int j) {
    int s = 0;
    for (int di = -1; di <= 1; ++di)
        for (int dj = -1; dj <= 1; ++dj)
            if (i + di >= 0 && i + di <= h - 1)
                if (j + dj >= 0 && j + dj <= w - 1)
                    s += (a2[i + di][j + dj] == 'X');
    return '0' + s;
}

int main(int argc, const char *argv[]) {
    if (argc != 3)
        ERR("Usage: %s input-file output-file", argv[0]);

    FILE *in = fopen(argv[1], "rt");
    if (!in)
        ERR("Can't open the input file %s", argv[1]);
    if (fscanf(in, "%d%d ", &h, &w) != 2)
        ERR("Can't read the input file on line 1");
    if (h < 1 || h > MAXH || w < 1 || w > MAXW)
        ERR("Invalid input file line 1");
    for (int i = 0; i < h; ++i) {
        if (fgets(s, sizeof(s), in) != s)
            ERR("Unexpected end of input file on line %d", 2 + i);
        for (int j = 0; j < w; ++j) {
            if (s[j] < '0' || s[j] > '9') {
                if (empty(s + j))
                    ERR("Input file line %d too short", 2 + i);
                ERR("Invalid character on input file line %d", 2 + i);
            }
            a1[i][j] = s[j];
        }
        if (!empty(s + w))
            ERR("Input file line line %d too long", 2 + i);
    }
    if (fscanf(in, "%10s", s) > 0)
        ERR("Unexpected lines at end of input file");
    fclose(in);

    FILE *out = fopen(argv[2], "rt");
    if (!out)
        ERR("Can't open the output file %s", argv[2]);
    for (int i = 0; i < h; ++i) {
        if (fgets(s, sizeof(s), out) != s)
            ERR("Unexpected end of output file on line %d", 1 + i);
        for (int j = 0; j < w; ++j) {
            if (s[j] != 'X' && s[j] != '.') {
                if (empty(s + j))
                    ERR("Output file line %d too short", 1 + i);
                ERR("Invalid character on output file line %d", 1 + i);
            }
            a2[i][j] = s[j];
        }
        if (!empty(s + w))
            ERR("Output file line %d too long", 1 + i);
    }
    if (fscanf(out, "%10s", s) > 0)
        ERR("Unexpected lines at end of output file");

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (a1[i][j] != count(i, j))
                ERR("Wrong count on line %d, pos %d", 1 + i, 1 + j);

    puts("OK");
    return 0;
}
