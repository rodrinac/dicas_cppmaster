import qbs
  
CppApplication {
    name : "qt_wavplayer"
    files : "src/*"

    Depends { name: "Qt"; submodules: ["core", "gui", "widgets", "multimedia"] }
}

