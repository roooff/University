def squares_of_fractions(prompt="Enter comma-separated fractions: "):
    try:
        fraction_list = [float(fraction) for fraction in input(prompt).split(",")]
        squared_fractions = tuple(number ** 2 for number in fraction_list)
        return squared_fractions
    except ValueError:
        print("Invalid input. Please enter comma-separated numbers.")
        return squares_of_fractions()  # Recursive call to retry


# Get user input and calculate squares (with error handling)
squared_fractions = squares_of_fractions()
print(f"Tuple of squared fractions: {squared_fractions}")