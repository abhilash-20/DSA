from math import comb

def probability_with_replacement(num_black, num_white, num_draws):
    total_balls = num_black + num_white
    probability = (num_black / total_balls) ** num_draws
    return probability

def probability_without_replacement(num_black, num_white, num_draws):
    total_balls = num_black + num_white
    combinations_black = comb(num_black, num_draws)
    combinations_total = comb(total_balls, num_draws)
    probability = combinations_black / combinations_total
    return probability

# Input the number of black and white balls
num_black = int(input("Enter the number of black balls: "))
num_white = int(input("Enter the number of white balls: "))

# The event is drawing of a black ball
# Input the number of black balls drawn
num_draws = int(input("Black ball's to be drawn: \n(2 for simulataneous occurance of 2 events)\n(3 for simulataneous occurance of 3 events)\n"))

# Calculate probabilities
prob_with_replacement = probability_with_replacement(num_black, num_white, num_draws)
prob_without_replacement = probability_without_replacement(num_black, num_white, num_draws)

# Display results
print("With Replacement:")
print(f"The probability of picking {num_draws} black balls with replacement is {prob_with_replacement:.4f}")

print("Without Replacement:")
print(f"The probability of picking {num_draws} black balls without replacement is {prob_without_replacement:.4f}")