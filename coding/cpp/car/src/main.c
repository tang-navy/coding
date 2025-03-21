#include "../include/head.h"
  
int main() {
            char start_location[10] = "S1";
            int max_load = 25;
        
            read_packages("C:\\data\\userdata\\coding\\cpp\\car\\data\\package.txt");
        read_map("C:\\data\\userdata\\coding\\cpp\\car\\data\\map_data.txt");
        
            compute_shortest_paths();
        
            int start_index = find_location_index(start_location);
            if (start_index == -1) {
                printf("Error: Start location not found in map.\n");
                return EXIT_FAILURE;
            }
        
            plan_delivery(start_index, max_load);
        
            return 0;
        }