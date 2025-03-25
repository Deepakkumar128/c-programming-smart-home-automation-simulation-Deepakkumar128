#include <stdio.h>

#define MAX_ROOMS 5  // Maximum allowed rooms

// Function prototypes
void initializeSystem(int rooms, int light[], int temp[], int motion[], int security[]);
void displayMenu();
void controlLights(int rooms, int light[]);
void readTemperature(int rooms, int temp[]);
void detectMotion(int rooms, int motion[]);
void securitySystem(int rooms, int security[]);
void analyzeHouseStatus(int rooms, int light[], int temp[], int motion[], int security[]);

int main() {
    int rooms;
    
    printf("Enter number of rooms (1-%d): ", MAX_ROOMS);
    scanf("%d", &rooms);

    if (rooms < 1 || rooms > MAX_ROOMS) {
        printf("Invalid number of rooms! Please restart the program.\n");
        return 1;
    }

    int light[MAX_ROOMS] = {0}, temp[MAX_ROOMS] = {22}, motion[MAX_ROOMS] = {0}, security[MAX_ROOMS] = {0};

    initializeSystem(rooms, light, temp, motion, security);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: controlLights(rooms, light); break;
            case 2: readTemperature(rooms, temp); break;
            case 3: detectMotion(rooms, motion); break;
            case 4: securitySystem(rooms, security); break;
            case 5: analyzeHouseStatus(rooms, light, temp, motion, security); break;
            case 6: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeSystem(int rooms, int light[], int temp[], int motion[], int security[]) {
    for (int i = 0; i < rooms; i++) {
        light[i] = 0;
        temp[i] = 22;
        motion[i] = 0;
        security[i] = 0;
    }
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Lights\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. Show House Status\n");
    printf("6. Exit\n");
}

void controlLights(int rooms, int light[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);

    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }

    light[room - 1] = !light[room - 1];
    printf("Room %d lights are now %s.\n", room, light[room - 1] ? "ON" : "OFF");
}

void readTemperature(int rooms, int temp[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);

    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }

    printf("Room %d temperature: %d°C\n", room, temp[room - 1]);
}

void detectMotion(int rooms, int motion[]) {
    int room;
    printf("Enter room number to check motion (1-%d): ", rooms);
    scanf("%d", &room);

    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }

    motion[room - 1] = !motion[room - 1];
    printf("Room %d motion is now %s.\n", room, motion[room - 1] ? "DETECTED" : "NOT DETECTED");
}

void securitySystem(int rooms, int security[]) {
    int room;
    printf("Enter room number to lock/unlock security (1-%d): ", rooms);
    scanf("%d", &room);

    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }

    security[room - 1] = !security[room - 1];
    printf("Room %d security is now %s.\n", room, security[room - 1] ? "LOCKED" : "UNLOCKED");
}

void analyzeHouseStatus(int rooms, int light[], int temp[], int motion[], int security[]) {
    printf("\n===== House Status Summary =====\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d | Light: %s | Temp: %d°C | Motion: %s | Security: %s\n",
               i + 1,
               light[i] ? "ON" : "OFF",
               temp[i],
               motion[i] ? "DETECTED" : "NOT DETECTED",
               security[i] ? "LOCKED" : "UNLOCKED");
    }
}
