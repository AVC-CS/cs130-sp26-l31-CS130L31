#ifndef ANSWERS_HPP
#define ANSWERS_HPP

// ============================================================
// Part A — Multiple Choice
// ============================================================
// For each question, replace 0 with the correct answer (1, 2, 3, or 4).
// Compile and run main1-4.cpp to observe the behavior before answering.
//   g++ -std=c++17 main1.cpp -o main1 && ./main1
//   g++ -std=c++17 main2.cpp -o main2 && ./main2
//   g++ -std=c++17 main3.cpp -o main3 && ./main3
//   g++ -std=c++17 main4.cpp -o main4 && ./main4

// Q1 (main1.cpp, line 24-25): After getRefStruct().age = 21; what is s.age?
//   1) 19   2) 20   3) 21   4) Undefined behavior
// TODO: enter your answer (1-4)
const int Q1 = 3;

// Q2 (main2.cpp, line 13-15): After getRefNum(num) = 100; what is num?
//   1) 10   2) 100   3) 0   4) Undefined behavior
// TODO: enter your answer (1-4)
const int Q2 = 2;

// Q3 (main3.cpp, line 28-32): After str = "World"; (line 31) what is ms.strvalue?
//   1) World   2) Hello   3) ""   4) Undefined behavior
// TODO: enter your answer (1-4)
const int Q3 = 2;

// Q4 (main4.cpp, line 17-20): After changeStruct1(ms); what is ms.value?
//   1) 100   2) 200   3) 300   4) 400
// TODO: enter your answer (1-4)
const int Q4 = 1;

// Q5 (main4.cpp, line 34-37): Why does changeStruct1(ms) NOT change ms?
//   1) It passes by value (copy)
//   2) It passes by reference
//   3) It passes by pointer
//   4) The struct is const
// TODO: enter your answer (1-4)
const int Q5 = 1;

// Q6 (main3.cpp, line 28-36): Why does str = "World" (line 31) NOT change ms.strvalue,
//   but strRef = "World" (line 35) DOES change it?
//   1) str is a copy; strRef is a reference to the member
//   2) str is a reference; strRef is a copy
//   3) Both are copies but strRef uses move semantics
//   4) str points to a temporary object
// TODO: enter your answer (1-4)
const int Q6 = 1;

// ============================================================
// Part B — Coding
// ============================================================

// Swap two integers using references
void swapByRef(int &a, int &b) {
    // TODO: Swap the values of a and b using references
    int temp = a;
    a = b;
    b = temp;
}

// Swap two integers using pointers
void swapByPtr(int *a, int *b) {
    // TODO: Swap the values of a and b using pointers
    int temp = *a;
    *a = *b;
    *b = temp;
}

#endif
