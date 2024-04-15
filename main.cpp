#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

float poissonDist(float lambda);
float uniformRand();
float expDist(float t);

int main() {
    tuple <int, float, float> process;//stores process number, arrival time, service time 
    float arrTime;//arrival time
    double totArrTime, totSerTime;//total service and arrival times
    float avgArrTime, avgSerTime;//average service and arrival times
    srand(time(0));//time seed

    for (int i = 0; i < 1000; i++) {
        if (i == 0) {//first tuple in list
            arrTime = poissonDist(2);
            process = make_tuple( (i+1), arrTime, expDist(1) );
            totArrTime = arrTime;
        }
        else {//arrival time gets added to last arrival time
            arrTime = poissonDist(2);
            process = make_tuple( (i+1), arrTime + get<1>(process), expDist(1) );
            totArrTime += arrTime;
        }
        cout << "[ " << get<0>(process) << ", " << get<1>(process) << ", " << get<2>(process) << " ]" << endl;
        totSerTime += get<2>(process);
    }
    avgArrTime = totArrTime/1000;//average arrival time
    avgSerTime = totSerTime/1000;//average service time
    cout << "The average arrival rate is: " << avgArrTime << endl;
    cout << "The average service time is: " << avgSerTime << endl;

    return 0;
}

//returns a random number between 0 and 1
float uniformRand() {
    return ((float) rand()/RAND_MAX);//
}

//returns a float with poisson distribution with a rate of 2 processes per second
float poissonDist(float lambda) {
    float x, z;

    z = uniformRand();
    x = (-1/lambda)*log(z);//poisson formula
    return (x);
}

//returns a float with exponential distribution with expected average service time of 1 second
float expDist(float t) {
    float x, z;

    z = uniformRand();
    x = (-t)*log(z);//exponential formula
    return (x);
}
