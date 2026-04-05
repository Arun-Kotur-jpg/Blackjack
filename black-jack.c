#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// --- STACK DATA STRUCTURE ---
#define MAX_CARDS 52

// Struct to represent a card
typedef struct {
    char *suit;
    char *name;
    int value;
} Card;

// Global Stack (The Deck)
Card deck[MAX_CARDS];
int top = -1; // Stack Pointer

// Stack Operation: PUSH (Add card to deck)
void push(char *suit, char *name, int value) {
    if(top < MAX_CARDS - 1) {
        top++;
        deck[top].suit = suit;
        deck[top].name = name;
        deck[top].value = value;
    }
}

// Stack Operation: POP (Deal card from deck)
Card pop() {
    return deck[top--];
}

// --- DECK MANAGEMENT ALGORITHMS ---

// Fisher-Yates Shuffle Algorithm
void shuffleDeck() {
    srand(time(0));
    for (int i = top; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Initialize Deck with 52 cards
void initDeck() {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *names[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    top = -1; // Reset stack pointer
    for (int s = 0; s < 4; s++) {
        for (int n = 0; n < 13; n++) {
            push(suits[s], names[n], values[n]);
        }
    }
}

// Calculate Score (Handles Ace logic 1 vs 11)
int calculateScore(Card hand[], int count) {
    int score = 0;
    int aces = 0;
    for(int i=0; i<count; i++) {
        score += hand[i].value;
        if(hand[i].value == 11) aces++;
    }
    // If bust, convert Aces from 11 to 1
    while(score > 21 && aces > 0) {
        score -= 10;
        aces--;
    }
    return score;
}

// --- MAIN GAME LOOP ---

int main() {
    Card playerHand[10], dealerHand[10];
    int pCount = 0, dCount = 0;
    char choice;

    // 1. Setup Game
    initDeck();
    shuffleDeck();

    printf("\n==========================================\n");
    printf("     BLACKJACK (Stack Implementation)     \n");
    printf("==========================================\n");
    
    // 2. Initial Deal (Pop 2 cards each)
    playerHand[pCount++] = pop();
    dealerHand[dCount++] = pop();
    playerHand[pCount++] = pop();
    dealerHand[dCount++] = pop();

    // 3. Player Turn
    while(1) {
        int score = calculateScore(playerHand, pCount);
        
        printf("\n--- YOUR TURN ---\n");
        printf("Dealer shows: %s of %s\n", dealerHand[0].name, dealerHand[0].suit);
        printf("Your Hand:    ");
        for(int i=0; i<pCount; i++) printf("[%s %s] ", playerHand[i].name, playerHand[i].suit);
        printf("\nYour Score:   %d\n", score);

        if(score == 21) {
            printf("\n*** BLACKJACK! You got 21! ***\n");
            break; 
        }
        if(score > 21) {
            printf("\n*** BUST! You went over 21. YOU LOSE. ***\n");
            return 0; // End game immediately
        }

        printf("Action: (h) Hit or (s) Stand? ");
        scanf(" %c", &choice);

        if(choice == 'h' || choice == 'H') {
            printf("Dealing card...\n");
            playerHand[pCount++] = pop(); // Pop from stack
        } else if(choice == 's' || choice == 'S') {
            printf("You chose to Stand.\n");
            break;
        } else {
            printf("Invalid input.\n");
        }
    }

    // 4. Dealer Turn 
    printf("\n==========================================\n");
    printf("         DEALER'S TURN (AI)               \n");
    printf("==========================================\n");
    
    // Reveal hidden card
    printf("Dealer reveals: %s of %s\n", dealerHand[1].name, dealerHand[1].suit);
    
    while(1) {
        int dScore = calculateScore(dealerHand, dCount);
        printf("Dealer Hand: ");
        for(int i=0; i<dCount; i++) printf("[%s %s] ", dealerHand[i].name, dealerHand[i].suit);
        printf(" -> Score: %d\n", dScore);

        if(dScore >= 17) {
            printf("Dealer Stands (Score is 17 or higher).\n");
            break;
        } else {
            printf("Dealer Hits (Score < 17)...\n");
            dealerHand[dCount++] = pop(); // Pop from stack
        }
    }
    
    // 5. Final Results
    int pScore = calculateScore(playerHand, pCount);
    int dScore = calculateScore(dealerHand, dCount);
    
    printf("\n==========================================\n");
    printf("FINAL: You [%d] vs Dealer [%d]\n", pScore, dScore);
    
    if(dScore > 21) {
        printf("RESULT: Dealer Busted! YOU WIN!\n");
    } else if(pScore > dScore) {
        printf("RESULT: You have the higher score. YOU WIN!\n");
    } else if(dScore > pScore) {
        printf("RESULT: Dealer has the higher score. DEALER WINS.\n");
    } else {
        printf("RESULT: It's a Tie (Push).\n");
    }
    printf("==========================================\n");

    return 0;
}