#ifndef PLAYLIST_H
#define PLAYLIST_H

// Node template for a song item in the playlist
template <typename T>
class SongNode {
public:
    T title;
    T artist;
    SongNode<T>* next = nullptr;
    SongNode<T>* prev = nullptr;
};

// Helper function to create a new song node dynamically
template <typename T>
SongNode<T>* createSongNode(T songTitle, T songArtist) {
    SongNode<T>* newNode = new SongNode<T>();
    newNode->title = songTitle;
    newNode->artist = songArtist;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to display playlist items
template <typename T>
void displayPlaylist(SongNode<T>* head) {
    if (head == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    SongNode<T>* current = head;
    std::cout << "Playlist:\n";
    do {
        std::cout << current->title << "\n";
        current = current->next;
    } while (current != head);
}

// Traverse and play all songs ONCE in a loop (as requested)
template <typename T>
void playAllSongs(SongNode<T>* head) {
    if (head == nullptr) {
        std::cout << "The playlist is empty.\n";
        return;
    }

    SongNode<T>* current = head;
    std::cout << "Playing All Songs (Circular Loop)\n";
    do {
        std::cout << "Playing: \"" << current->title << "\" by " << current->artist << "\n";
        current = current->next;
    } while (current != head); // Stops after completing one full circle
    std::cout << "\n=========================================\n";
}

// Add a song to the end (maintaining circular links)
template <typename T>
void addSong(T title, T artist, SongNode<T>** head) {
    SongNode<T>* newNode = createSongNode(title, artist);

    // If playlist is empty
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
        return;
    }

    // Get the tail node (which is head's prev in a circular list)
    SongNode<T>* tail = (*head)->prev;

    // Connect new node between tail and head
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Move to next track
template <typename T>
void nextTrack(SongNode<T>** current) {
    if (*current != nullptr) {
        *current = (*current)->next;
        std::cout << ">> Next Track: \"" << (*current)->title << "\" by " << (*current)->artist << "\n";
    }
}

// Move to previous track
template <typename T>
void prevTrack(SongNode<T>** current) {
    if (*current != nullptr) {
        *current = (*current)->prev;
        std::cout << "<< Previous Track: \"" << (*current)->title << "\" by " << (*current)->artist << "\n";
    }
}

// Delete a song by title in circular list
template <typename T>
void deleteSong(T title, SongNode<T>** head) {
    if (*head == nullptr) return;

    SongNode<T>* current = *head;
    bool found = false;

    // Search circular list
    do {
        if (current->title == title) {
            found = true;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (!found) {
        std::cout << "Song \"" << title << "\" not found in playlist.\n";
        return;
    }

    // Case 1: Only 1 song in list
    if (current->next == current) {
        delete current;
        *head = nullptr;
        std::cout << "Successfully deleted \"" << title << "\". Playlist is now empty.\n";
        return;
    }

    // Case 2: Deleting head node
    if (current == *head) {
        *head = current->next;
    }

    // Fix surrounding circular pointers
    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    std::cout << "Successfully deleted \"" << title << "\" from the playlist.\n";
}

// Deallocate circular playlist
template <typename T>
void deletePlaylist(SongNode<T>** head) {
    if (*head == nullptr) return;

    SongNode<T>* current = *head;
    // Break circular connection first to prevent infinite loop during deletion
    (*head)->prev->next = nullptr; 

    while (current != nullptr) {
        SongNode<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
    std::cout << "All songs cleared from playlist.\n";
}
#endif