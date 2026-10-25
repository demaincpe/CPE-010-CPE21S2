// binarySearch in searching.h for Table 6-3a
template <typename T>
void binarySearch(int size, T dataFind, T array[]) {
    int low = 0;
    int up = size - 1;

    while (low <= up) {
        int mid = (low + up) / 2;

        if (array[mid] == dataFind) {
            std::cout << "Search element is found!\n";
            return;
        } else if (dataFind < array[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << "Search element is not found\n";
}