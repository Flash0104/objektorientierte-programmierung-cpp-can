#import "@preview/grape-suite:1.0.0": exercise
#import exercise: project, task, subtask

#let task = task.with(numbering-format: (..n) => numbering("1", ..n))
#let subtask = subtask.with(markers: ("a)", "1)"))

#show: project.with(
    title: "Exercise 7: Encapsulation",

    university: [University of Duisburg-Essen],
    institute: [Distributed Systems],
    seminar: [Objektorientied Programming in C++],

    abstract: [In dieser Aufgabe geht es darum Ampeln zu modellieren. Viel Erfolg!
    
    Bei Fragen oder Problemen schreiben Sie gerne im Moodle!],
    

    author: "Peter Zdankin",

    show-solutions: false,
    show-hints: true,
    task-type: [Aufgabe],
)

#task[Primzahlen][

    #subtask[
        Öffnen Sie #link("https://git.uni-due.de/vs.ude/objektorientierte-programmierung-cpp"). Nutzen Sie git um das Repository zu _clonen_ und importieren Sie das Projekt in 07_Encapsulation.
    ]

    #subtask[
        Nutzen Sie die in der Vorlesung gelernten Prinzipien der Encapsulation und Abstraction, um zum einen den Zugriff auf die internen red/green/yellow_on Variablen zu verhindern.
        Schreiben Sie zum anderen Methoden die die Übergänge von einem Zustand in den anderen ermöglichen (z.b. ` void green_to_yellow()` ) damit es eine sinnvolle Schnittstelle gibt, mit der man von außen die richtigen Übergänge aufrufen kann.
    ]

    #subtask[
        Hmm jetzt ist es aber doof dass der Entwickler selbst wissen muss welcher Zustand nach dem anderen kommen soll. Schaffen Sie es dafür zu sorgen dass ihr `TrafficLight` nur zwei public Methoden `print_traffic_light()` und `next()` hat und intern festgehalten wird, welcher Zustand aktuell ist und welche Methode jeweils als nächstes aufgerufen werden soll?
    ]
][]