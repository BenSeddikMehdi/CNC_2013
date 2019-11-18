//
// Created by HP-EliteBook on 11/18/2019.
//

#ifndef CNC_2013_FIRST_PROBLEM_H
#define CNC_2013_FIRST_PROBLEM_H

#include <string.h>


/*************/
#define Na 5
char tKeyWords[Na][80] = {"if","else","for","int","void"};

/* Question A-1 */
/****************/
int comment(char instr[]){
    unsigned int n = strlen(instr);
    if (instr[0]=='/' && instr[1] == '*' && instr[n-2] == '*' && instr[n-1] == '/'){
        return 1;
    }
    return 0;
}

/* Question A-2 */
/****************/
void deleteSpaces(char instr[]){
    unsigned int n = strlen(instr);
    int j = 0;
    for (unsigned int i = 0; i < n; ++i) {
        if (instr[i] == ' '){
            continue;
        } else{
            instr[j] = instr[i];
            j++;
        }
    }
    instr[j] = '\0';
}

/* Question B-1 */
/****************/
int keyWord(char word[]){
    for (int i = 0; i < Na; ++i) {
        if(strcmp(word,tKeyWords[i]) == 0)
            return 1;
    }
    return 0;
}

/* Question B-2 */
/****************/
int identifier(char id[]){
    char noSpace[80] = "";
    strcpy(noSpace,id);
    deleteSpaces(noSpace);
    unsigned int nId = strlen(id);
    if (nId >= 80 || strcmp(id,noSpace) != 0 || keyWord(id) != 0)
        return 0;
    for (int i = 0; i < 10; ++i) {
        if (id[0] == i + 48)
            return 0;
    }
    return 1;
}

/* Question C-1 */
/****************/
FILE *pFile;

int instructionAnalyzer(char instr[]){
    char keyWord[80] = "", test[80] = "";
    pFile = fopen("fKeyWords.txt","r");
    unsigned int k = 0;
    if ((instr[strlen(instr)-1] != ';') || comment(instr) == 1){
        return 0;
    }
    for (k = 0; k < strlen(instr); ++k) {
        if (instr[k] == ' '){
            break;
        }
        test[k] = instr[k];
    }
    test[k] = '\n';
    //printf("test = %s", test);
    int j = 0, a = 2;
    for (int i = 0; i < Na; ++i) {
        fgets(keyWord, 80, pFile);
        if (strcmp(keyWord,test) == 0){
            //printf("keyWord = %s", keyWord);
            return 1;
        }
    }
    fclose(pFile);
    return 0;
}

/* Question C-2 */
/****************/
FILE *plFile;

void sourceAnalyzer(char source[]){
    plFile = fopen(source,"r");
    char instr[80] = "";
    int j = 0, a = 0;
    for (int i = 1; i <= Na+1; ++i) {
        fgets(instr, 80, plFile);
        for (int k = 0; instr[k] != '\0'; ++k) {
            if (instr[k] == '\n'){
                instr[k] = '\0';
                break;
            }
        }
        if (instructionAnalyzer(instr) == 0){
            printf("%d ", i);
            j++;
        }
    }
    if (j == 0)
        printf("success");
}

#endif //CNC_2013_FIRST_PROBLEM_H
