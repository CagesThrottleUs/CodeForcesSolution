#include <algorithm>
#include <iostream>
#include <limits>

/**
 * Represents available resources for making toasts
 */
struct AvailableResources
{
    int friends;
    int drink_ml;
    int lime_slices;
    int salt_grams;
};

/**
 * Represents resource requirements per friend per toast
 */
struct ResourceRequirements
{
    int drink_per_friend;
    int salt_per_friend;
    // Note: Each friend needs exactly 1 lime slice per toast
};

/**
 * Calculates the maximum number of toasts possible given available resources
 * @param resources Available resources (friends, drink, limes, salt)
 * @param requirements Resource requirements per friend per toast
 * @return Maximum number of toasts possible
 */
auto calculate_max_toasts(const AvailableResources &resources, const ResourceRequirements &requirements) -> int
{
    // Resources needed for one complete toast (all friends)
    const int drink_per_toast = requirements.drink_per_friend * resources.friends;
    const int slices_per_toast = resources.friends; // 1 slice per friend
    const int salt_per_toast = requirements.salt_per_friend * resources.friends;

    // Calculate maximum toasts limited by each resource
    const int max_by_drink = resources.drink_ml / drink_per_toast;
    const int max_by_limes = resources.lime_slices / slices_per_toast;
    const int max_by_salt = resources.salt_grams / salt_per_toast;

    // Return minimum (bottleneck resource)
    return std::min({max_by_drink, max_by_limes, max_by_salt});
}

/**
 * Reads and validates input values
 * @param resources Output parameter for available resources
 * @param requirements Output parameter for resource requirements
 * @return true if input is valid, false otherwise
 */
auto read_input(AvailableResources &resources, ResourceRequirements &requirements) -> bool
{
    int bottles{};
    int ml_per_bottle{};
    int limes{};
    int slices_per_lime{};

    if (!(std::cin >> resources.friends >> bottles >> ml_per_bottle >> limes >> slices_per_lime >>
          resources.salt_grams))
    {
        return false;
    }

    if (!(std::cin >> requirements.drink_per_friend >> requirements.salt_per_friend))
    {
        return false;
    }

    // Calculate total available resources
    resources.drink_ml = bottles * ml_per_bottle;
    resources.lime_slices = limes * slices_per_lime;

    return (resources.friends > 0 && bottles > 0 && ml_per_bottle > 0 && limes > 0 && slices_per_lime > 0 &&
            resources.salt_grams > 0 && requirements.drink_per_friend > 0 && requirements.salt_per_friend > 0);
}

auto main() -> int
{
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    AvailableResources resources{};
    ResourceRequirements requirements{};

    if (!read_input(resources, requirements))
    {
        std::cerr << "Error: Invalid input\n";
        return 1;
    }

    // Calculate and output result
    const int max_toasts = calculate_max_toasts(resources, requirements);

    std::cout << max_toasts << '\n';

    return 0;
}
