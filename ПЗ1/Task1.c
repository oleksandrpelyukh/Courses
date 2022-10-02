#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

int modb(int a, int b, int m){

	long y;
	
    if (a == 0){return 0;}
    if (b == 0){return 1;}
 
    if (b % 2 == 0) {
        y = modb(a, b / 2, m);
        y = (y * y) % m;
    }
    else {
        y = a % m;
        y = (y * modb(a, b - 1, m) % m) % m;
    }
 
    return (int)((y + m) % m);
}

int prime(int n){
	
	int i;
	
	if(n == 1){return 0;}
	
	for(i=2;i<=n/2;i++){
		if(n%i!=0){
			continue;
		}
		else{
			return 1;
		}
	}
	
	return 0;
}

int gennum(int A, int B){
	
	int i, result ,flag=0;
	srand(time(NULL));
	
	if(A==B){
		printf("\nYou entered equal numbers as a range. In this case result = 1\n");
		result = 1;
	}
	else if (A > B){result = (rand() % (A - B + 1)) + B;}
	else{result = (rand() % (B - A + 1)) + A;}
 
	return result;
}

int gcd(int a, int b){
    if (a == 0){return b;}
    return gcd(b % a, a);
}

int phi(int n){
	
    int i, result = 1;
    
    for (i = 2; i < n; i++){
        if (gcd(i, n) == 1){ result++;}
	}
            
    return result;
}

int main(){
	
	int a,result,m,b,flag;
	unsigned long long temp, result1;
	char input;
	
	printf("Enter module value m : ");
	scanf("%d", &m);
				
	while (1){
    	printf("1. a mod m\n");
    	printf("2. a^b mod m\n");
    	printf("3. a*x = b mod m => x = ?\n");
    	printf("4. Generate prime number in range\n");
    	printf("5. Change module m value\n");
    	printf("6. Exit\n");
    	printf("Enter your choice: ");
    	input = getche();
      	switch(input){
    		case '1':
				printf("\nEnter a value: ");
				scanf("%d", &a);
				result = a%m;
				printf("Result: %d mod %d = %d\n", a,m,result);
            	break;
    		case '2':
    			printf("\nEnter a value: ");
				scanf("%d", &a);
				printf("Enter b value: ");
				scanf("%d", &b);
				result = modb(a,b,m);
				printf("Result: %d^%d mod %d = %d\n", a,b,m,result);
        		break;
        	case '3':
    			printf("\nEnter a value: ");
				scanf("%d", &a);
				printf("Enter b value: ");
				scanf("%d", &b);
				if(gcd(a,m) == 1){
					flag = phi(m);
					temp = pow(a,flag-1);
					temp=temp%m;
					temp = b * temp;
					result1 = temp%m;
					printf("Result: %d*x = %d mod %d => x = %lld\n", a,b,m,result1);
				}
				else{
					printf("a and m values aren`t relatively prime");
				}
				break;
            case '4':
			    printf("\nLet`s consider a range\nEnter a value: ");
				scanf("%d", &a);
				printf("Enter b value: ");
				scanf("%d", &b);
				result = gennum(a,b);
				flag = prime(result);
				while(flag != 0){
					result = gennum(a,b);
					flag = prime(result);
				}
				printf("Prime number in chosen range: %d\n", result);
				break;
        	case '5':
				printf("\nEnter module value m : ");
				scanf("%d", &m);
				printf("Current module value m: %d\n",m);
				break;
        	case '6':
        		printf("\nTesting is over\n");
            	exit(0);
   			default:
        		printf("\nWrong choice, try again!\n");
        		break;
    	}    
	} 
	
	return 0;
}
