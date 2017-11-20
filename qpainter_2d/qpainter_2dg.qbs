import qbs
  
CppApplication {
    name : "qpainter_2dg"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core", "gui", "widgets"] }
}

