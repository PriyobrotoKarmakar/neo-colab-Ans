#include <iostream>

template <size_t N>
int calculateCompatibilityScore(const int (&profile1)[N], const int (&profile2)[N]) {
    int compatibilityScore = 0;

    // Compare corresponding attributes of both profiles
    for (size_t i = 0; i < N; ++i) {
        if (profile1[i] == profile2[i]) {
            compatibilityScore += 10;
        }
    }

    return compatibilityScore;
}

int main() {
    int profile1[3]; 
    int profile2[3]; 

    // Read the profile attributes
    std::cin >> profile1[0] >> profile1[1] >> profile1[2];
    std::cin >> profile2[0] >> profile2[1] >> profile2[2];

    // Calculate the compatibility score
    int compatibilityScore = calculateCompatibilityScore(profile1, profile2);

    // Output the result
    std::cout << "Compatibility Score: " << compatibilityScore << std::endl;

    return 0;
}
