{
    "targets": [
        {
            "target_name": "Klondike-Solver-NativeExtension",
            "sources": ["Klondike-Solver-NativeExtension.cc", "functions.cc",
                        "Klondike-Solver/Solitaire.cpp",
                        "Klondike-Solver/Random.cpp",
                        "Klondike-Solver/Pile.cpp",
                        "Klondike-Solver/Move.cpp",
                        "Klondike-Solver/KlondikeSolver.cpp",
                        "Klondike-Solver/Card.cpp",
                        ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ],
}
