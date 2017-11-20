import qbs
  
CppApplication {
    name : "qt_charts"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core", "gui", "sql", "widgets", "charts"] }
}

