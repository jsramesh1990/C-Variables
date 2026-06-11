
# Control Statements

## Table of Contents

1. Introduction
2. Definition
3. Why Control Statements Are Needed
4. Types of Control Statements
5. Selection Control Statements
6. Iteration Control Statements
7. Jump Control Statements
8. Nested Control Statements
9. Advantages
10. Disadvantages
11. Real-Time Examples
12. Major Project Usage
13. Best Practices
14. Common Mistakes
15. Interview Questions
16. Conclusion

---

# 1. Introduction

Programs execute statements in a sequence by default.

Example:

```c
printf("Step 1");
printf("Step 2");
printf("Step 3");
```

Output:

```text
Step 1
Step 2
Step 3
```

However, real-world applications require decision-making and repetition.

Examples:

* Checking user credentials
* Processing transactions
* Repeating calculations
* Menu-driven programs

To control program flow, we use **Control Statements**.

---

# 2. Definition

## Definition

**Control Statements** are statements that determine the order in which program instructions are executed.

They allow a program to:

* Make decisions
* Repeat tasks
* Skip statements
* Transfer control

---

## Simple Definition

```text
Control Statements =
Statements that control
the flow of execution
in a program.
```

---

# 3. Why Control Statements Are Needed

Without control statements:

```c
printf("Login Success");
```

This executes regardless of user credentials.

---

With control statements:

```c
if(password == correct)
{
    printf("Login Success");
}
```

Program behaves intelligently.

---

## Uses

* Decision making
* Repetition
* Menu systems
* Error handling
* Validation

---

# 4. Types of Control Statements

Control statements are classified into:

```text
1. Selection Statements
2. Iteration Statements
3. Jump Statements
```

---

## Classification Diagram

```text
Control Statements
        |
        +------------------+
        |                  |
        v                  v
 Selection          Iteration
        |
        v
      Jump
```

---

# 5. Selection Control Statements

Selection statements allow programs to choose among alternatives.

---

## 5.1 if Statement

### Syntax

```c
if(condition)
{
    statements;
}
```

---

### Example

```c
int age = 20;

if(age >= 18)
{
    printf("Eligible to Vote");
}
```

Output:

```text
Eligible to Vote
```

---

## Flow Diagram

```text
Condition
   |
True?
 /   \
Yes   No
 |     |
Execute Skip
```

---

## 5.2 if-else Statement

### Syntax

```c
if(condition)
{
    statements;
}
else
{
    statements;
}
```

---

### Example

```c
if(age >= 18)
{
    printf("Adult");
}
else
{
    printf("Minor");
}
```

---

## 5.3 else-if Ladder

Used for multiple conditions.

### Syntax

```c
if(condition1)
{
}
else if(condition2)
{
}
else
{
}
```

---

### Example

```c
int marks = 75;

if(marks >= 90)
{
    printf("A");
}
else if(marks >= 75)
{
    printf("B");
}
else
{
    printf("C");
}
```

---

## 5.4 Nested if

An if statement inside another if statement.

### Example

```c
if(age >= 18)
{
    if(hasLicense)
    {
        printf("Can Drive");
    }
}
```

---

## 5.5 switch Statement

Used when multiple options exist.

### Syntax

```c
switch(expression)
{
    case value1:
        statements;
        break;

    case value2:
        statements;
        break;

    default:
        statements;
}
```

---

### Example

```c
int day = 2;

switch(day)
{
    case 1:
        printf("Monday");
        break;

    case 2:
        printf("Tuesday");
        break;

    default:
        printf("Invalid");
}
```

Output:

```text
Tuesday
```

---

# 6. Iteration Control Statements

Used to execute statements repeatedly.

---

## 6.1 for Loop

### Syntax

```c
for(initialization;
    condition;
    increment)
{
    statements;
}
```

---

### Example

```c
for(int i=1; i<=5; i++)
{
    printf("%d ", i);
}
```

Output:

```text
1 2 3 4 5
```

---

## Flow

```text
Initialize
     |
Condition
     |
 True
     |
Execute
     |
Increment
     |
Condition
```

---

## 6.2 while Loop

### Syntax

```c
while(condition)
{
    statements;
}
```

---

### Example

```c
int i=1;

while(i<=5)
{
    printf("%d ", i);
    i++;
}
```

---

## 6.3 do-while Loop

Executes at least once.

### Syntax

```c
do
{
    statements;
}
while(condition);
```

---

### Example

```c
int i=1;

do
{
    printf("%d ", i);
    i++;
}
while(i<=5);
```

---

## Difference

| Loop     | Condition Check  |
| -------- | ---------------- |
| for      | Before execution |
| while    | Before execution |
| do-while | After execution  |

---

# 7. Jump Control Statements

Transfer control from one part of program to another.

---

## 7.1 break

Terminates loop or switch.

### Example

```c
for(int i=1;i<=10;i++)
{
    if(i==5)
        break;

    printf("%d ",i);
}
```

Output:

```text
1 2 3 4
```

---

## 7.2 continue

Skips current iteration.

### Example

