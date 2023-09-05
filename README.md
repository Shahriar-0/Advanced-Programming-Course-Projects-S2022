# Advanced-Programming-Course-Projects

Projects for the advanced programming course at Tehran university in Fall of 2022.

- [Advanced-Programming-Course-Projects](#advanced-programming-course-projects)
  - [1. Time Management System](#1-time-management-system)
  - [2. Recursive](#2-recursive)
  - [3. Work Assignment](#3-work-assignment)

## 1. Time Management System

This simple program was a warmup for the course. It helps you manage your time, given events that you have to do and tasks that you want to do. It is a command line program that takes in a file of events and tasks and outputs a schedule of events and tasks. The program uses a greedy algorithm to schedule the events and tasks. The program is written in C++. The input file is a text file with the following format:

```text
<event_time>
<event_time>
...
#
<task_duration> <empty_range_id>
<task_duration> <empty_range_id>
...
```

The output is a text file with the following format:

```text
<task_id> <task_scheduled_time>
<task_id> <task_scheduled_time>
...
```

---

## 2. Recursive

This project contains 4 problems that are solved recursively. The problems are as follows:

- 1: Given *n* and *k*, find the k-th character in the n-th iteration. In each iteration you substitute as follows:
  - 0 -> 01
  - 1 -> 10
- 2: Given three strings determine if the last one is an interleaving of the first two.
- 3: Find your way in a maze, but when you go one way you cannot change it until you hit the wall or the end of the maze.
- 4: Given a scale with two pans and a set of weights, find if it's possible to weight an object.

---

## 3. Work Assignment

In this project we have a set of seminars with required langues and a set of translators that each of them know a set of languages. We want to assign each seminar to a translator such conditions mentioned in description are met. The program is written in C++ and uses a greedy algorithm to assign the seminars to the translators. The input file is a text file with the following format:

```text
number_of_translators
<translator_name> <start_time> <end_time> <languages>
...
number_of_seminars
<seminar_name> <start_time> <end_time> <languages>
```

And output should be like this:

```text
<event1_name>
<language1>: <translator>
<language2>: <translator>
...
<event2_name>
<language1>: <translator>
<language2>: <translator>
...
```

For running the program you should run the following command:

```sh
g++ -std=c++11 A3.cpp -o main
./main <input_file> 
```

---
