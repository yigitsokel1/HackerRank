int main()
{
    int i;
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    total_number_of_books = (int*)malloc(total_number_of_shelves*sizeof(int));
    for(i=0;i<total_number_of_shelves;i++)
        total_number_of_books[i] = 0;
        
    total_number_of_pages = (int**)malloc(total_number_of_shelves*sizeof(int*));
        
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            
            int x, y;
            scanf("%d %d", &x, &y);
            
            if(total_number_of_books[x] == 0){
                total_number_of_pages[x] = (int*)malloc(sizeof(int));
                total_number_of_pages[x][total_number_of_books[x]] = y;
                total_number_of_books[x]++;
            }else{
                total_number_of_pages[x] = (int*)realloc(total_number_of_pages[x],(total_number_of_books[x]+1)*sizeof(int));
                total_number_of_pages[x][total_number_of_books[x]] = y;
                total_number_of_books[x]++;
            }
                

