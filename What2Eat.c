#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main() {

	// Ask the number of people
	int n;
	printf("How many guys of you? Enter a number: ");
	scanf("%d", &n);
	printf("You are %d fellas!\n", n);
	
	// Round 1
	char meals[n*5][30];
	for(int i = 0; i < n*5; i++) {
		strcpy(meals[i], "");
	}
	int points[n*5];
	for(int i = 0; i < n*5; i++) {
		points[i] = 0;
	}
	int index = 0;
	char meal [30];
	bool found = false;
	
	
	/* Ask people to order their preferences
	 * This piece of code accepts user input and put each unique meal in the meals array. And collect the points for meals
	 * at the corresponding index in the points array. (If meals[0] is kebab then points[0] holds the points for kebab) */
	 
	printf("\nNow each of you enter your preferences in order.\n\n");
	for(int i = 0; i < n; i++) {
		printf("Your turn #%d!\n", (i+1));
		for(int j = 0; j < 5; j++) {
			printf("%d-", (j+1));
			scanf("%s", meal);
			for(int k = 0; k < index; k++) {
				if(strcmp(meals[k], meal)==0) {
					points[k] += 6-(j+1);
					found  = true;
					break;
				}
			}
			if(!found) {
				strcpy(meals[index], meal);
				points[index] += 6-(j+1);
				index++;
			}
			found = false;
		}
		printf("\n");
	}
	printf("*************************************************************************\n\n");
	
	// Check for meals that are above the threshold
	int threshold = n*3;
	int count = 0;
	for(int i = 0; i < index; i++) {
		if(points[i] > threshold) {
			printf("·%s\n", meals[i]);
			count++;
		}
	}
	
	// If there is no meal above the threshold, program exits
	if(count == 0) {
		printf("You are eating at home/dorm today!\n");
		return 0;
	}
	
	// Round 2
	for(int i = 0; i < n*5; i++) {
		points[i] = 0;
	}
	for(int i = 0; i < n*5; i++) {
		strcpy(meals[i], "");
	}
	index = 0;
	
	
	/* Ask people to order their preferences
	 * This piece of code applies the same logic with the above one */
	 
	printf("\nNow enter your preferences from the above list in order.\n\n");
	for(int i = 0; i < n; i++) {
		printf("Your turn #%d!\n", (i+1));
		for(int j = 0; j < count; j++) {
			printf("%d-", (j+1));
			scanf("%s", meal);
			for(int k = 0; k < index; k++) {
				if(strcmp(meals[k], meal)==0) {
					points[k] += 6-(j+1);
					found  = true;
					break;
				}
			}
			if(!found) {
				strcpy(meals[index], meal);
				points[index] += 6-(j+1);
				index++;
			}
			found = false;
		}
		printf("\n");
	}
	
	// Print final scores on the screen
	for(int i = 0; i < index; i++) {
		if(points[i] > threshold) {
			printf("%s: %d points\n", meals[i], points[i]);
		}
	}
	
	// Find the meal that has maximum points
	int max = 0;
	char result [30];
	for(int i = 0; i < count; i++) {
		if(points[i] > max) {
			max = points[i];
			strcpy(result, meals[i]);
		}
	}
	printf("You are ordering %s!\n", result);
	return 0;
}



