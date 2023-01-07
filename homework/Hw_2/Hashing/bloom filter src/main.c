#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define SIZE 2000
#define ELEMENT 300
#define TIMES 10000.0

bool bitvector[SIZE] = {0};
unsigned element[ELEMENT] = {0};
unsigned lookup[ELEMENT] = {0};
unsigned false_positive[15] = {0};

unsigned  hashfunction_1(unsigned data)
{
    data ^= (data << 8);
    data ^= (data >> 7);
    data ^= (data << 5);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned  hashfunction_2(unsigned data)
{
    data ^= data >> 16;
    data *= 0x7feb352d;
    data ^= data >> 15;
    data *= 0x846ca68b;
    data ^= data >> 16;
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_3(unsigned data)
{
    data ^= (data << 2);
    data ^= (data >> 9);
    data ^= (data << 5);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_4(unsigned data)
{
    data ^= (data << 3);
    data ^= (data >> 11);
    data ^= (data << 15);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_5(unsigned data)
{
    data ^= (data << 4);
    data ^= (data >> 10);
    data ^= (data << 17);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_6(unsigned data)
{
    data ^= (data << 5);
    data ^= (data >> 13);
    data ^= (data << 23);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_7(unsigned data)
{
    data ^= (data << 6);
    data ^= (data >> 17);
    data ^= (data << 29);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_8(unsigned data)
{
    data ^= (data << 7);
    data ^= (data >> 14);
    data ^= (data << 31);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_9(unsigned data)
{
    data ^= (data << 8);
    data ^= (data >> 23);
    data ^= (data << 37);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_10(unsigned data)
{
    data ^= (data << 9);
    data ^= (data >> 27);
    data ^= (data << 41);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_11(unsigned data)
{
    data ^= (data << 10);
    data ^= (data >> 31);
    data ^= (data << 45);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_12(unsigned data)
{
    data ^= (data << 11);
    data ^= (data >> 35);
    data ^= (data << 49);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_13(unsigned data)
{
    data ^= (data << 12);
    data ^= (data >> 39);
    data ^= (data << 53);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_14(unsigned data)
{
    data ^= (data << 13);
    data ^= (data >> 43);
    data ^= (data << 57);
    unsigned index = data % SIZE;
    bitvector[index] = true;
    return index;
}

unsigned hashfunction_1_transform(unsigned data)
{
    data ^= (data << 8);
    data ^= (data >> 7);
    data ^= (data << 5);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_2_transform(unsigned data)
{
    data ^= data >> 16;
    data *= 0x7feb352d;
    data ^= data >> 15;
    data *= 0x846ca68b;
    data ^= data >> 16;
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_3_transform(unsigned data)
{
    data ^= (data << 2);
    data ^= (data >> 9);
    data ^= (data << 5);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_4_transform(unsigned data)
{
    data ^= (data << 3);
    data ^= (data >> 11);
    data ^= (data << 15);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_5_transform(unsigned data)
{
    data ^= (data << 4);
    data ^= (data >> 10);
    data ^= (data << 17);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_6_transform(unsigned data)
{
    data ^= (data << 5);
    data ^= (data >> 13);
    data ^= (data << 23);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_7_transform(unsigned data)
{
    data ^= (data << 6);
    data ^= (data >> 17);
    data ^= (data << 29);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_8_transform(unsigned data)
{
    data ^= (data << 7);
    data ^= (data >> 14);
    data ^= (data << 31);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_9_transform(unsigned data)
{
    data ^= (data << 8);
    data ^= (data >> 23);
    data ^= (data << 37);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_10_transform(unsigned data)
{
    data ^= (data << 9);
    data ^= (data >> 27);
    data ^= (data << 41);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_11_transform(unsigned data)
{
    data ^= (data << 10);
    data ^= (data >> 31);
    data ^= (data << 45);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_12_transform(unsigned data)
{
    data ^= (data << 11);
    data ^= (data >> 35);
    data ^= (data << 49);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_13_transform(unsigned data)
{
    data ^= (data << 12);
    data ^= (data >> 39);
    data ^= (data << 53);
    unsigned index = data % SIZE;
    return index;
}

unsigned hashfunction_14_transform(unsigned data)
{
    data ^= (data << 13);
    data ^= (data >> 43);
    data ^= (data << 57);
    unsigned index = data % SIZE;
    return index;
}

void  find_element_1(unsigned index,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[1]++;
        }
    }
}

void find_element_2(unsigned index,unsigned index_2,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[2]++;
        }
    }
}

void find_element_3(unsigned index,unsigned index_2,unsigned index_3,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[3]++;
        }
    }
}

void find_element_4(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[4]++;
        }
    }
}

void find_element_5(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[5]++;
        }
    }
}

void find_element_6(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[6]++;
        }
    }
}

void find_element_7(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[7]++;
        }
    }
}

void find_element_8(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned index_8,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true && bitvector[index_8] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[8]++;
        }
    }
}
void find_element_9(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned index_8,unsigned index_9,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true && bitvector[index_8] == true && bitvector[index_9] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[9]++;
        }
    }
}

void find_element_10(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned index_8,unsigned index_9,unsigned index_10,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true && bitvector[index_8] == true && bitvector[index_9] == true && bitvector[index_10] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[10]++;
        }
    }
}

void find_element_11(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned index_8,unsigned index_9,unsigned index_10,unsigned index_11,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true && bitvector[index_8] == true && bitvector[index_9] == true && bitvector[index_10] == true && bitvector[index_11] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[11]++;
        }
    }
}

void find_element_12(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned index_8,unsigned index_9,unsigned index_10,unsigned index_11,unsigned index_12,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true && bitvector[index_8] == true && bitvector[index_9] == true && bitvector[index_10] == true && bitvector[index_11] == true && bitvector[index_12] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[12]++;
        }
    }
}

void find_element_13(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned index_8,unsigned index_9,unsigned index_10,unsigned index_11,unsigned index_12,unsigned index_13,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true && bitvector[index_8] == true && bitvector[index_9] == true && bitvector[index_10] == true && bitvector[index_11] == true && bitvector[index_12] == true && bitvector[index_13] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[13]++;
        }
    }
}

