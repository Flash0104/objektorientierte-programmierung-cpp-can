#import "@preview/grape-suite:1.0.0": exercise
#import exercise: project, task, subtask
#import math

#let task = task.with(numbering-format: (..n) => numbering("1", ..n))
#let subtask = subtask.with(markers: ("a)", "1)"))

#show: project.with(
    title: "Exercise 8 - Smart Pointers and OOP-Basics",

    university: [University of Duisburg-Essen],
    institute: [Distributed Systems],
    seminar: [Object Oriented Programming in C++],

    abstract: [

    _This weeks exercise sheet will focus on implementing some simple classes, as well as creating some 'smart_pointers' from the 'std-library'._
    
    If you have any questions or problems, please write in the Moodle!
  ],
    

    author: "Thies Josten",

    show-solutions: false,
    show-hints: true,
    task-type: [Exercise],
)

#task[Your very own classes][
  For this Exercise create your own `Classes` inside your project folder. \ *Try out your code* in `main.cpp`. \ You should at least create one `Rectangle` and `Circle` each and calculate both of their areas and print them to the `console`. \
  \ ]
  #subtask[
    Implement a `class` called `Rectangle`. In its `header`, define the `private` fields `width` and `height` with appropriate data types. Write a method `calculate_area`, which does exactly that and returns the solution. \
    _The area of a rectangle is equal to its width multiplied by its height._ \ \
    
  ]

  #subtask[
    Implement a `class` called `Circle`. In its `header`, define the `private` field `radius` with an appropriate data type. Write a method `calculate_area`, which does exactly that and returns the solution. \ 
    _The area of a Circle is equal to its radius squared multiplied by pi (You can use 3.141)._ \ \
  ]
  #subtask[
    Write `getter` and `setter` methods for all fields of both your classes. \ \
  ]
  
   
    

#task[Smart pointers][
  For this Exercise try out your code in `main.cpp`. \ 
  \ ]
  #subtask[
    Declare a `std::unique_ptr` holding the integer value `42`. Declare another `std::unique_ptr` and try to assign the first pointer to it. What happens?
    Explain the occurring behaviour with respect to the idea of a unique pointer. \ \
  ]
  #subtask[
    Now use `std::move(<unique pointer>)` to assign the first pointer to the second one. What happened to the first pointer now? Find out with a bit of `trial and error` and explain your results. \
    _You can look up `unique_ptr`s via the lecture slides or by browsing the web._ \ \
  ]

   
 