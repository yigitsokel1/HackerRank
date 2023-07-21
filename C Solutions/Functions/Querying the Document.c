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

