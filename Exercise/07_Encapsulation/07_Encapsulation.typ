#import "@preview/grape-suite:1.0.0": exercise
#import exercise: project, task, subtask

#let task = task.with(numbering-format: (..n) => numbering("1", ..n))
#let subtask = subtask.with(markers: ("a)", "1)"))

#show: project.with(
    title: "Exercise 7: Encapsulation",

    university: [University of Duisburg-Essen],
    institute: [Distributed Systems],
    seminar: [Objektorientied Programming in C++],

    abstract: [This task is about modelling traffic lights. Good luck!
    
    If you have any questions or problems, please write to us in Moodle!],
    

    author: "Peter Zdankin",

    show-solutions: false,
    show-hints: true,
    task-type: [Aufgabe],
)

#task[Primzahlen][

    #subtask[
        Open #link("https://git.uni-due.de/vs.ude/objektorientierte-programmierung-cpp"). Use git to _clone_ the repository and import the project into 07_Encapsulation.
    ]

    #subtask[
        Use the principles of encapsulation and abstraction learnt in the lecture to prevent access to the internal red/green/yellow_on variables.
        On the other hand, write methods that enable transitions from one state to another (e.g. ` void green_to_yellow()` ) so that there is a meaningful interface that can be used to call the correct transitions from outside.
    ]

    #subtask[
        Hmm, but now it's silly that the developer himself has to know which state should come after the other. Can you make sure that your `TrafficLight` only has two public methods `print_traffic_light()` and `next()` and that it is internally recorded which state is current and which method should be called next?
    ]
][]