```c
for(int i=1;i<=5;i++)
{
    if(i==3)
        continue;

    printf("%d ",i);
}
```

Output:

```text
1 2 4 5
```

---

## 7.3 goto

Transfers control to a label.

### Example

```c
goto label;

label:
printf("Hello");
```

---

### Note

Rarely recommended in modern programming.

---

## 7.4 return

Terminates function execution.

### Example

```c
int add()
{
    return 10;
}
```

---

# 8. Nested Control Statements

Control statements can be placed inside another.

Example:

```c
for(int i=1;i<=3;i++)
{
    if(i%2==0)
    {
        printf("Even");
    }
}
```

---

## Nested Loop Example

```c
for(int i=1;i<=3;i++)
{
    for(int j=1;j<=3;j++)
    {
        printf("*");
    }
}
```

Output:

```text
***
***
***
```

---

# 9. Advantages

## Decision Making

Programs become intelligent.

---

## Automation

Reduces repetitive code.

---

## Flexibility

Supports multiple execution paths.

---

## Better Logic Control

Improves program structure.

---

## Efficient Programming

Less code duplication.

---

# 10. Disadvantages

## Complex Nesting

Too many nested statements reduce readability.

---

## Infinite Loops

Incorrect conditions may never terminate.

Example:

```c
while(1)
{
}
```

---

## Debugging Difficulty

Complex flow becomes harder to trace.

---

# 11. Real-Time Examples

## Example 1: ATM System

```text
Check PIN
     |
Correct?
     |
Yes → Withdraw
No  → Error
```

Uses:

```text
if-else
```

---

## Example 2: Login System

```text
Username Valid?
Password Valid?
```

Uses:

```text
Nested if
```

---

## Example 3: Menu-Driven Application

```text
1. Deposit
2. Withdraw
3. Balance
```

Uses:

```text
switch
```

---

## Example 4: Employee Salary Processing

Process every employee.

Uses:

```text
for loop
```

---

## Example 5: Sensor Monitoring

Continuously check sensor values.

Uses:

```text
while loop
```

---

# 12. Major Project Usage

## Banking System

Uses:

```text
if-else
for
while
switch
```

for transactions and validation.

---

## E-Commerce

Uses:

```text
Product Search
Order Processing
Payment Verification
```

---

## Embedded Systems

Uses:

```text
Sensor Monitoring
Motor Control
Interrupt Handling
```

---

## Gaming

Uses:

```text
Game Loop
Decision Trees
```

---

## Operating Systems

Uses:

```text
Scheduling
Resource Management
```

---

# 13. Best Practices

## Use switch for Multiple Fixed Options

More readable than long if-else chains.

---

## Avoid Deep Nesting

Use functions where possible.

---

## Use Meaningful Conditions

Improves readability.

---

## Prevent Infinite Loops

Ensure loop termination conditions exist.

---

# 14. Common Mistakes

## Missing break in switch

```c
case 1:
    printf("One");
```

Falls through unintentionally.

---

## Infinite Loop

```c
while(1)
{
}
```

---

## Assignment Instead of Comparison

Wrong:

```c
if(a = 5)
```

Correct:

```c
if(a == 5)
```

---

# 15. Interview Questions

### Q1. What Are Control Statements?

Statements that control program flow.

---

### Q2. Types of Control Statements?

* Selection
* Iteration
* Jump

---

### Q3. Difference Between if and switch?

if:

```text
Any Condition
```

switch:

```text
Fixed Values
```

---

### Q4. Difference Between while and do-while?

while:

```text
May execute zero times
```

do-while:

```text
Executes at least once
```

---

### Q5. Purpose of break?

Terminates loop or switch.

---

### Q6. Purpose of continue?

Skips current iteration.

---

### Q7. Purpose of return?

Exits function and returns value.

---

# 16. Conclusion

Control Statements are fundamental programming constructs that control the execution flow of programs. They enable decision-making, repetition, and control transfer, making software intelligent and interactive.

Control statements are widely used in:

* Software Development
* Embedded Systems
* Web Applications
* Operating Systems
* Game Development
* Banking Applications
* IoT Systems

Mastering control statements is essential for learning algorithms, data structures, system programming, and advanced software engineering concepts.

### Quick Interview Cheat Sheet

| Category  | Statements                    |
| --------- | ----------------------------- |
| Selection | if, if-else, else-if, switch  |
| Iteration | for, while, do-while          |
| Jump      | break, continue, goto, return |

### Real-World Mapping

| Application         | Control Statement |
| ------------------- | ----------------- |
| Login Validation    | if-else           |
| ATM Menu            | switch            |
| Employee Processing | for               |
| Sensor Monitoring   | while             |
| Retry Operations    | do-while          |
| Function Exit       | return            |

### Learning Path

```text
Variables
   ↓
Operators
   ↓
Control Statements
   ↓
Functions
   ↓
Arrays
   ↓
Pointers
   ↓
Structures
   ↓
Data Structures
   ↓
Algorithms
```

Control Statements are one of the most important foundations of programming because every real-world application—from embedded systems to operating systems and enterprise software—uses them extensively.
