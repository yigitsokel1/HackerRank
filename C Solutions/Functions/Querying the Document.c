#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    char ****res;
    char *token = strtok(text, "\n");
    int para_count = 0;
    char para_list[MAX_PARAGRAPHS][MAX_CHARACTERS];
    
    while(token != NULL) {
        strcpy(para_list[para_count], token);
        para_count++;
        token = strtok(NULL, "\n");
    }
    res = (char ****)malloc(para_count * sizeof(char***));
    
    for(int i = 0; i < para_count; i++) {
        char ***para;
        
        token = strtok(para_list[i], ".");
        int sen_count = 0;
        char sen_list[1000][MAX_CHARACTERS];
        
        while(token != NULL) {
            strcpy(sen_list[sen_count], token);
            sen_count++;
            token = strtok(NULL, ".");
        }
        
        para = (char ***)malloc(sen_count * sizeof(char**));
        res[i] = para;
        
        for(int j = 0; j < sen_count; j++) {
            char **sen;
            
            token = strtok(sen_list[j], " ");
            int word_count = 0;
            char word_list[1000][MAX_CHARACTERS];
            
            while(token != NULL) {
                
                strcpy(word_list[word_count], token);
                word_count++;
                token = strtok(NULL, " ");
            }
            
            sen = (char **)malloc(word_count * sizeof(char *));
            res[i][j] = sen;
            
            for(int k = 0; k < word_count; k++) {
                char *word = (char*)malloc(MAX_CHARACTERS * sizeof(char));
                strcpy(word, word_list[k]);
                res[i][j][k] = word;
            }
        }
        
    }
    
    
    return res;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
