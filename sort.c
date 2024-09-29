#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_list(int list[], int size) {
    printf("<-");
    for(int i = 0; i < size; i++) {
        printf("%i-", list[i]);
    }
    printf(">end\n\n");
}

void merge_sort(int list[], int from, int to) {
    if(from < to) {
        int mid = ((from + to) / 2);
        merge_sort(list, from, mid);
        merge_sort(list, mid + 1, to);    

        int left_len = mid - from + 1;
        int right_len = to - mid; 
        int left[left_len];
        int right[right_len];

        int temp = from;
        for(int i = 0; i < (mid-from+1); i++) {
            left[i] = list[temp];
            temp++;
        }

        temp = mid + 1;
        for(int i = 0; i < (to-mid); i++) {
            right[i] = list[temp];
            temp++;
        }

        int lx = 0;
        int rx = 0;

        for(int i = from; i < to + 1; i++) {

            if((left[lx] > right[rx])) {
                if(rx < right_len) {
                    list[i] = right[rx];
                    rx++;    
                } else {
                    list[i] = left[lx];
                    lx++;
                }
            } else if(left[lx] < right[rx]) {
                if(lx < left_len) {
                    list[i] = left[lx];
                    lx++;
                } else {
                    list[i] = right[rx];
                    rx++;
                }
            }
        }
        //print_list(list, 10);
    } else { return; }
}

void randomize(int list[], int size) {
    int temp;
    int random;
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        temp = list[i];
        random = rand() % size;
        list[i] = list[random];
        list[random] = temp;

    }
}

int main(void) {

    int list[] = {9,3,8,7,4,6,5,1,0,2,22,34,99,56,43,21,11,54};
    int size = (sizeof(list) / sizeof(list[0])) - 1;
    
    randomize(list, size);

    print_list(list, size);

    merge_sort(list, 0, size);

    print_list(list, size);

}