#import "@preview/grape-suite:1.0.0": exercise
#import exercise: project, task, subtask

#let task = task.with(numbering-format: (..n) => numbering("1", ..n))
#let subtask = subtask.with(markers: ("a)", "1)"))

#show: project.with(
    title: "Praktikum 6: Global Illumination",

    university: [University of Duisburg-Essen],
    institute: [Distributed Systems],
    seminar: [Objektorientied Programming in C++],

    abstract: [In der letzten Praktikumsaufgabe geht es darum globale Beleuchtungseffekte einzufügen. Der fleißige Programmierer hat über die Festtage sogar Multithreading eingebaut, damit es jetzt etwas schneller läuft. Bisher wurde die lokale Farbe, die Reflektion und die Brechung deterministisch bestimmt. Für realistische Bilder müssen aber globale Beleuchtungseffekte berücksichtigt werden. Dazu benutzt man Sampling. Wenn ein Strahl auf ein Objekt trifft, bestimmt man die Farbe an diesem Punkt, indem man eine Anzahl von Sampling strahlen in die Szene hineinschießt. Je mehr Samples, umso realistischer der Bildpunkt.

    Viel Erfolg!

    Bei Fragen oder Problemen schreiben Sie gerne im Moodle!],
    

    author: "Peter Zdankin",

    show-solutions: false,
    show-hints: true,
    task-type: [Aufgabe],
)
    

    #task[Global Illumination][]
#figure(
  image("starter.png", width: 100%),
  caption: [
    Das hier sollten sie sehen, wenn sie den Code ausführen ohne etwas zu ändern.
  ],
)

    #subtask[
        Öffnen Sie #link("https://git.uni-due.de/vs.ude/objektorientierte-programmierung-cpp"). Nutzen Sie git um das Repository zu _clonen_ und importieren Sie das Projekt in 06_GlobalIllumination/.
    ]

    #subtask[
        In `Scene.cpp` finden Sie die Methode `vec3 get_random_direction`, welche zu einem Normalenvektor (Vektor, welcher immer von einer Oberfläche weg zeigt) einen zufälligen Vektor bestimmt, welcher in die Hemisphäre um den Normalenvektor zeigt. Aktuell ist es ein schlechter Zufallsvektorgenerator, da immer der gleiche Wert zurückgegeben wird. Ändern Sie den Code sodass ein Vektor mit 3 Zufallswerten die jeweils zwischen -1.0 und 1.0 liegen, zurückgegeben wird. 
        #figure(
  image("sample.png", width: 100%),
  caption: [
    So (oder so ähnlich) sollte es aussehen, wenn das Sampling richtig umgesetzt wurde.
  ],
)
    ]

    #subtask[
        In `Scene.cpp` finden Sie die Methode `vec3 Scene::traceRayRealistic`, welche ein realistisches Raytracing implementieren soll. Aufgerufen wird sie parallelisiert in `YourRayTracer::renderRealistic` bzw. `YourRayTracer::render_row`. Schauen Sie sich `Scene::traceRay` an, um sich zu überlegen wie `reflection` berechnet werden wollte, damit die Spiegelung in den Kugeln und der Fläche realistisch aussieht.
        #figure(
  image("reflection.png", width: 100%),
  caption: [
    So (oder so ähnlich) sollte es aussehen, wenn Reflektionen richtig umgesetzt wurden.
  ],
)
    ]

        #subtask[
        Das selbe für die Brechung. In der Glaskugel vorne können Sie erkennen wie es aussehen sollte. 
        #figure(
  image("refraction.png", width: 100%),
  caption: [
    So (oder so ähnlich) sollte es aussehen, wenn Brechungen richtig umgesetzt wurden.
  ],
)
    ]

    #figure(
  image("fancy.png", width: 100%),
  caption: [
    In `main.cpp` können Sie bei der Erstellung der `Scene` einstellen, wie viele Samples genutzt werden sollen. Bei 1000 Samples kann es dann wie folgt aussehen. 
  ],
)

Falls Sie es bis hierhin geschafft haben, herzlichen Glückwunsch! Ich hoffe es hat Ihnen Spaß gemacht dieses Praktikum zu bestreiten und Sie konnten etwas für ihre Weiterbildung mitnehmen. Computergrafiken sind ein riesiges Feld und es gibt zahllose Optimierungen die noch möglich wären, damit die Bilder noch schöner oder realistischer aussehen. Ich wünsche Ihnen viel Erfolg bei der Vorbereitung für die Klausur. 


    