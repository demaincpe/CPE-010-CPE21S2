#include <iostream>
#include <string>
#include "playlist.h"

void printMenu() {
    std::cout << "\n========== PLAYLIST MENU ==========\n";
    std::cout << "[1] Display Playlist\n";
    std::cout << "[2] Play All Songs\n";
    std::cout << "[3] Next Song\n";
    std::cout << "[4] Previous Song\n";
    std::cout << "[5] Insert Song\n";
    std::cout << "[6] Remove Song\n";
    std::cout << "[0] Exit\n";
    std::cout << "Enter Choice: ";
}

int main() {
    SongNode<std::string>* playlist = nullptr;
    SongNode<std::string>* currentTrack = nullptr;

    // Optional: Pre-populate with a few initial songs
    addSong(std::string("Through the Years"), std::string("Kenny Rogers"), &playlist);
    addSong(std::string("Am I Wrong"), std::string("Nico & Vinz"), &playlist);
    addSong(std::string("Way Back Home"), std::string("SHAUN"), &playlist);
    
    currentTrack = playlist; // Set pointer to start of playlist

    int choice = -1;

    while (choice != 0) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character left by std::cin

        std::cout << "\n";

        switch (choice) {
            case 1:
                displayPlaylist(playlist);
                break;

            case 2:
                playAllSongs(playlist);
                break;

            case 3:
                if (currentTrack != nullptr) {
                    nextTrack(&currentTrack);
                } else {
                    std::cout << "Playlist is empty.\n";
                }
                break;

            case 4:
                if (currentTrack != nullptr) {
                    prevTrack(&currentTrack);
                } else {
                    std::cout << "Playlist is empty.\n";
                }
                break;

            case 5: {
                std::string title, artist;
                std::cout << "Enter Song Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Artist Name: ";
                std::getline(std::cin, artist);

                addSong(title, artist, &playlist);
                
                // If this is the first song added, initialize currentTrack pointer
                if (currentTrack == nullptr) {
                    currentTrack = playlist;
                }
                
                std::cout << "Added \"" << title << "\" to the playlist.\n";
                break;
            }

            case 6: {
                if (playlist == nullptr) {
                    std::cout << "Playlist is empty. Nothing to remove.\n";
                    break;
                }

                std::string title;
                std::cout << "Enter Song Title to Remove: ";
                std::getline(std::cin, title);

                // Adjust currentTrack pointer if deleting the active track
                if (currentTrack != nullptr && currentTrack->title == title) {
                    currentTrack = currentTrack->next;
                }

                deleteSong(title, &playlist);

                // If playlist becomes completely empty after deletion
                if (playlist == nullptr) {
                    currentTrack = nullptr;
                }
                break;
            }

            case 0:
                std::cout << "Exiting playlist application. Cleaning memory...\n";
                deletePlaylist(&playlist);
                currentTrack = nullptr;
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}