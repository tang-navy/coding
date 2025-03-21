#include "../include/head.h"


int num_locations = 0;
int num_packages = 0;
Package packages[MAX_PACKAGES];
Edge edges[MAX_LOCATIONS * MAX_LOCATIONS];
int graph[MAX_LOCATIONS][MAX_LOCATIONS];
char location_names[MAX_LOCATIONS][10];

int find_location_index(const char *location) {
    for (int i = 0; i < num_locations; i++) {
        if (strcmp(location_names[i], location) == 0) {
            return i;
        }
    }
    return -1;
}

void read_packages(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open package data file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%[^,],%dkg\n", packages[num_packages].location, &packages[num_packages].weight) == 2) {
        num_packages++;
    }

    fclose(file);
}

void read_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_LOCATIONS; i++) {
        for (int j = 0; j < MAX_LOCATIONS; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    while (fscanf(file, "%[^,],%[^,],%d\n", edges[num_locations].from, edges[num_locations].to, &edges[num_locations].distance) == 3) {
        int from_idx = -1, to_idx = -1;

        for (int i = 0; i < num_locations; i++) {
            if (strcmp(location_names[i], edges[num_locations].from) == 0) {
                from_idx = i;
            }
            if (strcmp(location_names[i], edges[num_locations].to) == 0) {
                to_idx = i;
            }
        }

        if (from_idx == -1) {
            strcpy(location_names[num_locations], edges[num_locations].from);
            from_idx = num_locations++;
        }
        if (to_idx == -1) {
            strcpy(location_names[num_locations], edges[num_locations].to);
            to_idx = num_locations++;
        }

        graph[from_idx][to_idx] = edges[num_locations - 1].distance;
        graph[to_idx][from_idx] = edges[num_locations - 1].distance;
    }

    fclose(file);
}

void compute_shortest_paths() {
    for (int k = 0; k < num_locations; k++) {
        for (int i = 0; i < num_locations; i++) {
            for (int j = 0; j < num_locations; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void plan_delivery(int start_index, int max_load) {
    int total_distance = 0;
    int current_load = 0;
    int current_location = start_index;

    // 用于存储当前行程的包裹
    Package current_trip[MAX_PACKAGES];
    int trip_count = 0;

    // 遍历所有包裹，规划每次行程
    for (int i = 0; i < num_packages; i++) {
        if (current_load + packages[i].weight <= max_load) {
            // 如果当前包裹可以加入当前行程
            current_trip[trip_count++] = packages[i];
            current_load += packages[i].weight;
        } else {
            // 当前行程已满，开始新的行程
            if (trip_count > 0) {
                // 计算当前行程的总距离
                for (int j = 0; j < trip_count; j++) {
                    int package_index = find_location_index(current_trip[j].location);
                    total_distance += graph[current_location][package_index];
                    current_location = package_index;
                    printf("Delivering to %s, distance: %d, current load: %d\n", location_names[package_index], graph[current_location][package_index], current_load);
                }

                // 返回起点
                total_distance += graph[current_location][start_index];
                printf("Returning to start from %s, distance: %d\n", location_names[current_location], graph[current_location][start_index]);
                current_location = start_index;
                current_load = 0;
                trip_count = 0;
            }

            // 将当前包裹加入新的行程
            current_trip[trip_count++] = packages[i];
            current_load += packages[i].weight;
        }
    }

    // 处理最后一个行程
    if (trip_count > 0) {
        for (int j = 0; j < trip_count; j++) {
            int package_index = find_location_index(current_trip[j].location);
            total_distance += graph[current_location][package_index];
            current_location = package_index;
            printf("Delivering to %s, distance: %d, current load: %d\n", location_names[package_index], graph[current_location][package_index], current_load);
        }

        // 返回起点
        total_distance += graph[current_location][start_index];
        printf("Returning to start from %s, distance: %d\n", location_names[current_location], graph[current_location][start_index]);
    }

    printf("Total distance traveled: %d\n", total_distance);
}