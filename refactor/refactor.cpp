#include "stdafx.h"

static const float ACCELERATION_OF_GRAVITY = 9.8f;

float CalculationOfDistance(float const& time, float const& startingSpeed)
{
	return startingSpeed * time - 0.5f * ACCELERATION_OF_GRAVITY * pow(time, 2);
}

int main(int argc, char *argv[])
{
	int jumpHeight;
	printf("Enter the maximum height: ");
	if (scanf("%i", &jumpHeight) == 0)
	{
		printf("Expected floating-point number\n");
		exit(1);
	}
	float timeOfMaxHeight;
	timeOfMaxHeight = sqrt(jumpHeight * 2 / ACCELERATION_OF_GRAVITY);
	printf("The time to reach the maximum height = %f\n", timeOfMaxHeight);
	bool flag = false;
	for (float currentTime = 0; currentTime < timeOfMaxHeight * 2; currentTime += 0.1f)
	{
		if (currentTime > timeOfMaxHeight && !flag)
		{
			flag = true;
			float startingSpeed = ACCELERATION_OF_GRAVITY * timeOfMaxHeight;
			float height = CalculationOfDistance(timeOfMaxHeight, startingSpeed);
			printf("t=%f, s=%f\n", timeOfMaxHeight, height);
		}
		float startingSpeed = ACCELERATION_OF_GRAVITY * timeOfMaxHeight;
		float height = CalculationOfDistance(currentTime, startingSpeed);
		printf("t=%f, s=%f\n", currentTime, height);
	}

	float startingSpeed = ACCELERATION_OF_GRAVITY * timeOfMaxHeight;
	float height = CalculationOfDistance(timeOfMaxHeight * 2, startingSpeed);
	printf("t=%f, s=%f\n", timeOfMaxHeight * 2, height);

	return 0;
}