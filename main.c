
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define ON 1
#define OFF 0
#define LOCKED 1
#define UNLOCKED 0
#define MOTION_DETECTED 1
#define NO_MOTION 0

typedef struct {
    int light;
    int temp;
    int motion;
    int security;
} Room;

void initializeSystem(Room rooms[], int count);
void displayMenu();
void toggleLight(Room rooms[], int count);
void readTemperature(Room rooms[], int count);
void simulateMotion(Room rooms[], int count);
void toggleSecurity(Room rooms[], int count);
void houseStatus(Room rooms[], int count);

int main() {
    int roomCount;

    printf("Enter number of rooms (1 to %d): ", MAX_ROOMS);
    scanf("%d", &roomCount);

    if (roomCount < 1 || roomCount > MAX_ROOMS) {
        printf("PLEASE ENTER A VALID NUMBER !!\n");
        return 1;
    }

    Room rooms[MAX_ROOMS];
    srand(time(0));
    initializeSystem(rooms, roomCount);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleLight(rooms, roomCount);
                break;
            case 2:
                readTemperature(rooms, roomCount);
                break;
            case 3:
                simulateMotion(rooms, roomCount);
                break;
            case 4:
                toggleSecurity(rooms, roomCount);
                break;
            case 5:
                houseStatus(rooms, roomCount);
                break;
            case 6:
                printf("EXITING SMART HOME SYSTEM. GOODBYE!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void initializeSystem(Room rooms[], int count) {
    for (int i = 0; i < count; i++) {
        rooms[i].light = OFF;
        rooms[i].temp = 18 + rand() % 10; // Random temp between 18-27°C
        rooms[i].motion = NO_MOTION;
        rooms[i].security = UNLOCKED;
    }
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Simulate Motion Detection\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
    printf("===========================\n");
}

int getRoomNumber(int count) {
    int room;
    printf("Enter room number (1-%d): ", count);
    scanf("%d", &room);
    if (room < 1 || room > count) {
        printf("PLEASE ENTER A VALID ROOM NUMBER !!\n");
        return -1;
    }
    return room - 1;
}

void toggleLight(Room rooms[], int count) {
    int room = getRoomNumber(count);
    if (room == -1) return;

    rooms[room].light = !rooms[room].light;
    printf("LIGHT IN ROOM %d IS NOW %s\n", room + 1, rooms[room].light ? "ON" : "OFF");
}

void readTemperature(Room rooms[], int count) {
    int room = getRoomNumber(count);
    if (room == -1) return;

    printf("TEMPERATURE OF ROOM %d IS %d°C\n", room + 1, rooms[room].temp);
}

void simulateMotion(Room rooms[], int count) {
    int room = getRoomNumber(count);
    if (room == -1) return;

    rooms[room].motion = !rooms[room].motion;
    printf("MOTION IN ROOM %d: %s\n", room + 1, rooms[room].motion ? "DETECTED" : "NOT DETECTED");
}

void toggleSecurity(Room rooms[], int count) {
    int room = getRoomNumber(count);
    if (room == -1) return;

    rooms[room].security = !rooms[room].security;
    printf("SECURITY IN ROOM %d IS NOW %s\n", room + 1, rooms[room].security ? "LOCKED" : "UNLOCKED");
}

void houseStatus(Room rooms[], int count) {
    printf("\n===== HOUSE STATUS =====\n");
    for (int i = 0; i < count; i++) {
        printf("ROOM %d --> ", i + 1);
        printf("Light: %s | ", rooms[i].light ? "ON" : "OFF");
        printf("Temp: %d°C | ", rooms[i].temp);
        printf("Motion: %s | ", rooms[i].motion ? "Detected" : "None");
        printf("Security: %s\n", rooms[i].security ? "Locked" : "Unlocked");
    }
    printf("\n");
}
