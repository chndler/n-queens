#include "nqueens_library.h"
static char s[100];

int generate_n_queens_serial(int n, int out_flag){
    int i, list[n], solutions, total_permutations = 1;

    // Generate first sequence from 0 to n 
    for(i = 0; i < n; i++)
        list[i] = i;

    // If flag is set, print first permutation
    if(out_flag){
        get_array_string(list, n, s);
        printf("%s", s);
    }

    // next_permutation returns 0 on success
    // and returns 1 if no more permutations exist
    while (next_permutation(list, n)==0){
        total_permutations++;
        if(out_flag){
            get_array_string(list, n, s);
            printf("%s", s);
        }
        if(check_diagonal(list, n)){
            solutions++;
            get_array_string(list, n, s);
            printf("%s", s);
        }
    }
    printf("Total permutations:\t%-d\n", total_permutations);
    return solutions;
}

void get_array_string(int *list, int n, char *s){
    int i;
    // Clear previous s contents, if any
    memset(s, 0, strlen(s)); 
    for (i = 0; i < n; i++){    
        sprintf(s + strlen(s), "%4d", list[i]);
    }
    sprintf(s + strlen(s), "\n");
    fprintf(stdout, "%s", s);
}

int next_permutation(int *list, int n){
    int i = n - 1; 
    while (i > 0 && list[i - 1] >= list[i])
        i--;
    // i is now the head index of the suffix

    if(i <= 0) // last permutation
        return 1;

    int j = n - 1;
    while (list[j] <= list[i - 1])
        j--;
    // value list[j] will become the new pivot
    // Assertion: j >= i
    
    // Swap the pivot with j
    int tmp = list[i - 1];
    list[i - 1] = list[j];
    list[j] = tmp;

    // Reverse the suffix
    j = n - 1;
    while (i < j){
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
        i++;
        j--;
    }

    return 0;
}
   
/* check_diagonal returns 0 if false, 1 if true */
int check_diagonal(int *list, int n){
    int i, j, vert, horiz;

    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++){
            vert = abs(list[i] - list[j]);
            horiz = abs(i - j);
            if(vert == horiz)
                return 0;
        }
    }
    return 1;
}

/* generate_n_queens_serial_one performs n queens permutation
 * and diagonal checks for perms beginning with value first */
int generate_n_queens_serial_one(int n, int out_flag, int first){
    int i, j, list[n], solutions, total_permutations = 1;
    solutions = 0;

    // Fill list w/ first lexicographical permutation that
    // has 'first' in list[0]
    for(i = 0; i < n; i++)
        list[i] = i;

    if(first != 0){
        int count = 0;
        list[0] = first;
        for(i = 1; i <= first; i++){
            list[i] = count;
            count++;
        }
    }
 
    // Print first permutation
    if (out_flag){
        get_array_string(list, n, s);
    }

    // iterate through perms while list[0] == first
    while (next_permutation(list, n)==0 && list[0] == first){ 
        total_permutations++;
        if(out_flag){
            get_array_string(list, n, s);
        }       
        if(check_diagonal(list, n)){
            solutions++;
            //get_array_string(list, n, s);
        }
    }
    return solutions;
}

void *queens_thread(void *infopointer){
    thread_info_t *info = infopointer;
    int n = info->n;
    int out_flag = info->out_flag;
    int first = info->first;
    int result = generate_n_queens_serial_one(n, out_flag, first);
    info->result = result;
    
    // print value of first and number of solutions 
    // found all on one line, independent of flag
    fprintf(stdout, "First: %d  Solutions: %d\n", first, result);
    return NULL;
}
