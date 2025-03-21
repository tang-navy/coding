#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LOCATIONS 100
#define MAX_PACKAGES 1000

typedef struct {
    char location[10];
    int weight;
} Package;

typedef struct {
    char from[10];
    char to[10];
    int distance;
} Edge;

extern int num_locations;
extern int num_packages;
extern Package packages[MAX_PACKAGES];
extern Edge edges[MAX_LOCATIONS * MAX_LOCATIONS];
extern int graph[MAX_LOCATIONS][MAX_LOCATIONS];
extern char location_names[MAX_LOCATIONS][10];

void read_packages(const char *filename);
void read_map(const char *filename);
void compute_shortest_paths();
void plan_delivery(int start_index, int max_load);
int find_location_index(const char *location);

#endif // LIST_H