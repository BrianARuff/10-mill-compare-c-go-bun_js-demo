#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct album {
    int id;
    char name[20];
    char artist[20];
    int rating;
    float price;
};

float timeDiffInMilliseconds(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

struct album* make_albums(int n)
{
    struct album* albums = (struct album*)malloc(n * sizeof(struct album));
    for (int i = 0; i < n; i++) {
        albums[i].id = i;
        sprintf(albums[i].name, "album %d", i);
        sprintf(albums[i].artist, "artist %d", i);
        albums[i].rating = rand() % 10;
        albums[i].price = rand() % 100;
    }
    return albums;
}

struct album* merge_sort(struct album* albums, int n)
{
    if (n == 1) {
        return albums;
    }
    int mid = n / 2;
    struct album* left = merge_sort(albums, mid);
    struct album* right = merge_sort(albums + mid, n - mid);
    struct album* sorted = (struct album*)malloc(n * sizeof(struct album));
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid) {
        if (left[i].rating < right[j].rating) {
            sorted[k] = left[i];
            i++;
        } else {
            sorted[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < mid) {
        sorted[k] = left[i];
        i++;
        k++;
    }
    while (j < n - mid) {
        sorted[k] = right[j];
        j++;
        k++;
    }
    return sorted;
}


int main(int argc, char const *argv[])
{
    struct timeval t0;

    gettimeofday(&t0, NULL);
    
    int n = 10000000;

    struct album *albums = make_albums(n);
    
    merge_sort(albums, n);

    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (albums[i].id != 0) {
            count++;
        }
    }

    struct timeval t1;

    gettimeofday(&t1, NULL);

    printf("\nran %d times\n", count);
    
    printf("time: %fms\n\n", timeDiffInMilliseconds(t0, t1));

    return 0;
}
