import qbs
  
CppApplication {
    name : "qt_download"
    files : "src/*"
    consoleApplication: true

    Depends { name: "Qt"; submodules: ["core", "network"] }
}

