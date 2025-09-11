#include <iostream>
#include <sstream>
#include <vector>

// We use radix sort to sort IP addresses.
// IPs are stored as strings (e.g., "192.168.0.1") because they're easier for humans to read.
// Internally, the computer converts each part into numbers.
// Example:
// "192.168.0.1" → {192, 168, 0, 1} → stored as 4 bytes in memory.
// Each part (192, 168, etc.) is 1 byte (8 bits), ranging from 0 to 255.

std::vector<int> parseIps(const std::string &ip) {
    std::stringstream ss(ip); // Used to split the IP string
    std::vector<int> parts;   // To store the 4 integer parts of the IP

    std::string segment;
    while (std::getline(ss, segment, '.')) {
        // Convert each string segment to an integer
        parts.push_back(std::stoi(segment));
    }

    return parts;
}

void countingSort(std::vector<std::pair<std::string, std::vector<int>>> &arr, int pos) {
    // Each IP block ranges from 0–255 (8-bit), so we need 256 buckets
    const int range = 256;
    int n = arr.size();

    std::vector<int> count(range, 0);
    std::vector<std::pair<std::string, std::vector<int>>> output(n);

    // Count frequency of the key at position 'pos'
    for (int i = 0; i < n; i++) {
        count[arr[i].second[pos]]++;
    }

    // Compute prefix sums
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array in stable order
    for (int i = n - 1; i >= 0; i--) {
        int key = arr[i].second[pos];
        output[count[key] - 1] = arr[i];
        count[key]--;
    }

    arr = output;
}

void radixSortByIpAddress(std::vector<std::string> &ips) {
    // Store each IP as a pair: {original_string, parsed_vector}
    std::vector<std::pair<std::string, std::vector<int>>> data;

    for (const std::string &ip : ips) {
        data.emplace_back(ip, parseIps(ip));
    }

    // Perform radix sort from the least significant part (D) to the most (A)
    for (int pos = 3; pos >= 0; pos--) {
        countingSort(data, pos);
    }

    // Extract the sorted IP strings back into the original vector
    for (int i = 0; i < ips.size(); i++) {
        ips[i] = data[i].first;
    }
}

int main() {
    std::vector<std::string> ips = {
        "192.168.0.1",
        "10.0.0.2",
        "172.16.0.1",
        "192.168.0.5",
        "10.0.0.1",
        "172.16.0.2"
    };

    radixSortByIpAddress(ips);

    for (const std::string &ip : ips) {
        std::cout << ip << '\n';
    }

    return 0;
}
