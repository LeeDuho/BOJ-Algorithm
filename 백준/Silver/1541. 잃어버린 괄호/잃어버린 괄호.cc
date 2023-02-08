#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char str[51];
int len, tmp;
bool ckeck; 

int main()
{
	cin >> str;
	len = strlen(str);
    int sum = 0;
	for (int i = 0; i <= len; i++){
		if (str[i] == '+' || str[i] == '-' || i == len){
			if (ckeck == false){
				sum += tmp;
				tmp = 0;
			}
			else{
				sum -= tmp;
				tmp = 0;
			}

			if (str[i] == '-') 
                ckeck = true;
		}
		else{
			tmp *= 10;
			tmp += str[i] - '0'; 
		}
	}
	cout << sum;
}