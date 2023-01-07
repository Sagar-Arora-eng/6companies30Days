#include<bits/stdc++.h>
using namespace std;

double nthPersonGetsNthSeat(int n){
    //     reference explanation:
//         Let us imagine the airplane queue as follows:
// 10 --> 9 --> 8 --> 7 --> 6 --> 5 --> 4 --> 3 --> 2 --> 1

// The first person comes in and takes an arbitrary seat. Let this seat be that of the kth person ( 2 <= k <= 10). Let us assume for the sake of this example, that k = 5.

// So now, the seat of 1st person is empty, and the seat of 5th person is occupied by the first person. However, the seats of person 2 - 4 are free. I could genralize this to say that the original seats of person 2 to person k-1 are free. Therefore, they would go and sit on their original seats.

// Now, when the kth (= 5 here) person has to take a seat, they can end up doing one of these two things:

// Take the seat that belonged to person 1 originally.
// Take the seat of another person from k+1 to n.
// In the first case, the original seats of person k+1 to person n would be free and they would end up sitting in their original seats.

// This makes us realize that in order for the nth person to get their original seat, the kth person person should sit on the seat of 1st person. Otherwise, the seat of first person remains empty, and we have a sub-problem. The subproblem being that a new person between k+1 and n would have their original seat occupied, and must either choose to sit on the seat of first person and end the cycle, or take the seat of a person after them and let that person decide whether they want to end or continue the cycle.

// Eventually it comes down to the nth person. If they are lucky, someone before them had taken the seat of 1st person and had already ended the cycle. Otherwise, they must be the one to take up the seat of 1st person and end the cycle. Thus, the probability of them being able to sit on their original seat would be 0.5.
    return n == 1 ? 1 : 0.5; 
}

int main(){
   int n; 
   cin>>n; 

   cout << nthPersonGetsNthSeat(n) << endl;

   return 0;
}