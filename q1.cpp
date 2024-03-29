#include <bits/stdc++.h>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/wait.h>

using namespace std;

int main(){
	/*! \brief prints the parent pid 
	*
	*  Once the PID is printed, then 2 children are made
	*  and 2 grandchildren are also made. 
	*  We also print their PIDs along with their parents PIDs
	*/
	cout << "Parent PID: " 
		<< getpid() 
		<< endl 
		<< endl;
	for(int iterator = 0; iterator < 2; iterator++){
		if(fork() == 0){
			cout << "Child -> " 
			<< (iterator+1) 
			<< " with pid "
			<< getpid() 
			<< " from parent pid " 
			<< getppid() 
			<< endl;

			for(int childIterator = 0; childIterator < 2; childIterator++){
				if(fork() == 0){
					cout << "Grandchild -> " 
					<< (iterator*2 + 1 + childIterator) 
					<< " with pid "
					<< getpid() 
					<< " from parent pid " 
					<< getppid() 
					<< endl;
					exit(0);
				}
				wait(NULL);	
			}
			exit(0);
			wait(NULL);
		}
		cout << endl;
	}
	
	exit(0);
}