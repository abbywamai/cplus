#include <iostream>
#include <fstream>

using namespace std;

void IPv4PacketStructure() {
    cout << "IPv4 Packet Structure:\n";
     cout << "0                    1                   2                   3\n";
      cout << "0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "| Version |  IHL  |  Type of Service   |      Total Length        |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "|      Identification     | Flags    |      Fragment Offset       |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "|   Time To Live      |      Protocol       |   Header Checksum   |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "|                       Source Address                            |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "|                       Destination Address                       |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "|                 Options                  |     Padding          |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
   
}

void TCPPacketStructure() {
    cout << "TCP Packet Structure:\n";
    cout << "----------------------\n";
    cout << "|    Source Port       |\n";
    cout << "|----------------------|\n";
    cout << "|  Destination Port    |\n";
    cout << "|----------------------|\n";
    cout << "|    Sequence Number   |\n";
    cout << "|----------------------|\n";
    cout << "|    Acknowledgment Number  |\n";
    cout << "|----------------------|\n";
    cout << "| Data  |Reserved|Flags|\n";
    cout << "|----------------------|\n";
    cout << "|     Window Size      |\n";
    cout << "|----------------------|\n";
    cout << "|    Checksum          |\n";
    cout << "|----------------------|\n";
    cout << "|  Urgent Pointer      |\n";
    cout << "|----------------------|\n";
}

void writePacketStructureToFile(const string& fileName, const string& packetStructure) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << packetStructure;
        outFile.close();
        cout << "Packet structure has been written to " << fileName << " successfully.\n";
    } else {
        cerr << "Unable to open file " << fileName << " for writing.\n";
    }
}

int main() {
    int choice;
    cout << "Choose a protocol:\n";
    cout << "1. IPv4\n";
    cout << "2. TCP\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            IPv4PacketStructure();
            cout << "Do you want to save this structure to a file? (y/n): ";
            char saveChoice;
            cin >> saveChoice;
            if (saveChoice == 'y' || saveChoice == 'Y') {
                writePacketStructureToFile("ipv4_structure.txt", "IPv4 Packet Structure:\n<Structure content here>");
            }
            break;
        case 2:
            TCPPacketStructure();
            cout << "Do you want to save this structure to a file? (y/n): ";
            cin >> saveChoice;
            if (saveChoice == 'y' || saveChoice == 'Y') {
                writePacketStructureToFile("tcp_structure.txt", "TCP Packet Structure:\n<Structure content here>");
            }
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

    return 0;
}

