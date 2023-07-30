#Dice Rolling Game using Python
import random

def roll_dice():
    return random.randint(1, 6)

def get_user_guess():
    while True:
        try:
            guess = int(input("Guess the number (1-6): "))
            if 1 <= guess <= 6:
                return guess
            else:
                print("Invalid input. Guess should be between 1 and 6.")
        except ValueError:
            print("Invalid input. Please enter an integer.")

def play_dice_game():
    print("Welcome to the Dice Rolling Game!")
    print("Rolling the dice...")
    rolled_number = roll_dice()
    print("The dice has been rolled. Try to guess the number!")

    user_guess = get_user_guess()
    print(f"You guessed: {user_guess}")
    print(f"The dice rolled: {rolled_number}")

    if user_guess == rolled_number:
        print("Congratulations! You guessed correctly. You win!")
    else:
        print("Sorry, your guess was incorrect. You lose.")

if __name__ == "__main__":
    play_dice_game()
