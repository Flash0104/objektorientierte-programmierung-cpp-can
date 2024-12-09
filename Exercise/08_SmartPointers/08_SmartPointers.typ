#import "@preview/grape-suite:1.0.0": exercise
#import exercise: project, task, subtask
#import math

#let task = task.with(numbering-format: (..n) => numbering("1", ..n))
#let subtask = subtask.with(markers: ("a)", "1)"))

#show: project.with(
    title: "Blatt 8 - Smart Pointers und OOP-Basics",

    university: [University of Duisburg-Essen],
    institute: [Distributed Systems],
    seminar: [Object Oriented Programming in C++],

    abstract: [

    _Übungsblatt 7 wird sich mit dem implementieren einiger einfachen Klassen sowie 'unique_ptr' aus der 'std-library' beschäftigen._
    
    Bei Fragen oder Problemen, gerne ins Moodle schreiben!
  ],
    

    author: "Thies Josten",

    show-solutions: false,
    show-hints: true,
    task-type: [Exercise],
)

#task[Eure eigenen Klassen][

  Zum ersten mal erzeugen Sie die 'Klassen' in Ihrem Projektordner selbst. \
  *Testen* Sie Ihren Code in `main.cpp`. \
  Dazu sollten Sie mindestens ein `Rectangle` und `Circle` erzeugen und Beider Flächen berechnen. \ 
  \ ]
  #subtask[
    Implementieren Sie eine `Klasse` namens `Rectangle`. Definieren Sie in der `Header-File` der `Klasse`die `privaten` Felder `width`und `height` mit passenden Datentypen. Schreiben Sie eine Methode `calculate_area`, die Ihrem Namen gerecht wird und die Fläche zurückgibt. \
    _Die Fläche eines `Rectangle` ist das Produkt aus `width` und `height`._ \ \ 
  ]

  #subtask[
    Implementieren Sie eine `Klasse` namens `Circle`. Definieren Sie in der `Header-File` der `Klasse`das `private` Feld `radius` mit einem passenden Datentypen. Schreiben Sie eine Methode `calculate_area`, die Ihrem Namen gerecht wird und die Fläche zurückgibt. \
    _Die Fläche eines `Circle` ist dessen Radius quadriert und mit Pi (Benutzen Sie 3.141) multipliziert._ \ \
  ]
  #subtask[
    Schreiben Sie `getter` und `setter` Methoden für Alle Felder der Beiden Klassen. \ \
  ]
  
   
    

#task[Smart Pointer][
  Testen Sie Ihren Code in der `main.cpp-Datei`. \ 
  \ ]
  #subtask[
    Erzeugen Sie einen `std::unique_ptr`, der auf eine Variable mit  dem Wert `42` zeigt. Erzeugen Sie einen weiteren `std::unique_ptr` und versuchen Sie diesem den Anderen Pointer zu übergeben. Beschwert sich der Compiler?
    Erklären Sie das Verhalten basierend auf Ihrem Verständnis von unique Pointern. \ \
  ]
  #subtask[
    Benutzen Sie nun `std::move(<unique pointer>)`, um den ersten Pointer dem Zweiten zu zuweisen. Was passier mit dem ersten Pointer? Probieren Sie ein bisschen herum und erklären Sie Ihre Ergebnisse. \
    _ Informationen zu `unique_ptr` können Sie auf den Vorlesungsfolien oder im Internet finden._ \ \
  ]

   
 