INTRODUCTION 
 
Card Games are a traditional use of the principles of computer science, where data is processed and 
simulated efficiently and randomly. Blackjack, otherwise known as Twenty-One, is one of the most popular 
casino banking games in the world. Unlike other card games, the approach here is such that Blackjack is a 
comparing card game played by a player and a dealer. 
Blackjack, a betting game involving a casino banker, will be the basis of this case study. It will illustrate 
how a simulation of a Deck of Cards can be done through a Linear Data Structure; that is, through a Stack. 
A Player plays against a Dealer, who tries to get cards that sum to 21 or the closest to 21 without going 
"bust." This report will outline the concept and programming of this game through the C programming 
language. 

 
PROBLEM DESCRIPTION 
 
In a normal game of Blackjack, the deck of 52 playing cards needs to be randomly shuffled and disposed of 
in a Last In-First Out pattern. The conventional management of an array may not be the most efficient 
process when it comes to the distribution of the playing cards.This is the reason, the Stack datastructure is 
used in this implementation. 
The Problem: To handle card operations on a deck as well as game operations efficiently without any 
memory leak or bias. 
The Context: The dealer (computer) has strict rules (hit if 17), while the player has interactives. It requires a 
good mechanism for handling the 'Ace' card value dynamically, either 1 or 11. 
Game Logic Complexity: Handling the dynamic valuation of specific cards (e.g., the Ace, which can be 
valued at 1 or 11) to prevent the player from "busting" unnecessarily, while simultaneously enforcing strict 
dealer rules (e.g., hitting on soft 16). 
 
 

OBJECTIVES OF THE CASE STUDY 
 
1. To implement a Stack data structure for managing the deck of cards, utilizing PUSH (add card) 
and POP (deal card) operations. 
2. To apply the Fisher-Yates Shuffle algorithm to ensure an unbiased, random permutation of the 
deck. 
3. To simulate real-world game logic, including specific Blackjack rules for dealers and players. 
4. To demonstrate memory management in C through the use of pointers and structural definitions. 
                                                             