void find_element_14(unsigned index,unsigned index_2,unsigned index_3,unsigned index_4,unsigned index_5,unsigned index_6,unsigned index_7,unsigned index_8,unsigned index_9,unsigned index_10,unsigned index_11,unsigned index_12,unsigned index_13,unsigned index_14,unsigned data)
{
    bool find = false;
    if(bitvector[index] == true && bitvector[index_2] == true && bitvector[index_3] == true && bitvector[index_4] == true && bitvector[index_5] == true && bitvector[index_6] == true && bitvector[index_7] == true && bitvector[index_8] == true && bitvector[index_9] == true && bitvector[index_10] == true && bitvector[index_11] == true && bitvector[index_12] == true && bitvector[index_13] == true && bitvector[index_14] == true) {
        for (int i = 0; i < ELEMENT; i++) {
            if (element[i] == data) {
                find = true;
                break;
            }
        }
        if(find == false) {
            false_positive[14]++;
        }
    }
}

int main() {
    srand(time(NULL));

    for(int i=0;i<TIMES;i++) {

        for (int j = 0; j < ELEMENT; j++) {
            element[j] =(unsigned) rand();
        }

        for (int j = 0; j < ELEMENT; j++) {
            lookup[j] =(unsigned) rand();
        }

        //one hash function
        for (int j = 0; j < ELEMENT; j++) {
            hashfunction_1(element[j]);
        }
        for (int j = 0; j < ELEMENT; j++) {
            find_element_1(hashfunction_1_transform(lookup[j]),lookup[j]);
        }

        //two hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_2(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_2(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),lookup[j]);
        }

        //three hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_3(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_3(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),lookup[j]);
        }

        //four hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_4(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_4(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),lookup[j]);
        }

        //five hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_5(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_5(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),lookup[j]);
        }

        //six hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_6(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_6(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),lookup[j]);
        }

        //seven hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_7(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_7(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),lookup[j]);
        }

        //eight hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_8(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_8(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),hashfunction_8_transform(lookup[j]),lookup[j]);
        }

        //nine hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_9(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_9(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),hashfunction_8_transform(lookup[j]),hashfunction_9_transform(lookup[j]),lookup[j]);
        }

        //ten hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_10(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_10(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),hashfunction_8_transform(lookup[j]),hashfunction_9_transform(lookup[j]),hashfunction_10_transform(lookup[j]),lookup[j]);
        }

        //eleven hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_11(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_11(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),hashfunction_8_transform(lookup[j]),hashfunction_9_transform(lookup[j]),hashfunction_10_transform(lookup[j]),hashfunction_11_transform(lookup[j]),lookup[j]);
        }

        //twelve hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_12(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_12(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),hashfunction_8_transform(lookup[j]),hashfunction_9_transform(lookup[j]),hashfunction_10_transform(lookup[j]),hashfunction_11_transform(lookup[j]),hashfunction_12_transform(lookup[j]),lookup[j]);
        }

        //thirteen hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_13(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_13(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),hashfunction_8_transform(lookup[j]),hashfunction_9_transform(lookup[j]),hashfunction_10_transform(lookup[j]),hashfunction_11_transform(lookup[j]),hashfunction_12_transform(lookup[j]),hashfunction_13_transform(lookup[j]),lookup[j]);
        }

        //fourteen hash function
        for(int j = 0; j < ELEMENT; j++) {
            hashfunction_14(element[j]);
        }
        for(int j = 0; j < ELEMENT; j++) {
            find_element_14(hashfunction_1_transform(lookup[j]),hashfunction_2_transform(lookup[j]),hashfunction_3_transform(lookup[j]),hashfunction_4_transform(lookup[j]),hashfunction_5_transform(lookup[j]),hashfunction_6_transform(lookup[j]),hashfunction_7_transform(lookup[j]),hashfunction_8_transform(lookup[j]),hashfunction_9_transform(lookup[j]),hashfunction_10_transform(lookup[j]),hashfunction_11_transform(lookup[j]),hashfunction_12_transform(lookup[j]),hashfunction_13_transform(lookup[j]),hashfunction_14_transform(lookup[j]),lookup[j]);
        }
        //reset bitvector
        for(int j=0;j<SIZE;j++){
            bitvector[j] = false;
        }
    }
    printf("\nThe size of bloom filter is %d bits\nThe number of elements is %d\n",SIZE,ELEMENT);
    printf("\nAfter %d times experiments,each experiment test %d random records\n\n",(unsigned )TIMES,ELEMENT);
    for(int i=1;i<15;i++) {
        printf("The average false positive rate tested by %d hash function(s) is : %.2lf%%\n",i,(double) false_positive[i] / ((double) ELEMENT * TIMES) * 100);
    }
    printf("\n");
    for(int i=1;i<15;i++){
        printf("%lf,", (double) false_positive[i] / ((double) ELEMENT * TIMES));
    }
    return 0;
}
