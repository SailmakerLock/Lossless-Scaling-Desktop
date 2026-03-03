#include <iostream>
#include <stdexcept>
#include <limits>

/**
 * @brief Simple console calculator supporting basic arithmetic operations.
 * Handles user input and performs calculations with error checking.
 */
class SimpleCalculator {
public:
    /**
     * @brief Performs arithmetic operation based on provided operator and operands.
     * @param a First operand
     * @param b Second operand
     * @param op Operator (+, -, *, /)
     * @return Result of the operation
     * @throws std::invalid_argument for invalid operators or division by zero
     */
    static double calculate(double a, double b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b == 0) {
                    throw std::invalid_argument("Error: Division by zero is not allowed.");
                }
                return a / b;
            default:
                throw std::invalid_argument("Error: Unsupported operator. Use +, -, *, or /.");
        }
    }
};

/**
 * @brief Safely reads a double value from user input with error handling.
 * @param prompt Message to display to the user
 * @return Valid double number
 */
double getNumber(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');
            std::cout << "Invalid input. Please enter a valid number.
";
        }
    }
}

/**
 * @brief Main function — entry point of the program.
 * Runs the calculator loop until user chooses to exit.
 */
int main() {
    std::cout << "=== Simple Calculator ===
";
    std::cout << "Supported operations: +, -, *, /
";

    char continueChoice;
    do {
        // Get user input
        double num1 = getNumber("Enter first number: ");
        double num2 = getNumber("Enter second number: ");

        char op;
        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> op;

        try {
            double result = SimpleCalculator::calculate(num1, num2, op);
            std::cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << "

";
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "
";
        }

        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> continueChoice;

        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');

    } while (continueChoice == 'y' || continueChoice == 'Y');

    std::cout << "Calculator terminated. Goodbye!
";
    return 0;
}
