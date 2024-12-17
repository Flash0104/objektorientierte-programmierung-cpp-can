#import "@preview/grape-suite:1.0.0": exercise
#import exercise: project, task, subtask

#let task = task.with(numbering-format: (..n) => numbering("1", ..n))
#let subtask = subtask.with(markers: ("a)", "1)"))

#show: project.with(
    title: "Exercise 2: Prime Numbers",

    university: [University of Duisburg-Essen],
    institute: [Distributed Systems],
    seminar: [Objektorientied Programming in C++],

    abstract: [This task is about finding all prime numbers up to a user-specified limit. Good luck!
    
    If you have any questions or problems, please write in the Moodle!],
    

    author: "Peter Zdankin",

    show-solutions: false,
    show-hints: true,
    task-type: [Aufgabe],
)

#task[Prime Numbers][

    #subtask[
        Open #link("https://git.uni-due.de/vs.ude/objektorientierte-programmierung-cpp"). Use git to _clone_ the repository and import the project into 02_Primes.
    ]

    #subtask[
        Complete the source code so that the is_prime method returns `true` if the number passed is a prime number, and `false` otherwise.
        A prime number is a number that has exactly 2 divisors.
    ]
][]